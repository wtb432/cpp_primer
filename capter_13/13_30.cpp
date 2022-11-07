#include <iostream>
#include <algorithm>
using std::string;
class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(string s) : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr &operator=(const HasPtr &);
    ~HasPtr();
    void print() { std::cout << *ps << std::endl; }

private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    std::cout << "HasPtr swaped" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    HasPtr *hp0 = new HasPtr("sjf");
    HasPtr *hp1 = new HasPtr("ysz");
    HasPtr *hp2(hp0);
    HasPtr *hp3 = hp1;
    hp0->print();
    hp1->print();
    hp2->print();
    hp3->print();
    swap(*hp0, *hp1);
    hp0->print();
    hp1->print();
    hp2->print();
    hp3->print();
    return 0;
}
