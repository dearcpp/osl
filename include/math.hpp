#ifndef _OSL_MATH_HPP
#define _OSL_MATH_HPP

# include <defines.hpp>

OSL_BEGIN_NAMESPACE

template <class _type>
_OSL_NODISCARD _OSL_CONSTEXPR _type pow(_type value, _type power) _OSL_NOEXCEPT {
    if (power == 0)
        return 1;
    else if (power % 2 == 0)
        return pow(value, power / 2) * pow(value, power / 2);
    else
        return value * pow(value, power / 2) * pow(value, power / 2);
}

OSL_END_NAMESPACE

#endif
