#include "12_19.h"
#include<iostream>

using namespace std;
int main(){
	StrBlob blob({"sjf","ysz","ncx","hx","zqc"});
	auto p = blob.begin(),q = blob.end();
	for(;p!=q;p.incr()) cout<<p.deref()<<endl;
	return 0;
}
