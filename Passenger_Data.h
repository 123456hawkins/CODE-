#pragma once
#include "Passenger.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>
#include<ctime>
#include <string.h>
#include <stdio.h>
#include<iomanip>
#include<fstream>
using namespace std;
#define maxsize 1000
class Passenger_Data
{
private:
	int top;//乘客记录指针
	Passenger passenger[maxsize];//乘客对象数组
public:
	/*构造函数*/
	Passenger_Data();

	/*乘客信息结构体,目的是文件信息的读入*/
	typedef struct
	{
		char Flight_Id[20];//航班号
		char Id[20];//身份证号
		char Name[20];//姓名
		char Sex[20];//性别
		char Birthday[20];//出生年月
		char Seat_num[20];//座位号
		int P_ticket_num;//订票标记 >=1已定 0:未定
	}Data_type1;

	/*定义储存航班信息结构链表*/
	typedef struct node1
	{
		Data_type1* info1;
		struct node1* next;
	}nodelist1;

	nodelist1* L;//定义存储链表

	Data_type1* E;//定义借阅者信息结构体

	/*初始化链表函数*/
	void init_N(nodelist1** L);

	/*构造函数，读入乘客.txt到passenger[]中*/

	/*文件数据读入链表操作*/
	bool save_insert(nodelist1* L, Data_type1* E);

	/*根据身份证号查找乘客*/
	Passenger* Inquire_by_Id(char id[]);

	/*返回新增乘客*/
	Passenger* inquire_last();

	/*填加乘客*/
	void Add(char* id, char* name, char* sex, char* birthday);

	/*输出所有乘客信息*/
	void disp();
	
	/*析构函数，写入乘客类数组到txt文件中*/
	~Passenger_Data();

};

