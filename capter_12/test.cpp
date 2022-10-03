#include<iostream>
#include<memory>
using namespace std;
int main(){
	int ix = 42;
	unique_ptr<int> p(&ix);
	unique_ptr<int> q(p.get());
	cout<<"p:"<<*p<<endl;
	cout<<"q:"<<*q<<endl;
	p.release();
	return 0;
}
