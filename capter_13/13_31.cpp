#include <iostream>
// #include <algorithm>
// #include <vector>
// using std::string;
// class HasPtr
// {
// public:
//     friend void swap(HasPtr *, HasPtr *);
//     friend bool operator<(const HasPtr *const , const HasPtr *const );
//     HasPtr(string s) : ps(new string(s)), i(0), use(new size_t(1)) {}
//     HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
//     HasPtr &operator=(const HasPtr &);
//     ~HasPtr();
//     void print() const { std::cout << *ps << std::endl; }
//     void swap(HasPtr *rhs)
//     {
//         using std::swap;
//         swap(ps, rhs->ps);
//         swap(i, rhs->i);
//     }

// private:
//     string *ps;
//     int i;
//     size_t *use;
// };

// HasPtr::~HasPtr()
// {
//     if (--*use == 0)
//     {
//         delete ps;
//         delete use;
//     }
// }

// HasPtr &HasPtr::operator=(const HasPtr &rhs)
// {
//     ++*rhs.use;
//     if (--*use == 0)
//     {
//         delete ps;
//         delete use;
//     }
//     ps = rhs.ps;
//     i = rhs.i;
//     use = rhs.use;
//     return *this;
// }
// inline void swap(HasPtr *lhs, HasPtr *rhs)
// {
//     std::cout << "Hasptr swap" << std::endl;
//     lhs->swap(rhs);
// }
// bool operator<(const HasPtr * const lhp, const HasPtr* const rhp)
// {
//     return *(lhp->ps) < *(rhp->ps);
// }
// int main()
// {
//     HasPtr *hp0 = new HasPtr("sjf");
//     HasPtr *hp1 = new HasPtr("ysz");
//     HasPtr *hp2 = new HasPtr("ttt");
//     HasPtr *hp3 = new HasPtr("hhh");
//     std::vector<HasPtr *> vec;

//     vec.push_back(hp2);
//     vec.push_back(hp3);
//     vec.push_back(hp1);
//     vec.push_back(hp0);
//     using std::swap;
//     std::sort(vec.begin(), vec.end());
//     std::for_each(vec.begin(), vec.end(), [](HasPtr *p)
//                   { p->print(); });

//     return 0;
// }

#include <string>
#include <iostream>>
class HasPtr
{
public:
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);

    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0)
    {
    }
    HasPtr(const HasPtr &hp)
        : ps(new std::string(*hp.ps)), i(hp.i)
    {
    }
    HasPtr &operator=(HasPtr tmp)
    {
        this->swap(tmp);
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }
    void swap(HasPtr &rhs)
    {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }
    void show() const
    {
        std::cout << *ps << std::endl;
    }

private:
    std::string *ps;
    int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}
#include <vector>
#include <algorithm>

int main()
{
    HasPtr s{"s"}, a{"a"}, c{"c"};
    std::vector<HasPtr> vec{s, a, c};
    std::sort(vec.begin(), vec.end());
    std::for_each(vec.begin(), vec.end(), [&](HasPtr p)
                  { p.show(); });
    return 0;
}