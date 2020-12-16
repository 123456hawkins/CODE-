#pragma once
#include"Flight.h"
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
using namespace std;
#define maxsize 1000
/*航班库类,实现航班的相关操作*/
class Flight_Data
{
private:
	int top;//航班记录指针
	Flight flight[maxsize];//航班类对象数组
public:

	/*航班信息结构体,目的是文件信息的读入*/
	typedef struct
	{
		char Flight_Id[20];//航班号
		int Max_cap;//最大载客数
		char Dep_place[20];//起飞地点
		char Dep_time[20];//起飞时间
		char Land_place[20];//降落地点
		char land_time[20];//降落时间
		double price; //票价
		int ticket_num;//票数
		int flag1;//删除标记 1:已删 0:未删
	} Data_type;

	/*定义储存航班信息结构链表*/
	typedef struct node
	{
		Data_type* info;
		struct node* next;
	}nodelist;

	nodelist* L;//定义存储链表
	Data_type* E;//定义航班信息结构体

	/*储存列表初始化*/
	bool init_N(nodelist** L);

	/*航班信息结构体初始化*/
	bool init_D(Flight** E);

	/*航班类的构造函数，读取航班.txt文件到对象数组之中*/
	Flight_Data();

	/*文件数据读入链表操作*/
	bool save_insert(nodelist* L, Data_type* E);

	/*根据航班号查询*/
	Flight* inquire_by_Id(char FlightId[]);

	/*根据降落地点和降落时间查询*/
	Flight* inquire_by_Departe(char Dep_place[], char Dep_time[]);

	/*根据起飞地点和降落地点查询*/
	Flight* inquire_by_Place(char Dep_place[], char Land_place[]);

	/*特殊的查询方式，订票操作要用*/
	Flight* inquire_speccial(char flightid[], char dep_place[], char dep_time[], char land_place[]);

	/*添加航班*/
	int Add_Flight(char* flightid, int max_cap, char* dep_place, char* dep_time, char* land_place, char* land_time, double price, int num);

	/*显示函数*/
	void Disp_Flight();

	/*取消航班函数*/
	Flight* Cancel();

	/*析构函数，把flight对象数组写到航班.txt之中*/
	~Flight_Data();
};

