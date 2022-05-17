#include"Prime.cpp"

int main(){
	
	Prime a;
	a.findPrime(100 , 999);
	cout << "素数为：" << endl; 
	a.showPrime();
	
	superPrime b;
	b.findSuperPrime(100 , 999);
	cout << "其中超级素数为：" << endl;
	b.showSuperPrime(); 
	
	return 0;
}
