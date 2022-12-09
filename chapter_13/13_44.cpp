#include "13_44.h"
#include <cstring>
std::allocator<char> String::alloc;

String::String(char *p)
{
    std::size_t s = std::strlen(p);
    auto data = alloc.allocate(s);
    elements = data;
    first_free = cap = std::uninitialized_copy(p, p + s, data);
}

void String::push_back(const String &t)
{
}

std::pair<char *, char *>
String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void String::free()
{
    if (elements)
    {
        std::for_each(elements, first_free, [this](char &p)
                      { alloc.destroy(&p); });
        alloc.deallocate(elements, cap - elements);
    }
}

String::String(const String &t)
{
    int s = t.size(), c = t.capacity();
    auto data = alloc.allocate(c);
    elements = first_free = data;
    cap = data + c;
    auto b = t.begin();
    while (b != t.end())
    {
        alloc.construct(first_free++, *b++);
    }
}

String::~String() { free(); }

String &String::operator=(String &p)
{
    auto data = alloc_n_copy(p.begin(), p.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void String::reallocate()
{
    auto newcapacity = size() ? size() * 2 : 1;
    alloc_n_move(newcapacity);
}

void String::alloc_n_move(std::size_t new_size)
{
    auto newdata = alloc.allocate(new_size);
    auto dest = newdata;
    auto elem = elements;
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_size;
}

void String::reserver(std::size_t new_cap)
{
    if (cap - elements >= new_cap)
        return;
    alloc_n_move(new_cap);
}

void String::resize(std::size_t new_size)
{
    if (new_size > size())
    {
        if (new_size > capacity())
            reserver(new_size * 2);
        for (std::size_t i = size(); i != new_size; i++)
            alloc.construct(first_free++, ' ');
    }
    else if (new_size < size())
    {
        while (first_free != elements + new_size)
            alloc.destroy(--first_free);
    }
}

String &String::operator+(const String &p)
{
    int new_size = size() + p.size();
    if (new_size >= capacity())
        alloc_n_move(new_size * 2);
    auto elem = p.begin();
    while (first_free != elements + new_size)
        alloc.construct(first_free++, *elem++);
    return *this;
}

bool String::operator==(const String &p) const
{
    if (size() != p.size())
        return false;
    auto elem = elements, q = p.begin();
    for (std::size_t i = 0; i < size(); i++)
        if (*elem++ != *q++)
            return false;
    return true;
}

bool String::operator<(const String &p) const
{
    auto a = elements, b = p.begin();
    while (a != first_free && b != p.end())
    {
        if (*a == *b)
        {
            a++, b++;
            continue;
        }
        return *a < *b;
    }
    return size() < p.size();
}

std::ostream &operator<<(std::ostream &os, String &p)
{
    std::for_each(p.elements, p.first_free, [&os](char &c)
                  { os << c; });
    return os;
}