#pragma once
#include"Passenger.h"
#include"Passenger_Data.h"
#include"Flight.h"
#include"Flight_Data.h"
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
class main_menu
{
private:
	int flag;//����Ա�ͳ˿�ѡ����,1Ϊ����Ա��0�û�
	Passenger* r;
	Passenger_Data PassengerDB;
	Flight* f;
	Flight_Data FlightDB;
	int count = 0;
	char password[10] = "123456";//����Ա��¼����
public:
	main_menu();//����Ĺ��캯��

	/*���ع���Ա����*/
	char* get_password()
	{
		return password;
	}

	/*���ù���Ա����*/
	void set_password(char password[]);

	/*��¼���溯��*/
	void login();

	/*����Ա����*/
	void admin_interface();

	/*�˿ͺ���*/
	void passenger_interface();

	/*���Һ���*/
	void search();

	/*ɾ������*/
	void del();

	/*�޸ĺ���*/
	void change();

	/*��������*/
	void add();

	/*��Ʊ����*/
	void book();

	/*��λ�ŷ��亯��*/
	char* seat_num_allocate(int num);

	/*��λ���з��亯��*/
	char* seat_num_allocate_row(int num);

	/*��λ���з��亯��*/
	char* seat_num_allocate_rol(int num);

	/*��ӳ˿ͺ���*/
	void add_passenger();

	/*����Ա����*/
	void admin();

	/*�˿ͽ���*/
	void user();

	/*�޸Ĺ���Ա����*/
	void change_password();
};

