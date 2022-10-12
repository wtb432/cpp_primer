#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
int main(){
	string n;
	cin>>n;
	list<string> strs;
	string str;
	while(cin>>str){
		strs.push_back(str);
	}
	cout<<"the num of "<<n<<" "<<count(strs.begin(),strs.end(),str)<<endl;
	return 0;
}
