#ifndef CPP5_ex12_20_h
#define CPP5_ex12_20_h

#include<vector>
#include<string>
#include<initializer_list>
#include<memory>
#include<stdexcept>
using std::vector;using std::string;

class StrBlobPtr;

class StrBlob{
public:
	using size_type = vector<string>::size_type;
	friend class StrBlobPtr;

	StrBlobPtr begin();
	StrBlobPtr end();

	StrBlob():data(std::make_shared<vector<string>>()){}
	StrBlob(std::initializer_list<string> il):data(std::make_shared<vector<string>>(il)){ }
	size_type size() const { return data->size();}
	bool empty() const { return data->empty();}

	void push_back(const string &t){ data->push_back(t);}
	void pop_back(){
		check(0,"pop_back on empty StrBlob");
		data->pop_back();
	}

	string& front() const{
	       	check(0,"front on empty StrBlob");
       		return data->front();
	}

	string& back() const {
		check(0,"back on empty StrBlob");
		return data->back();
	}

private:
	void check(size_type i,const string &msg) const {
		if(i >= data->size()) throw std::out_of_range(msg);
	}
private:
	std::shared_ptr<vector<string>> data;
};

class StrBlobPtr{
public:
	StrBlobPtr():curr(0) {}
	StrBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz) { }
	string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& p){ return  p.curr!=curr;}
private:

	std::shared_ptr<vector<string>> check(std::size_t,const string&) const;
	std::weak_ptr<vector<string>> wptr;
	std::size_t curr;
	
};

std::shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i,const string& msg) const{
	auto ret = wptr.lock();
	if(!ret) 
		throw std::runtime_error("unbound StrBlobPtr");
	if(i>=ret->size()) 
		throw std::out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() const{
	auto p = check(curr,"dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr StrBlob::begin(){ return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this,data->size());
	return ret;
}

#endif
