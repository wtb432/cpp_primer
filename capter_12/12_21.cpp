#include "12_21.h"
#include<iostream>

using namespace std;
int main(){
	const StrBlob blob({"sjf","ysz","ncx","hx","zqc"});
	auto p = blob.begin(),q = blob.end();
	for(;p!=q;p.incr()) cout<<p.deref()<<endl;
	return 0;
}
