#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;
int main(){
	vector<string> vec;
	string str;
	while(cin>>str){
		vec.push_back(str);
	}
	auto q = partition(vec.begin(),vec.end(),[](string a){
		return a.size()>=5;		
	});
	for(auto p = vec.begin();p!=q;p++){
		cout<<*p<<endl;
	}
	return 0;
}
