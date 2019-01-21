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

