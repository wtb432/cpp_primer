#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct X{
	X(){cout<<"X()"<<endl;}
	X(const X&){cout<<"X(const X&)"<<endl;}
	X& operator=(const X& x){
		cout<<"X& operator=(const X& x)"<<endl;
		return *this;
	}
	~X(){cout<<"~X()"<<endl;}
};
void test1(X &x1){
	cout<<"test1:"<<endl;
	X x2 = x1;
	X x3(x1);
	x3 = x2;
}
void test2(X *x1){
	cout<<"test2:"<<endl;
	X x2 = *x1;
	X x3(*x1);
}
void test3(X x1){
	cout<<"test3:"<<endl;
	vector<X> vec;
	vec.push_back(x1);
}
void test4(X x1){
	cout<<"test4:"<<endl;
	X *p = new X(x1);
	delete p;
}
int main(){
	X x1;
	test1(x1);
	test2(&x1);
	test3(x1);
	test4(x1);
	return 0;
}
