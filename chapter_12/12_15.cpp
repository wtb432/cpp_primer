#include<iostream>
#include<memory>
#include<string>
using namespace std;

struct connection{
	string ip;
	int port;
	connection(string ip_,int port_):ip(ip_),port(port_){}
};
struct destination{
	string ip;
	int port;
	destination(string ip_,int port_):ip(ip_),port(port_){}
};
connection connect(destination *pDes){
	shared_ptr<connection> pConn(new connection(pDes->ip,pDes->port));
	cout<<"creating connection("<<pConn.use_count()<<")"<<endl;
	return *pConn;
}

void f(destination &d){
	connection conn = connect(&d);
	shared_ptr<connection> p(&conn,[](connection* pConn){
		cout<<"closing connection "<<pConn->ip<<":"<<pConn->port<<endl;
	});
	cout<<"Connection now("<<p.use_count()<<")"<<endl;
}
int main(){
	destination dest("10.69.98.198",3316);
	f(dest);
}
