#ifndef _OSL_QUEUE_HPP
#define _OSL_QUEUE_HPP

# include <int_types.hpp>
# include <assert.hpp>

# include <initializer_list>

OSL_BEGIN_NAMESPACE

template <class _Type>
class queue
{
protected:

    struct node
    {
        _Type value;
        node *prev, *next;

        node(_Type value, node *next) : value(value), prev(0), next(next) { }
    };

public:

    using type = _Type;

    _OSL_CONSTEXPR queue() _OSL_NOEXCEPT : _back(0), _front(0), _size(0) { }

    queue(std::initializer_list<_Type> queue) _OSL_NOEXCEPT : _back(0), _front(0), _size(0) {
        for (u32 i = queue.size() - 1; i != 0; --i)
            this->push(queue.begin()[i]);
        this->push(queue.begin()[0]);
    }

    queue(const queue &queue) _OSL_NOEXCEPT : _back(0), _front(0), _size(0) {
        for (auto it = queue._back; it != 0; it = it->next)
            this->push(it->value);
    }

    virtual ~queue() {
        clear();
    }

    void push(const type &value) {
        node *new_back = new node(value, _back);

        if (_size == 0) _front = new_back;
        else _back->prev = new_back;

        _size++, _back = new_back;
    }

    void pop() {
        node *old_last = _front;
        _front = _front->prev;
        _Type value = old_last->value;
        delete old_last;
        _size--;
    }

    _Type back() const {
        return _back->value;
    }

    _Type front() const {
        return _front->value;
    }

    bool empty() const {
        return _back == 0;
    }

    u64 size() const {
        return _size;
    }

    void clear() {
        auto it = _front;
        while (it != 0) {
            node *buffer = it->prev;
            delete it;
            it = buffer;
        }
        _back = 0, _size = 0;
    }

protected:

    node *_back, *_front;
    u64 _size;

};

OSL_END_NAMESPACE

#endif
