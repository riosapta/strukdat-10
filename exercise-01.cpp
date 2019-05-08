/*Strukdat-10
Nama: Rio Sapta Samudera
NPM : 140810180030
Desc: Queue Array
*/


#include"pch.h"
#include<iostream>
#include<string>

#define max 5
using namespace std;

typedef struct queue
{
	int head;
	int tail;
	char data[20][20];
} antrian;

queue antri;

void createQueue() {
	antri.head = antri.tail = -1;
}

int isFull() {
	if (antri.tail == max - 1)
		return 1;
	else
		return 0;
}

int isEmpty() {
	if (antri.tail == -1)
	{
		antri.head = -1;
		return 1;
	}
	else
		return 0;
}

void enqueue(char d[20]) {
	system("cls");
	antri.head = 0;
	antri.tail++;
	strcpy_s(antri.data[antri.tail], d);
}

void delqueue() {
	system("cls");
	for (int i = antri.head; i <= antri.tail; i++)
		strcpy_s(antri.data[i], antri.data[i + 1]);
	antri.tail--;
}


int main() {
	int pil;
	createQueue();
	char dt[20];
	do {
		cout << "Antrian" << endl;
		cout << "|";
		for (int i = 0; i <= antri.tail; i++)
		{
			cout << " [" << antri.data[i] << "] ";
		}
		cout << "\n-----------------------------------------" << endl;
		cout << "\t1. Push" << endl;
		cout << "\t2. Pop" << endl;
		cout << "\t3. Keluar" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "\nPilihan : ";
		cin >> pil;

		switch (pil) {
		case 1:
			if (!isFull()) {
				cout << "Nama : ";
				cin >> dt;
				enqueue(dt);
			}
			else
				cout << "\nAntrian sudah penuh!" << endl;
			break;
		case 2:
			if (!isEmpty())
				delqueue();
			else
				cout << "\nKosong! Tidak ada data yg dicari" << endl;
			break;
		}
	} while (pil != 3);
}