#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	auto p = [](int a,int b){ return a+b;};
	cout<<p(a,b)<<endl;
}
