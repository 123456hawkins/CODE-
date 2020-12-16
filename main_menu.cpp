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
#include<ctype.h>//isdigit islower isupper要用
using namespace std;
#define maxsize 1000

main_menu::main_menu() { ; }//该类的构造函数

main_menu b1;

/*登录界面函数*/
void main_menu::login()
{
	int choice1 = 9;//第一次选择判断是管理员还是乘客
	int choice2 = 9;//第二次选择实现功能
	int choice3 = 9;
	char in_password[1000];//管理员密码
	int count = 0, i = 0;
	int k = 0;
	while (choice1 != 0)
	{
		system("cls");
		cout << "*************************************\n";
		cout << "$  欢 迎 使 用 航 班 管 理 系 统    $\n";
		cout << "-------------------------------------\n";
		cout << "$         请选择登录方式：          $\n";
		cout << "$          1.管 理 员 登 录         $\n";
		cout << "$          2.用 户 登 录            $\n";
		cout << "$          0. 退出系统              $\n";
		cout << "-------------------------------------\n";
		cout << "请输入您的选择(请输入数字!)：";
		scanf("%1d", &choice1);


		/*用户选择分支*/
		switch (choice1)
		{
		case 1:
			for (i = 0; i < 3; i++)
			{
				cout << "请输入密码(请输入数字!)：" << endl;
				cin >> in_password;
				if (strcmp(in_password, b1.get_password()) == 0)
				{
					break;
				}
				else
				{
					cout << "密码输入错误！" << endl;
					count++;
				}
			}
			if (count == 3)
			{
				cout << "登录次数超过三次，退出系统！" << endl;
			}
			else
			{
				cout << "密码输入正确！" << endl;
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

/*管理员函数*/
void main_menu::admin_interface()
{

	int choice2 = 9;
	while (choice2 != 0)
	{
		system("cls");
		admin();
		cout << "请输入您的选择(请输入数字！): ";
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
			cout << "根据公司规定，预定票数少于航班最大载客量的10%的航班应取消，以下是应取消的航班" << endl;
			f=FlightDB.Cancel();
			if (f == NULL)
			{
				cout << "没有待取消的航班！" << endl;
				_getch();
			}
			else
			{
				cout << std::left << setw(15) << "航班号" << setw(20) << "最大载客量" << setw(15) << "起飞地点" << setw(15) << "起飞时间" << setw(15) << "降落地点" << setw(15) << "降落时间" << setw(10) << "票价" << setw(10) << "剩余票数" << endl;
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

/*乘客函数*/
void main_menu::passenger_interface()
{

	int choice3 = 9;
	while (choice3 != 0)
	{
		system("cls");
		user();
		cout << "请输入您的选择: ";
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

/*查找函数*/
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
		cout << "$         请选择查找方式：           $\n";
		cout << "$          1.按航班号查找            $\n";
		cout << "$          2.按起飞地点和起飞时间查找$\n";
		cout << "$          3.按起飞地点和降落地点查找$\n";
		cout << "$          4.显示所有航班            $\n";
		cout << "$          0.返回                    $\n";
		cout << "-------------------------------------\n";
		cout << "请输入您的选择：";
		cin >> chose_num;
		switch (chose_num)
		{
		case 1:
			cout << "请输入航班号：" << endl;
			cin >> flightid;
			if (strlen(flightid) > 6)
			{
				cout << "请输入正确的航班号！" << endl;
				break;
			}
			else
			{
				f = FlightDB.inquire_by_Id(flightid);
				if (f == NULL)
				{
					cout << "无此航班！" << endl;
					delete[] f;//释放内存
					break;
				}
				cout << std::left << setw(15) << "航班号" << setw(20) << "最大载客量" << setw(15) << "起飞地点" << setw(15) << "起飞时间" << setw(15) << "降落地点" << setw(15) << "降落时间" << setw(10) << "票价" << setw(10) << "剩余票数" << endl;
				f->disp();
				break;
			}
		case 2:
			cout << "请输入起飞地点：" << endl;
			cin >> dep_place;
			cout << "请输入起飞时间：" << endl;
			cin >> dep_time;
			if (strlen(dep_place) > 10||strlen(dep_time)>10)
			{
				cout << "请输入正确的起飞地点或起飞时间！" << endl;
				break;
			}
			else
			{
				f = FlightDB.inquire_by_Departe(dep_place, dep_time);
				f = FlightDB.inquire_by_Id(flightid);
				if (f == NULL)
				{
					cout << "无此航班！" << endl;
					delete[] f;//释放内存
					break;
				}
				cout << std::left << setw(15) << "航班号" << setw(20) << "最大载客量" << setw(15) << "起飞地点" << setw(15) << "起飞时间" << setw(15) << "降落地点" << setw(15) << "降落时间" << setw(10) << "票价" << setw(10) << "剩余票数" << endl;
				f->disp();
				break;
			}
		case 3:
			cout << "请输入起飞地点：" << endl;
			cin >> dep_place;
			cout << "请输入降落地点：" << endl;
			cin >> land_place;
			if (strlen(dep_place) > 10 || strlen(land_place) > 10)
			{
				cout << "请输入正确的起飞地点或降落地点！" << endl;
				break;
			}
			else
			{
				f = FlightDB.inquire_by_Departe(dep_place, dep_time);
				f = FlightDB.inquire_by_Id(flightid);
				if (f == NULL)
				{
					cout << "无此航班！" << endl;
					delete[] f;//释放内存
					break;
				}
				cout << std::left << setw(15) << "航班号" << setw(20) << "最大载客量" << setw(15) << "起飞地点" << setw(15) << "起飞时间" << setw(15) << "降落地点" << setw(15) << "降落时间" << setw(10) << "票价" << setw(10) << "剩余票数" << endl;
				f->disp();
				break;
			}
		case 4:
			cout << std::left << setw(15) << "航班号" << setw(20) << "最大载客量" << setw(15) << "起飞地点" << setw(15) << "起飞时间" << setw(15) << "降落地点" << setw(15) << "降落时间" << setw(10) << "票价" << setw(10) << "剩余票数" << endl;
			FlightDB.Disp_Flight();
		}
	}

}

/*删除函数*/
void main_menu::del()
{
	system("cls");
	char tmp1[999];//时间记录数组
	FILE* fp = fopen("change_list.txt", "a+");//以继续写入的方式打开change_list.txt文件
	char flight_id[100];
	cout << "请输入需删除的航班号：" << endl;
	cin >> flight_id;
	if (strlen(flight_id) > 5)
	{
		cout << "请输入正确的航班号！" << endl;
		_getch();
	}
	else
	{
		f = FlightDB.inquire_by_Id(flight_id);
		if (f == NULL)
		{
			cout << "无此航班！无法删除！" << endl;
			delete[] f;//释放内存
			_getch();
		}
		else
		{
			if (f->Del() == 1)
			{
				cout << "删除成功!" << endl;
				time_t timep;
				time(&timep);
				strftime(tmp1, sizeof(tmp1), "%Y-%m-%d-%H:%M:%S", localtime(&timep));
				fprintf(fp, "删除航班->%s %d %s %s %s %s %lf %d %d %s", f->get_flight_Id(), f->get_max_cup(), f->get_dep_place(), f->get_dep_time(), f->get_land_place(), f->get_land_time(), f->get_price(), f->get_flag1(), f->get_ticket_num(), tmp1);
				fprintf(fp, "\n");
				_getch();
			}
		}
	}
}

/*修改函数*/
void main_menu::change()
{
	system("cls");
	char tmp2[999];//时间数组
	FILE* fp = fopen("change_list.txt", "a+");
	int Max_cap;//最大载客数
	char Dep_place[20];//起飞地点
	char Dep_time[10];//起飞时间
	char Land_place[20];//降落地点
	char land_time[10];//降落时间
	double price; //票价
	int ticket_num;//票数
	char flight_id[100];//航班号
	int chose_num = 1;
	char ch;
	cout << "请输入需修改的航班号：" << endl;
	cin >> flight_id;
	if (strlen(flight_id) > 5)
	{
		cout << "请输入正确的航班号！" << endl;
		_getch();
	}
	else
	{
		f = FlightDB.inquire_by_Id(flight_id);
		if (f == NULL)
		{
			cout << "无此航班！无法修改！" << endl;
			delete[] f;//释放内存
			_getch();
		}
		else
		{
			cout << "该航班的信息是：" << endl;
			cout << std::left << setw(15) << "航班号" << setw(20) << "最大载客量" << setw(15) << "起飞地点" << setw(15) << "起飞时间" << setw(15) << "降落地点" << setw(15) << "降落时间" << setw(10) << "票价" << setw(10) << "剩余票数" << endl;
			f->disp();
			cout << "是否确定修改?(Y/N)" << endl;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				while (chose_num != 0)
				{
					cout << "-------------------------------------\n";
					cout << "$         请选择修改的数据：        $\n";
					cout << "$          1.航班号                 $\n";
					cout << "$          2.最大载客量             $\n";
					cout << "$          3.起飞地点               $\n";
					cout << "$          4.起飞时间               $\n";
					cout << "$          5.降落地点               $\n";
					cout << "$          6.降落时间               $\n";
					cout << "$          7.票价                   $\n";
					cout << "$          8.剩余票数               $\n";
					cout << "$          0.返回                   $\n";
					cout << "-------------------------------------\n";
					cout << "请输入你选择：";
					cin >> chose_num;
					switch (chose_num)
					{
					case 1:
						cout << "请输入新的航班号:";
						cin >> flight_id;
						f->set_flight_Id(flight_id);
						break;
					case 2:
						cout << "请输入新的最大载客量:";
						cin >> Max_cap;
						f->set_max_cap(Max_cap);
						break;
					case 3:
						cout << "请输入新的起飞地点:";
						cin >> Dep_place;
						f->set_dep_place(Dep_place);
						break;
					case 4:
						cout << "请输入新起飞时间:";
						cin >> Dep_time;
						f->set_dep_time(Dep_time);
						break;
					case 5:
						cout << "请输入新降落地点:";
						cin >> Land_place;
						f->set_land_place(Land_place);
						break;
					case 6:
						cout << "请输入新降落时间:";
						cin >> land_time;
						f->set_land_time(land_time);
						break;
					case 7:
						cout << "请输入新的票价:";
						cin >> price;
						f->set_price(price);
						break;
					case 8:
						cout << "请输入新的剩余票数:";
						cin >> ticket_num;
						f->set_ticket_num(ticket_num);
						break;
					}
				}
				cout << "修改成功！" << endl;
				time_t timep;
				time(&timep);/*获取time_t类型的当前时间*/
				strftime(tmp2, sizeof(tmp2), "%Y-%m-%d-%H:%M:%S", localtime(&timep));
				fprintf(fp, "修改航班->%s %d %s %s %s %s %lf %d %d %s", f->get_flight_Id(), f->get_max_cup(), f->get_dep_place(), f->get_dep_time(), f->get_land_place(), f->get_land_time(), f->get_price(), f->get_flag1(), f->get_ticket_num(), tmp2);
				fprintf(fp, "\n");
				_getch();
			}
		}
	}
}

/*新增函数*/
void main_menu::add()
{
	system("cls");
	int Max_cap;//最大载客数
	char Dep_place[20];//起飞地点
	char Dep_time[20];//起飞时间
	char Land_place[20];//降落地点
	char land_time[20];//降落时间
	double price; //票价
	int ticket_num;//票数
	char flight_id[100];//航班号
	cout << "请输入航班号" << endl;
	cin >> flight_id;
	if (strlen(flight_id) > 5)
	{
		cout << "请输入正确的航班号！" << endl;
		_getch();
	}
	else
	{
		f = FlightDB.inquire_by_Id(flight_id);
		if (f != NULL)
		{
			cout << "已存在此航班！无法添加！" << endl;
			delete[] f;
			_getch();
		}
		else
		{
			cout << "无此航班，请输入相关信息以添加航班" << endl;
			cout << "请输入航班号:";
			cin >> flight_id;
			cout << "请输入最大载客量:";
			cin >> Max_cap;
			cout << "请输入起飞地点:";
			cin >> Dep_place;
			cout << "请输入起飞时间:";
			cin >> Dep_time;
			cout << "请输入降落地点:";
			cin >> Land_place;
			cout << "请输入降落时间:";
			cin >> land_time;
			cout << "请输入票价:";
			cin >> price;
			cout << "请输入剩余票数:";
			cin >> ticket_num;
			FlightDB.Add_Flight(flight_id, Max_cap, Dep_place, Dep_time, Land_place, land_time, price, ticket_num);
			cout << "添加成功" << endl;
			_getch();
		}
	}
}

/*订票函数*/
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
	cout << "以下为所有航班:" << endl;
	cout << std::left << setw(15) << "航班号" << setw(20) << "最大载客量" << setw(15) << "起飞地点" << setw(15) << "起飞时间" << setw(15) << "降落地点" << setw(15) << "降落时间" << setw(10) << "票价" << setw(10) << "剩余票数" << endl;
	FlightDB.Disp_Flight();
	cout << "请输入乘客身份证号以订票：" << endl;
	cin >> passenger_id;
	r = PassengerDB.Inquire_by_Id(passenger_id);
	if (r == NULL)//添加新乘客再订票
	{
		cout << "无此乘客！" << endl;
		add_passenger();
		r = PassengerDB.inquire_last();//找到最后一个新添加的乘客，即最后一个乘客
		cout << "请输入航班号、起飞地点、起飞时间、降落地点以定航班" << endl;
		cin >> flight_id >> dep_place >> dep_time >> land_place;

		f = FlightDB.inquire_by_Id(flight_id);//通过航班号查找航班，找到则能订票，反之订不了
		if (f == NULL)
		{
			cout << "无此航班！无法订票！" << endl;
			delete[] f;
			_getch();
		}
		else
		{
			cout << "已找到该航班，该航班剩余" << f->get_ticket_num() << "张票！" << endl;
			if (f->get_ticket_num() < 0)
			{
				cout << "航班票数不足，无法订票！" << endl;
				_getch();
			}
			else
			{
				char a[20];
				strcpy(a, f->get_flight_Id());
				r->set_Flight_Id(a);
				f->book();
				count++;
				strcpy(seat_num, seat_num_allocate(count));//调用座位条件函数分配座位
				r->book();
				r->set_Seat_num(seat_num);
				cout << "你的座位号为" << seat_num << endl;
				cout << "订票成功！" << endl;
				cout << "请缴纳费用" << f->get_price() << "元" << endl;
				_getch();
			}
		}
	}

	else//直接订票
	{
		if (r->get_ticket_num() != 0)
		{
			cout << "该乘客已订票，无法再订！" << endl;
			cout << "重新订票或退出订票？(Y/N)" << endl;
			cin >> chose_str;
			if (chose_str == "Y")
			{
				book();
			}
		}
		else
		{
			cout << "请输入航班号、起飞地点、起飞时间、降落地点以定航班" << endl;
			cin >> flight_id >> dep_place >> dep_time >> land_place;
			f = FlightDB.inquire_by_Id(flight_id);
			if (f == NULL)
			{
				cout << "无此航班！无法订票！" << endl;
				_getch();
			}
			else
			{
				cout << "已找到该航班，该航班剩余" << f->get_ticket_num() << "张票！" << endl;
				if (f->get_ticket_num() < 0)
				{
					cout << "航班票数不足，无法订票！" << endl;
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
					cout << "你的座位号为" << seat_num << endl;
					cout << "订票成功！" << endl;
					cout << "请缴纳费用" << f->get_price() << "元" << endl;
					_getch();
				}
			}
		}
	}

}

/*座位号分配函数*/
char* main_menu::seat_num_allocate(int num)
{
	int row = num / 6;//行名(以A,B,C,D,E,F.....代表)
	int rol = num % 6;//列名(以1,2,3,4,5.....代表)
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

/*座位号行分配函数*/
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

/*座位号列分配函数*/
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

/*添加乘客函数*/
void main_menu::add_passenger()
{
	char Flight_Id[20];//航班号 0代表未定
	char Id[20];//身份证号
	char Name[20];//姓名
	char Sex[20];//性别
	char Birthday[20];//出生年月
	char Seat_num[20];//座位号 0代表未定
	int P_ticket_num;//订票标记 >=1已定 0:未定
	cout << "输入乘客相关信息以添加乘客" << endl;
	cout << "请输入身份证号：";
	cin >> Id;
	cout << "请输入姓名：";
	cin >> Name;
	cout << "请输入性别：";
	cin >> Sex;
	cout << "请输入出生年月：";
	cin >> Birthday;
	PassengerDB.Add(Id, Name, Sex, Birthday);
}

/*管理员界面*/
void main_menu::admin()
{
	cout << "*************************************\n";
	cout << "$         管理员操作系统            $\n";
	cout << "-------------------------------------\n";
	cout << "$         请输入操作项目 ：         $\n";
	cout << "$          1:查 找 航 班            $\n";
	cout << "$          2:删 除 航 班            $\n";
	cout << "$          3:修 改 航 班            $\n";
	cout << "$          4:添 加 航 班            $\n";
	cout << "$          5:查 看 乘 客 数 据      $\n";
	cout << "$          6:查 看 待 取 消 的 航 班$\n";
	cout << "$          7:修 改 登 录 密 码      $\n";
	cout << "$          0:退 出                  $\n";
	cout << "-------------------------------------\n";
}

/*乘客界面*/
void main_menu::user()
{
	cout << "*************************************\n";
	cout << "$      航班信息查询和检索系统       $\n";
	cout << "-------------------------------------\n";
	cout << "$         请选择操作 :              $\n";
	cout << "$         1.查 询 航 班             $\n";
	cout << "$         2.订 票                   $\n";
	cout << "$         0:退 出 系 统             $\n";
	cout << "-------------------------------------\n";
}

/*设置登录密码*/
void main_menu::set_password(char new_password[])
{
	strcpy(password, new_password);
}

/*修改管理员密码函数*/
void main_menu::change_password()
{
	system("cls");
	char new_password[100];
	cout << "请输入新的密码：";
	cin >> new_password;
	b1.set_password(new_password);
	cout << "修改成功！"<<endl;
	_getch();
	b1.login();
}