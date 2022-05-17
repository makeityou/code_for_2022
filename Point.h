#include<iostream>
using namespace std;

class Point{
	public:
		Point(){//默认构造函数 
			x = 0;
			y = 0;
			count++;
		}
		Point(float x , float y){//重载，带参构造函数 
			this -> x = x;//形参与数据成员同名，用this赋值 
			this -> y = y;
			count++;
		}
		~Point(){//析构函数 
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
		static int getcount(){//静态成员函数 
			return count;
		}
		private:
			float x;
			float y;
			static int count;//静态成员count,用于计数对象的个数 
};
int Point::count = 0;//初始化count 
