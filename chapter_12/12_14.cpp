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
connection connect(destination* des){
	shared_ptr<connection> pConn(new connection(des->ip,des->port));
	cout<<"creating connection("<<pConn.use_count()<<")"<<endl;
	return *pConn;
}
void disconnect(connection pConn){
	cout<<"connection close("<<pConn.ip<<":"<<pConn.port<<")"<<endl;
}
void end_connection(connection *pConn){
	disconnect(*pConn);
}
void f(destination &d){
	connection conn = connect(&d);
	shared_ptr<connection> p(&conn,end_connection);
	cout<<"Connection now("<<p.use_count()<<")"<<endl;
}


int main(){
	destination dest("10.69.98.198",3316);
	f(dest);	
}
