#include "Flight.h"
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
Flight::Flight() {; }//Flight�Ĺ��캯��

void Flight::set_flight_Id(char n0[])
{
	strcpy(Flight_Id, n0);
};//����˽�����ݺ����

void  Flight::set_max_cap(int n1)
{
	Max_cap = n1;
};//����˽����������ؿ���

void Flight::set_dep_place(char n2[])
{
	strcpy(Dep_place, n2);
};//����˽��������ɵص�

void Flight::set_dep_time(char n3[])
{
	strcpy(Dep_time, n3);
};//����˽���������ʱ��

void Flight::set_land_place(char n4[])
{
	strcpy(Land_place, n4);
};//����˽�����ݽ���ص�

void Flight::set_land_time(char n5[])
{
	strcpy(land_time, n5);
};//����˽�����ݽ���ʱ��

void Flight::set_price(double n6)
{
	price = n6;
};//����˽������Ʊ��

void Flight::set_flag1(int n7)
{
	flag1 = n7;
};//����˽������ɾ�����

void Flight::set_ticket_num(int n8)
{
	ticket_num = n8;
};//����˽������ɾ�����

void Flight::book()
{
	ticket_num--;
};//��Ʊ����

void Flight::Add(char a0[], int a1, char a3[], char a4[], char a5[], char a6[], double a7, int a8)
{
	strcpy(Flight_Id, a0);//����a0��Flight_Id
	Max_cap = a1;
	strcpy(Dep_place, a3);
	strcpy(Dep_time, a4);
	strcpy(Land_place, a5);
	strcpy(land_time, a6);
	price = a7;
	flag1 = 0;
	ticket_num = a8;
};//���Ӻ������

int Flight::Del()
{
	char a;
	cout << "ȷ��ɾ����Y/N ?" << endl;
	cin >> a;
	if (a == 'y' || a == 'Y')
	{
		flag1 = 1;
		return 1;
	}
	if (a == 'y' || a == 'Y')
	{
		return 0;
			 
	}

};//ɾ���������

void Flight::disp()
{
	cout << std::left << setw(20) << Flight_Id << setw(15) << Max_cap << setw(15) << Dep_place << setw(15) << Dep_time << setw(15) << Land_place << setw(15) << land_time << setw(15) << price << setw(10) << ticket_num << endl;
};//���˽�����ݲ���