#include"Point.h"

CPoint::CPoint(int x , int y){
	xp = x;
	yp = y;
} 

void CPoint::getpoint(int x , int y){
	xp = x , yp = y;
}

void CPoint::printpoint(){
//	printf("�������Ϊ��(%d , %d)\n", xp , yp);
	cout << "�������Ϊ��(" << xp << "," << yp << ")" << endl;
}
