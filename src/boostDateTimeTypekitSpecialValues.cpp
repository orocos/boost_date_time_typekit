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

#include "boostDateTimeTypekitSpecialValues.hpp"
#include <rtt/types/GlobalsRepository.hpp>

namespace boost {
namespace date_time {
// Writing.
std::ostream &operator<<(std::ostream &os, const boost::date_time::special_values &val) {
    switch (val) {
    case boost::date_time::not_a_date_time:
        os << "not_a_date_time";
        break;

    case boost::date_time::neg_infin:
        os << "neg_infin";
        break;

    case boost::date_time::pos_infin:
        os << "pos_infin";
        break;

    case boost::date_time::min_date_time:
        os << "min_date_time";
        break;

    case boost::date_time::max_date_time:
        os << "max_date_time";
        break;

    case boost::date_time::not_special:
        os << "not_special";
        break;

    case boost::date_time::NumSpecialValues:
        os << "NumSpecialValues";
        break;

    default:
        os << "unknown_value";
        break;
    }

    return os;
}

// Reading.
std::istream &operator>>(std::istream &is, boost::date_time::special_values &val) {
    // default:
    val = boost::date_time::not_special;
    std::string s;
    is >> s;

    if (s == "not_a_date_time") {
        val = boost::date_time::not_a_date_time;
    } else if (s == "neg_infin") {
        val = boost::date_time::neg_infin;
    } else if (s == "min_date_time") {
        val = boost::date_time::min_date_time;
    } else if (s == "max_date_time") {
        val = boost::date_time::max_date_time;
    } else if (s == "not_special") {
        val = boost::date_time::not_special;
    } else if (s == "NumSpecialValues") {
        val = boost::date_time::not_special;
    }

    return is;
}
}  // namespace date_time
}  // namespace boost

namespace boost_date_time_typekit {

void loadSpecialValuesTypes() {
    RTT::types::Types()->addType(new special_valuesTypeInfo());
}

// Function used to make RTT aware of some constants values.
// This way the constants can be used for scripting
void loadSpecialValuesGlobals() {
    RTT::types::GlobalsRepository::shared_ptr globals = RTT::types::GlobalsRepository::Instance();
    globals->setValue(new RTT::Constant<boost::date_time::special_values>("not_a_date_time",
                      boost::date_time::not_a_date_time));
    globals->setValue(new RTT::Constant<boost::date_time::special_values>("neg_infin",
                      boost::date_time::neg_infin));
    globals->setValue(
        new RTT::Constant<boost::date_time::special_values>("pos_infin", boost::date_time::pos_infin));
    globals->setValue(
        new RTT::Constant<boost::date_time::special_values>("min_date_time",
                boost::date_time::min_date_time));
    globals->setValue(new RTT::Constant<boost::date_time::special_values>("max_date_time",
                      boost::date_time::max_date_time));
    globals->setValue(new RTT::Constant<boost::date_time::special_values>("not_special",
                      boost::date_time::not_special));
    globals->setValue(new RTT::Constant<boost::date_time::special_values>("NumSpecialValues",
                      boost::date_time::NumSpecialValues));
}

}  // namespace boost_date_time_typekit
