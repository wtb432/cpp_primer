#ifndef _CP5_c13_44_
#define _CP5_c13_44_
#include <memory>
#include <utility>
#include <iostream>
#include <algorithm>
class String
{
    friend std::ostream &operator<<(std::ostream &os, String &);

public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(char *p);
    String(const String &);
    ~String();
    char *begin() const { return elements; }
    char *end() const { return first_free; }
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    void push_back(const String &);
    bool operator==(const String &) const;
    bool operator<(const String &) const;
    String &operator+(const String &);
    String &operator=(String &);

private:
    static std::allocator<char> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void alloc_n_move(std::size_t new_cap);
    void free();
    void resize(std::size_t);
    void resize(std::size_t, const char &);
    void reallocate();
    void reserver(std::size_t new_cap);
    char *elements;
    char *first_free;
    char *cap;
};

#endif