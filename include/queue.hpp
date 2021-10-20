#ifndef _OSL_QUEUE_HPP_
#define _OSL_QUEUE_HPP_

# include <int_types.hpp>
# include <assert.hpp>

# include <initializer_list>

OSL_BEGIN_NAMESPACE

template <class _Type>
class queue
{
public:

    using type = _Type;
    using size_type = u32;
    using initializer_list = std::initializer_list<_Type>;

protected:

    struct node
    {
        type value;
        node *next = 0, *prev;
        node(type value, node *prev) : value(value), prev(prev) { }
    };

public:

    queue() _OSL_NOEXCEPT : _back(0), _front(0), _size(0) { }

    queue(initializer_list queue) : _back(0), _front(0), _size(0)
    {
        for (u32 i = 0; i != queue.size(); ++i)
        {
            this->push(queue.begin()[i]);
        }
    }

    queue(const queue &queue) : _back(0), _front(0), _size(0)
    {
        for (auto it = queue._back; it != 0; it = it->next) 
        {
            this->push(it->value);
        }
    }

    virtual ~queue()
    {
        clear();
    }

    void push(const type &value)
    {
        _front = new node(value, _front);

        if (_size == 0) _back = _front;
        else _front->prev->next = _front;

        _size++;
    }

    void pop()
    {
        if (_size == 0)
        {
            assert_failed(__FILE__, __LINE__, "failed to pop element from queue");
        }

        node *old_back = _back;
        _back = _back->next;

        if (_back) _back->prev = 0;
        else _front = 0;

        delete old_back;
        _size--;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE _Type back() const _OSL_NOEXCEPT
    {
        return _back->value;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE _Type front() const _OSL_NOEXCEPT
    {
        return _front->value;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE bool empty() const _OSL_NOEXCEPT
    {
        return _back == 0;
    }

    _OSL_NODISCARD _OSL_FORCE_INLINE size_type size() const _OSL_NOEXCEPT
    {
        return _size;
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
        _back = 0, _size = 0;
    }

protected:

    node *_front, *_back;
    size_type _size;

};

OSL_END_NAMESPACE

#endif
