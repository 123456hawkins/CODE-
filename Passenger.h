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
	char Flight_Id[20];//�����
	char Id[20];//���֤��
	char Name[20];//����
	char Sex[20];//�Ա�
	char Birthday[20];//��������
	char Seat_num[20];//��λ��
	int P_ticket_num;//��Ʊ��� >=1�Ѷ� 0:δ��
public:
	Passenger();//�˿���Ĺ��캯��

	char* get_Flight_Id()//����˽�����ݺ����
	{
		return Flight_Id;
	}

	char* get_id()//����˽���������֤��
	{
		return Id;
	}

	char* get_name()//����˽����������
	{
		return Name;
	}

	char* get_sex()//����˽�������Ա�
	{
		return Sex;
	}

	char* get_birthday()//����˽��������������
	{
		return Birthday;
	}

	char* get_seat()//����˽������λ��
	{
		return Seat_num;
	}

	int get_ticket_num()//����˽��������Ʊ��
	{
		return P_ticket_num;
	}

	void set_Flight_Id(char flightid[]);//����˽�����ݺ����

	void set_Id(char id[]);//����˽���������֤��

	void set_Name(char name[]);//����˽����������

	void set_Sex(char sex[]);//����˽�������Ա�

	void set_Birthday(char birthday[]);//����˽����������

	void set_Seat_num(char seatnum[]);//����˽��������λ��

	void set_P_ticket_num(int ticketnum);//����˽������Ʊ��

	void add(char* id, char* name, char* sex, char* birthday);//��ӳ˿Ͳ���

	void disp();//��ʾ�˿���Ϣ

	void book();//��Ʊ����

};

