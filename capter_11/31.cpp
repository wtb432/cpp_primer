#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	multimap<string,string> author_book{{"sjf","c++"},{"sjf","python"},{"sjf","java"},{"yxc","ac"},{"ysz","rust"},{"ysz","go"}};
	string name;
	cin>>name;
	auto entries = author_book.count(name);
	auto iter = author_book.find(name);
	while(entries--){
		cout<<iter->second<<endl;
		++iter;
	}
	return 0;
}
