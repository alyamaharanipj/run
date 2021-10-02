//File		: Ilham_181511016.c

#include "Ilham_181511016.h"
#include "Alya_181511038.h"
#include "Iqbal_181511022.h"
#include "Ichwan_181511046.h"
void Show(int z[brs][klm])
{
	for(int i=0;i<brs;i++)
	{
		for(int j=0;j<klm;j++)
		{
			switch (z[i][j])
			{
				case 0 : readimagefile("images//backgroundfix.jpg",0+kotak*j,0+kotak*i,kotak+kotak*j,kotak+kotak*i);break;
				case 1 : readimagefile("images//brick.jpg",0+kotak*j,0+kotak*i,kotak+kotak*j,kotak+kotak*i);break;
				case 2 : readimagefile("images//bricks2.jpg",0+kotak*j,0+kotak*i,kotak+kotak*j,kotak+kotak*i);;break;
				case 3 : readimagefile("images//talifix.jpg",0+kotak*j,0+kotak*i,kotak+kotak*j,kotak+kotak*i);break;
				case 4 : readimagefile("images//tanggakosong.jpg",0+kotak*j,0+kotak*i,kotak+kotak*j,kotak+kotak*i);break;
				case 7 : readimagefile("images//walk1r.jpg",0+kotak*j,0+kotak*i,kotak+kotak*j,kotak+kotak*i);break;
				case 8 : readimagefile("images//treasure.jpg",0+kotak*j,0+kotak*i,kotak+kotak*j,kotak+kotak*i);break;
				case 10 : readimagefile("images//walk1rbot.jpg",0+kotak*j,0+kotak*i,kotak+kotak*j,kotak+kotak*i);break;
			}
		}
	}
}

void Menu()
{
	typedef struct start{
		int x;
		int y;
	}start1;
	char *input;
	start1 start2;
	while(1)
	{
		readimagefile("images//menu.jpg",0,0,kotakmenu*klm,kotakmenu*brs);
		getmouseclick(WM_LBUTTONDOWN,start2.x,start2.y);
		if((start2.x>=9*kotakmenu-12)&&(start2.x<=16*kotakmenu-7)&&(start2.y>=2*kotakmenu-7)&&(start2.y<=3*kotakmenu-7))//start
		{
			stop_menu();
			readimagefile("images//backgroundfix.jpg",0,0,kotakmenu*klm,kotakmenu*brs);
			createLevel();
			break;
		}		
		if((start2.x>=6*kotakmenu-25)&&(start2.x<=19*kotakmenu+10)&&(start2.y>=4*kotakmenu-7)&&(start2.y<=5*kotakmenu-7))
		{
			readimagefile("images//highscore.jpg",0,0,kotakmenu*klm,kotakmenu*brs);
			viewScore();
			while(1)
			{	
				getmouseclick(WM_LBUTTONDOWN,start2.x,start2.y);
				if((start2.x>=kotakmenu-3)&&(start2.x<=7*kotakmenu-3)&&(start2.y>=12*kotakmenu-10)&&(start2.y<=13*kotakmenu-32))//highscore
				{
					Menu();
				}
			}
		}
		if((start2.x>=7*kotakmenu-20)&&(start2.x<=18*kotakmenu)&&(start2.y>=8*kotakmenu-10)&&(start2.y<=9*kotakmenu-10))
		{
			while(1)
			{
				readimagefile("images//about usfix.jpg",0,0,kotakmenu*klm,kotakmenu*brs);
				getmouseclick(WM_LBUTTONDOWN,start2.x,start2.y);
				if((start2.x>=kotakmenu-3)&&(start2.x<=7*kotakmenu-3)&&(start2.y>=12*kotakmenu-10)&&(start2.y<=13*kotakmenu-32))//menu
				{
					Menu();
				}
			}
		}	
		if((start2.x>=4*kotakmenu+15)&&(start2.x<=20*kotakmenu+20)&&(start2.y>=6*kotakmenu-10)&&(start2.y<=7*kotakmenu-10))
		{
			while(1)
			{
				readimagefile("images//how to playfix.jpg",0,0,kotakmenu*klm,kotakmenu*brs);
				getmouseclick(WM_LBUTTONDOWN,start2.x,start2.y);
				if((start2.x>=kotakmenu-3)&&(start2.x<=7*kotakmenu-3)&&(start2.y>=12*kotakmenu-30)&&(start2.y<=13*kotakmenu-32))//menu
				{
					Menu();
				}
			}
		}
	}
}


int cek_waktu(){
	clock_t waktu;
	waktu = clock();
	return waktu;
}

double count(clock_t awal, clock_t akhir){
	clock_t hasila, hasilb;
	double hasil;
	hasila = ((double)awal)/CLOCKS_PER_SEC;
	hasilb = ((double)akhir)/CLOCKS_PER_SEC;
	return hasil = hasilb - hasila;
}
