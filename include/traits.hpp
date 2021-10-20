#ifndef _OSL_TRAITS_HPP_
#define _OSL_TRAITS_HPP_

# include <defines.hpp>

OSL_BEGIN_NAMESPACE

struct true_type 
{
    static const bool value = true;
};

struct false_type 
{
    static const bool value = false;
};

template <class _Type> struct is_const              : false_type { };
template <class _Type> struct is_const<const _Type> : true_type  { };

template <class _Type> struct remove_const              { typedef _Type type; };
template <class _Type> struct remove_const<const _Type> { typedef _Type type; };

OSL_END_NAMESPACE

# define OSL_REMOVE_CONST(TYPE) typename osl::remove_const<TYPE>::type
# define OSL_IS_CONST(TYPE) osl::is_const<TYPE>::value

#endif
