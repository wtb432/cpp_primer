#include "13_40.h"

std::allocator<std::string> StrVec::alloc;
StrVec::StrVec(std::initializer_list<std::string> li)
{
    auto data = alloc.allocate(li.size());
    elements = data;
    first_free = cap = std::uninitialized_copy(li.begin(), li.end(), data);
}
void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
void StrVec::alloc_n_move(std::size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));

    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}

void StrVec::reserver(std::size_t new_cap)
{
    if (cap - elements >= new_cap)
        return;
    alloc_n_move(new_cap);
}
void StrVec::resize(std::size_t new_size)
{
    resize(new_size, std::string());
}

void StrVec::resize(std::size_t new_size, const std::string &s)
{
    if (new_size > size())
    {
        if (new_size > capacity())
            reserver(new_size * 2);
        for (std::size_t i = size(); i != new_size; i++)
            alloc.construct(first_free++, s);
    }
    else if (new_size < size())
    {
        while (first_free != elements + new_size)
            alloc.destroy(--first_free);
    }
}