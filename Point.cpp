#include"Point.h"

CPoint::CPoint(int x , int y){
	xp = x;
	yp = y;
} 

void CPoint::getpoint(int x , int y){
	xp = x , yp = y;
}

void CPoint::printpoint(){
//	printf("点的坐标为：(%d , %d)\n", xp , yp);
	cout << "点的坐标为：(" << xp << "," << yp << ")" << endl;
}
