#include<iostream>
#include<cstring>
#include<memory>
using namespace std;
int main(){
	char c;
	char *r = new char[20];
	int l = 0;
	while(cin.get(c)){
		if(isspace(c)){
			break;
		}
		r[l++] = c;
		if(l==20) {
			cout<<"the upper limit of the array has been reached";
			break;
		}
		
	}
	r[l] = 0;
	cout<<r<<endl;
	delete[] r;
	return 0;
}
