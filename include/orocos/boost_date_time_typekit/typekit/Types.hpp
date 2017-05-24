/* Generated from orogen/lib/orogen/templates/typekit/Types.hpp */

#ifndef BOOST_DATE_TIME_TYPES_HPP
#define BOOST_DATE_TIME_TYPES_HPP

// include <rtt/config.h> first, as it might define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG
#include <rtt/rtt-config.h>

#include <boost/date_time/posix_time/posix_time.hpp>

// This is a hack. We include it unconditionally as it may be required by some
// typekits *and* it is a standard header. Ideally, we would actually check if
// some of the types need std::vector.
#include <vector>
#include <boost/cstdint.hpp>
//#include <boost/serialization/serialization.hpp>
#include <boost/serialization/array.hpp>

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

#endif

