/*
(c) 2014-2015 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGNMENT_OF_MSVC_HPP
#define BOOST_ALIGN_DETAIL_ALIGNMENT_OF_MSVC_HPP

#pragma warning(push)
#pragma warning(disable: 4121) // alignment of a member was sensitive to packing

#include <boost/align/detail/min_size.hpp>

namespace boost {
namespace alignment {
namespace detail {

template<class T>
struct alignof_helper {
    T first;
    char value;
    T second;
};

template<class T>
struct alignment_of
    : min_size<sizeof(T),
        sizeof(alignof_helper<T>) - (sizeof(T) << 1)> { };

} /* .detail */
} /* .alignment */
} /* .boost */

#pragma warning(pop)
#endif
