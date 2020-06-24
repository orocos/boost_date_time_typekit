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

#include <rtt/transports/corba/CorbaTemplateProtocol.hpp>
#include <rtt/types/TypekitPlugin.hpp>

#include <boost_date_time_typekit/transports/corba/BoostDateTimeCorbaConversion.hpp>

using namespace RTT;
using namespace RTT::types;
using namespace RTT::corba;

#include <rtt/types/TransportPlugin.hpp>

namespace boost_date_time_typekit {

    namespace corba {

        struct BoostDateTimeCorbaTransportPlugin : public RTT::types::TransportPlugin
        {
            bool registerTransport(std::string name, RTT::types::TypeInfo* ti)
            {
                if ( name == "boost.posix_time.ptime" )
                    return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new CorbaTemplateProtocol< boost::posix_time::ptime >() );
                if ( name == "boost.posix_time.time_duration" )
                    return ti->addProtocol(ORO_CORBA_PROTOCOL_ID, new CorbaTemplateProtocol< boost::posix_time::time_duration >() );
                return false;
            }

            std::string getTransportName() const {
                return "CORBA";
            }

            std::string getName() const {
                return "boost-date_time-transport-corba";
            }

            std::string getTypekitName() const {
                return "boost-date_time";
            }
        };

    }
}

ORO_TYPEKIT_PLUGIN( boost_date_time_typekit::corba::BoostDateTimeCorbaTransportPlugin )
