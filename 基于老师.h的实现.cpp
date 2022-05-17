#include<iostream>
#include<vector>
#include<math.h> 

using namespace std;

class Prime{
	public:
		Prime(int low , int high);//构造函数 √ 
    Prime(int n);	//√ 
    bool judgePrime(int);//判断一个数是否为素数 √ 
    virtual bool isPrime();
		void showPrime();//打印出所选范围内的所有素数，空格分隔 √ 
		int getSize();//获取素数个数 √ 
//		int *getPrime();//将vector中的素数放入一个数组并返回首地址，以供superPrime使用 
	protected:
		vector<int> p;//容器，存放素数 
};

class superPrime : public Prime {
	public:
		superPrime(int low , int high);//构造函数 
    superPrime(int n);
    virtual bool isPrime();
	private:
    bool judgePrime(int);//判断是否为超级素数 √ 
		void findPrime(int , int);//找素数，放入vector 
};


Prime::Prime(int low , int high){
	for(int i = low ; i <= high ; i++){
		if(judgePrime(i)){
			p.push_back(i);
		}
	}
} 
Prime::Prime(int n){
	for(int i = 2 ; i <= n ; i++){
		if(judgePrime(i)){
			p.push_back(i);
		}
	}
} 
bool Prime::judgePrime(int a){
	if(a == 2){//2单独判断 
		return true;
	}
	for(int i = 2 ; i <= sqrt(a) + 1 ; i++){
		if(a % i == 0){
			return false;
		}
	}
	return true;
}
void Prime::showPrime(){
	for(int i = 0 ; i < p.size() ; i++){
		cout << p[i] << " ";
	}
	cout << endl;
}
int Prime::getSize(){
	return p.size();
}

superPrime::superPrime(int low , int high){
	Prime(low , high);
	findPrime(low , high);
}
void findPrime(int low , int high){
	int count = 0;
	for(int i = 0 ; i < p.size() ; i++){
		if(judgePrime(i)){
			p.push_back(i);
			count++;
		}
	}
	for(int i = count ; i < p.size() ; i++){
		p.pop_back(i);
	}
}
bool superPrime::judgePrime(int a){
	int eve[20] = {0} , i = 0 , sum = 0 , largesum = 0;//sum为各位数的和，largesum是各位数平方和，i是脚标 
	while(a){//循环提取各位数 
		eve[i] = a % 10;
		sum += eve[i];
		largesum += eve[i] * eve[i];
		i++;
		a /= 10;
	}
	if(judgePrime(sum) && judgePrime(largesum) && judgePrime(a)){
		return true;
	}
	return false;
}
