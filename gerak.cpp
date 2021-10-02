 //File			: new.cpp//


#include "Ilham_181511016.h"
#include "Ichwan_181511046.h"
#include "Adhitya_181511002.h"
#include "Iqbal_181511022.h"
#include <process.h>
#include "Alya_181511038.h"
#include <MMSystem.h> //untuk sound
#pragma comment<lib, "winmm.lib">
#include <time.h>

/* run this program using the console pauser or ad d your own getch, system("pause") or input loop */

int lv = 5, trs = 0, allScr=0;

void gerak(int map[brs][klm], int *scr, int level)
{
	position user_pst,bot1,bot2,bot3;
	int n=0, nbot=0, awal=1, akhir=1, trBot=0, inTreasure;
	clock_t waktuawal, waktuakhir, waktutotal;
	elemen queue[20];
	char ch;
	double hasil;
	FILE *f_runner;
	
	readimagefile("images//coin.jpg",50,595,100,640);
	readimagefile("images//heart.jpg",350,595,400,640);
	readimagefile("images//bola.jpg",600,595,650,640);
	readimagefile("images//bendera.jpg",950,595,1000,640);
	
	user_pst.row=11;
	user_pst.col=12;
	if(trs == 0){
		trs = countTreasure(map);
	}
	if(lv == -1){
		lv = 5;
	}
	reset_posisi(&bot1.row, &bot1.col, &bot2.row, &bot2.col, &bot3.row, &bot3.col, level);
	inTreasure=countTreasure(map);
	bot1.code=false;
	bot1.tCode=false;
	bot2.code=false;
	bot2.tCode=false;
	bot3.code=false;
	bot3.tCode=false;
	user_pst.code=false;
	
	while(1)
	{
//		play_music();
//		delay(50);
		waktuakhir = cek_waktu();
		if(awal != akhir){	
			hasil = count(queue[awal].waktu, waktuakhir);	
			if(hasil >= 5){
				if(map[queue[awal].baris][queue[awal].kolom]==11&&(map[user_pst.row][user_pst.col]!=11||map[user_pst.row][user_pst.col]!=10))
				{
					change(queue[awal].baris-1, queue[awal].kolom, map, n, 72, 2);
					if(bot1.code==true)
					{
						bot1.row=queue[awal].baris-1;
						bot1.col=queue[awal].kolom;
						bot1.code=false;
						if(bot1.tCode==true)
						{
							change(bot1.row-1,bot1.col-1,map,n,8,2);
//							map[bot1.row-1][bot1.col-1]=8;
							bot1.tCode=false;
						}
					}

					if(bot2.code==true)
					{
						bot2.row=queue[awal].baris-1;
						bot2.col=queue[awal].kolom;
						bot2.code=false;
						if(bot2.tCode==true)
						{
							change(bot2.row-1,bot2.col-1,map,n,8,2);
							bot2.tCode=false;
						}
					}
					if(bot3.code==true)
					{
						bot3.row=queue[awal].baris-1;
						bot3.col=queue[awal].kolom;
						bot3.code=false;
						if(bot3.tCode==true)
						{
							change(bot3.row-1,bot3.col-1,map,n,8,2);
							bot3.tCode=false;
						}
					}
				}
				change(queue[awal].baris, queue[awal].kolom, map, n, 1, 1);
				awal++;
				if(awal == 21){
					awal = 1;
				}
			}	
		}
	
		user_pst.row=jatuh(user_pst.row,user_pst.col,map,n,1,&user_pst.code);
		bot1.row=jatuh(bot1.row,bot1.col,map,n,2,&bot1.code);
		bot(map, &bot1.col, &bot1.row, user_pst.row, user_pst.col, nbot,&bot1.tCode);
		bot2.row=jatuh(bot2.row,bot2.col,map,n,2,&bot2.code);
		bot(map, &bot2.col, &bot2.row, user_pst.row, user_pst.col, nbot,&bot2.tCode);
		bot3.row=jatuh(bot3.row,bot3.col,map,n,2,&bot3.code);
		bot(map, &bot3.col, &bot3.row, user_pst.row, user_pst.col, nbot,&bot3.tCode);
		
		trs=countTreasure(map);
		if(bot1.tCode==false){
			printf("false");
		}
		if(bot1.tCode==true)
		{
			printf("TRUE");
		}
//		if(bot1.tCode==true||bot2.tCode==true||bot3.tCode==true)
//		{
			if(bot1.tCode==true&&bot2.tCode==true&&bot3.tCode==true)
			{
				trBot=3;
				printf("treasurebot=3");
			}
			if((bot1.tCode==true&&bot2.tCode==true&&bot3.tCode==false)||(bot2.tCode==true&&bot3.tCode==true&&bot1.tCode==false)||(bot1.tCode==true&&bot3.tCode==true&&bot2.tCode==false))
			{
				trBot=2;
				printf("treasurebot=2");
			}
			if((bot1.tCode==true&&bot2.tCode==false&&bot3.tCode==false)||(bot2.tCode==true&&bot3.tCode==false&&bot1.tCode==false)||(bot1.tCode==false&&bot3.tCode==true&&bot2.tCode==false))
			{
				trBot=1;
				printf("treasurebot=1");
			}
//		}
		*scr=allScr+(inTreasure-trs-trBot);
		score(*scr);
		live(lv);
		treasure(trs);
		
		if(map[user_pst.row][user_pst.col]==10||map[user_pst.row][user_pst.col]==11)
		{
			delay(6000);
			hasil=5;
			lv--;
			reset(user_pst.row,user_pst.col,map,n);
			reset(bot1.row,bot1.col,map,n);
			reset(bot2.row,bot2.col,map,n);
			reset(bot3.row,bot3.col,map,n);
			user_pst.row=11;user_pst.col=12;
			reset_posisi(&bot1.row, &bot1.col, &bot2.row, &bot2.col, &bot3.row, &bot3.col, level);
			change(bot1.row,bot1.col,map,n,72,2);
			change(bot2.row,bot2.col,map,n,72,2);
			change(bot3.row,bot3.col,map,n,72,2);
			change(user_pst.row,user_pst.col,map,n,72,1);
		}
		if(trs==0)
		{
			change(0,1,map,n,9,1);
		}
		if(lv==0)
		{
			Update_File(*scr);
			game_over();
			delay(5000);
			lv=5;
			Menu();
			break;
		}
		if(map[user_pst.row][user_pst.col]==9)
			break;
		while(kbhit())
		{
			ch = getch();				
			switch(ch){
			case 's'://move down
			{
				user_pst.row=moveDown(user_pst.row,user_pst.col,map,n,1);
				break;
			}
			case 'w'://moveup
			{
				user_pst.row=moveUp(user_pst.row,user_pst.col,map,n,1);
				break;
			}
			case 'a'://move left
			{
				user_pst.col=moveLeft(user_pst.row,user_pst.col,map,n,1,&user_pst.tCode);
				break;
			}
			case 'd'://move right
			{
				user_pst.col=moveRight(user_pst.row,user_pst.col,map,n,1,&user_pst.tCode);
				break;
			}
			case 'z':	//menekan z untuk menggali kiri
			{
				if (map[user_pst.row+1][user_pst.col-1] == 1){
					waktuawal = cek_waktu();
					if(akhir == 21)
					{
						akhir = 1;
					}
					queue[akhir].baris = user_pst.row+1;
					queue[akhir].kolom = user_pst.col-1;
					queue[akhir].waktu = waktuawal;
					akhir++;
					change(user_pst.row+1, user_pst.col-1, map, n, 100, 1);	
				}	
				break;
			}			
			case 'c'://menekan c untuk menggali
			{
				if (map[user_pst.row+1][user_pst.col+1] == 1){
					waktuawal = cek_waktu();
					if(akhir == 21){
						akhir = 1;
					}
					queue[akhir].baris = user_pst.row+1;
					queue[akhir].kolom = user_pst.col+1;
					queue[akhir].waktu = waktuawal;
					akhir++;
					change(user_pst.row+1, user_pst.col+1, map, n, 100, 1);	
				}		
				break;
			}
	 		}
			n++;
			delay(50);
		}
		nbot++;
	}
	stop_music();
	allScr=*scr;
}
