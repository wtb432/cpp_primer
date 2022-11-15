#include "13_44.h"
using namespace std;
int main()
{
    String p = "asf";
    String t = "fljkdas";
    String ans = "";
    if (p < t)
        ans = p + t;
    else
        ans = t + p;
    cout << ans << endl;
    return 0;
}