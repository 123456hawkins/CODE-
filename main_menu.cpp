#include "main_menu.h"
#include"Passenger.h"
#include"Passenger_Data.h"
#include"Flight.h"
#include"Flight_Data.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>
#include"time.h"
#include<ctime>
#include <string.h>
#include <stdio.h>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<ctype.h>//isdigit islower isupperҪ��
using namespace std;
#define maxsize 1000

main_menu::main_menu() { ; }//����Ĺ��캯��

main_menu b1;

/*��¼���溯��*/
void main_menu::login()
{
	int choice1 = 9;//��һ��ѡ���ж��ǹ���Ա���ǳ˿�
	int choice2 = 9;//�ڶ���ѡ��ʵ�ֹ���
	int choice3 = 9;
	char in_password[1000];//����Ա����
	int count = 0, i = 0;
	int k = 0;
	while (choice1 != 0)
	{
		system("cls");
		cout << "*************************************\n";
		cout << "$  �� ӭ ʹ �� �� �� �� �� ϵ ͳ    $\n";
		cout << "-------------------------------------\n";
		cout << "$         ��ѡ���¼��ʽ��          $\n";
		cout << "$          1.�� �� Ա �� ¼         $\n";
		cout << "$          2.�� �� �� ¼            $\n";
		cout << "$          0. �˳�ϵͳ              $\n";
		cout << "-------------------------------------\n";
		cout << "����������ѡ��(����������!)��";
		scanf("%1d", &choice1);


		/*�û�ѡ���֧*/
		switch (choice1)
		{
		case 1:
			for (i = 0; i < 3; i++)
			{
				cout << "����������(����������!)��" << endl;
				cin >> in_password;
				if (strcmp(in_password, b1.get_password()) == 0)
				{
					break;
				}
				else
				{
					cout << "�����������" << endl;
					count++;
				}
			}
			if (count == 3)
			{
				cout << "��¼�����������Σ��˳�ϵͳ��" << endl;
			}
			else
			{
				cout << "����������ȷ��" << endl;
				admin_interface();
			}
			break;
		case 2:
			passenger_interface();
			break;
		case 0:
			break;
		}
	}
}

/*����Ա����*/
void main_menu::admin_interface()
{

	int choice2 = 9;
	while (choice2 != 0)
	{
		system("cls");
		admin();
		cout << "����������ѡ��(���������֣�): ";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			search();
			break;
		case 2:
			del();
			break;
		case 3:
			change();
			break;
		case 4:
			add();
			break;
		case 5:
			PassengerDB.disp();
			break;
		case 6:
			system("cls");
			cout << "���ݹ�˾�涨��Ԥ��Ʊ�����ں�������ؿ�����10%�ĺ���Ӧȡ����������Ӧȡ���ĺ���" << endl;
			f=FlightDB.Cancel();
			if (f == NULL)
			{
				cout << "û�д�ȡ���ĺ��࣡" << endl;
				_getch();
			}
			else
			{
				cout << std::left << setw(15) << "�����" << setw(20) << "����ؿ���" << setw(15) << "��ɵص�" << setw(15) << "���ʱ��" << setw(15) << "����ص�" << setw(15) << "����ʱ��" << setw(10) << "Ʊ��" << setw(10) << "ʣ��Ʊ��" << endl;
				f->disp();
				_getch();
			}
			break;
		case 7:
			change_password();
		case 0:
			break;
		default:
			break;
		}
	}
}

/*�˿ͺ���*/
void main_menu::passenger_interface()
{

	int choice3 = 9;
	while (choice3 != 0)
	{
		system("cls");
		user();
		cout << "����������ѡ��: ";
		cin >> choice3;
		switch (choice3)
		{
		case 1:
			search();
			break;
		case 2:
			book();
			break;
		case 0:
			break;
		default:
			break;
		}
	}
}

/*���Һ���*/
void main_menu::search()
{
	system("cls");
	int chose_num = 1;
	char flightid[100];
	char dep_place[100], dep_time[100];
	char land_place[100];
	while (chose_num != 0)
	{
		cout << "-------------------------------------\n";
		cout << "$         ��ѡ����ҷ�ʽ��           $\n";
		cout << "$          1.������Ų���            $\n";
		cout << "$          2.����ɵص�����ʱ�����$\n";
		cout << "$          3.����ɵص�ͽ���ص����$\n";
		cout << "$          4.��ʾ���к���            $\n";
		cout << "$          0.����                    $\n";
		cout << "-------------------------------------\n";
		cout << "����������ѡ��";
		cin >> chose_num;
		switch (chose_num)
		{
		case 1:
			cout << "�����뺽��ţ�" << endl;
			cin >> flightid;
			if (strlen(flightid) > 6)
			{
				cout << "��������ȷ�ĺ���ţ�" << endl;
				break;
			}
			else
			{
				f = FlightDB.inquire_by_Id(flightid);
				if (f == NULL)
				{
					cout << "�޴˺��࣡" << endl;
					delete[] f;//�ͷ��ڴ�
					break;
				}
				cout << std::left << setw(15) << "�����" << setw(20) << "����ؿ���" << setw(15) << "��ɵص�" << setw(15) << "���ʱ��" << setw(15) << "����ص�" << setw(15) << "����ʱ��" << setw(10) << "Ʊ��" << setw(10) << "ʣ��Ʊ��" << endl;
				f->disp();
				break;
			}
		case 2:
			cout << "��������ɵص㣺" << endl;
			cin >> dep_place;
			cout << "���������ʱ�䣺" << endl;
			cin >> dep_time;
			if (strlen(dep_place) > 10||strlen(dep_time)>10)
			{
				cout << "��������ȷ����ɵص�����ʱ�䣡" << endl;
				break;
			}
			else
			{
				f = FlightDB.inquire_by_Departe(dep_place, dep_time);
				f = FlightDB.inquire_by_Id(flightid);
				if (f == NULL)
				{
					cout << "�޴˺��࣡" << endl;
					delete[] f;//�ͷ��ڴ�
					break;
				}
				cout << std::left << setw(15) << "�����" << setw(20) << "����ؿ���" << setw(15) << "��ɵص�" << setw(15) << "���ʱ��" << setw(15) << "����ص�" << setw(15) << "����ʱ��" << setw(10) << "Ʊ��" << setw(10) << "ʣ��Ʊ��" << endl;
				f->disp();
				break;
			}
		case 3:
			cout << "��������ɵص㣺" << endl;
			cin >> dep_place;
			cout << "�����뽵��ص㣺" << endl;
			cin >> land_place;
			if (strlen(dep_place) > 10 || strlen(land_place) > 10)
			{
				cout << "��������ȷ����ɵص����ص㣡" << endl;
				break;
			}
			else
			{
				f = FlightDB.inquire_by_Departe(dep_place, dep_time);
				f = FlightDB.inquire_by_Id(flightid);
				if (f == NULL)
				{
					cout << "�޴˺��࣡" << endl;
					delete[] f;//�ͷ��ڴ�
					break;
				}
				cout << std::left << setw(15) << "�����" << setw(20) << "����ؿ���" << setw(15) << "��ɵص�" << setw(15) << "���ʱ��" << setw(15) << "����ص�" << setw(15) << "����ʱ��" << setw(10) << "Ʊ��" << setw(10) << "ʣ��Ʊ��" << endl;
				f->disp();
				break;
			}
		case 4:
			cout << std::left << setw(15) << "�����" << setw(20) << "����ؿ���" << setw(15) << "��ɵص�" << setw(15) << "���ʱ��" << setw(15) << "����ص�" << setw(15) << "����ʱ��" << setw(10) << "Ʊ��" << setw(10) << "ʣ��Ʊ��" << endl;
			FlightDB.Disp_Flight();
		}
	}

}

/*ɾ������*/
void main_menu::del()
{
	system("cls");
	char tmp1[999];//ʱ���¼����
	FILE* fp = fopen("change_list.txt", "a+");//�Լ���д��ķ�ʽ��change_list.txt�ļ�
	char flight_id[100];
	cout << "��������ɾ���ĺ���ţ�" << endl;
	cin >> flight_id;
	if (strlen(flight_id) > 5)
	{
		cout << "��������ȷ�ĺ���ţ�" << endl;
		_getch();
	}
	else
	{
		f = FlightDB.inquire_by_Id(flight_id);
		if (f == NULL)
		{
			cout << "�޴˺��࣡�޷�ɾ����" << endl;
			delete[] f;//�ͷ��ڴ�
			_getch();
		}
		else
		{
			if (f->Del() == 1)
			{
				cout << "ɾ���ɹ�!" << endl;
				time_t timep;
				time(&timep);
				strftime(tmp1, sizeof(tmp1), "%Y-%m-%d-%H:%M:%S", localtime(&timep));
				fprintf(fp, "ɾ������->%s %d %s %s %s %s %lf %d %d %s", f->get_flight_Id(), f->get_max_cup(), f->get_dep_place(), f->get_dep_time(), f->get_land_place(), f->get_land_time(), f->get_price(), f->get_flag1(), f->get_ticket_num(), tmp1);
				fprintf(fp, "\n");
				_getch();
			}
		}
	}
}

/*�޸ĺ���*/
void main_menu::change()
{
	system("cls");
	char tmp2[999];//ʱ������
	FILE* fp = fopen("change_list.txt", "a+");
	int Max_cap;//����ؿ���
	char Dep_place[20];//��ɵص�
	char Dep_time[10];//���ʱ��
	char Land_place[20];//����ص�
	char land_time[10];//����ʱ��
	double price; //Ʊ��
	int ticket_num;//Ʊ��
	char flight_id[100];//�����
	int chose_num = 1;
	char ch;
	cout << "���������޸ĵĺ���ţ�" << endl;
	cin >> flight_id;
	if (strlen(flight_id) > 5)
	{
		cout << "��������ȷ�ĺ���ţ�" << endl;
		_getch();
	}
	else
	{
		f = FlightDB.inquire_by_Id(flight_id);
		if (f == NULL)
		{
			cout << "�޴˺��࣡�޷��޸ģ�" << endl;
			delete[] f;//�ͷ��ڴ�
			_getch();
		}
		else
		{
			cout << "�ú������Ϣ�ǣ�" << endl;
			cout << std::left << setw(15) << "�����" << setw(20) << "����ؿ���" << setw(15) << "��ɵص�" << setw(15) << "���ʱ��" << setw(15) << "����ص�" << setw(15) << "����ʱ��" << setw(10) << "Ʊ��" << setw(10) << "ʣ��Ʊ��" << endl;
			f->disp();
			cout << "�Ƿ�ȷ���޸�?(Y/N)" << endl;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				while (chose_num != 0)
				{
					cout << "-------------------------------------\n";
					cout << "$         ��ѡ���޸ĵ����ݣ�        $\n";
					cout << "$          1.�����                 $\n";
					cout << "$          2.����ؿ���             $\n";
					cout << "$          3.��ɵص�               $\n";
					cout << "$          4.���ʱ��               $\n";
					cout << "$          5.����ص�               $\n";
					cout << "$          6.����ʱ��               $\n";
					cout << "$          7.Ʊ��                   $\n";
					cout << "$          8.ʣ��Ʊ��               $\n";
					cout << "$          0.����                   $\n";
					cout << "-------------------------------------\n";
					cout << "��������ѡ��";
					cin >> chose_num;
					switch (chose_num)
					{
					case 1:
						cout << "�������µĺ����:";
						cin >> flight_id;
						f->set_flight_Id(flight_id);
						break;
					case 2:
						cout << "�������µ�����ؿ���:";
						cin >> Max_cap;
						f->set_max_cap(Max_cap);
						break;
					case 3:
						cout << "�������µ���ɵص�:";
						cin >> Dep_place;
						f->set_dep_place(Dep_place);
						break;
					case 4:
						cout << "�����������ʱ��:";
						cin >> Dep_time;
						f->set_dep_time(Dep_time);
						break;
					case 5:
						cout << "�������½���ص�:";
						cin >> Land_place;
						f->set_land_place(Land_place);
						break;
					case 6:
						cout << "�������½���ʱ��:";
						cin >> land_time;
						f->set_land_time(land_time);
						break;
					case 7:
						cout << "�������µ�Ʊ��:";
						cin >> price;
						f->set_price(price);
						break;
					case 8:
						cout << "�������µ�ʣ��Ʊ��:";
						cin >> ticket_num;
						f->set_ticket_num(ticket_num);
						break;
					}
				}
				cout << "�޸ĳɹ���" << endl;
				time_t timep;
				time(&timep);/*��ȡtime_t���͵ĵ�ǰʱ��*/
				strftime(tmp2, sizeof(tmp2), "%Y-%m-%d-%H:%M:%S", localtime(&timep));
				fprintf(fp, "�޸ĺ���->%s %d %s %s %s %s %lf %d %d %s", f->get_flight_Id(), f->get_max_cup(), f->get_dep_place(), f->get_dep_time(), f->get_land_place(), f->get_land_time(), f->get_price(), f->get_flag1(), f->get_ticket_num(), tmp2);
				fprintf(fp, "\n");
				_getch();
			}
		}
	}
}

/*��������*/
void main_menu::add()
{
	system("cls");
	int Max_cap;//����ؿ���
	char Dep_place[20];//��ɵص�
	char Dep_time[20];//���ʱ��
	char Land_place[20];//����ص�
	char land_time[20];//����ʱ��
	double price; //Ʊ��
	int ticket_num;//Ʊ��
	char flight_id[100];//�����
	cout << "�����뺽���" << endl;
	cin >> flight_id;
	if (strlen(flight_id) > 5)
	{
		cout << "��������ȷ�ĺ���ţ�" << endl;
		_getch();
	}
	else
	{
		f = FlightDB.inquire_by_Id(flight_id);
		if (f != NULL)
		{
			cout << "�Ѵ��ڴ˺��࣡�޷���ӣ�" << endl;
			delete[] f;
			_getch();
		}
		else
		{
			cout << "�޴˺��࣬�����������Ϣ����Ӻ���" << endl;
			cout << "�����뺽���:";
			cin >> flight_id;
			cout << "����������ؿ���:";
			cin >> Max_cap;
			cout << "��������ɵص�:";
			cin >> Dep_place;
			cout << "���������ʱ��:";
			cin >> Dep_time;
			cout << "�����뽵��ص�:";
			cin >> Land_place;
			cout << "�����뽵��ʱ��:";
			cin >> land_time;
			cout << "������Ʊ��:";
			cin >> price;
			cout << "������ʣ��Ʊ��:";
			cin >> ticket_num;
			FlightDB.Add_Flight(flight_id, Max_cap, Dep_place, Dep_time, Land_place, land_time, price, ticket_num);
			cout << "��ӳɹ�" << endl;
			_getch();
		}
	}
}

/*��Ʊ����*/
void main_menu::book()
{
	system("cls");
	char passenger_id[100];
	char flight_id[20];
	char dep_place[20];
	char dep_time[20];
	char land_place[20];
	char land_time[20];
	int ticket_num;
	char chose_str[20];
	char seat_num[20] = {};
	cout << "����Ϊ���к���:" << endl;
	cout << std::left << setw(15) << "�����" << setw(20) << "����ؿ���" << setw(15) << "��ɵص�" << setw(15) << "���ʱ��" << setw(15) << "����ص�" << setw(15) << "����ʱ��" << setw(10) << "Ʊ��" << setw(10) << "ʣ��Ʊ��" << endl;
	FlightDB.Disp_Flight();
	cout << "������˿����֤���Զ�Ʊ��" << endl;
	cin >> passenger_id;
	r = PassengerDB.Inquire_by_Id(passenger_id);
	if (r == NULL)//����³˿��ٶ�Ʊ
	{
		cout << "�޴˳˿ͣ�" << endl;
		add_passenger();
		r = PassengerDB.inquire_last();//�ҵ����һ������ӵĳ˿ͣ������һ���˿�
		cout << "�����뺽��š���ɵص㡢���ʱ�䡢����ص��Զ�����" << endl;
		cin >> flight_id >> dep_place >> dep_time >> land_place;

		f = FlightDB.inquire_by_Id(flight_id);//ͨ������Ų��Һ��࣬�ҵ����ܶ�Ʊ����֮������
		if (f == NULL)
		{
			cout << "�޴˺��࣡�޷���Ʊ��" << endl;
			delete[] f;
			_getch();
		}
		else
		{
			cout << "���ҵ��ú��࣬�ú���ʣ��" << f->get_ticket_num() << "��Ʊ��" << endl;
			if (f->get_ticket_num() < 0)
			{
				cout << "����Ʊ�����㣬�޷���Ʊ��" << endl;
				_getch();
			}
			else
			{
				char a[20];
				strcpy(a, f->get_flight_Id());
				r->set_Flight_Id(a);
				f->book();
				count++;
				strcpy(seat_num, seat_num_allocate(count));//������λ��������������λ
				r->book();
				r->set_Seat_num(seat_num);
				cout << "�����λ��Ϊ" << seat_num << endl;
				cout << "��Ʊ�ɹ���" << endl;
				cout << "����ɷ���" << f->get_price() << "Ԫ" << endl;
				_getch();
			}
		}
	}

	else//ֱ�Ӷ�Ʊ
	{
		if (r->get_ticket_num() != 0)
		{
			cout << "�ó˿��Ѷ�Ʊ���޷��ٶ���" << endl;
			cout << "���¶�Ʊ���˳���Ʊ��(Y/N)" << endl;
			cin >> chose_str;
			if (chose_str == "Y")
			{
				book();
			}
		}
		else
		{
			cout << "�����뺽��š���ɵص㡢���ʱ�䡢����ص��Զ�����" << endl;
			cin >> flight_id >> dep_place >> dep_time >> land_place;
			f = FlightDB.inquire_by_Id(flight_id);
			if (f == NULL)
			{
				cout << "�޴˺��࣡�޷���Ʊ��" << endl;
				_getch();
			}
			else
			{
				cout << "���ҵ��ú��࣬�ú���ʣ��" << f->get_ticket_num() << "��Ʊ��" << endl;
				if (f->get_ticket_num() < 0)
				{
					cout << "����Ʊ�����㣬�޷���Ʊ��" << endl;
					_getch();
				}
				else
				{
					char a[20];
					strcpy(a, f->get_flight_Id());
					r->set_Flight_Id(a);
					f->book();
					count++;
					strcpy(seat_num, seat_num_allocate(count));
					r->book();
					r->set_Seat_num(seat_num);
					cout << "�����λ��Ϊ" << seat_num << endl;
					cout << "��Ʊ�ɹ���" << endl;
					cout << "����ɷ���" << f->get_price() << "Ԫ" << endl;
					_getch();
				}
			}
		}
	}

}

/*��λ�ŷ��亯��*/
char* main_menu::seat_num_allocate(int num)
{
	int row = num / 6;//����(��A,B,C,D,E,F.....����)
	int rol = num % 6;//����(��1,2,3,4,5.....����)
	cout << row;
	cout << rol;
	char row1[10];
	char rol1[10];
	char seat_num[10];
	strcpy(row1, seat_num_allocate_row(row));
	strcpy(rol1, seat_num_allocate_rol(rol));
	strcat(row1, rol1);
	return row1;
}

/*��λ���з��亯��*/
char* main_menu::seat_num_allocate_row(int num)
{
	char row1[10];
	if (num == 0)
		strcpy(row1, "A");
	if (num == 1)
		strcpy(row1, "B");
	if (num == 2)
		strcpy(row1, "C");
	if (num == 3)
		strcpy(row1, "D");
	if (num == 4)
		strcpy(row1, "E");
	if (num == 5)
		strcpy(row1, "F");
	if (num == 6)
		strcpy(row1, "G");
	if (num == 7)
		strcpy(row1, "H");
	if (num == 8)
		strcpy(row1, "I");
	if (num == 9)
		strcpy(row1, "J");
	return row1;
}

/*��λ���з��亯��*/
char* main_menu::seat_num_allocate_rol(int num)
{
	char rol1[10];
	if (num == 0)
		strcpy(rol1, "0");
	if (num == 1)
		strcpy(rol1, "1");
	if (num == 2)
		strcpy(rol1, "2");
	if (num == 3)
		strcpy(rol1, "3");
	if (num == 4)
		strcpy(rol1, "4");
	if (num == 5)
		strcpy(rol1, "5");
	if (num == 6)
		strcpy(rol1, "6");
	if (num == 7)
		strcpy(rol1, "7");
	if (num == 8)
		strcpy(rol1, "8");
	if (num == 9)
		strcpy(rol1, "9");
	return rol1;
}

/*��ӳ˿ͺ���*/
void main_menu::add_passenger()
{
	char Flight_Id[20];//����� 0����δ��
	char Id[20];//���֤��
	char Name[20];//����
	char Sex[20];//�Ա�
	char Birthday[20];//��������
	char Seat_num[20];//��λ�� 0����δ��
	int P_ticket_num;//��Ʊ��� >=1�Ѷ� 0:δ��
	cout << "����˿������Ϣ����ӳ˿�" << endl;
	cout << "���������֤�ţ�";
	cin >> Id;
	cout << "������������";
	cin >> Name;
	cout << "�������Ա�";
	cin >> Sex;
	cout << "������������£�";
	cin >> Birthday;
	PassengerDB.Add(Id, Name, Sex, Birthday);
}

/*����Ա����*/
void main_menu::admin()
{
	cout << "*************************************\n";
	cout << "$         ����Ա����ϵͳ            $\n";
	cout << "-------------------------------------\n";
	cout << "$         �����������Ŀ ��         $\n";
	cout << "$          1:�� �� �� ��            $\n";
	cout << "$          2:ɾ �� �� ��            $\n";
	cout << "$          3:�� �� �� ��            $\n";
	cout << "$          4:�� �� �� ��            $\n";
	cout << "$          5:�� �� �� �� �� ��      $\n";
	cout << "$          6:�� �� �� ȡ �� �� �� ��$\n";
	cout << "$          7:�� �� �� ¼ �� ��      $\n";
	cout << "$          0:�� ��                  $\n";
	cout << "-------------------------------------\n";
}

/*�˿ͽ���*/
void main_menu::user()
{
	cout << "*************************************\n";
	cout << "$      ������Ϣ��ѯ�ͼ���ϵͳ       $\n";
	cout << "-------------------------------------\n";
	cout << "$         ��ѡ����� :              $\n";
	cout << "$         1.�� ѯ �� ��             $\n";
	cout << "$         2.�� Ʊ                   $\n";
	cout << "$         0:�� �� ϵ ͳ             $\n";
	cout << "-------------------------------------\n";
}

/*���õ�¼����*/
void main_menu::set_password(char new_password[])
{
	strcpy(password, new_password);
}

/*�޸Ĺ���Ա���뺯��*/
void main_menu::change_password()
{
	system("cls");
	char new_password[100];
	cout << "�������µ����룺";
	cin >> new_password;
	b1.set_password(new_password);
	cout << "�޸ĳɹ���"<<endl;
	_getch();
	b1.login();
}