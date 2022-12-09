#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<typeinfo>
using namespace std;

//11.24 add a key-value pair{0,1} into the map
//11.25 out_of_range 
int main(){
	map<int,string> m = {{1,"ss"},{2,"sz"}};
	using KeyType = map<int,string>::key_type;
	cout<<"type to subscript: "<<typeid(KeyType).name()<<endl;
	cout<<"returned from the subscript operator: "<<typeid(decltype(m[1])).name()<<endl;
	return 0;
}
