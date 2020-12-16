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

Passenger::Passenger() { ; }//�˿���Ĺ��캯��

void Passenger::set_Flight_Id(char flightid[])//����˽�����ݺ����
{
	strcpy(Flight_Id, flightid);
}

void Passenger::set_Id(char id[])//����˽���������֤��
{
	strcpy(Id, id);
}

void Passenger::set_Name(char name[])//����˽����������
{
	strcpy(Name, name);
}

void Passenger::set_Sex(char sex[])//����˽�������Ա�
{
	strcpy(Sex, sex);
}

void Passenger::set_Birthday(char birthday[])//����˽����������
{
	strcpy(Birthday, birthday);
}

void Passenger::set_Seat_num(char seatnum[])//����˽��������λ��
{
	strcpy(Seat_num, seatnum);
}

void Passenger::set_P_ticket_num(int ticketnum)//����˽������Ʊ��
{
	P_ticket_num = ticketnum;
}

void Passenger::add(char* id, char* name, char* sex, char* birthday)//��ӳ˿Ͳ���
{
	strcpy(Id, id);//����id��Id
	strcpy(Name, name);
	strcpy(Sex, sex);
	strcpy(Birthday, birthday);
	strcpy(Seat_num, "0");
	P_ticket_num = 0;
	strcpy(Flight_Id, "0");
}

void Passenger::disp()//��ʾ�˿���Ϣ
{
	cout<<std::left << setw(25) << Id << setw(10) << Name << setw(10) << Sex << setw(20) << Birthday;
	if (P_ticket_num != 0)
	{
		cout << "\t�����Ϊ��" << Flight_Id << setw(5) << "\tƱ����" << P_ticket_num << "\t��λ�ţ�" << Seat_num << endl;
	}
	else
	{
		cout << "�ó˿�δ��Ʊ��" << endl;
	}
}

void Passenger::book()//��Ʊ����
{
	P_ticket_num++;
}
