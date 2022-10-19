#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
	map<string,vector<int>> mp{{"sjf",{1,2,3,4,5}},{"ysz",{2,5,8,6,4}}};

	map<string,vector<int>>::iterator it = mp.find("sjf");
	return 0;
}
