#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
	int a = 10;
	auto p = [&a]()->bool{
		if(a==0) return true;
		a--;
		return false;
	};
	for(int i = 0;i<=10;i++){
		cout<<"a:"<<a<<" "<<p()<<endl;
	}
	return 0;
}
