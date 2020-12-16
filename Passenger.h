#pragma once
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
class Passenger
{
private:
	char Flight_Id[20];//航班号
	char Id[20];//身份证号
	char Name[20];//姓名
	char Sex[20];//性别
	char Birthday[20];//出生年月
	char Seat_num[20];//座位号
	int P_ticket_num;//订票标记 >=1已定 0:未定
public:
	Passenger();//乘客类的构造函数

	char* get_Flight_Id()//访问私有数据航班号
	{
		return Flight_Id;
	}

	char* get_id()//访问私有数据身份证号
	{
		return Id;
	}

	char* get_name()//访问私有数据姓名
	{
		return Name;
	}

	char* get_sex()//访问私有数据性别
	{
		return Sex;
	}

	char* get_birthday()//访问私有数据生日年月
	{
		return Birthday;
	}

	char* get_seat()//访问私有数据位置
	{
		return Seat_num;
	}

	int get_ticket_num()//访问私有数据怕票数
	{
		return P_ticket_num;
	}

	void set_Flight_Id(char flightid[]);//设置私有数据航班号

	void set_Id(char id[]);//设置私有数据身份证号

	void set_Name(char name[]);//设置私有数据姓名

	void set_Sex(char sex[]);//设置私有数据性别

	void set_Birthday(char birthday[]);//设置私有数据生日

	void set_Seat_num(char seatnum[]);//设置私有数据座位号

	void set_P_ticket_num(int ticketnum);//设置私有数据票数

	void add(char* id, char* name, char* sex, char* birthday);//添加乘客操作

	void disp();//显示乘客信息

	void book();//订票函数

};

