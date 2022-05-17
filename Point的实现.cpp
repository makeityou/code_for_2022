#include"Point.cpp"

int main(){
	CPoint *p = new CPoint[5];
	for(int i = 0 ; i < 5 ; i++){
		p[i].getpoint(i , i);
	} 
	for(int i = 0 ; i< 5 ; i++){
		p[i].printpoint();
	}
	delete []p;
	
	return 0;
}
