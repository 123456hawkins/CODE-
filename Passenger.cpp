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

Passenger::Passenger() { ; }//乘客类的构造函数

void Passenger::set_Flight_Id(char flightid[])//设置私有数据航班号
{
	strcpy(Flight_Id, flightid);
}

void Passenger::set_Id(char id[])//设置私有数据身份证号
{
	strcpy(Id, id);
}

void Passenger::set_Name(char name[])//设置私有数据姓名
{
	strcpy(Name, name);
}

void Passenger::set_Sex(char sex[])//设置私有数据性别
{
	strcpy(Sex, sex);
}

void Passenger::set_Birthday(char birthday[])//设置私有数据生日
{
	strcpy(Birthday, birthday);
}

void Passenger::set_Seat_num(char seatnum[])//设置私有数据座位号
{
	strcpy(Seat_num, seatnum);
}

void Passenger::set_P_ticket_num(int ticketnum)//设置私有数据票数
{
	P_ticket_num = ticketnum;
}

void Passenger::add(char* id, char* name, char* sex, char* birthday)//添加乘客操作
{
	strcpy(Id, id);//复制id到Id
	strcpy(Name, name);
	strcpy(Sex, sex);
	strcpy(Birthday, birthday);
	strcpy(Seat_num, "0");
	P_ticket_num = 0;
	strcpy(Flight_Id, "0");
}

void Passenger::disp()//显示乘客信息
{
	cout<<std::left << setw(25) << Id << setw(10) << Name << setw(10) << Sex << setw(20) << Birthday;
	if (P_ticket_num != 0)
	{
		cout << "\t航班号为：" << Flight_Id << setw(5) << "\t票数：" << P_ticket_num << "\t座位号：" << Seat_num << endl;
	}
	else
	{
		cout << "该乘客未订票！" << endl;
	}
}

void Passenger::book()//订票函数
{
	P_ticket_num++;
}
