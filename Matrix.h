#include<iostream>
#include<string.h>
using namespace std;

class Matrix{
	private:// ���ݳ�Ա�������������Լ������� 
		int cols;
		int rows;
		double *p;//��һά����¶�ά���飬������⣬������� 
	public:
		Matrix(){//�޲ι��캯�� 
			rows = 0;
			cols = 0;
			p = NULL;
		}
		Matrix(int row , int col , int value = 0.0){//�вι��캯���������������������Լ���ֵ 
			rows = row;
			cols = col;
			p = new double[rows * cols];//��̬�����ڴ����ڴ�ž������Ԫ�� 
			for(int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < col ; j++){
					p[i * col + j] = value;//�����ֵ 
				}
			}
		}
		~Matrix(){//�����������ͷ��ڴ� 
			delete p;
		}
		int getrow(){
			return rows;
		}
		int getcol(){
			return cols;
		}
		double getvalue(int i , int j){//��ȡi��j�е�Ԫ�ص�ֵ
			return p[(i - 1) * cols + j - 1];//��������ű���㿪ʼ,���i��jҪ��һ 
		}
		void show(){//��ӡ���� 
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < cols ; j++){
					cout << p[i * cols + j] << " ";
				}
				cout << endl;
			}
		}
		
		Matrix operator+(Matrix m){//��������������ش���add���� 
			if(m.getrow() != rows || m.getcol() != cols){
				cout << "�����С��ͬ���޷���ӡ�" << endl;
				return *this; 
			}
			Matrix tem(rows , cols);//����һ���������ڴ�����Ӻ�Ľ�� 
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < cols ; j++){
					tem.p[i * cols + j] = m.getvalue(i + 1 , j + 1) + p[i * cols + j]; // Ԫ�ذ������ 
				}
			}
			return tem;
		}
		Matrix operator-(Matrix m){//ͬ������������ش���sub���� 
			if(m.getrow() != rows || m.getcol() != cols){
				cout << "�����С��ͬ���޷������" << endl;
				return *this;
			}
			Matrix tem(rows , cols);
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < cols ; j++){
					tem.p[i * cols + j] = p[i * cols + j] - m.getvalue(i + 1 , j + 1);  
				}
			}
			return tem;
		}
		Matrix operator*(Matrix m){//�˷������� 
			if(m.getrow() != cols){
				cout << "�޷���ˡ�" << endl;
				return *this;
			}
			Matrix tem(rows , m.getcol());//�µľ���ȡ��ǰ�к��С� 
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < m.getcol() ; j++){//ע��ѭ������ 
					for(int k = 0 ; k < cols ; k++){
						tem.p[i * m.getcol() + j] += p[i * cols + k] * m.getvalue(k + 1 , j + 1);//�˴��ű��״� 
					}
				}
			}
			return tem;
		}
		Matrix dot(Matrix m){//���ڵ��û�ж�Ӧ����������ó�Ա����dot 
			if(m.getrow() != rows || m.getcol() != cols){
				cout << "�����С��ͬ���޷���ˡ�" << endl;
				return *this; 
			}
			Matrix tem(rows , cols);
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < cols ; j++){
					tem.p[i * cols + j] = p[i * cols + j] * m.getvalue(i + 1 , j + 1); 
				}
			}
			return tem;
		}
};

