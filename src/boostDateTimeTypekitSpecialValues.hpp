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

#ifndef ORO_BOOST_DATE_TIME_TYPEKIT_SPECIALVALUES_HPP
#define ORO_BOOST_DATE_TIME_TYPEKIT_SPECIALVALUES_HPP

#include "boostDateTimeTypekitTypes.hpp"

#include <ostream>
#include <istream>
#include <rtt/types/TemplateTypeInfo.hpp>

// TODO compilation error setting <special_values, true>
namespace boost {
namespace date_time {
// The streaming operators >> and << search for an implementation of operator>>
// or operator<< in the namespace of the arguments, so std or boost::date_time in
// that case.
std::istream &operator>>(std::istream &is, boost::date_time::special_values &val);
std::ostream &operator<<(std::ostream &os, const boost::date_time::special_values &val);
}  // namespace date_time
}  // namespace boost

namespace boost_date_time_typekit {
// Free functions to be called by the Typekit Plugin
void loadSpecialValuesTypes();
void loadSpecialValuesGlobals();

struct special_valuesTypeInfo: public
    RTT::types::TemplateTypeInfo<boost::date_time::special_values, true> {
    special_valuesTypeInfo() :
        RTT::types::TemplateTypeInfo<boost::date_time::special_values, true>("boost.date_time.special_values") {

    }
};
}  // namespace boost_date_time_typekit


#endif
