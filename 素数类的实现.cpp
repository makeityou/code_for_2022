#include"Prime.cpp"

int main(){
	
	Prime a;
	a.findPrime(100 , 999);
	cout << "����Ϊ��" << endl; 
	a.showPrime();
	
	superPrime b;
	b.findSuperPrime(100 , 999);
	cout << "���г�������Ϊ��" << endl;
	b.showSuperPrime(); 
	
	return 0;
}
