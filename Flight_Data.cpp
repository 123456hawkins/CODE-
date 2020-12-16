#include "Flight_Data.h"
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
/*储存列表初始化*/
bool Flight_Data::init_N(nodelist** L)
{
	(*L) = (nodelist*)malloc(sizeof(nodelist));//分配内存空间
	if ((*L) != NULL)
	{
		(*L)->next = NULL;
		return true;
	}
	else
	{
		cout << "malloc failed!\n";
		return false;
	}
}

/*航班信息结构体初始化*/
bool Flight_Data::init_D(Flight** E)
{
	(*E) = (Flight*)malloc(sizeof(Flight));
	if ((*E) != NULL)
		return true;
	else
	{
		cout << "malloc failed!\n";
		return false;
	}
}

/*航班类的构造函数，读取航班.txt文件到对象数组之中*/
Flight_Data::Flight_Data()
{
	Flight b;
	init_N(&L);
	FILE* fp;
	top = -1;
	fp = fopen("flight.txt", "r");
	E = (Data_type*)malloc(sizeof(Data_type));
	while (9 == fscanf(fp, "%s %d %s %s %s %s %lf %d %d", &E->Flight_Id, &E->Max_cap, E->Dep_place, E->Dep_time, E->Land_place, E->land_time, &E->price, &E->flag1, &E->ticket_num))//读取文件内容，对应结构体各元素
	{
		save_insert(L, E);//将其放入链表存储
		E = (Data_type*)malloc(sizeof(Data_type));//开辟结构体指针
	}
	nodelist* s = L->next;//设置一个指针指向储存链表
	while (s != NULL)//调用航班类函数赋值给对象数组
	{
		b.set_flight_Id(s->info->Flight_Id);
		b.set_max_cap(s->info->Max_cap);
		b.set_dep_place(s->info->Dep_place);
		b.set_dep_time(s->info->Dep_time);
		b.set_land_place(s->info->Land_place);
		b.set_land_time(s->info->land_time);
		b.set_price(s->info->price);
		b.set_flag1(s->info->flag1);
		b.set_ticket_num(s->info->ticket_num);
		top++;
		flight[top] = b;
		s = s->next;
	}
	fclose(fp);
}

/*文件数据读入链表操作*/
bool Flight_Data::save_insert(nodelist* L, Data_type* E)
{
	nodelist* new_node;  //定义一个链表节点
	init_N(&new_node);    //初始化链表
	new_node->info = E;     //给节点元素赋值
	while (L->next != NULL)
		L = L->next;
	L->next = new_node;     //将其插入到链表中
	return true;
}

/*根据航班号查询*/
Flight* Flight_Data::inquire_by_Id(char FlightId[])
{
	for (int i = 0; i <= top; i++)
	{
		if (strcmp(flight[i].get_flight_Id(), FlightId) == 0 && flight[i].get_flag1() == 0)
		{
			return &flight[i];
		}
	}
	return NULL;

}


/*根据降落地点和降落时间查询*/
Flight* Flight_Data::inquire_by_Departe(char Dep_place[], char Dep_time[])
{
	for (int i = 0; i <= top; i++)
	{
		if (strcmp(flight[i].get_dep_place(), Dep_place) == 0 && strcmp(flight[i].get_dep_time(), Dep_time) == 0 && flight[i].get_flag1() == 0)
		{
			return &flight[i];
		}
	}
	return NULL;


}

/*根据起飞地点和降落地点查询*/
Flight* Flight_Data::inquire_by_Place(char Dep_place[], char Land_place[])
{
	for (int i = 0; i <= top; i++)
	{
		if (strcmp(flight[i].get_dep_place(), Dep_place) == 0 && strcmp(flight[i].get_land_place(), Land_place) == 0 && flight[i].get_flag1() == 0)
		{
			return &flight[i];
		}
	}
	return NULL;
		
}

/*特殊的查询方式，订票操作要用*/
Flight* Flight_Data::inquire_speccial(char flightid[], char dep_place[], char dep_time[], char land_place[])
{
	for (int i = 0; i <= top; i++)
	{
		if (strcmp(flight[i].get_flight_Id(), flightid) && strcmp(flight[i].get_dep_place(), dep_place) && strcmp(flight[i].get_land_place(), land_place) && strcmp(flight[i].get_dep_time(), dep_time) && flight[i].get_flag1() == 0)
		{
			return &flight[i];
		}
	}
	return NULL;

}

/*添加航班*/
int Flight_Data::Add_Flight(char* flightid, int max_cap, char* dep_place, char* dep_time, char* land_place, char* land_time, double price, int num)
{
	Flight* p = inquire_by_Id(flightid);
	char tmp4[999];//时间数组
	FILE* fp = fopen("change_list.txt", "a+");
	if (p == NULL)
	{
		top++;
		flight[top].Add(flightid, max_cap, dep_place, dep_time, land_place, land_time, price, num);
		time_t timep;
		time(&timep);
		strftime(tmp4, sizeof(tmp4), "%Y-%m-%d-%H:%M:%S", localtime(&timep));
		fprintf(fp, "添加航班->%s %d %s %s %s %s %lf %d %d %s", flight[top].get_flight_Id(), flight[top].get_max_cup(), flight[top].get_dep_place(), flight[top].get_dep_time(), flight[top].get_land_place(), flight[top].get_land_time(), flight[top].get_price(), flight[top].get_flag1(), flight[top].get_ticket_num(), tmp4);
		fprintf(fp, "\n");
		return 1;
	}
	return 0;
}

/*显示函数*/
void Flight_Data::Disp_Flight()
{
	for (int i = 0; i <= top; i++)//循环，全部显示
	{
		if (flight[i].get_flag1() == 0)
		{
			flight[i].disp();
		}
	}
}

/*取消航班函数*/
Flight* Flight_Data::Cancel()
{
	for (int i = 0; i <= top; i++)
	{
		if (flight[i].get_ticket_num() < 0.1 * flight[i].get_max_cup())
		{
			flight[i].set_flag1(1);//标记为已取消
			return &flight[i];
		}
	}
	return NULL;
}


/*析构函数，把flight对象数组写到航班.txt之中*/
Flight_Data::~Flight_Data()
{
	FILE* fp = fopen("flight.txt", "w");//以写的形式打开flight.txt文件
	for (int i = 0; i <= top; i++)
	{
		if (flight[i].get_flag1() == 0)
		{
			fprintf(fp, "%s %d %s %s %s %s %lf %d %d", flight[i].get_flight_Id(), flight[i].get_max_cup(), flight[i].get_dep_place(), flight[i].get_dep_time(), flight[i].get_land_place(), flight[i].get_land_time(), flight[i].get_price(), flight[i].get_flag1(), flight[i].get_ticket_num());
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
}