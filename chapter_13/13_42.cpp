#include "query.h"

int main()
{
    std::string book = "../static/book.txt";
    std::ifstream ftr(book);
    runQueries(ftr);
    return 0;
}
