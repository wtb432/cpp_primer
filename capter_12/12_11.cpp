#include<iostream>
#include<memory>
using namespace std;
void process(shared_ptr<int> ptr){
	cout<<"inside the function use_count"<<ptr.use_count()<<endl;
}
int main(){
	shared_ptr<int> p(new int(33));
	cout<<p.use_count()<<endl;
	process(shared_ptr<int>(p.get()));
	cout<<p.use_count()<<endl;//execute this file will arise free():double free detected in tcache 2
	//reason: shared_ptr<int>(p.get()) construct a temporary shared_ptr.However it is a copy of p
}

