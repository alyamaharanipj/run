//File		: Ilham_181511016.h
/*Deskripsi : Header buatan Ilham Triza Kurniawan (181511016)*/
#include "universal.h"
#include "time.h"
typedef struct{
	int baris;
	int kolom;
}pos;

typedef struct{
	pos posisi;
	clock_t waktu;
}lubang;

typedef struct{
	lubang dt_lubang[20];
	int Max;
	int Count;
	int Front;
	int Back;
}Queue;

typedef struct{
	int baris;
	int kolom;
	clock_t waktu;
}elemen;

void Show(int z[brs][klm]);	//Modul untuk menampilkan map beserta sprite isinya
void Menu();
double count(clock_t awal, clock_t akhir);
int cek_waktu();

