#include"Matrix.h"

int main(){
	
	Matrix m1(3 , 2 , 1) , m2(2 , 3 , 2) , m3(2 , 2 , 2) , m4(2 , 2 , 3) , m5(2 , 2);
	cout << m1.getrow() << endl << m1.getcol() << endl << "****" << endl;//验证函数 
	cout << m3.getvalue(2 , 2) << endl << m4.getvalue(2 , 2) << endl << "****" << endl; 
	(m3 + m4).show();
	(m3 - m4).show();
	(m1 * m2).show();
	( m3.dot(m4) ).show();//验证四种运算 
	m5.show();
	
	return 0;
}
