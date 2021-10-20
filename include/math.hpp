#ifndef _OSL_MATH_HPP_
#define _OSL_MATH_HPP_

# include <defines.hpp>

OSL_BEGIN_NAMESPACE

template <class _Type>
_OSL_NODISCARD _OSL_CONSTEXPR _Type pow(_Type value, _Type power) _OSL_NOEXCEPT
{
    if (power == 0) 
        return 1;
    else if (power % 2 == 0)
        return pow(value, power / 2) * pow(value, power / 2);
    else
        return value * pow(value, power / 2) * pow(value, power / 2);
}

OSL_END_NAMESPACE

#endif
