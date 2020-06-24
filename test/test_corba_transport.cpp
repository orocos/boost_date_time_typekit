/******************************************************************************
*                                                                             *
*       You may redistribute this software and/or modify it under either the  *
*       terms of the GNU Lesser General Public License version 2.1 (LGPLv2.1  *
*       <http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>) or (at your *
*       discretion) of the Modified BSD License:                              *
*       Redistribution and use in source and binary forms, with or without    *
*       modification, are permitted provided that the following conditions    *
*       are met:                                                              *
*       1. Redistributions of source code must retain the above copyright     *
*       notice, this list of conditions and the following disclaimer.         *
*       2. Redistributions in binary form must reproduce the above copyright  *
*       notice, this list of conditions and the following disclaimer in the   *
*       documentation and/or other materials provided with the distribution.  *
*       3. The name of the author may not be used to endorse or promote       *
*       products derived from this software without specific prior written    *
*       permission.                                                           *
*       THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  *
*       IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED        *
*       WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    *
*       ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,*
*       INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    *
*       (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS       *
*       OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) *
*       HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,   *
*       STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING *
*       IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE    *
*       POSSIBILITY OF SUCH DAMAGE.                                           *
*                                                                             *
*******************************************************************************/

#include <boost/date_time/posix_time/posix_time.hpp>

#include <rtt/RTT.hpp>
#include <rtt/os/TimeService.hpp>
#include <rtt/plugin/PluginLoader.hpp>
#include <rtt/transports/corba/CorbaConnPolicy.hpp>
#include <rtt/transports/corba/CorbaLib.hpp>
#include <rtt/transports/corba/Corba.hpp>
#include <rtt/transports/corba/TaskContextServer.hpp>

#include <rtt/os/main.h>

#include <unistd.h>

#define BOOST_TEST_MODULE test_corba_transport
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/auto_unit_test.hpp>

using namespace RTT;
using namespace corba;

struct BoostDateTimeCorbaTestSetup {
    BoostDateTimeCorbaTestSetup()
    {
        plugin::PluginLoader::Instance()->loadTypekit("boost_date_time_typekit", "");
    }
};

template<typename Predicate>
bool waitFor(double timeout_s, Predicate pred) {
    const auto ts = os::TimeService::Instance();
    const auto sleep_time_us = static_cast<useconds_t>((timeout_s * 1e6) / 10);
    const auto start = ts->getTicks();
    while (!pred()) {
        if (ts->secondsSince(start) >= timeout_s) return false;
        usleep(sleep_time_us);
    }
    return true;
}

BOOST_GLOBAL_FIXTURE(BoostDateTimeCorbaTestSetup);

BOOST_AUTO_TEST_CASE(RemoteConnectionPtime)
{
    TaskContext tca("a");
    TaskContext tcb("b");
    OutputPort<boost::posix_time::ptime> ptime_out("ptime");
    InputPort<boost::posix_time::ptime> ptime_in("ptime");
    OutputPort<boost::posix_time::time_duration> time_duration_out("time_duration");
    InputPort<boost::posix_time::time_duration> time_duration_in("time_duration");
    tca.addPort(ptime_out);
    tcb.addPort(ptime_in);
    tca.addPort(time_duration_out);
    tcb.addPort(time_duration_in);

    TaskContextServer* tsa = TaskContextServer::Create(&tca, false); //no-naming
    TaskContextServer* tsb = TaskContextServer::Create(&tcb, false); //no-naming
    CDataFlowInterface_var pa = tsa->server()->ports();
    CDataFlowInterface_var pb = tsb->server()->ports();

    // Create a default CORBA policy specification
    CConnPolicy policy = toCORBA(ConnPolicy::data());
    policy.init = false;
    policy.transport = ORO_CORBA_PROTOCOL_ID; // force creation of non-local connections

    // Connect ports
    BOOST_REQUIRE( pa->createConnection("ptime", pb, "ptime", policy) );
    BOOST_REQUIRE( pa->createConnection("time_duration", pb, "time_duration", policy) );

    const std::initializer_list<boost::posix_time::ptime> ptime_samples{
      boost::posix_time::microsec_clock::local_time(),
      boost::posix_time::not_a_date_time,
      boost::posix_time::pos_infin,
      boost::posix_time::neg_infin
    };
    for(boost::posix_time::ptime write_sample : ptime_samples) {
        boost::posix_time::ptime read_sample = boost::posix_time::from_time_t(0);
        BOOST_CHECK_EQUAL(ptime_out.write(write_sample), WriteSuccess);
        BOOST_CHECK(waitFor(1.0, [&](){ return ptime_in.read(read_sample) == NewData; }));
        BOOST_CHECK_EQUAL(read_sample, write_sample);
    }

    const std::initializer_list<boost::posix_time::time_duration> time_duration_samples{
      boost::posix_time::seconds(42.42),
      boost::posix_time::seconds(-42.42),
      boost::posix_time::microseconds(-1),
      boost::posix_time::microseconds(-2),
      boost::posix_time::not_a_date_time,
      boost::posix_time::pos_infin,
      boost::posix_time::neg_infin
    };
    for(boost::posix_time::time_duration write_sample : time_duration_samples) {
        boost::posix_time::time_duration read_sample = boost::posix_time::time_duration();
        BOOST_CHECK_EQUAL(time_duration_out.write(write_sample), WriteSuccess);
        BOOST_CHECK(waitFor(1.0, [&](){ return time_duration_in.read(read_sample) == NewData; }));
        BOOST_CHECK_EQUAL(read_sample, write_sample);
    }
}

int ORO_main(int argc, char* argv[]) {
    TaskContextServer::InitOrb(argc,argv);
    TaskContextServer::ThreadOrb();

    int ret = boost::unit_test::unit_test_main(&init_unit_test, argc, argv);

    TaskContextServer::ShutdownOrb(true);
    TaskContextServer::DestroyOrb();

    return ret;
}
