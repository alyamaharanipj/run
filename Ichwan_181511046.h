/*	nama file		:	Ichwan_181511046.h
	deskripsi		:	header sebagai prototype untuk modul
	dibuat oleh		:	ichwan latif / 181511046
	last update		:	31/03/2019
	*/
#include "universal.h"

typedef struct{
	int kolom;
	int jarak;
}jalan_bot;

int moveRight(int b, int k, int map[brs][klm], int n,int code, bool *tCode);
int moveLeft(int b, int k, int map[brs][klm], int n,int code, bool *tCode);
void Update_File(int p);
void write_highscore(int scr);
void Hapus_File();
void read_map(int a[brs][klm], int lv);
void reset_posisi(int *bbot1, int *kbot1, int *bbot2, int *kbot2, int *bbot3, int *kbot3,int level);
void bot(int map[brs][klm], int *kolom, int *baris, int b, int k, int nbot, bool *tCode);



