#ifndef _OSL_QUEUE_HPP_
#define _OSL_QUEUE_HPP_

# include <deque.hpp>

OSL_BEGIN_NAMESPACE

template <class _Type, class _Container = deque<_Type>>
class queue
{
public:

    using container_type = _Container;
    using size_type = typename _Container::size_type;
    using value_type = typename _Container::value_type;
    using initializer_list = typename _Container::initializer_list;

public:

    queue() _OSL_NOEXCEPT : _container() { }

    queue(initializer_list list) : _container()
    {
        for (size_type i = 0; i != list.size(); ++i)
        {
            _container.push_front(list.begin()[i]);
        }
    }

    queue(const queue &queue) : _container(queue._container) { }

    virtual ~queue()
    {
        clear();
    }

    void push(const value_type &value)
    {
        _container.push_front(value);
    }

    void pop()
    {
        _container.pop_back();
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE value_type front() const _OSL_NOEXCEPT
    {
        return _container.front();
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE value_type back() const _OSL_NOEXCEPT
    {
        return _container.back();
    }

    void clear()
    {
        _container.clear();
    }

protected:

    container_type _container;

};

OSL_END_NAMESPACE

#endif
