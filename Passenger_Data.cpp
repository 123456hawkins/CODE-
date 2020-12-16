#include "Passenger_Data.h"
#include"Passenger.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>
#include<ctime>
#include <string.h>
#include <stdio.h>
#include<iomanip>
#include<fstream>
#include<conio.h>
using namespace std;
#define maxsize 1000
/*初始化链表函数*/
	void Passenger_Data::init_N(nodelist1** L)
	{
		(*L) = (nodelist1*)malloc(sizeof(nodelist1));
		if ((*L) != NULL)
		{
			(*L)->next = NULL;
		}
	}

	/*构造函数，读入乘客.txt到passenger[]中*/
	Passenger_Data::Passenger_Data()
	{
		Passenger s;
		init_N(&L);
		FILE* fp;
		top = -1;
		fp = fopen("passenger.txt", "r");
		E = (Data_type1*)malloc(sizeof(Data_type1));
		while (7 == fscanf(fp, "%s %s %s %s %s %s %d", &E->Flight_Id,E->Id,E->Name,E->Sex,E->Birthday,E->Seat_num,&E->P_ticket_num))//读取文件内容，对应结构体各元素
		{
			save_insert(L, E);//将其放入链表存储
			E = (Data_type1*)malloc(sizeof(Data_type1));//开辟结构体指针
		}
		nodelist1* c = L->next;
		while (c != NULL)
		{
			s.set_Flight_Id(c->info1->Flight_Id);
			s.set_Id(c->info1->Id);
			s.set_Name(c->info1->Name);
			s.set_Sex(c->info1->Sex);
			s.set_Birthday(c->info1->Birthday);
			s.set_Seat_num(c->info1->Seat_num);
			s.set_P_ticket_num(c->info1->P_ticket_num);
			top++;
			passenger[top] = s;
			c = c->next;
		}
		fclose(fp);
	}

	/*文件数据读入链表操作*/
	bool Passenger_Data::save_insert(nodelist1* L, Data_type1* E)
	{
		nodelist1* new_node;  //定义一个链表节点
		init_N(&new_node);    //初始化链表
		new_node->info1= E;     //给节点元素赋值
		while (L->next != NULL)
			L = L->next;
		L->next = new_node;     //将其插入到链表中
		return true;
	}

	/*根据身份证号查找乘客*/
	Passenger* Passenger_Data::Inquire_by_Id(char id[])
	{
		for (int i = 0; i <= top; i++)
		{
			if (strcmp(passenger[i].get_id(), id) == 0)
			{
				return &passenger[i];//找到就返回该乘客
			}
		}
		return NULL;
	}

	/*返回新增乘客*/
	Passenger* Passenger_Data::inquire_last()
	{
		return &passenger[top];
	}

	/*填加乘客*/
	void Passenger_Data::Add(char* id, char* name, char* sex, char* birthday)
	{
		top++;
		passenger[top].add(id,name,sex,birthday);//调用passenger中的函数从而修改私有数据
	}

	/*输出所有乘客信息*/
	void Passenger_Data::disp()
	{
		system("cls");
		cout << std::left << setw(25) << "身份证号" << setw(10) << "姓名" << setw(10) << "性别" << setw(15) << "出生年月" << endl;
		for (int i = 0; i <= top; i++)
		{

			passenger[i].disp();
		}
		_getch();
	}

	Passenger_Data::~Passenger_Data()//析构函数，写入乘客类数组到txt文件中
	{
		FILE* fp = fopen("passenger.txt", "w");//以写的方式打开文件passenger.txt
		for (int i = 0; i <= top; i++)
		{
			fprintf(fp, "%s %s %s %s %s %s %d", passenger[i].get_Flight_Id(), passenger[i].get_id(), passenger[i].get_name(), passenger[i].get_sex(), passenger[i].get_birthday(), passenger[i].get_seat(), passenger[i].get_ticket_num());
			fprintf(fp, "\n");
		}
		fclose(fp);
	}