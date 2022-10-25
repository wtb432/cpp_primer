Point global;
Point foo_bar(Point arg){//use copy_function
	Point local = arg;//use
	Point *heap = new Point(global);//use
	*heap = local;
	Point pa[4] = {local,*heap};//use
	return *heap;//use
}
