#include<iostream>
#include<numeric>
using namespace std;
int main(){
	int nums[100];
	fill_n(nums,100,0);
	for(int i = 0;i<100;i++){
		cout<<nums[i];
	}
	cout<<endl;
	return 0;
}
