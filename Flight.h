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
class Flight
{
private:
	char Flight_Id[20];//�����
	int Max_cap;//����ؿ���
	char Dep_place[20];//��ɵص�
	char Dep_time[20];//���ʱ��
	char Land_place[20];//����ص�
	char land_time[20];//����ʱ��
	double price; //Ʊ��
	int ticket_num;//Ʊ��
	int flag1;//ɾ����� 1:��ɾ 0:δɾ
public:
	Flight();
	char* get_flight_Id()//����˽�����ݺ����
	{
		return Flight_Id;
	}
	int get_max_cup()//����˽����������ؿ���
	{
		return Max_cap;
	}
	char* get_dep_place()//����˽��������ɵص�
	{
		return Dep_place;
	}
	char* get_dep_time()//����˽���������ʱ��
	{
		return Dep_time;
	}
	char* get_land_place()//����˽�����ݽ���ص�
	{
		return Land_place;
	}
	char* get_land_time()//����˽�����ݽ���ʱ��
	{
		return land_time;
	}
	double get_price()//����˽������Ʊ��
	{
		return price;
	}
	int get_flag1()//����˽������ɾ�����
	{
		return flag1;
	}
	int get_ticket_num()//����˽������Ʊ��
	{
		return ticket_num;
	}
	void set_flight_Id(char n0[]);//����˽�����ݺ����
	void set_max_cap(int n1);//����˽����������ؿ���
	void set_dep_place(char n2[]);//����˽��������ɵص�
	void set_dep_time(char n3[]);//����˽���������ʱ��
	void set_land_place(char n4[]);//����˽�����ݽ���ص�
	void set_land_time(char n5[]);//����˽�����ݽ���ʱ��
	void set_price(double n6);//����˽������Ʊ��
	void set_flag1(int n7);//����˽������ɾ�����
	void set_ticket_num(int n8);//����˽������ɾ�����
	void book();//��Ʊ����
	void Add(char a0[], int a1, char a3[], char a4[], char a5[], char a6[], double a7, int a8);//���Ӻ������
	int Del();//ɾ���������
	void disp();//���˽�����ݲ���
};

