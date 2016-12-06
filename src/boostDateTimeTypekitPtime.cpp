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

#include "boostDateTimeTypekitPtime.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"

#include <rtt/types/TemplateTypeInfo.hpp>
#include <rtt/types/SequenceTypeInfo.hpp>
#include <rtt/types/Operators.hpp>
#include <rtt/types/OperatorTypes.hpp>
#include <rtt/types/GlobalsRepository.hpp>
#include <rtt/internal/mystd.hpp>
#include <rtt/internal/GlobalService.hpp>

template class RTT::internal::DataSource< ::boost::posix_time::ptime >;
template class RTT::internal::AssignableDataSource< ::boost::posix_time::ptime >;
template class RTT::internal::ValueDataSource< ::boost::posix_time::ptime >;
template class RTT::internal::ConstantDataSource< ::boost::posix_time::ptime >;
template class RTT::internal::ReferenceDataSource< ::boost::posix_time::ptime >;
template class RTT::base::ChannelElement< ::boost::posix_time::ptime >;
template class RTT::OutputPort< ::boost::posix_time::ptime >;
template class RTT::InputPort< ::boost::posix_time::ptime >;
template class RTT::Property< ::boost::posix_time::ptime >;
template class RTT::Attribute< ::boost::posix_time::ptime >;
template class RTT::internal::DataSource< std::vector<boost::posix_time::ptime> >;
template class RTT::internal::AssignableDataSource< std::vector<boost::posix_time::ptime> >;
template class RTT::internal::ValueDataSource< std::vector<boost::posix_time::ptime> >;
template class RTT::internal::ConstantDataSource< std::vector<boost::posix_time::ptime> >;
template class RTT::internal::ReferenceDataSource< std::vector<boost::posix_time::ptime> >;
template class RTT::base::ChannelElement< std::vector<boost::posix_time::ptime> >;
template class RTT::OutputPort< std::vector<boost::posix_time::ptime> >;
template class RTT::InputPort< std::vector<boost::posix_time::ptime> >;
template class RTT::Property< std::vector<boost::posix_time::ptime> >;
template class RTT::Attribute< std::vector<boost::posix_time::ptime> >;

namespace boost_date_time_typekit {
using namespace std;
using namespace RTT;
using namespace boost::posix_time;
using namespace boost::date_time;
using boost::posix_time::time_duration;

// Helper functions used to implement "virtual members"
int getHours(const ptime &time) {
    return time.time_of_day().hours();
}

int getMinutes(const ptime &time) {
    return time.time_of_day().minutes();
}

int getSeconds(const ptime &time) {
    return time.time_of_day().seconds();
}

unsigned long long getTotalSeconds(const ptime &time) {
    const ptime epoch = from_time_t(0);  // Unix start time
    boost::posix_time::time_duration timeFromEpoch = time - epoch;
    return timeFromEpoch.total_seconds();
}

unsigned long long getTotalMilliseconds(const ptime &time) {
    const ptime epoch = from_time_t(0);  // Unix start time
    boost::posix_time::time_duration timeFromEpoch = time - epoch;
    return timeFromEpoch.total_milliseconds();
}

unsigned long long getTotalMicroseconds(const ptime &time) {
    const ptime epoch = from_time_t(0);  // Unix start time
    boost::posix_time::time_duration timeFromEpoch = time - epoch;
    return timeFromEpoch.total_microseconds();
}

unsigned long long getTotalNanoseconds(const ptime &time) {
    const ptime epoch = from_time_t(0);  // Unix start time
    boost::posix_time::time_duration timeFromEpoch = time - epoch;
    return timeFromEpoch.total_nanoseconds();
}

// Construct from a date and offset.
ptime ptimeConstructorDo(boost::gregorian::date d, posix_time_system::time_duration_type td) {
    return ptime(d, td);
}

// Copy constructor.
ptime ptimeConstructorCopy(ptime time) {
    return ptime(time);
}

// Constructor for infinities, not-a-date-time, max_date_time, and min_date_time.
ptime ptimeConstructorSv(special_values sv) {
    return ptime(sv);
}

// Constructor from an iso string.
ptime ptimeConstructorSt(std::string stime) {
    ptime tmp = from_iso_string(stime);

    if (tmp.is_not_a_date_time()) {
        return time_from_string(stime);
    }
    return from_iso_string(stime);
}

void loadPtimeTypes() {
    RTT::types::Types()->addType(new PtimeTypeInfo("boost.posix_time.ptime"));
    RTT::types::Types()->addType(new
                                 RTT::types::SequenceTypeInfo<std::vector< ptime > >("boost.posix_time.ptime[]"));
}

void loadPtimeConstructors() {
    RTT::types::TypeInfoRepository::shared_ptr ti = RTT::types::TypeInfoRepository::Instance();

    ti->type("boost.posix_time.ptime")->addConstructor(RTT::types::newConstructor(&ptimeConstructorDo));
    ti->type("boost.posix_time.ptime")->addConstructor(RTT::types::newConstructor(
                &ptimeConstructorCopy));
    ti->type("boost.posix_time.ptime")->addConstructor(RTT::types::newConstructor(&ptimeConstructorSv));
    // Setting automatic to true the conversion "from string to boost.posix_time.ptime" it is done automatically
    // without any warning.
    ti->type("boost.posix_time.ptime")->addConstructor(RTT::types::newConstructor(
                &ptimeConstructorSt, /* automatic = */ true));
}

// Function used to decompose a ptime and store it as a property.
bool PtimeTypeInfo::decomposeTypeImpl(const ptime &source, PropertyBag &targetbag) const {
    // A PropertyBag with the type boost.posix_time.ptime is generated
    targetbag.setType("boost.posix_time.ptime");
    // A simple property is added to the PropertyBag
    // If source.is_not_a_date_time()  to_iso_string print "not-a-date-time"
    targetbag.add(new Property<std::string>("date", "time value",  to_iso_string(source)));
    return true;
}

// Function to compose a ptime from a property.
bool PtimeTypeInfo::composeTypeImpl(const PropertyBag &source, ptime &result) const {
    if (source.getType() == std::string("boost.posix_time.ptime")) {  // check the type
        // The simple property named "date" inside of the struct Tag named
        // "boost.posix_time.ptime" is retrieved
        Property<std::string> stime = source.getProperty("date");
        result = from_iso_string(stime);

        if (result.is_not_a_date_time()) {
            result = time_from_string(stime);
        }
        return true;
    }
    return false; // unknown type !
}

void loadPtimeOperators() {
    RTT::types::OperatorRepository::shared_ptr oreg = RTT::types::OperatorRepository::Instance();

    // Comparison operators
    oreg->add(RTT::types::newBinaryOperator("==", std::equal_to<ptime>()));
    oreg->add(RTT::types::newBinaryOperator("!=", std::not_equal_to<ptime>()));
    oreg->add(RTT::types::newBinaryOperator(">", std::greater<ptime>()));
    oreg->add(RTT::types::newBinaryOperator("<", std::less<ptime>()));
    oreg->add(RTT::types::newBinaryOperator(">=", std::greater_equal<ptime>()));
    oreg->add(RTT::types::newBinaryOperator("<=", std::less_equal<ptime>()));
    // Return a ptime adding a day offset.
    oreg->add(RTT::types::newBinaryOperator("+",
                                            RTT::internal::adds3<ptime, ptime, boost::gregorian::days >()));
    // Return a ptime subtracting a day offset.
    oreg->add(RTT::types::newBinaryOperator("-",
                                            RTT::internal::subs3<ptime, ptime, boost::gregorian::days >()));
    // Return a ptime adding a time duration.
    oreg->add(RTT::types::newBinaryOperator("+", RTT::internal::adds3<ptime, ptime, time_duration >()));
    // Return a ptime subtracting a time duration.
    oreg->add(RTT::types::newBinaryOperator("-", RTT::internal::subs3<ptime, ptime, time_duration >()));
    // Take the difference between two times.
    oreg->add(RTT::types::newBinaryOperator("-", RTT::internal::subs3<time_duration, ptime, ptime >()));
}

void loadPtimeGlobals() {
    // We add free global functions.
    RTT::Service::shared_ptr gs = RTT::internal::GlobalService::Instance();

    gs->provides("boost")->provides("posix_time")->addOperation("getLocalTime",
            static_cast<ptime(*)()>(&boost::posix_time::microsec_clock::local_time), RTT::ClientThread);
}

std::vector<std::string> PtimeTypeInfo::getMemberNames() const {
    // We add the "virtual members" so that for example when the user types
    // <ptime_instance>.hours a function is called
    std::vector<std::string> result;
    result.push_back("hours");
    result.push_back("minutes");
    result.push_back("seconds");
    result.push_back("totalSeconds");
    result.push_back("totalMilliseconds");
    result.push_back("totalMicroseconds");
    result.push_back("totalNanoseconds");
    return result;
}

base::DataSourceBase::shared_ptr PtimeTypeInfo::getMember(base::DataSourceBase::shared_ptr item,
        const std::string &name) const        {
    return getMember(item, new RTT::internal::ConstantDataSource<std::string>(name));
}

// We have to install our member factory so that the function getMember() that we write is called
bool PtimeTypeInfo::installTypeInfoObject(RTT::types::TypeInfo *ti) {
    // Aquire a shared reference to the this object.
    boost::shared_ptr< PtimeTypeInfo > mthis = boost::dynamic_pointer_cast< PtimeTypeInfo >
            (this->getSharedPtr());
    assert(mthis);
    // Allow base to install first
    TemplateTypeInfo<ptime, true>::installTypeInfoObject(ti);
    // Install the factories for primitive types
    ti->setMemberFactory(mthis);
    // Don't delete us, we're memory-managed.
    return false;
}

base::DataSourceBase::shared_ptr PtimeTypeInfo::getMember(base::DataSourceBase::shared_ptr item,
        base::DataSourceBase::shared_ptr id) const {
    // Discover if user gave us a part name. If it is since this member is not really present in the structure we add
    // a Functor, so that the "virtual member" value is just the result of a function call.
    RTT::internal::DataSource<string>::shared_ptr id_name = RTT::internal::DataSource<string>::narrow(
                id.get());

    if (id_name) {
        if (id_name->get() == "hours") {
            try {
                return RTT::internal::newFunctorDataSource(&getHours,
                        RTT::internal::GenerateDataSource()(item.get()));
            } catch (...) {}
        } else if (id_name->get() == "minutes") {
            try {
                return RTT::internal::newFunctorDataSource(&getMinutes,
                        RTT::internal::GenerateDataSource()(item.get()));
            } catch (...) {}
        } else if (id_name->get() == "seconds") {
            try {
                return RTT::internal::newFunctorDataSource(&getSeconds,
                        RTT::internal::GenerateDataSource()(item.get()));
            } catch (...) {}
        } else if (id_name->get() == "totalSeconds") {
            try {
                return RTT::internal::newFunctorDataSource(&getTotalSeconds,
                        RTT::internal::GenerateDataSource()(item.get()));
            } catch (...) {}
        } else if (id_name->get() == "totalMilliseconds") {
            try {
                return RTT::internal::newFunctorDataSource(&getTotalMilliseconds,
                        RTT::internal::GenerateDataSource()(item.get()));
            } catch (...) {}
        } else if (id_name->get() == "totalMicroseconds") {
            try {
                return RTT::internal::newFunctorDataSource(&getTotalMicroseconds,
                        RTT::internal::GenerateDataSource()(item.get()));
            } catch (...) {}
        } else if (id_name->get() == "totalNanoseconds") {
            try {
                return RTT::internal::newFunctorDataSource(&getTotalNanoseconds,
                        RTT::internal::GenerateDataSource()(item.get()));
            } catch (...) {}
        }
    }

    log(Error) << "PtimeTypeInfo has no member named : " << id_name->get() << endlog();
    return base::DataSourceBase::shared_ptr();
}

}  // namespace boost_date_time_typekit
