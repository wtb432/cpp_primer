#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;
int main(){
	
	vector<string> strs{"asfdj;l","sjf","686234","asfhd","tf"};
	cout<<count_if(strs.begin(),strs.end(),[](string a)->bool { return a.size()>6;})<<endl;
	return 0;	
}
