#include<iostream>
#include<vector>
#include<math.h> 

using namespace std;

class Prime{
	public:
		Prime(int low , int high);//���캯�� �� 
    Prime(int n);	//�� 
    bool judgePrime(int);//�ж�һ�����Ƿ�Ϊ���� �� 
    virtual bool isPrime();
		void showPrime();//��ӡ����ѡ��Χ�ڵ������������ո�ָ� �� 
		int getSize();//��ȡ�������� �� 
//		int *getPrime();//��vector�е���������һ�����鲢�����׵�ַ���Թ�superPrimeʹ�� 
	protected:
		vector<int> p;//������������� 
};

class superPrime : public Prime {
	public:
		superPrime(int low , int high);//���캯�� 
    superPrime(int n);
    virtual bool isPrime();
	private:
    bool judgePrime(int);//�ж��Ƿ�Ϊ�������� �� 
		void findPrime(int , int);//������������vector 
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
	if(a == 2){//2�����ж� 
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
	int eve[20] = {0} , i = 0 , sum = 0 , largesum = 0;//sumΪ��λ���ĺͣ�largesum�Ǹ�λ��ƽ���ͣ�i�ǽű� 
	while(a){//ѭ����ȡ��λ�� 
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
