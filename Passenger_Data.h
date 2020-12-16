#pragma once
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
class Passenger_Data
{
private:
	int top;//�˿ͼ�¼ָ��
	Passenger passenger[maxsize];//�˿Ͷ�������
public:
	/*���캯��*/
	Passenger_Data();

	/*�˿���Ϣ�ṹ��,Ŀ�����ļ���Ϣ�Ķ���*/
	typedef struct
	{
		char Flight_Id[20];//�����
		char Id[20];//���֤��
		char Name[20];//����
		char Sex[20];//�Ա�
		char Birthday[20];//��������
		char Seat_num[20];//��λ��
		int P_ticket_num;//��Ʊ��� >=1�Ѷ� 0:δ��
	}Data_type1;

	/*���崢�溽����Ϣ�ṹ����*/
	typedef struct node1
	{
		Data_type1* info1;
		struct node1* next;
	}nodelist1;

	nodelist1* L;//����洢����

	Data_type1* E;//�����������Ϣ�ṹ��

	/*��ʼ��������*/
	void init_N(nodelist1** L);

	/*���캯��������˿�.txt��passenger[]��*/

	/*�ļ����ݶ����������*/
	bool save_insert(nodelist1* L, Data_type1* E);

	/*�������֤�Ų��ҳ˿�*/
	Passenger* Inquire_by_Id(char id[]);

	/*���������˿�*/
	Passenger* inquire_last();

	/*��ӳ˿�*/
	void Add(char* id, char* name, char* sex, char* birthday);

	/*������г˿���Ϣ*/
	void disp();
	
	/*����������д��˿������鵽txt�ļ���*/
	~Passenger_Data();

};

