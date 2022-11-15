#ifndef _CP5_13_40_h_
#define _CP5_13_40_h_
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec(std::initializer_list<std::string> li);
    StrVec &operator=(const StrVec &);
    ~StrVec();
    void push_back(const std::string &);
    std::size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    void reserver(std::size_t);
    void resize(std::size_t);

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void alloc_n_move(std::size_t new_cap);
    void free();
    void reallocate();
    void resize(std::size_t, const std::string &);
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

#endif