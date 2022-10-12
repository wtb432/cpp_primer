#include<iostream>
#include<algorithm>
using namespace std;
void test(){
	int sz = 10;
	auto p = [sz](int x){return sz+x;};
	cout<<p(5)<<endl;
}
int main(){
	test();
	return 0;
}
