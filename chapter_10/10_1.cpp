#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> nums;
	int num;
	while(cin>>num){
		nums.push_back(num);
	}
	cout<<"num of "<<n<<": "<<count(nums.begin(),nums.end(),n)<<endl;
	return 0;
}
