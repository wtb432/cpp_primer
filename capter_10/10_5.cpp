#include<iostream>
#include<numeric>
#include<vector>
#include<list>
#include<string.h>
using namespace std;
int main(){
	vector<const char*> vec1{"sjf","ysz","ncx","yxc"};
	list<const char*> vec2{"sjf","ysz","ncx","yxc"};
	cout<<"equal:"<<equal(vec1.cbegin(),vec1.cend(),vec2.cbegin())<<endl;
	
	/*char *p[] = {"Hello","World","!"};
	char *q[] = {strdup(p[0]),strdup(p[1]),strdup(p[2])};
	char *r[] = {p[0],p[1],p[2]};
	cout<<"p q:"<<equal(begin(p),end(p),q)<<endl;
	cout<<"p r:"<<equal(begin(p),end(q),r)<<endl;*/
	return 0;
	
}
