#include<iostream>
#include<algorithm>
using namespace std;
class numbered{
	static int i;
public:
	numbered(){mysn = i++;}


	int mysn;
};
int numbered::i = 0;
void f(numbered s){ cout<<s.mysn<<endl;}
int main(){
	numbered a,b = a,c= b;
	f(a);f(b);f(c);
	return 0;
}
