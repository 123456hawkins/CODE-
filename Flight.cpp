#include "Flight.h"
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
Flight::Flight() {; }//Flight的构造函数

void Flight::set_flight_Id(char n0[])
{
	strcpy(Flight_Id, n0);
};//设置私有数据航班号

void  Flight::set_max_cap(int n1)
{
	Max_cap = n1;
};//设置私有数据最大载客量

void Flight::set_dep_place(char n2[])
{
	strcpy(Dep_place, n2);
};//设置私有数据起飞地点

void Flight::set_dep_time(char n3[])
{
	strcpy(Dep_time, n3);
};//设置私有数据起飞时间

void Flight::set_land_place(char n4[])
{
	strcpy(Land_place, n4);
};//设置私有数据降落地点

void Flight::set_land_time(char n5[])
{
	strcpy(land_time, n5);
};//设置私有数据降落时间

void Flight::set_price(double n6)
{
	price = n6;
};//设置私有数据票价

void Flight::set_flag1(int n7)
{
	flag1 = n7;
};//设置私有数据删除标记

void Flight::set_ticket_num(int n8)
{
	ticket_num = n8;
};//设置私有数据删除标记

void Flight::book()
{
	ticket_num--;
};//订票操作

void Flight::Add(char a0[], int a1, char a3[], char a4[], char a5[], char a6[], double a7, int a8)
{
	strcpy(Flight_Id, a0);//复制a0到Flight_Id
	Max_cap = a1;
	strcpy(Dep_place, a3);
	strcpy(Dep_time, a4);
	strcpy(Land_place, a5);
	strcpy(land_time, a6);
	price = a7;
	flag1 = 0;
	ticket_num = a8;
};//增加航班操作

int Flight::Del()
{
	char a;
	cout << "确定删除吗？Y/N ?" << endl;
	cin >> a;
	if (a == 'y' || a == 'Y')
	{
		flag1 = 1;
		return 1;
	}
	if (a == 'y' || a == 'Y')
	{
		return 0;
			 
	}

};//删除航班操作

void Flight::disp()
{
	cout << std::left << setw(20) << Flight_Id << setw(15) << Max_cap << setw(15) << Dep_place << setw(15) << Dep_time << setw(15) << Land_place << setw(15) << land_time << setw(15) << price << setw(10) << ticket_num << endl;
};//输出私有数据操作