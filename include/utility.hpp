#ifndef _OSL_UTILITY_HPP_
#define _OSL_UTILITY_HPP_

# include <defines.hpp>

OSL_BEGIN_NAMESPACE

template <class _Type>
void swap(_Type &first, _Type &second)
{
    _Type temporary = first;
    first = second;
    second = temporary;
}

OSL_END_NAMESPACE

#endif
