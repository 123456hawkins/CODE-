#pragma once
#include"Passenger.h"
#include"Passenger_Data.h"
#include"Flight.h"
#include"Flight_Data.h"
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
class main_menu
{
private:
	int flag;//管理员和乘客选择标记,1为管理员，0用户
	Passenger* r;
	Passenger_Data PassengerDB;
	Flight* f;
	Flight_Data FlightDB;
	int count = 0;
	char password[10] = "123456";//管理员登录密码
public:
	main_menu();//该类的构造函数

	/*返回管理员密码*/
	char* get_password()
	{
		return password;
	}

	/*设置管理员密码*/
	void set_password(char password[]);

	/*登录界面函数*/
	void login();

	/*管理员函数*/
	void admin_interface();

	/*乘客函数*/
	void passenger_interface();

	/*查找函数*/
	void search();

	/*删除函数*/
	void del();

	/*修改函数*/
	void change();

	/*新增函数*/
	void add();

	/*订票函数*/
	void book();

	/*座位号分配函数*/
	char* seat_num_allocate(int num);

	/*座位号行分配函数*/
	char* seat_num_allocate_row(int num);

	/*座位号列分配函数*/
	char* seat_num_allocate_rol(int num);

	/*添加乘客函数*/
	void add_passenger();

	/*管理员界面*/
	void admin();

	/*乘客界面*/
	void user();

	/*修改管理员密码*/
	void change_password();
};

