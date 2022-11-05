#ifndef CP5_13_22_h
#define Cp5_13_22_h

#include<string>
class HasPtr{
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)),i(0){}
	HasPtr(const HasPtr& ptr):ps(new std::string(*hp.ps)),i(ps.i){}
	HasPtr& operator=(const HasPtr& ptr){
		if(this!=&ptr){
			std::string *temp_ps = new std::string(*ptr.ps);
			delete ps;
			ps = temp_ps;
			i = ptr.i;
		}
		return *this;
	}
	~HasPtr(){
		delete ps;
	}
private:
	std::string *ps;
	int i;
};


#endif
