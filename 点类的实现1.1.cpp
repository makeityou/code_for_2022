#include"Point.h"

int main(){
	Point *p1 = new Point(1 , 1);
	Point *p2 = new Point(2 , 2);
	Point *p3 = new Point(3 , 3);
	Point *p = new Point[5];
	for(int i = 0 ; i < 5 ; i++){
		p[i].move(i + 3 , i + 3); 
	} 
	cout << "�Ѵ���" << Point::getcount() << "����" << endl;
	delete p1;
	delete p2;
	delete p3;
	delete []p; 
	cout << "�ͷź�������" << Point::getcount() << "����" << endl;
	return 0;
}
