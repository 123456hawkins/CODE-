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
/*��ʼ��������*/
	void Passenger_Data::init_N(nodelist1** L)
	{
		(*L) = (nodelist1*)malloc(sizeof(nodelist1));
		if ((*L) != NULL)
		{
			(*L)->next = NULL;
		}
	}

	/*���캯��������˿�.txt��passenger[]��*/
	Passenger_Data::Passenger_Data()
	{
		Passenger s;
		init_N(&L);
		FILE* fp;
		top = -1;
		fp = fopen("passenger.txt", "r");
		E = (Data_type1*)malloc(sizeof(Data_type1));
		while (7 == fscanf(fp, "%s %s %s %s %s %s %d", &E->Flight_Id,E->Id,E->Name,E->Sex,E->Birthday,E->Seat_num,&E->P_ticket_num))//��ȡ�ļ����ݣ���Ӧ�ṹ���Ԫ��
		{
			save_insert(L, E);//�����������洢
			E = (Data_type1*)malloc(sizeof(Data_type1));//���ٽṹ��ָ��
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

	/*�ļ����ݶ����������*/
	bool Passenger_Data::save_insert(nodelist1* L, Data_type1* E)
	{
		nodelist1* new_node;  //����һ������ڵ�
		init_N(&new_node);    //��ʼ������
		new_node->info1= E;     //���ڵ�Ԫ�ظ�ֵ
		while (L->next != NULL)
			L = L->next;
		L->next = new_node;     //������뵽������
		return true;
	}

	/*�������֤�Ų��ҳ˿�*/
	Passenger* Passenger_Data::Inquire_by_Id(char id[])
	{
		for (int i = 0; i <= top; i++)
		{
			if (strcmp(passenger[i].get_id(), id) == 0)
			{
				return &passenger[i];//�ҵ��ͷ��ظó˿�
			}
		}
		return NULL;
	}

	/*���������˿�*/
	Passenger* Passenger_Data::inquire_last()
	{
		return &passenger[top];
	}

	/*��ӳ˿�*/
	void Passenger_Data::Add(char* id, char* name, char* sex, char* birthday)
	{
		top++;
		passenger[top].add(id,name,sex,birthday);//����passenger�еĺ����Ӷ��޸�˽������
	}

	/*������г˿���Ϣ*/
	void Passenger_Data::disp()
	{
		system("cls");
		cout << std::left << setw(25) << "���֤��" << setw(10) << "����" << setw(10) << "�Ա�" << setw(15) << "��������" << endl;
		for (int i = 0; i <= top; i++)
		{

			passenger[i].disp();
		}
		_getch();
	}

	Passenger_Data::~Passenger_Data()//����������д��˿������鵽txt�ļ���
	{
		FILE* fp = fopen("passenger.txt", "w");//��д�ķ�ʽ���ļ�passenger.txt
		for (int i = 0; i <= top; i++)
		{
			fprintf(fp, "%s %s %s %s %s %s %d", passenger[i].get_Flight_Id(), passenger[i].get_id(), passenger[i].get_name(), passenger[i].get_sex(), passenger[i].get_birthday(), passenger[i].get_seat(), passenger[i].get_ticket_num());
			fprintf(fp, "\n");
		}
		fclose(fp);
	}