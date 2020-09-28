#ifndef _OSL_UTILITY_HPP
#define _OSL_UTILITY_HPP

namespace osl
{
    template <class _type>
    void swap(_type &first, _type &second) {
        _type temporary = first;
        first = second;
        second = temporary;
    }
}

#endif