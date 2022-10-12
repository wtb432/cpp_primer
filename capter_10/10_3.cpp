#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main(){
	vector<int> nums;
	int num;
	while(cin>>num){
		nums.push_back(num);
	}
	cout<<accumulate(nums.begin(),nums.end(),0)<<endl;
	return 0;
}
