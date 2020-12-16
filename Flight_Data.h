#pragma once
#include"Flight.h"
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
using namespace std;
#define maxsize 1000
/*�������,ʵ�ֺ������ز���*/
class Flight_Data
{
private:
	int top;//�����¼ָ��
	Flight flight[maxsize];//�������������
public:

	/*������Ϣ�ṹ��,Ŀ�����ļ���Ϣ�Ķ���*/
	typedef struct
	{
		char Flight_Id[20];//�����
		int Max_cap;//����ؿ���
		char Dep_place[20];//��ɵص�
		char Dep_time[20];//���ʱ��
		char Land_place[20];//����ص�
		char land_time[20];//����ʱ��
		double price; //Ʊ��
		int ticket_num;//Ʊ��
		int flag1;//ɾ����� 1:��ɾ 0:δɾ
	} Data_type;

	/*���崢�溽����Ϣ�ṹ����*/
	typedef struct node
	{
		Data_type* info;
		struct node* next;
	}nodelist;

	nodelist* L;//����洢����
	Data_type* E;//���庽����Ϣ�ṹ��

	/*�����б��ʼ��*/
	bool init_N(nodelist** L);

	/*������Ϣ�ṹ���ʼ��*/
	bool init_D(Flight** E);

	/*������Ĺ��캯������ȡ����.txt�ļ�����������֮��*/
	Flight_Data();

	/*�ļ����ݶ����������*/
	bool save_insert(nodelist* L, Data_type* E);

	/*���ݺ���Ų�ѯ*/
	Flight* inquire_by_Id(char FlightId[]);

	/*���ݽ���ص�ͽ���ʱ���ѯ*/
	Flight* inquire_by_Departe(char Dep_place[], char Dep_time[]);

	/*������ɵص�ͽ���ص��ѯ*/
	Flight* inquire_by_Place(char Dep_place[], char Land_place[]);

	/*����Ĳ�ѯ��ʽ����Ʊ����Ҫ��*/
	Flight* inquire_speccial(char flightid[], char dep_place[], char dep_time[], char land_place[]);

	/*��Ӻ���*/
	int Add_Flight(char* flightid, int max_cap, char* dep_place, char* dep_time, char* land_place, char* land_time, double price, int num);

	/*��ʾ����*/
	void Disp_Flight();

	/*ȡ�����ຯ��*/
	Flight* Cancel();

	/*������������flight��������д������.txt֮��*/
	~Flight_Data();
};

