#include<iostream>
#include<memory>
using namespace std;
int main(){
	int n;
	cin>>n;
	allocator<string> alloc;
	auto p = alloc.allocate(n);
	string s;
	auto q = p;
	while(cin>>s&&q!=p+n){
		alloc.construct(q++,s);
	}
	const size_t size = q-p;
	cout<<"size:"<<size<<endl;
	while(q!=p){
		cout<<"cout:"<<*--q<<endl;
		alloc.destroy(q);
	}
	alloc.deallocate(p,n);
	return 0;
}
