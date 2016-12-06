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
/* @Description:
 * @brief BOOST_DATE_TIME typekit for Orocos RTT
 * @Author: Luca Magnabosco
 */

#include "boostDateTimeTypekitTimeDuration.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"

#include <rtt/types/TemplateTypeInfo.hpp>
#include <rtt/types/SequenceTypeInfo.hpp>
#include <rtt/types/Operators.hpp>
#include <rtt/types/OperatorTypes.hpp>
#include <rtt/internal/mystd.hpp>
#include <rtt/internal/GlobalService.hpp>
#include <rtt/types/GlobalsRepository.hpp>

template class RTT::internal::DataSource< ::boost::posix_time::time_duration >;
template class RTT::internal::AssignableDataSource< ::boost::posix_time::time_duration >;
template class RTT::internal::ValueDataSource< ::boost::posix_time::time_duration >;
template class RTT::internal::ConstantDataSource< ::boost::posix_time::time_duration >;
template class RTT::internal::ReferenceDataSource< ::boost::posix_time::time_duration >;
template class RTT::base::ChannelElement< ::boost::posix_time::time_duration >;
template class RTT::OutputPort< ::boost::posix_time::time_duration >;
template class RTT::InputPort< ::boost::posix_time::time_duration >;
template class RTT::Property< ::boost::posix_time::time_duration >;
template class RTT::Attribute< ::boost::posix_time::time_duration >;
template class RTT::internal::DataSource< std::vector<boost::posix_time::time_duration> >;
template class RTT::internal::AssignableDataSource< std::vector<boost::posix_time::time_duration> >;
template class RTT::internal::ValueDataSource< std::vector<boost::posix_time::time_duration> >;
template class RTT::internal::ConstantDataSource< std::vector<boost::posix_time::time_duration> >;
template class RTT::internal::ReferenceDataSource< std::vector<boost::posix_time::time_duration> >;
template class RTT::base::ChannelElement< std::vector<boost::posix_time::time_duration> >;
template class RTT::OutputPort< std::vector<boost::posix_time::time_duration> >;
template class RTT::InputPort< std::vector<boost::posix_time::time_duration> >;
template class RTT::Property< std::vector<boost::posix_time::time_duration> >;
template class RTT::Attribute< std::vector<boost::posix_time::time_duration> >;

namespace boost_date_time_typekit {
using namespace std;
using namespace RTT;
using namespace boost::posix_time;
using namespace boost::date_time;
typedef boost::posix_time::time_duration::hour_type hour_type;
typedef boost::posix_time::time_duration::min_type min_type;
typedef boost::posix_time::time_duration::sec_type sec_type;
typedef boost::posix_time::time_duration::fractional_seconds_type fractional_seconds_type;

// Helper functions used to implement "virtual members"
int getHours(const time_duration &duration) {
    return duration.hours();
}

int getMinutes(const time_duration &duration) {
    return duration.minutes();
}

int getSeconds(const time_duration &duration) {
    return duration.seconds();
}

unsigned long long getTotalSeconds(const time_duration &duration) {
    return duration.total_seconds();
}

unsigned long long getTotalMilliseconds(const time_duration &duration) {
    return duration.total_milliseconds();
}

unsigned long long getTotalMicroseconds(const time_duration &duration) {
    return duration.total_microseconds();
}

unsigned long long getTotalNanoseconds(const time_duration &duration) {
    return duration.total_nanoseconds();
}

void loadTimeDurationTypes() {
    RTT::types::Types()->addType(new timeDurationTypeInfo("boost.posix_time.time_duration"));
    RTT::types::Types()->addType(new
                                 RTT::types::SequenceTypeInfo<std::vector< time_duration > >("boost.posix_time.time_duration[]"));
}

// Copy constructor.
time_duration timeDurationConstructorCopy(time_duration duration) {
    return time_duration(duration);
}

// Construct a duration from the counts.
time_duration timeDurationContructorFromCounts(hour_type h, min_type m, sec_type s,
        fractional_seconds_type fs) {
    return time_duration(h, m, s, fs);
}

// Construct a duration from the counts without fractional seconds.
time_duration timeDurationContructorFromCounts2(hour_type h, min_type m, sec_type s) {
    return time_duration(h, m, s);
}

// Construct a time duration with a special value such as not_a_date_time, pos_infin, or neg_infin.
time_duration timeDurationContructorSv(special_values sv) {
    return time_duration(sv);
}

// Constructor from a string such as "23:59:59.000"
time_duration timeDurationContructorSt(std::string sduration) {
    return duration_from_string(sduration);
}

void loadTimeDurationConstructors() {
    RTT::types::TypeInfoRepository::shared_ptr ti = RTT::types::TypeInfoRepository::Instance();

    ti->type("boost.posix_time.time_duration")->addConstructor(RTT::types::newConstructor(
                &timeDurationConstructorCopy));
    ti->type("boost.posix_time.time_duration")->addConstructor(RTT::types::newConstructor(
                &timeDurationContructorFromCounts));
    ti->type("boost.posix_time.time_duration")->addConstructor(RTT::types::newConstructor(
                &timeDurationContructorFromCounts2));
    ti->type("boost.posix_time.time_duration")->addConstructor(RTT::types::newConstructor(
                &timeDurationContructorSv));
    // Setting automatic to true the conversion "from string to boost.posix_time.time_duration" it is done automatically
    // without any warning.
    ti->type("boost.posix_time.time_duration")->addConstructor(RTT::types::newConstructor(
                &timeDurationContructorSt, /* automatic = */ true));
}

// Function used to decompose a time_duration and store it as a property.
bool timeDurationTypeInfo::decomposeTypeImpl(const time_duration &source,
        PropertyBag &targetbag) const {
    // A PropertyBag with the type boost.posix_time.time_duration is generated
    targetbag.setType("boost.posix_time.time_duration");
    // A simple property is added to the PropertyBag
    targetbag.add(new Property<std::string>("duration", "duration value",  to_simple_string(source)));
    return true;
}

// Function to compose a time_duration from a property.
bool timeDurationTypeInfo::composeTypeImpl(const PropertyBag &source, time_duration &result) const {
    if (source.getType() == std::string("boost.posix_time.time_duration")) {  // check the type
        // The simple property named "duration" inside of the struct Tag named
        // "boost.posix_time.time_duration" is retrieved
        Property<std::string> stime = source.getProperty("duration");

        result = duration_from_string(stime);

        return true;
    }

    return false; // unknown type !
}

void loadTimeDurationOperators() {
    RTT::types::OperatorRepository::shared_ptr oreg = RTT::types::OperatorRepository::Instance();

    // Comparison operators
    oreg->add(RTT::types::newBinaryOperator("==", std::equal_to<time_duration>()));
    oreg->add(RTT::types::newBinaryOperator("!=", std::not_equal_to<time_duration>()));
    oreg->add(RTT::types::newBinaryOperator(">", std::greater<time_duration>()));
    oreg->add(RTT::types::newBinaryOperator("<", std::less<time_duration>()));
    oreg->add(RTT::types::newBinaryOperator(">=", std::greater_equal<time_duration>()));
    oreg->add(RTT::types::newBinaryOperator("<=", std::less_equal<time_duration>()));
    // Add durations.
    oreg->add(RTT::types::newBinaryOperator("+", std::plus<time_duration>()));
    // Subtract durations.
    oreg->add(RTT::types::newBinaryOperator("-", std::minus<time_duration>()));
    // Invert sign.
    oreg->add(RTT::types::newUnaryOperator("-", std::negate<time_duration>()));
    // Divide the length of a duration by an integer value. Discards any remainder.
    oreg->add(RTT::types::newBinaryOperator("/",
                                            RTT::internal::divides3<time_duration, time_duration, int >()));
    // Multiply the length of a duration by an integer value.
    oreg->add(RTT::types::newBinaryOperator("*",
                                            RTT::internal::multiplies3<time_duration, time_duration, int >()));
}

// Returns a time_duration of a specified amount of hours.
time_duration timeDurationFromHours(int h) {
    return boost::posix_time::hours(h);
}

// Returns a time_duration of a specified amount of minutes.
time_duration timeDurationFromMinutes(int m) {
    return boost::posix_time::minutes(m);
}

// Returns a time_duration of a specified amount of seconds.
time_duration timeDurationFromSeconds(int s) {
    return boost::posix_time::seconds(s);
}

// Returns a time_duration of a specified amount of fractional seconds.
time_duration timeDurationFromFractionalSeconds(long long fs) {
    return time_duration(0, 0, 0, static_cast<fractional_seconds_type>(fs));
}

void loadTimeDurationGlobals() {
    // We add free global functions.
    RTT::Service::shared_ptr gs = RTT::internal::GlobalService::Instance();

    gs->provides("boost")->provides("posix_time")->addOperation("hours", &timeDurationFromHours, RTT::ClientThread).
    doc("Returns a time_duration of a specified amount of hours");
    gs->provides("boost")->provides("posix_time")->addOperation("minutes", &timeDurationFromMinutes,
            RTT::ClientThread).
    doc("Returns a time_duration of a specified amount of minutes");
    gs->provides("boost")->provides("posix_time")->addOperation("seconds", &timeDurationFromSeconds,
            RTT::ClientThread).
    doc("Returns a time_duration of a specified amount of seconds");
    gs->provides("boost")->provides("posix_time")->addOperation("fractionalSeconds", &timeDurationFromFractionalSeconds,
            RTT::ClientThread).
    doc("Returns a time_duration of a specified amount of fractional seconds");
}

std::vector<std::string> timeDurationTypeInfo::getMemberNames() const {
    // We add the "virtual members" so that for example when the user types
    // <time_duration_instance>.hours a function is called
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

base::DataSourceBase::shared_ptr timeDurationTypeInfo::getMember(base::DataSourceBase::shared_ptr
        item, const std::string &name) const        {
    return getMember(item, new RTT::internal::ConstantDataSource<std::string>(name));
}

// We have to install our member factory so that the function getMember() that we write is called
bool timeDurationTypeInfo::installTypeInfoObject(RTT::types::TypeInfo *ti) {
    // aquire a shared reference to the this object
    boost::shared_ptr< timeDurationTypeInfo > mthis =
        boost::dynamic_pointer_cast< timeDurationTypeInfo >(this->getSharedPtr());
    assert(mthis);
    // Allow base to install first
    TemplateTypeInfo<time_duration, true>::installTypeInfoObject(ti);
    // Install the factories for primitive types
    ti->setMemberFactory(mthis);
    // Don't delete us, we're memory-managed.
    return false;
}

base::DataSourceBase::shared_ptr timeDurationTypeInfo::getMember(base::DataSourceBase::shared_ptr
        item,
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

    log(Error) << "timeDurationTypeInfo has no member named : " << id_name->get() << endlog();
    return base::DataSourceBase::shared_ptr();
}

}  // namespace boost_date_time_typekit
