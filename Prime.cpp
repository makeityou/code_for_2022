#include"Prime.h"
#include<math.h>

Prime::Prime(){}

void Prime::findPrime(int low , int high){//���������� 
	for(int i = low ; i <= high ; i++){
		if(judgePrime(i)){
			p.push_back(i);//push�������� 
		}
	}
}

void Prime::showPrime(){
	for(int i = 0 ; i < p.size() ; i++){
		cout << p[i] << " ";//ѭ����� 
	}
	cout << endl;
}

int Prime::getSize(){
	return p.size();//��ȡ���� 
}

//int *Prime::getPrime(){
//	int *arr = new int[p.size()];//��̬���������Դ洢���� 
//	for(int i = 0 ; i < p.size() ; i++){
//		arr[i] = p[i];
//	}
//	return arr;
//}

superPrime::superPrime(){}

//void superPrime::findsuperPrime(int low , int high){
//	Prime get;//����һ��ʵ�� 
//	get.findPrime(low , high); 
//	int *super = get.getPrime();//��ô������������� 
//	for(int i = 0 ; i < get.getSize() ; i++){
//		if(judgeSuperPrime(super[i])){//�ж��Ƿ�Ϊ�������� 
//			sp.push_back(super[i]); //push��vector 
//		}
//	}
//	delete super;
//}

void superPrime::findSuperPrime(int low , int high){
	vector<int> prime;
	for(int i = low ; i <= high ; i++){
		if(judgePrime(i)){
			prime.push_back(i);//push�������� 
		}
	}
//	for(int i = 0 ; i < prime.size() ; i++){
//		cout << prime[i] << " ";
//	}
//	cout << prime.size() << endl;
	for(int i = 0 ; i < prime.size() ; i++){
		if(judgeSuperPrime(prime[i])){
			sp.push_back(prime[i]); 
		}
	}
} 

void superPrime::showSuperPrime(){
	for(int i = 0 ; i < sp.size() ; i++){
		cout << sp[i] << " ";
	}
	cout << endl;
}  

bool judgePrime(int a){
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

bool judgeSuperPrime(int a){
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
