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
/*�����б��ʼ��*/
bool Flight_Data::init_N(nodelist** L)
{
	(*L) = (nodelist*)malloc(sizeof(nodelist));//�����ڴ�ռ�
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

/*������Ϣ�ṹ���ʼ��*/
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

/*������Ĺ��캯������ȡ����.txt�ļ�����������֮��*/
Flight_Data::Flight_Data()
{
	Flight b;
	init_N(&L);
	FILE* fp;
	top = -1;
	fp = fopen("flight.txt", "r");
	E = (Data_type*)malloc(sizeof(Data_type));
	while (9 == fscanf(fp, "%s %d %s %s %s %s %lf %d %d", &E->Flight_Id, &E->Max_cap, E->Dep_place, E->Dep_time, E->Land_place, E->land_time, &E->price, &E->flag1, &E->ticket_num))//��ȡ�ļ����ݣ���Ӧ�ṹ���Ԫ��
	{
		save_insert(L, E);//�����������洢
		E = (Data_type*)malloc(sizeof(Data_type));//���ٽṹ��ָ��
	}
	nodelist* s = L->next;//����һ��ָ��ָ�򴢴�����
	while (s != NULL)//���ú����ຯ����ֵ����������
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

/*�ļ����ݶ����������*/
bool Flight_Data::save_insert(nodelist* L, Data_type* E)
{
	nodelist* new_node;  //����һ������ڵ�
	init_N(&new_node);    //��ʼ������
	new_node->info = E;     //���ڵ�Ԫ�ظ�ֵ
	while (L->next != NULL)
		L = L->next;
	L->next = new_node;     //������뵽������
	return true;
}

/*���ݺ���Ų�ѯ*/
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


/*���ݽ���ص�ͽ���ʱ���ѯ*/
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

/*������ɵص�ͽ���ص��ѯ*/
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

/*����Ĳ�ѯ��ʽ����Ʊ����Ҫ��*/
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

/*��Ӻ���*/
int Flight_Data::Add_Flight(char* flightid, int max_cap, char* dep_place, char* dep_time, char* land_place, char* land_time, double price, int num)
{
	Flight* p = inquire_by_Id(flightid);
	char tmp4[999];//ʱ������
	FILE* fp = fopen("change_list.txt", "a+");
	if (p == NULL)
	{
		top++;
		flight[top].Add(flightid, max_cap, dep_place, dep_time, land_place, land_time, price, num);
		time_t timep;
		time(&timep);
		strftime(tmp4, sizeof(tmp4), "%Y-%m-%d-%H:%M:%S", localtime(&timep));
		fprintf(fp, "��Ӻ���->%s %d %s %s %s %s %lf %d %d %s", flight[top].get_flight_Id(), flight[top].get_max_cup(), flight[top].get_dep_place(), flight[top].get_dep_time(), flight[top].get_land_place(), flight[top].get_land_time(), flight[top].get_price(), flight[top].get_flag1(), flight[top].get_ticket_num(), tmp4);
		fprintf(fp, "\n");
		return 1;
	}
	return 0;
}

/*��ʾ����*/
void Flight_Data::Disp_Flight()
{
	for (int i = 0; i <= top; i++)//ѭ����ȫ����ʾ
	{
		if (flight[i].get_flag1() == 0)
		{
			flight[i].disp();
		}
	}
}

/*ȡ�����ຯ��*/
Flight* Flight_Data::Cancel()
{
	for (int i = 0; i <= top; i++)
	{
		if (flight[i].get_ticket_num() < 0.1 * flight[i].get_max_cup())
		{
			flight[i].set_flag1(1);//���Ϊ��ȡ��
			return &flight[i];
		}
	}
	return NULL;
}


/*������������flight��������д������.txt֮��*/
Flight_Data::~Flight_Data()
{
	FILE* fp = fopen("flight.txt", "w");//��д����ʽ��flight.txt�ļ�
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