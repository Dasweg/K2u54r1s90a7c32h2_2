#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <math.h>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <regex>
#include <limits>
#include <windows.h>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

FILE *fl;
typedef struct
{
	char fio[100];
	int group;
	int bal;
	int income;
	string social_work;
} TStudent;

FILE *flAc;
typedef struct
{
	char login[50];
	char password[50];
} TUsers;

TStudent stud[30]; // Массив структур
TUsers users[30]; // Массив учетных записей

regex regular("^[A-Za-z][0-9]{6}$");
char name_file_value[20] = {"Initial value"}; // Имя файла FilesForRecordAccounts
char fileRecAc[40] = { "FilesForRecordAccounts" };
string arr[2] = {"да", "нет"};
string fio[17] = { 
	"Сергеев Анатолий Евгеньевич", 
	"Кузнецов Пётр Андреевич", 
	"Попова Ирина Михайловна", 
	"Васнецова Маргарита Лютая", 
	"Адов Ра Изов", 
	"Сон Джин Ву", 
	"Борый Дмитрий Иванович", 
	"Серьезный Эхо Петрович", 
	"Лапушкин Андрей Хирасенко", 
	"Воинский Андрей Ярославович",
	"Чи Хаен Ки",
	"Го Гун Хи",
	"Восставший Андрей Злобин", 
	"Пусько Петр Петрович", 
	"Андреев Андрей Иванович", 
	"Харизмов Никита Романюк", 
	"Пестров Владислав Великий" };
int nst = 0; // Число введенных структур
int nut = 0; // Кол-во уч. записей
int sel = 0;
int sel_2 = 0;
int selSearch = 0;

int menu_user(); // Меню User
int menu_ADmin(); // Меню Admin

void sinQuest(); // Индивидуальнок задание

void newFile(); // Ручной список
void autoGenerList(); // Автоматический список

void editStudent(); // Редактирование записи студента 
void addStudent(); // Добавление студента в список
void delStudent(); // Удаление студента из списка
void spisok(); // Список
void sort(); // Cортировки
void sortFio(TStudent std); // Сортировка ФИО
void sortGroup(TStudent std); // Сортировка Группы
void sortBal(TStudent std); // Сортировка Среднего бала
void search(); // Поиск
void impFile(); // Импортирование данных

void controlUserAccount(); // уч. записи пользователя
void spisokAccount(); // список уч. записей пользователя
void showAllDataUsers(); // показать все уч. записи пользователя
void addAccountUser(); // добавление новой уч. записи пользователя
void delAccountUser(); // удаление уч. записи пользователя

void autorization();// вход в уч. запись

void autorization() 
{
	string login;
	string password;
	string str1 = "----------";

	while (true)
	{
		system("cls");
		cout << "--------------------------------------------------------------\n\t\t***Авторизация***\n--------------------------------------------------------------\n\n";
		cout << "--------------------------------------------------------------\n";
		cout << "Логин: ";
		cin >> login;
		cout << "Пароль: ";
		cin >> password;
		cout << "--------------------------------------------------------------\n";
		if (login == "Admin" && password == "1111") {
			
			for (int sec = 0;; sec++)
			{
				Sleep(470);
				string str2 = str1.substr(0, str1.length() - sec);
				system("cls"); cout << str2;
				if (sec == 10)
				{
					system("cls");
					menu_ADmin();
				}
			}
		}
		else if (login == "User") {
			for (int sec = 0;; sec++)
			{
				Sleep(470);
				string str2 = str1.substr(0, str1.length() - sec);
				system("cls"); cout << str2;
				if (sec == 10)
				{
					system("cls");
					menu_user();
				}
			}
		}
		else
		{
			cout << "\nНеверно введен пароль/логин. Попробуйте еще раз.\n";
			system("pause");
		}
	}
}

int menu_ADmin() // Меню Админа
{
	system("cls");
	cout << "--------------------------------------------------------------\n\t\t***ADmin***\n--------------------------------------------------------------\n\n";
	cout << "--------------------------------------------------------------\n";
	cout << "Выберите:\n1. Управление учетными записями пользователей\n2. Редактирование данных структуры";
	cout << "\n--------------------------------------------------------------\n\n";
	cout << "--------------------------------------------------------------\n";
	int i;
	cout << "Введите команду: "; cin >> i;
	cout << "--------------------------------------------------------------\n";
	if (i > 0 && i < 4)
	{
		for (int sec = 0;; sec++)
		{
			Sleep(470);
			if (sec == 1)
			{
				switch(i)
				{
					case 1: controlUserAccount(); break;
					case 2: break;	
					case 3: exit(1); break;
				}
			}
		}
	}
	else
	{
		cout << "Данные введены не верно! попробуйте еще раз.\n";
		system("pause");
		menu_ADmin();
	}
}

void controlUserAccount() { // управление уч. записями 
	system("cls");
	
	cout << "--------------------------------------------------------------\n\t\t***ADmin control User's***\n--------------------------------------------------------------\n\n";
	cout << "--------------------------------------------------------------\n";
	cout << "Выберите:\n1. Просмотр всех учетных записей\n2. Добавление новой учетной записи\n3. Редактирование учетной записи\n4. Удаление учетной записи\n5. Перейти к авторизации";
	cout << "\n--------------------------------------------------------------\n\n";
	cout << "--------------------------------------------------------------\n";
	cout << "Введите команду: "; cin >> sel;
	cout << "--------------------------------------------------------------\n";
	if (sel > 0 & sel < 6)
	{
		for (int sec = 0;; sec++)
		{
			Sleep(470);
			if (sec == 1)
			{
				switch (sel)
				{
					case 1: showAllDataUsers(); break;
					case 2: addAccountUser(); break;
					case 3:  break;
					case 4: delAccountUser(); break;
					case 5: autorization(); break;
					case 6: exit(1); break;
				}
			}
		}
	}
	else
	{
		cout << "Данные введены не верно! Попробуйте еще раз.\n";
		system("pause");
		controlUserAccount();
	}
}

void addAccountUser() { // Добавление уч. записи
	system("cls");
	nut = 0;
	if (flAc = fopen(fileRecAc, "r"))  
	{
		while (fread(&users[nut], sizeof(TUsers), 1, flAc) > 0) {
			nut++;
		}
		fclose(flAc);
	}
	
	cout << nut << endl;

	cout << "----------------------------------------------------------------------------\n\t\t***Список учетных записей***\n----------------------------------------------------------------------------\n\n";
	cout << "|---------------------------------|\n|  \tЛогин\t  |  \tПароль\t  |\n|---------------------------------|\n";
	for (int i = 0; i < nut; i++) {
		cout << "| " << setw(14) << users[i].login << setw(4) << " | " << setw(10) << users[i].password << setw(6) << " |\n";
	}
	cout << "|---------------------------------|\n";

	cout << "\t\t***Добавление уч. записи***\n\n";
	if (nut < sizeof(users)) {
		cout << "\n--------------------------------------------------------------\n";
		cout << "Логин новой уч. записи: ";
		cin >> users[nut].login;

		cout << "Пароль(6 символов) новой уч. записи: ";
		cin >> users[nut].password;
		//if (regex_match(users[nut].password, regular)) { //регулярное для char*
		//	break;
		//}
		cout << "--------------------------------------------------------------\n";
		nut++;
	}
	else { cout << "Недостаточно памяти для добавления нового элемента!" << endl; }
	
	system("cls");
	cout << "----------------------------------------------------------------------------\n\t\t***Список учетных записей***\n----------------------------------------------------------------------------\n\n";
	cout << "|---------------------------------|\n|  \tЛогин\t  |  \tПароль\t  |\n|---------------------------------|\n";
	for (int i = 0; i < nut; i++) {
		cout << "| " << setw(14) << users[i].login << setw(4) << " | " << setw(10) << users[i].password << setw(6) << " |\n";
	}
	cout << "|---------------------------------|\n";

	if (flAc = fopen(fileRecAc, "r+")) {
		fseek(flAc, 0, SEEK_END);
		fwrite(&users[nut - 1], sizeof(TUsers), 1, flAc);
		fclose(flAc);
	}
	else
	{
		cout << "Not open for write";
	}
	system("pause");
	controlUserAccount();
}

void delAccountUser() { // удаление уч. записи
	system("cls");
	int numDelAc;
	char switchNum;
	if ((flAc = fopen(fileRecAc, "wb")) == NULL)
	{
		cout << "Ошибка при создании файла" << endl;
		exit(1);
	}
	fclose(flAc);
	if ((flAc = fopen(fileRecAc, "rb+")) == NULL)
	{
		cout << "Ошибка при создании" << endl;
		exit(1);
	}
	cout << "\t\t***Удаление записи***\n\n";
	cout << "Номер удаляемой уч. записи: ";
	cin >> numDelAc;
	numDelAc--;
	if (numDelAc >= 0 && numDelAc < nut)
	{
		cout << "Вы действительно хотите удалить эту уч. запись (y/n = д/н)? ";
		cin >> switchNum;
		if (switchNum == 'y' || switchNum == 'д') {
			for (int i = numDelAc; i < nut - 1; i++)
				users[i] = users[i + 1];
			nut--;
			cout << "\nРезультат удаления\n";
			spisokAccount();
			fclose(flAc);
			system("pause");
			controlUserAccount();
		}
		else if (switchNum == 'n' || switchNum == 'н') {
			cout << "Вы вернетесь в главное меню\n";
			system("pause");
			controlUserAccount();
		}
		else
		{
			cout << "Такой операции не существует! Попробуйте еще раз.\n"; system("pause"); delAccountUser();
		}
	}
	else { cout << "Введен некорректный номер удалемой записи! Попробуйте еще раз.\n"; system("pause"); delAccountUser(); }
}

void showAllDataUsers() { // просмотр всех уч. записей
	system("cls");
	nut = 0;
	if (flAc = fopen(fileRecAc, "r"))
	{
		while (fread(&users[nut], sizeof(TUsers), 1, flAc) > 0) {
			nut++;
		}
		fclose(flAc);
	}

	cout << nut << endl;

	cout << "----------------------------------------------------------------------------\n\t\t***Список учетных записей***\n----------------------------------------------------------------------------\n\n";
	cout << "|---------------------------------|\n|  \tЛогин\t  |  \tПароль\t  |\n|---------------------------------|\n";
	for (int i = 0; i < nut; i++) {
		cout << "| " << setw(14) << users[i].login << setw(4) << " | " << setw(10) << users[i].password << setw(6) << " |\n";
	}
	cout << "|---------------------------------|\n";
	system("pause");
	controlUserAccount();
}

void spisokAccount() { // список всех уч. записей
	cout << "----------------------------------------------------------------------------\n\t\t***Список учетных записей***\n----------------------------------------------------------------------------\n\n";
	cout << "|---------------------------------|\n|  \tЛогин\t  |  \tПароль\t  |\n|---------------------------------|\n";
	for (int i = 0; i < nut; i++) {
		cout << "| " << setw(14) << users[i].login << setw(4) << " | " << setw(10) << users[i].password << setw(6) << " |\n";
		fwrite(&users[i], sizeof(TUsers), 1, flAc);
	}
	cout << "|---------------------------------|\n";
}

int menu_user() // Меню Пользователя
{
	system("cls");
	cout << "***User***\n\n";
	cout << "Выберите:\n1. Ввод списка и сохранение в файл" << endl;//complete
	cout << "2. Импортирование данных из файла" << endl;
	cout << "3. Cортировка списка" << endl;
	cout << "4. Поиск по списку" << endl;
	cout << "5. Просмотр списка зачисленных в общежитие" << endl;
	cout << "6. Справка" << endl;
	cout << "7. Вернуться к авторизации" << endl;//complete
	cout << "8. Выход" << endl << endl;//complete
	int i;
	cout << "Введите команду: "; cin >> i;
	if (i > 0 && i < 11)
	{
		switch (i)
		{
		case 1: system("cls");
			cout << "Выберите тип формирования списка:\n1) Автоматически (рекомендуется)\n2) Вручную\n\nВведите команду: ";
			cin >> sel;
			switch (sel)
			{
				case 1: autoGenerList(); break;
				case 2: newFile(); break;
			}
			break;
		case 2: impFile(); break;
		case 3: sort(); break;
		case 4: search(); break; 
		case 5: addStudent(); break;
		case 6: delStudent(); break;
		case 7: sinQuest(); break;
		case 8: editStudent(); break;
		case 9: autorization(); break;
		case 10: exit(0);
		}
	}
	else
	{
		cout << "Данные введены не верно! Попробуйте еще раз.\n";
		system("pause");
		menu_user();
	}
}

void autoGenerList() //автоматический список
{
	system("cls");
	if ((fl = fopen(name_file_value, "wb")) == NULL)
	{
		cout << "Ошибка при создании файла" << endl;
		exit(1);
	}
	cout << "--------------------------------------------------------------\n";
	cout << "Список будет выгружен в файл Initial value" << endl;
	cout << "--------------------------------------------------------------\n";
	fclose(fl);
	for (int sec = 0;; sec++)
	{
		Sleep(470);
		if (sec == 4)
		{
			system("cls");
			break;
		}
	}
	if ((fl = fopen(name_file_value, "rb+")) == NULL)
	{
		cout << "Ошибка при создании" << endl;
		exit(1);
	}
	cout << "--------------------------------------------------------------\n";
	cout << "\t\t***Список студентов***" << endl;
	cout << "--------------------------------------------------------------\n\n--------------------------------------------------------------\n";
	srand(time(0));
	nst = 3 + rand() % (10 - 3);// min + rand() % (max - min);
	cout << "Всего студентов: " << nst << endl;
	cout << "--------------------------------------------------------------\n";
	for (int i = 0; i < nst; i++)
	{
		cout << "\n--------------------------------------------------------------\n";
		strcpy(stud[i].fio, fio[rand() % 17].c_str());//преобразование string в char* 
		cout << "ФИО студента: " << stud[i].fio << endl;//рандомно вписывается ФИО из Массива string
		stud[i].group = 100000 + rand() % (999999 - 100000);
		cout << "Группа(шесть цифр): " << stud[i].group << endl;//рандомно вписывается шесть цифр
		stud[i].bal = 4 + rand() % (9 - 4);
		cout << "Средний балл: " << stud[i].bal << endl;//рандомно вписывается число 4-9
		stud[i].income = 300 + rand() % (2000 - 300);
		cout << "Доход на члена семьи: " << stud[i].income << ",00р.\n";//рандомно вписывается 3-4 числа
		stud[i].social_work = arr[rand() % 2];
		cout << "Участие в общественной деятельности(да/нет): " << stud[i].social_work << endl;//рандомно вписывается да/нет
		cout << "--------------------------------------------------------------\n";
		fwrite(&stud[i], sizeof(TStudent), 1, fl);
	}
	fclose(fl);
	system("pause");
	menu_user();
}

void newFile() //Ручной способ ввода списка
{
	system("cls");
	if ((fl = fopen(name_file_value, "wb")) == NULL)
	{
		cout << "Ошибка при создании файла" << endl;
		exit(1);
	}
	cout << "--------------------------------------------------------------\n";
	cout << "Список будет выгружен в файл Initial value" << endl;
	cout << "--------------------------------------------------------------\n";
	fclose(fl);
	for (int sec = 0;; sec++)
	{
		Sleep(470);
		if (sec == 6)
		{
			system("cls");
			break;
		}
	}
	if ((fl = fopen(name_file_value, "rb+")) == NULL)
	{
		cout << "Ошибка при создании" << endl;
		exit(1);
	}
	cout << "--------------------------------------------------------------\n";
	cout << "\t\t***Список студентов***" << endl;
	cout << "--------------------------------------------------------------\n\n--------------------------------------------------------------\n";
	cout << "Всего студентов: ";
	cin >> nst;
	cout << "--------------------------------------------------------------\n";
	for (int i = 0; i < nst; i++)
	{
		cout << "\n--------------------------------------------------------------\n";
		cout << "ФИО студента: ";
		cin.getline(stud[i].fio, sizeof(stud[i].fio));
		cin.get(stud[i].fio, sizeof(stud[i].fio));
		while (true)
		{
			cout << "Группа(шесть цифр): ";
			cin >> stud[i].group;
				if (stud[i].group > 99999 && stud[i].group < 1000000) {
					break;
				}
		}
		/*if(!(regex_match(stud[i].group, regular))){//регулярные для char*
			goto repeat1;
		}*/
		while (true)
		{
			cout << "Средний балл: ";
			cin >> stud[i].bal;
			if (stud[i].bal > 0) {
				if (stud[i].bal < 10) {
					break;
				}
			}
		}
		cout << "Доход на члена семьи: ";
		cin >> stud[i].income; 
		cout << "\033[F"; 
		cout << "Доход на члена семьи: " << stud[i].income << ",00р.\n";
		while (true)
		{
			cout << "Участие в общественной деятельности(да/нет): ";
			cin >> stud[i].social_work;
			if (stud[i].social_work != "да") {
				if (stud[i].social_work != "нет") {
					break;
				}
			}
		}
		cout << "--------------------------------------------------------------\n";
		fwrite(&stud[i], sizeof(TStudent), 1, fl);
	}
	fclose(fl);
	system("pause");
	menu_user();
}

void editStudent() { // Рдактирование записи студента (и обновление файла со структурой)
	int numDelItem;
	char switchRes;
	system("cls");
	cout << "\t\t***Редактирование записи о студенте***\n\n";
	cout << "Введите номер записи для редактирования: ";
	cin >> numDelItem;
	numDelItem--;
	if (numDelItem >= 0 && numDelItem < nst)
	{
		cout << "Вы действительно хотите изменить данные этой записи (y/n = д/н)? ";
		cin >> switchRes;
		if (switchRes == 'y' || switchRes == 'д') {
			if ((fl = fopen(name_file_value, "rb+")) == NULL)
			{
				cout << "Ошибка при создании" << endl;
				exit(1);
			}
			cout << "ФИО студента: ";
			cin.getline(stud[numDelItem].fio, sizeof(stud[numDelItem].fio));
			cin.get(stud[numDelItem].fio, sizeof(stud[numDelItem].fio));
			cout << "Группа(шесть цифр): ";
			cin >> stud[numDelItem].group;
			cout << "Средний балл: ";
			cin >> stud[numDelItem].bal;
			cout << "Доход на члена семьи: ";
			cin >> stud[numDelItem].income;
			cout << "\033[F";
			cout << "Доход на члена семьи: " << stud[numDelItem].income << ",00р.\n";
			cout << "Участие в общественной деятельности(да/нет): ";
			cin >> stud[numDelItem].social_work;// запись изменена
			spisok();// вывод
			system("pause");
			fclose(fl);
			menu_user();
		}
		else if (switchRes == 'n' || switchRes == 'н') {
			cout << "Вы вернетесь в главное меню\n";
			system("pause");
			menu_user();
		}
		else
		{
			cout << "Такой операции не существует! Попробуйте еще раз.\n"; system("pause"); delStudent();
		}
	}
	else { cout << "Введен некорректный номер записи! Попробуйте еще раз.\n"; system("pause"); delStudent(); }
}

void addStudent() { // Добавление элемента структуры
	system("cls");
	cout << "\t\t***Добавление записи***\n\n";
	if (nst + 1 <= 30) {
		nst++;
		cout << "ФИО студента: ";
		cin.getline(stud[nst - 1].fio, sizeof(stud[nst - 1].fio));// первый элемент до пробела не выводит, а последующие выводит
		cin.get(stud[nst - 1].fio, sizeof(stud[nst - 1].fio));// эмм, все выводит, но без понятия как это работает?
		cout << "Группа(шесть цифр): ";
		cin >> stud[nst - 1].group;
		cout << "Средний балл: ";
		cin >> stud[nst-1].bal;
		cout << "Доход на члена семьи: ";
		cin >> stud[nst-1].income;
		cout << "\033[F";
		cout << "Доход на члена семьи: " << stud[nst-1].income << ",00р.\n";
		cout << "Участие в общественной деятельности(да/нет): ";
		cin >> stud[nst-1].social_work;
	}
	else { cout << "Недостаточно памяти для добавления нового элемента!" << endl; }
	spisok();
	system("pause");
	menu_user();
}

void delStudent() { // Удаление элемента из структуры
	system("cls");
	int numDelItem;
	char switchRes;
	cout << "\t\t***Удаление записи***\n\n";
	cout << "Введите номер удаляемой записи: ";
	cin >> numDelItem;
	numDelItem--;
	if (numDelItem >= 0 && numDelItem < nst)
	{
		cout << "Вы действительно хотите удалить эту запись (y/n = д/н)? ";
		cin >> switchRes;
		if (switchRes == 'y' || switchRes == 'д') {
			for (int i = numDelItem; i < nst - 1; i++)
				stud[i] = stud[i + 1];
			nst--;
			cout << "\nРезультат удаления\n";
			spisok();
			system("pause");
			menu_user();
		}
		else if (switchRes == 'n' || switchRes == 'н') {
			cout << "Вы вернетесь в главное меню\n";
			system("pause");
			menu_user();
		}
		else
		{
			cout << "Такой операции не существует! Попробуйте еще раз.\n"; system("pause"); delStudent();
		}
	}
	else { cout << "Введен некорректный номер удалемой записи! Попробуйте еще раз.\n"; system("pause"); delStudent(); }
}

void impFile() // Импортированный список из файла (в виде таблицы)
{
	system("cls");
	if ((fl = fopen(name_file_value, "rb")) == NULL)
	{
		cout << "Ошибка при открытии" << endl;
		exit(1);
	}
	nst = 0; TStudent std;
	cout << "\n\t\t\t\t***Список студентов в общежитие***\n\n";
	cout << "|---------------------------------------------------------------------------------------------------------|\n|  \t\tФИО\t\t  | Группа | Средний бал |  Доход   | Участие в общественной деятельности |\n|---------------------------------------------------------------------------------------------------------|\n";
	
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;
		cout << "| " << setw(30) << stud[nst].fio << setw(4) <<" | " << stud[nst].group << " | " << setw(6) << stud[nst].bal << setw(8) << " | " << setw(5) << stud[nst].income << setw(6) << " | " << setw(19) << stud[nst].social_work << setw(19) << " |\n";
		nst++;
	}
	cout << "|---------------------------------------------------------------------------------------------------------|\n";
	fclose(fl);
	system("pause");
	menu_user();
}

void sinQuest() { // Индивидуально задание
	TStudent std;
	int minPay;
	system("cls");
	cout << "Введите минимальную зарплату: "; cin >> minPay;
	cout << "\033[F";
	cout << "Введите минимальную зарплату: " << minPay << ",00р.";
	cout << "\n\t\t\t\t***Список студентов в общежитии***\n\n";
	cout << "|---------------------------------------------------------------------------------------------------------|\n|  \t\tФИО\t\t  | Группа | Средний бал |  Доход   | Участие в общественной деятельности |\n|---------------------------------------------------------------------------------------------------------|\n";
	
	for (int i = nst - 1; i >= 0; i--)// сорт по доходам ...
	{
		for (int j = 0; j < i; j++)
		{
			if (stud[j].income > stud[j + 1].income)
			{
				std = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = std;
			}
		}
	}

	for (int i = 0; i < nst; i++) {
		if (stud[i].income < 2 * minPay) { // и поиск по доходам меньших 2-ух мин. зп.
			cout << "| " << setw(30) << stud[i].fio << setw(4) << " | " << stud[i].group << " | " << setw(6) << stud[i].bal << setw(8) << " | " << setw(5) << stud[i].income << setw(6) << " | " << setw(19) << stud[i].social_work << setw(19) << " |\n";
		}
	}

	for (int i = nst - 1; i >= 0; i--)// сорт по возрастанию среднему балу ...
	{
		for (int j = 0; j < i; j++)
		{
			if (stud[j].bal < stud[j + 1].bal)
			{
				std = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = std;
			}
		}
	}

	for (int i = 0; i < nst; i++) {
		if (stud[i].income > 2 * minPay) { // и поиск по доходам больших 2-ух мин. зп.
			cout << "| " << setw(30) << stud[i].fio << setw(4) << " | " << stud[i].group << " | " << setw(6) << stud[i].bal << setw(8) << " | " << setw(5) << stud[i].income << setw(6) << " | " << setw(19) << stud[i].social_work << setw(19) << " |\n";
		}
	}

	cout << "|---------------------------------------------------------------------------------------------------------|\n\n";
	system("pause");
	search();
}

void spisok() { // Список
	cout << "\n\t\t\t\t***Список студентов в общежитие***\n\n";
	cout << "|---------------------------------------------------------------------------------------------------------|\n|  \t\tФИО\t\t  | Группа | Средний бал |  Доход   | Участие в общественной деятельности |\n|---------------------------------------------------------------------------------------------------------|\n";
	for (int i = 0; i < nst; i++) {
		cout << "| " << setw(30) << stud[i].fio << setw(4) << " | " << stud[i].group << " | " << setw(6) << stud[i].bal << setw(8) << " | " << setw(5) << stud[i].income << setw(6) << " | " << setw(19) << stud[i].social_work << setw(19) << " |\n";
	}
	cout << "|---------------------------------------------------------------------------------------------------------|\n\n";
}

void sortFio(TStudent std) { // Сортировка ФИО
	system("cls");
	for (int i = 0; i <= nst; i++)
	{
		for (int j = nst - 1; j > i; j--)
		{
			if (strcmp(stud[j].fio, stud[j - 1].fio) < 0)
			{
				std = stud[j];
				stud[j] = stud[j - 1];
				stud[j - 1] = std;
			}
		}
	}
	spisok();
	system("pause");
	sort();
}

void sortGroup(TStudent std) { // Сортировка Группы
	system("cls");
	for (int i = nst - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (stud[j].group > stud[j + 1].group)
			{
				std = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = std;
			}
		}
	}
	spisok();
	system("pause");
	sort();
}

void sortBal(TStudent std) { // Сортировка Средний бал
	system("cls");
	for (int i = nst - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (stud[j].bal > stud[j + 1].bal)
			{
				std = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = std;
			}
		}
	}
	spisok();
	system("pause");
	sort();
}

void sort() { // сортировка по ФИО, Группе, Средниму балу
	system("cls");
	TStudent std;
	cout << "Выберите столбец сортировки:\n0) Выход в главное меню\n1) ФИО\n2) Группа\n3) Средний балл\n\nВведите команду: ";
	cin >> sel_2;
	if (sel_2 < 4 && sel_2 >= 0) {
		switch (sel_2)
		{
		case 0: menu_user();  break;// Выход
		case 1:	sortFio(std); break;// ФИО 
		case 2:	sortGroup(std);	break;// Группа
		case 3:	sortBal(std); break;// Средний балл
		}
	}
	else
	{
		cout << "Такой команды не существует! Попробуйте еще раз.\n";
		system("pause");
		sort();
	}
}

void search() { // Поиск
	system("cls");
	char name[50];
	int gr;
	int selViewSearch;
	int bal;
	int from;
	int to;
	TStudent std;
	cout << "Выберите столбец поиска:\n0) Выход в главное меню\n1) ФИО\n2) Группа\n3) Средний балл\n\nВведите команду: ";
	cin >> selSearch;
	switch (selSearch) {
		case 0: menu_user(); break;// Выход
		case 1: // ФИО
			system("cls");
			cout << "Введите ФИО для поиска: "; cin >> name;
			cout << "\n\t\t\t\t***Список студентов в общежитие***\n\n";
			cout << "|---------------------------------------------------------------------------------------------------------|\n|  \t\tФИО\t\t  | Группа | Средний бал |  Доход   | Участие в общественной деятельности |\n|---------------------------------------------------------------------------------------------------------|\n";
			for (int i = 0; i < nst; i++) {
				if (strstr(stud[i].fio, name) != NULL) { //сравнение двух переменных
					cout << "| " << setw(30) << stud[i].fio << setw(4) << " | " << stud[i].group << " | " << setw(6) << stud[i].bal << setw(8) << " | " << setw(5) << stud[i].income << setw(6) << " | " << setw(19) << stud[i].social_work << setw(19) << " |\n";
				}
			}
			cout << "|---------------------------------------------------------------------------------------------------------|\n\n";
			system("pause");
			search();
		break;
		case 2: // Группа
			system("cls");
			cout << "Введите Группу для поиска: "; cin >> gr;
			cout << "\n\t\t\t\t***Список студентов в общежитие***\n\n";
			cout << "|---------------------------------------------------------------------------------------------------------|\n|  \t\tФИО\t\t  | Группа | Средний бал |  Доход   | Участие в общественной деятельности |\n|---------------------------------------------------------------------------------------------------------|\n";
			for (int i = 0; i < nst; i++) {
				if ( gr == stud[i].group) {
					cout << "| " << setw(30) << stud[i].fio << setw(4) << " | " << stud[i].group << " | " << setw(6) << stud[i].bal << setw(8) << " | " << setw(5) << stud[i].income << setw(6) << " | " << setw(19) << stud[i].social_work << setw(19) << " |\n";
				}
			}
			cout << "|---------------------------------------------------------------------------------------------------------|\n\n";
			system("pause");
			search();
		break;
		case 3: // Средний бал
			while (true)// проверка 
			{
				system("cls");
				cout << "Выберите тип сортировки: \n1) По диапазону\n2) Одиночная\n\nВведите команду: "; cin >> selViewSearch;
				if (selViewSearch == 1) {
					break;
					cout << "Введите диапазон для поиска Среднего бала от ";
					cin >> from;
					cout << "\033[F";
					cout << "Введите диапазон для поиска Среднего бала от " << from << " до ";
					cin >> to;
					cout << "\033[F";
					cout << "Введите диапазон для поиска Среднего бала от " << from << " до " << to << ":";
					cout << "\n\t\t\t\t***Список студентов в общежитие***\n\n";
					cout << "|---------------------------------------------------------------------------------------------------------|\n|  \t\tФИО\t\t  | Группа | Средний бал |  Доход   | Участие в общественной деятельности |\n|---------------------------------------------------------------------------------------------------------|\n";
					for (int i = 0; i < nst; i++) {
						if (from <= stud[i].bal && to >= stud[i].bal) {
							cout << "| " << setw(30) << stud[i].fio << setw(4) << " | " << stud[i].group << " | " << setw(6) << stud[i].bal << setw(8) << " | " << setw(5) << stud[i].income << setw(6) << " | " << setw(19) << stud[i].social_work << setw(19) << " |\n";
						}
					}
					cout << "|---------------------------------------------------------------------------------------------------------|\n\n";
					system("pause");
					search();
				}
				else if (selViewSearch == 2) {
					break;
					cout << "Введите Средний бал для поиска: "; cin >> bal;
					cout << "\n\t\t\t\t***Список студентов в общежитие***\n\n";
					cout << "|---------------------------------------------------------------------------------------------------------|\n|  \t\tФИО\t\t  | Группа | Средний бал |  Доход   | Участие в общественной деятельности |\n|---------------------------------------------------------------------------------------------------------|\n";
					for (int i = 0; i < nst; i++) {
						if (bal == stud[i].bal) {
							cout << "| " << setw(30) << stud[i].fio << setw(4) << " | " << stud[i].group << " | " << setw(6) << stud[i].bal << setw(8) << " | " << setw(5) << stud[i].income << setw(6) << " | " << setw(19) << stud[i].social_work << setw(19) << " |\n";
						}
					}
					cout << "|---------------------------------------------------------------------------------------------------------|\n\n";
					system("pause");
					search();
				}
				else {
					cout << "Ошибка ввода! Попробуйте еще раз.\n"; system("pause");
				}
			}
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	autorization();
}