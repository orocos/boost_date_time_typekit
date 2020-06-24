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

#ifndef BOOST_DATE_TIME_TYPES_HPP
#define BOOST_DATE_TIME_TYPES_HPP

// include <rtt/config.h> first, as it might define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG
#include <rtt/rtt-config.h>

#include <boost/date_time/posix_time/posix_time.hpp>

#include <vector>

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::boost::posix_time::ptime >;
    extern template class RTT::internal::AssignableDataSource< ::boost::posix_time::ptime >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::boost::posix_time::ptime >;
    extern template class RTT::internal::ConstantDataSource< ::boost::posix_time::ptime >;
    extern template class RTT::internal::ReferenceDataSource< ::boost::posix_time::ptime >;
#endif
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< ::boost::posix_time::ptime >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::OutputPort< ::boost::posix_time::ptime >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::InputPort< ::boost::posix_time::ptime >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::boost::posix_time::ptime >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::boost::posix_time::ptime >;
#endif

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< std::vector<::boost::posix_time::ptime> >;
    extern template class RTT::internal::AssignableDataSource< std::vector<::boost::posix_time::ptime> >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< std::vector<::boost::posix_time::ptime> >;
    extern template class RTT::internal::ConstantDataSource< std::vector<::boost::posix_time::ptime> >;
    extern template class RTT::internal::ReferenceDataSource< std::vector<::boost::posix_time::ptime> >;
#endif
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< std::vector<::boost::posix_time::ptime> >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::OutputPort< std::vector<::boost::posix_time::ptime> >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::InputPort< std::vector<::boost::posix_time::ptime> >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< std::vector<::boost::posix_time::ptime> >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< std::vector<::boost::posix_time::ptime> >;
#endif

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< ::boost::posix_time::time_duration >;
    extern template class RTT::internal::AssignableDataSource< ::boost::posix_time::time_duration >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< ::boost::posix_time::time_duration >;
    extern template class RTT::internal::ConstantDataSource< ::boost::posix_time::time_duration >;
    extern template class RTT::internal::ReferenceDataSource< ::boost::posix_time::time_duration >;
#endif
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< ::boost::posix_time::time_duration >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::OutputPort< ::boost::posix_time::time_duration >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::InputPort< ::boost::posix_time::time_duration >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< ::boost::posix_time::time_duration >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< ::boost::posix_time::time_duration >;
#endif

#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< std::vector<::boost::posix_time::time_duration> >;
    extern template class RTT::internal::AssignableDataSource< std::vector<::boost::posix_time::time_duration> >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< std::vector<::boost::posix_time::time_duration> >;
    extern template class RTT::internal::ConstantDataSource< std::vector<::boost::posix_time::time_duration> >;
    extern template class RTT::internal::ReferenceDataSource< std::vector<::boost::posix_time::time_duration> >;
#endif
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< std::vector<::boost::posix_time::time_duration> >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::OutputPort< std::vector<::boost::posix_time::time_duration> >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::InputPort< std::vector<::boost::posix_time::time_duration> >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< std::vector<::boost::posix_time::time_duration> >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< std::vector<::boost::posix_time::time_duration> >;
#endif

#endif

