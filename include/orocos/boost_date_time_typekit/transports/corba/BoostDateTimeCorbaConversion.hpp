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

#ifndef BOOST_DATE_TIME_TYPEKIT_TRANSPORT_CORBA_BOOST_DATE_TIME_CORBA_CONVERSION_HPP
#define BOOST_DATE_TIME_TYPEKIT_TRANSPORT_CORBA_BOOST_DATE_TIME_CORBA_CONVERSION_HPP

#include <boost/date_time/posix_time/posix_time.hpp>

#include <rtt/transports/corba/CorbaConversion.hpp>

namespace RTT {
    namespace corba {

        template<>
        struct AnyConversion< boost::posix_time::ptime >
        {
            typedef CORBA::LongLong CorbaType;
            typedef boost::posix_time::ptime StdType;

            static const CorbaType not_a_date_time() {
                return boost::date_time::int_adapter<CorbaType>::not_a_number().as_number();
            }

            static const CorbaType pos_infin() {
                return boost::date_time::int_adapter<CorbaType>::pos_infinity().as_number();
            }

            static const CorbaType neg_infin() {
                return boost::date_time::int_adapter<CorbaType>::neg_infinity().as_number();
            }

            static CorbaType toAny(const StdType& t) {
                if (t.is_not_a_date_time()) {
                    return not_a_date_time();
                } else if (t.is_pos_infinity()) {
                    return pos_infin();
                } else if (t.is_neg_infinity()) {
                    return neg_infin();
                } else {
                    static const boost::posix_time::ptime epoch = boost::posix_time::from_time_t(0);
                    boost::posix_time::time_duration d = t - epoch;
                    return static_cast<CorbaType>(d.total_nanoseconds());
                }
            }

            static bool updateAny( StdType const& t, CORBA::Any& any ) {
                any <<= toAny( t );
                return true;
            }

            static bool update(const CORBA::Any& any, StdType& _value) {
                CorbaType result;
                if ( any >>= result ) {
                    return toStdType(_value, result);
                }
                return false;
            }

            static CORBA::Any_ptr createAny( const StdType& t ) {
                CORBA::Any_ptr ret = new CORBA::Any();
                *ret <<= toAny( t );
                return ret;
            }

            static bool toCorbaType(CorbaType& cb, const StdType& tp) {
                cb = toAny(tp);
                return true;
            }

            static bool toStdType(StdType& tp, const CorbaType& cb) {
                if (cb == not_a_date_time()) {
                    tp = boost::posix_time::not_a_date_time;
                    return true;
                } else if (cb == pos_infin()) {
                    tp = boost::posix_time::pos_infin;
                    return true;
                } else if (cb == neg_infin()) {
                    tp = boost::posix_time::neg_infin;
                    return true;
                } else {
#if defined(BOOST_DATE_TIME_HAS_NANOSECONDS)
                    tp = boost::posix_time::from_time_t(0)
                        + boost::posix_time::nanoseconds(cb);
#else
                    tp = boost::posix_time::from_time_t(0)
                        + boost::posix_time::microseconds(cb / 1000ll);
#endif
                }
            }
        };

        template<>
        struct AnyConversion< boost::posix_time::time_duration >
        {
            typedef CORBA::LongLong CorbaType;
            typedef boost::posix_time::time_duration StdType;

            static const CorbaType not_a_date_time() {
                return boost::date_time::int_adapter<CorbaType>::not_a_number().as_number();
            }

            static const CorbaType pos_infin() {
                return boost::date_time::int_adapter<CorbaType>::pos_infinity().as_number();
            }

            static const CorbaType neg_infin() {
                return boost::date_time::int_adapter<CorbaType>::neg_infinity().as_number();
            }

            static CorbaType toAny(const StdType& d) {
                if (d.is_not_a_date_time()) {
                  return not_a_date_time();
                } else if (d.is_pos_infinity()) {
                  return pos_infin();
                } else if (d.is_neg_infinity()) {
                  return neg_infin();
                } else {
                  return static_cast<CorbaType>(d.total_nanoseconds());
                }
            }

            static bool updateAny( StdType const& t, CORBA::Any& any ) {
                any <<= toAny( t );
                return true;
            }

            static bool update(const CORBA::Any& any, StdType& _value) {
                CorbaType result;
                if ( any >>= result ) {
                    return toStdType(_value, result);
                }
                return false;
            }

            static CORBA::Any_ptr createAny( const StdType& t ) {
                CORBA::Any_ptr ret = new CORBA::Any();
                *ret <<= toAny( t );
                return ret;
            }

            static bool toCorbaType(CorbaType& cb, const StdType& tp) {
                cb = toAny(tp);
                return true;
            }

            static bool toStdType(StdType& tp, const CorbaType& cb) {
                if (cb == not_a_date_time()) {
                  tp = boost::posix_time::not_a_date_time;
                } else if (cb == pos_infin()) {
                  tp = boost::posix_time::pos_infin;
                } else if (cb == neg_infin()) {
                  tp = boost::posix_time::neg_infin;
                } else {
#if defined(BOOST_DATE_TIME_HAS_NANOSECONDS)
                  tp = boost::posix_time::nanoseconds(cb);
#else
                  tp = boost::posix_time::microseconds(cb / 1000ll);
#endif
                }
                return true;
            }
        };

    }  // namespace corba
}  // namespace RTT

#endif // BOOST_DATE_TIME_TYPEKIT_TRANSPORT_CORBA_BOOST_DATE_TIME_CORBA_CONVERSION_HPP
