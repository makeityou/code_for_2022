#include<iostream>
using namespace std;

class Point{
	public:
		Point(){//Ĭ�Ϲ��캯�� 
			x = 0;
			y = 0;
			count++;
		}
		Point(float x , float y){//���أ����ι��캯�� 
			this -> x = x;//�β������ݳ�Աͬ������this��ֵ 
			this -> y = y;
			count++;
		}
		~Point(){//�������� 
			count--;
		}
		void move(float x , float y){
			this -> x = x;
			this -> y = y;
		}
		float getx(){
			return x;
		}
		float gety(){
			return y;
		}
		static int getcount(){//��̬��Ա���� 
			return count;
		}
		private:
			float x;
			float y;
			static int count;//��̬��Աcount,���ڼ�������ĸ��� 
};
int Point::count = 0;//��ʼ��count 
