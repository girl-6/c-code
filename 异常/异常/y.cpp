#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

		//�쳣���׳��벶��
//double Division(int a, int b) 
//{    // ��b == 0ʱ�׳��쳣    
//	if (b == 0)       
//		throw "Division by zero condition!";    
//	else         
//		return ((double)a / (double)b); 
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl; //������1 0ʱ�����ú���ֱ�����쳣
//}
//int main()
//{
//	try{
//		Func();
//	}
//	catch (const char* errmsg){     //����char���쳣
//		cout << errmsg << endl;    //��ʾ������쳣
//	}
//	catch (...){             //�����������͵��쳣
//		cout << "unkown exception" << endl;
//	}
//	system("pause");
//	return 0;
//}


		//�쳣�������׳�
//double Division(int a, int b)
//{    // ��b == 0ʱ�׳��쳣    
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	// ������Կ������������0�����׳��쳣���������array��û�еõ��ͷš�    
//	// �������ﲶ���쳣�󲢲������쳣�����������׳�ȥ�������洦��
//	int* array = new int[10];
//	try{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl; //������1 0ʱ�����ú���ֱ�����쳣
//	}
//	catch (...){
//		throw;  //�����׳����������治ִ�лᷢ���ڴ�й©
//		cout << "delete[]" << array << endl;
//		delete[] array;
//	}
//	cout << "delete[]" << array << endl;    //�����쳣������ֱ������������catch��䣻��û�쳣���������ͷ�
//	delete[] array;   
//}
//int main()
//{
//	try{
//		Func();
//	}
//	catch (const char* errmsg){     //����char���쳣
//		cout << errmsg << endl;    //��ʾ������쳣
//	}
//	catch (...){             //�����������͵��쳣
//		cout << "unkown exception" << endl;
//	}
//	system("pause");
//	return 0;
//}


		// ������������ͨ��ʹ�õ��Զ����쳣�̳���ϵ 
class Exception 
{
protected:
	string _errmsg;   
	int _id;    
	//... 
};
class SqlException : public Exception   //���ݿ����
{};
class CacheException : public Exception    //�������
{};
class HttpServerException : public Exception   //HTTP����
{};
int main()
{
	try{
		// server.Start();       
		// �׳��Ķ������������    
	}
	catch (const Exception& e)   // ���ﲶ�������Ϳ���    
	{
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;
}



