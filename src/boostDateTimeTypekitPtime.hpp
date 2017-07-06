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

#ifndef ORO_BOOST_DATE_TIME_TYPEKIT_PTIME_HPP
#define ORO_BOOST_DATE_TIME_TYPEKIT_PTIME_HPP

#include <boost_date_time_typekit/typekit/Types.hpp>

#include <rtt/types/TemplateTypeInfo.hpp>

namespace boost_date_time_typekit {
using boost::posix_time::ptime;

// Free functions to be called by the Typekit Plugin
void loadPtimeTypes();
void loadPtimeOperators();
void loadPtimeConstructors();
void loadPtimeGlobals();

// Typeinfo for the boost::posix_time::ptime type
// see http://www.boost.org/doc/libs/1_43_0/doc/html/date_time/posix_time.html
// The streaming operators are already defined in boost if another implementation is desired the
// Typeinfo should be TemplateTypeInfo<ptime,false> and the functions read() and write()
// should be overridden
class PtimeTypeInfo: public RTT::types::TemplateTypeInfo<ptime, true>,
    public RTT::types::MemberFactory {
  public:
    PtimeTypeInfo(std::string name) : RTT::types::TemplateTypeInfo<ptime, true>(name) {
    }

    bool installTypeInfoObject(RTT::types::TypeInfo *ti);

    virtual bool decomposeTypeImpl(const ptime &source, RTT::PropertyBag &targetbag) const;

    // Another solution would be to use directly composeType() overriding the default implementation
    // that internally calls composeTypeImpl()
    // Using directly composeType leads to compose directly a simple tipe that is a string
    virtual bool composeTypeImpl(const RTT::PropertyBag &source, ptime &result) const;

    virtual std::vector<std::string> getMemberNames() const;

    virtual RTT::base::DataSourceBase::shared_ptr getMember(RTT::base::DataSourceBase::shared_ptr item,
            const std::string &name) const;

    virtual  RTT::base::DataSourceBase::shared_ptr getMember(RTT::base::DataSourceBase::shared_ptr item,
            RTT::base::DataSourceBase::shared_ptr id) const;
};
}   // namespace boost_date_time_typekit

#endif
