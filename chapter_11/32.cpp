#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
int main(){
	multimap<string,string> author_book{{"sjf","c++"},{"sjf","python"},{"sjf","java"},{"yxc","ac"},{"ysz","rust"},{"ysz","go"}};
	map<string,multiset<string>> tmp;
	for(const auto &p:author_book){
		tmp[p.first].insert(p.second);
	}
	for(const auto &author:tmp){
		cout<<author.first<<" : ";
		for(const auto &lan:author.second){
			cout<<lan<<" ";
		}
		cout<<endl;
	}
	return 0;
}
