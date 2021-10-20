#ifndef _OSL_DEQUE_HPP_
#define _OSL_DEQUE_HPP_

# include <assert.hpp>
# include <initializer_list>

OSL_BEGIN_NAMESPACE

template <class _Type>
class deque
{
public:

    using size_type = u32;
    using value_type = _Type;
    using initializer_list = std::initializer_list<value_type>;

protected:

    struct node
    {
        value_type value;
        node *next, *prev;
        node(value_type value, node *next, node *prev) : value(value), next(next), prev(prev) { }
    };

public:

    deque() _OSL_NOEXCEPT : _front(0), _back(0), _size(0) { }

    deque(initializer_list list) : _front(0), _back(0), _size(0)
    {
        for (size_type i = 0; i < list.size(); ++i)
        {
            push_back(list.begin()[i]);
        }
    }

    deque(const deque &deque) : _front(0), _back(0), _size(0)
    {
        for (auto it = deque._front; it != 0; it = it->prev)
        {
            push_back(it->value);
        }
    }

    virtual ~deque()
    {
        clear();
    }

    void push_front(const value_type &value)
    {
        _front = new node(value, 0, _front);

        if (_size == 0) _back = _front;
        else _front->prev->next = _front;

        _size++;
    }

    void push_back(const value_type &value)
    {
        _back = new node(value, _back, 0);

        if (_size == 0) _front = _back;
        else _back->next->prev = _back;

        _size++;
    }

    void pop_front()
    {
        OSL_ASSERT(_size != 0, "unable to pop element from empty container");

        node *old_front = _front;
        _front = _front->prev;

        if (_front) _front->next = 0;
        else _back = 0;

        delete old_front;
        _size--;
    }

    void pop_back()
    {
        OSL_ASSERT(_size != 0, "unable to pop element from empty container");

        node *old_back = _back;
        _back = _back->next;

        if (_back) _back->prev = 0;
        else _front = 0;
        
        delete old_back;
        _size--;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE value_type front() const _OSL_NOEXCEPT
    {
        return _front->value;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE value_type back() const _OSL_NOEXCEPT
    {
        return _back->value;
    }

    _OSL_NODISCARD value_type &operator[](size_type index)
    {
        OSL_ASSERT(index >= 0 && index < _size, "out of bounds element getting");

        auto it = _front;
        for (; index; --index) it = it->prev;

        return it->value;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE const value_type operator[](size_type index) const
    {
        return this->operator[](index);
    }

    void clear()
    {
        auto it = _front;
        while (it != 0)
        {
            node *buffer = it->prev;
            delete it;
            it = buffer;
        }
        _front = 0, _back = 0, _size = 0;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE bool empty() const _OSL_NOEXCEPT
    {
        return _size == 0;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE size_type size() const _OSL_NOEXCEPT
    {
        return _size;
    }

protected:

    node *_front, *_back;
    size_type _size;

};

OSL_END_NAMESPACE

#endif
