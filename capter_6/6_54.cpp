#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int function(int ,int );
int add(int a,int b){
	return a+b;
}
int sub(int a,int b){
	return a-b;
}
int mul(int a,int b){
	return a*b;
}
int divide(int a,int b){
	return a/b;
}
int main(){
	vector<decltype(function)*> vec;
	vec.push_back(add);
	vec.push_back(sub);
	vec.push_back(mul);
	vec.push_back(divide);
	int a = 6,b = 3;
	for(auto p:vec) cout<<p(a,b)<<endl;
	return 0;
		
}
