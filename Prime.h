#include<iostream>
#include<vector>

using namespace std;

class Prime{
	public:
		Prime();//���캯�� 
		void findPrime(int , int);//������������vector 
		void showPrime();//��ӡ����ѡ��Χ�ڵ������������ո�ָ� 
		int getSize();//��ȡ�������� 
//		int *getPrime();//��vector�е���������һ�����鲢�����׵�ַ���Թ�superPrimeʹ�� 
	private:
		vector<int> p;//������������� 
};

class superPrime{
	public:
		superPrime();//���캯�� 
		void findSuperPrime(int , int);
		void showSuperPrime();
	private:
		vector<int> sp;
};

bool judgePrime(int);//�ж�һ�����Ƿ�Ϊ���� 
bool judgeSuperPrime(int);//�ж��Ƿ�Ϊ�������� 
