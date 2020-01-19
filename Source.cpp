#include <iostream>
#include <Windows.h>
#include <math.h>
#include <ctime>

using namespace std;

void addr(int *type_1,int *type_2) {
	
	int ch = rand() % 10 + 1;
	if (ch == 1) {
		*type_1 = 2;
		type_1++;
	}
	else {
		*type_1 = 1;
		type_1++;
	}
	ch = rand() % 10 + 1;
	if (ch == 1) {
		*type_2 = 2;
		type_2++;
	}
	else {
		*type_2 = 1;
		type_2++;
	}
	ch = rand() % 10 + 1;
	if (ch <= 2) {
		*type_1 = 5;
		type_1++;
	}
	else {
		*type_1 = 1;
		type_1++;
	}
	ch = rand() % 10 + 1;
	if (ch <= 2) {
		*type_2 = 5;
		type_2++;
	}
	else {
		*type_2 = 1;
		type_2++;
	}
	ch = rand() % 10 + 1;
	if (ch <= 4) {
		*type_1 = 10;
		type_1++;
	}
	else {
		*type_1 = 1;
		type_1++;
	}
	ch = rand() % 10 + 1;
	if (ch <= 4) {
		*type_2 = 10;
		type_2++;
	}
	else {
		*type_2 = 1;
		type_2++;
	}
}

void oper(int *operation) {
	int ch = rand() % 10 + 1;
	if (ch == 1) {
		*operation = 4;
		operation++;
	}
	else
	{
		*operation = 1;
		operation++;
	}
	ch = rand() % 10 + 1;
	if (ch <= 3) {
		*operation = 8;
		operation++;
	}
	else
	{
		*operation = 1;
		operation++;
	}
	ch = rand() % 10 + 1;
	if (ch <= 5) {
		*operation = 16;
		operation++;
	}
	else
	{
		*operation = 1;
		operation++;
	}
}

void print_type_2(int *type_2, int *ptype_2) {
	for (int i = 0; i < 3; i++) {
		ptype_2[i] = type_2[i];
	}
}

void gist(int counter, int *op) {
	for (int i = 0; i < counter; i++) {
		cout << i + 1 << ")";
		for (int j = 0; j < op[i]; j++) {
			cout << ".";
		}
		cout << endl;
	}
}

void gist_conv(int *res_t, int op) {
	for (int i = 0; i < 3; i++) {
		cout << "Stage:" << i + 1 << " ";
		switch (i) {
		case 0:
			break;
		case 1:
			cout << "    ";
			break;
		case 2:
			for (int i = 0; i < op; i++) {
				cout << "    ";
			}
			break;
		}
		for (int j = 0; j < res_t[i]; j++) {
			cout << "_/T\\";
		}
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	int counter = 0;
	int counter_cin = 0;
	cout << "How much times do you want to use conveyor?" << endl << "> ";
	cin >> counter_cin;
	int res_av = 0;
	int res = 0;
	int *gist_av = new int[counter_cin];
	int *res_t = new int[3]; //результат команды 
	int *ptype_2 = new int[3]; //адрес второго операнда 
	int *type_1 = new int[3]; //тип первого операнда
	int *type_2 = new int[3]; //тип второго операнда
	int *operation = new int[3]; //вычисление результата
	int stage = 0; //команда 
	int main_av = 0;
	int *buzy = new int [2]; //для поиска начала третей команды 
	int min = 0;

	while (counter != counter_cin) {
		addr(type_1, type_2);
		oper(operation);
		print_type_2(type_2, ptype_2);
		for (stage; stage < 3; stage++) {
			cout << "Stage number: " << stage << endl;
			res_t[stage] = 0;
			res_t[stage] += 1;
			res_t[stage] += type_1[stage];
			res_t[stage] += type_2[stage];
			if (stage != 2) {
				buzy[stage] = res_t[stage];
			}
			res_t[stage] += operation[stage];
			res_t[stage] += ptype_2[stage];
			if (stage == 2) {
				res_t[stage] += max(buzy[0],buzy[1]);
				min = max(buzy[0], buzy[1]);
			}
			cout << "Average time of stage: " << res_t[stage] << endl;

		}
		for (unsigned int i = 0; i < 3; ++i)
			res_av += res_t[i];

		res_av = res_av / 3;
		for (unsigned int i = 0; i < 3; ++i) {
			if (res < res_t[i]) {
				res = res_t[i];
				res += max(buzy[0], buzy[1]);
			}
		}
		cout << "Average time: " << res_av << endl;
		cout << "The general time: " << res << endl;
		gist_conv(res_t,min);
		gist_av[counter] = res;
		main_av += res;
		res_av = 0;
		res = 0;
		int res_t[3] = { 0, 0, 0 };
		int ptype_2[3] = { 0, 0, 0 };
		int type_1[3] = { 0, 0, 0 };
		int type_2[3] = { 0, 0, 0 };
		int operation[3] = { 0, 0, 0 };
		stage = 0;
		counter++;
	}

	cout << endl;
	cout << "Result of programm: " << endl;
	cout << "Conveyor utilization bar graph." << endl;
	cout << "\".\"";
	cout << " - one tact of conveyor" << endl;
	gist(counter, gist_av);
	main_av = main_av / counter;
	cout << "Total average time: " << main_av << endl;
	int g = 0;
	cin >> g;
	return 0;
}
