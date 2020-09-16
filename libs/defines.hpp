#ifndef _OSL_DEFINES_HPP
#define _OSL_DEFINES_HPP

# if __cplusplus >= 201103L
#  define _OSL_NOEXCEPT noexcept
# else
#  define _OSL_NOEXCEPT
# endif

# if __cplusplus >= 201103L
#  define _OSL_CONSTEXPR constexpr
# else
#  define _OSL_CONSTEXPR const
# endif

# if __cplusplus >= 201703L
#  define _OSL_NODISCARD [[__nodiscard__]]
# else
#  define _OSL_NODISCARD
# endif

#endif