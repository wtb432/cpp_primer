#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
int main(){
	list<string> li{"sjf","fhsjak","fhsjak","jsf","sjf","yxc","yxcnb","yxc","yxcnb","sjfwww","fads"};
	li.sort();
	li.unique();
	for_each(li.begin(),li.end(),[](string a){ cout <<a<<" ";});
	return 0;
}
