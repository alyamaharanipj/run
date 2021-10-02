//File 		: Alya_181511038.h
//Nama		: Alya Maharani P.J (181511038)
//Deskripsi	: Modul untuk perubahan pergerakan karakter

#include "universal.h"
#include "linked.h"
#include <stdbool.h>



typedef struct
{
	int row, col;
	bool code, tCode;
}position;


void loading();
void gerak(int map[brs][klm],int *scr, int level);
int moveDown(int b, int k, int map[brs][klm], int n,int code);
int jatuh(int b, int k, int map[brs][klm], int n,int code, bool *botStatusm);
int moveUp(int b, int k, int map[brs][klm], int n,int code);
void reset(int b, int k, int map[brs][klm], int n);
void change(int b, int k, int map[brs][klm], int n, int newFill, int code);
void createInfo(int map[brs][klm], address *pNew);
void createLevel();
void playNow (address head, int scr);
int countTreasure(int map[brs][klm]);
void viewScore();
