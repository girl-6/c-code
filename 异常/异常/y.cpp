#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

		//异常的抛出与捕获
//double Division(int a, int b) 
//{    // 当b == 0时抛出异常    
//	if (b == 0)       
//		throw "Division by zero condition!";    
//	else         
//		return ((double)a / (double)b); 
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl; //当输入1 0时，调用函数直接抛异常
//}
//int main()
//{
//	try{
//		Func();
//	}
//	catch (const char* errmsg){     //捕获char型异常
//		cout << errmsg << endl;    //显示捕获的异常
//	}
//	catch (...){             //捕获其他类型的异常
//		cout << "unkown exception" << endl;
//	}
//	system("pause");
//	return 0;
//}


		//异常的重新抛出
//double Division(int a, int b)
//{    // 当b == 0时抛出异常    
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，但下面的array还没有得到释放。    
//	// 所以这里捕获异常后并不处理异常，而是重新抛出去交给外面处理
//	int* array = new int[10];
//	try{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl; //当输入1 0时，调用函数直接抛异常
//	}
//	catch (...){
//		throw;  //重新抛出，否则下面不执行会发生内存泄漏
//		cout << "delete[]" << array << endl;
//		delete[] array;
//	}
//	cout << "delete[]" << array << endl;    //若有异常则上面直接跳到主函数catch语句；若没异常，则正常释放
//	delete[] array;   
//}
//int main()
//{
//	try{
//		Func();
//	}
//	catch (const char* errmsg){     //捕获char型异常
//		cout << errmsg << endl;    //显示捕获的异常
//	}
//	catch (...){             //捕获其他类型的异常
//		cout << "unkown exception" << endl;
//	}
//	system("pause");
//	return 0;
//}


		// 服务器开发中通常使用的自定义异常继承体系 
class Exception 
{
protected:
	string _errmsg;   
	int _id;    
	//... 
};
class SqlException : public Exception   //数据库错误
{};
class CacheException : public Exception    //缓存错误
{};
class HttpServerException : public Exception   //HTTP错误
{};
int main()
{
	try{
		// server.Start();       
		// 抛出的都是派生类对象    
	}
	catch (const Exception& e)   // 这里捕获父类对象就可以    
	{
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;
}



