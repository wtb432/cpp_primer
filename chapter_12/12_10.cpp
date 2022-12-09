#include<iostream>
#include<memory>
using namespace std;
void process(shared_ptr<int> ptr){
	cout<<"inside the process function:"<<ptr.use_count()<<endl;
}
int main(){
	shared_ptr<int> p(new int(42));
	cout<<p.use_count()<<endl;
	process(shared_ptr<int>(p));
	cout<<p.use_count()<<endl;
	return 0;
}
