#include<algorithm>
#include<iostream>
using namespace std;
class HasPtr{
public:
	HasPtr(const string &s = string()):
		ps(new string(s)),i(0){}
	HasPtr(const HasPtr & ptr):ps(new string(*hp.ps)),i(ptr.i){
	}
private:
	string *ps;
	int i;
};
int main(){
	
}
