#ifndef _OSL_UTILITY_HPP
#define _OSL_UTILITY_HPP

#include <defines.hpp>

OSL_BEGIN_NAMESPACE

template <class _type>
void swap(_type &first, _type &second) {
    _type temporary = first;
    first = second;
    second = temporary;
}

OSL_END_NAMESPACE

#endif
