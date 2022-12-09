#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
#include"../capter_7/7_26.h"
using namespace std;
bool compareIsbn(Sales_data a,Sales_data b){
	return a.isbn()<b.isbn();
}
int main(){
	vector<Sales_data> vec;
	Sales_data sd;
	while(sd.read()){
		vec.push_back(sd);
	}	
	sort(vec);
	for(Sales_data t:vec) t.print()<<endl;
	return 0;
}
