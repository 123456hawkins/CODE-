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
class Flight
{
private:
	char Flight_Id[20];//航班号
	int Max_cap;//最大载客数
	char Dep_place[20];//起飞地点
	char Dep_time[20];//起飞时间
	char Land_place[20];//降落地点
	char land_time[20];//降落时间
	double price; //票价
	int ticket_num;//票数
	int flag1;//删除标记 1:已删 0:未删
public:
	Flight();
	char* get_flight_Id()//返回私有数据航班号
	{
		return Flight_Id;
	}
	int get_max_cup()//返回私有数据最大载客量
	{
		return Max_cap;
	}
	char* get_dep_place()//返回私有数据起飞地点
	{
		return Dep_place;
	}
	char* get_dep_time()//返回私有数据起飞时间
	{
		return Dep_time;
	}
	char* get_land_place()//返回私有数据降落地点
	{
		return Land_place;
	}
	char* get_land_time()//返回私有数据降落时间
	{
		return land_time;
	}
	double get_price()//返回私有数据票价
	{
		return price;
	}
	int get_flag1()//返回私有数据删除标记
	{
		return flag1;
	}
	int get_ticket_num()//返回私有数据票数
	{
		return ticket_num;
	}
	void set_flight_Id(char n0[]);//设置私有数据航班号
	void set_max_cap(int n1);//设置私有数据最大载客量
	void set_dep_place(char n2[]);//设置私有数据起飞地点
	void set_dep_time(char n3[]);//设置私有数据起飞时间
	void set_land_place(char n4[]);//设置私有数据降落地点
	void set_land_time(char n5[]);//设置私有数据降落时间
	void set_price(double n6);//设置私有数据票价
	void set_flag1(int n7);//设置私有数据删除标记
	void set_ticket_num(int n8);//设置私有数据删除标记
	void book();//订票操作
	void Add(char a0[], int a1, char a3[], char a4[], char a5[], char a6[], double a7, int a8);//增加航班操作
	int Del();//删除航班操作
	void disp();//输出私有数据操作
};

