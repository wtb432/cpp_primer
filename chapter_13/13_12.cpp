bool fcn(const Sales_data* trans,Sales_data accum){
	Sales_data item1(*trans),item2(accum);
	return item1.isbn()!=item2.isbn();
	//1 accum
	//2 item1
	//3 item2
}
