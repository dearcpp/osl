#ifndef _OSL_DEFINES_HPP_
#define _OSL_DEFINES_HPP_

# define OSL_NAMESPACE osl
# define OSL_BEGIN_NAMESPACE namespace OSL_NAMESPACE {
# define OSL_END_NAMESPACE }

# if __cplusplus >= 201703L
#  define _OSL_NODISCARD [[__nodiscard__]]
# else
#  define _OSL_NODISCARD
# endif

# if __cplusplus >= 201103L
#  define _OSL_CONSTEXPR constexpr
# else
#  define _OSL_CONSTEXPR const
# endif

# if __cplusplus >= 201703L
#  define _OSL_INLINE inline
# else
#  define _OSL_INLINE
# endif

# if __cplusplus >= 201103L
#  define _OSL_NOEXCEPT noexcept
#  define _OSL_NOEXCEPT_IF(...) noexcept(__VA_ARGS__)
#  define _OSL_THROW(_EXC)
# else
#  define _OSL_NOEXCEPT throw()
#  define _OSL_NOEXCEPT_IF(...)
#  define _OSL_THROW(_EXC) throw(_EXC)
# endif

# if defined(__GNUC__)
#  define _OSL_FORCE_INLINE __attribute__((always_inline)) inline
# elif defined(_MSC_VER)
#  define _OSL_FORCE_INLINE __forceinline
# else
#  define _OSL_FORCE_INLINE _OSL_INLINE
# endif

#endif
