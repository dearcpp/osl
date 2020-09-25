#ifndef _OSL_UTILS_HPP
#define _OSL_UTILS_HPP

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