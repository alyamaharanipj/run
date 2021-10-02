//File 		: Adhitya_181511002.c
#include "Adhitya_181511002.h"
#include "Alya_181511038.h"
#include "Iqbal_181511022.h"
void game_over(){
	cleardevice();
	readimagefile("images//gameover.jpg",0,0,klm*kotakmenu,brs*kotakmenu);
}

void score(int scr){
	char s[7];
	int puluhan,satuan;
	setbkcolor(3);
	settextstyle(3,0,15);
	puluhan = scr / 10;
	satuan = scr % 10;
	{
		switch(puluhan){
			case 0:
				readimagefile("images//0.jpg",150,595,200,640);
				break;
		case 1:
			readimagefile("images//1.jpg",150,595,200,640);
			break;
		case 2:
			readimagefile("images//2.jpg",150,595,200,640);
			break;
		case 3:
			readimagefile("images//3.jpg",150,595,200,640);
			break;
		case 4:
			readimagefile("images//4.jpg",150,595,200,640);
			break;
		case 5:
			readimagefile("images//5.jpg",150,595,200,640);
			break;
		case 6:
			readimagefile("images//6.jpg",150,595,200,640);
			break;
		case 7:
			readimagefile("images//7.jpg",150,595,200,640);
			break;
		case 8:
			readimagefile("images//8.jpg",150,595,200,640);
			break;
		}
		switch(satuan){
			case 1:
				readimagefile("images//1.jpg",200,595,250,640);
				break;
			case 2:
				readimagefile("images//2.jpg",200,595,250,640);
				break;
			case 3:
				readimagefile("images//3.jpg",200,595,250,640);
				break;
			case 4:
				readimagefile("images//4.jpg",200,595,250,640);
				break;
			case 5:
				readimagefile("images//5.jpg",200,595,250,640);
				break;
			case 6:
				readimagefile("images//6.jpg",200,595,250,640);
				break;
			case 7:
				readimagefile("images//7.jpg",200,595,250,640);
				break;
			case 8:
				readimagefile("images//8.jpg",200,595,250,640);
				break;
			case 9:
				readimagefile("images//9.jpg",200,595,250,640);
				break;
			case 0:
				readimagefile("images//0.jpg",200,595,250,640);
				break;
		}
	}
//	sprintf(s, "%d", scr);
//	outtextxy(220,600,s);
//	outtextxy(0,600,"SCORE:");

//	readimagefile("images//titikdua.jpg",65,595,115,640);
}

void live(int lv){
	char l[6];
	setbkcolor(3);
	settextstyle(3,0,15);
//	sprintf(l, "%d", lv);
	switch(lv){
		case 5:
			readimagefile("images//5.jpg",450,595,500,640);
			break;
		case 4:
			readimagefile("images//4.jpg",450,595,500,640);
			break;
		case 3:
			readimagefile("images//3.jpg",450,595,500,640);
			break;
		case 2:
			readimagefile("images//2.jpg",450,595,500,640);
			break;
		case 1:
			readimagefile("images//1.jpg",450,595,500,640);
			break;
	}
//	outtextxy(510,600,l);
//	outtextxy(460,600,":");

//	readimagefile("images//titikdua.jpg",450,595,500,640);
}

void treasure(int trs){
	char t[10];
	setbkcolor(3);
	settextstyle(3,0,15);
//	sprintf(t, "%d", trs);
//	switch(trs){
//		case 8:
//			readimagefile("images//8.jpg",710,595,760,640);
//			break;
//		case 7:
//			readimagefile("images//7.jpg",710,595,760,640);
//			break;
//		case 6:
//			readimagefile("images//6.jpg",710,595,760,640);
//			break;
//		case 5:
//			readimagefile("images//5.jpg",710,595,760,640);
//			break;
//		case 4:
//			readimagefile("images//4.jpg",710,595,760,640);
//			break;
//		case 3:
//			readimagefile("images//3.jpg",710,595,760,640);
//			break;
//		case 2:
//			readimagefile("images//2.jpg",710,595,760,640);
//			break;
//		case 1:
//			readimagefile("images//1.jpg",710,595,760,640);
//			break;
//	}
		int puluhan,satuan;
//	readimagefile("images//coin",0,12*50,50,13*50);
	setbkcolor(3);
	settextstyle(3,0,15);
	puluhan = trs / 10;
	satuan = trs % 10;
	{
		switch(puluhan){
			case 0:
				readimagefile("images//0.jpg",700,595,750,640);
				break;
		case 1:
			readimagefile("images//1.jpg",700,595,750,640);
			break;
		case 2:
			readimagefile("images//2.jpg",700,595,750,640);
			break;
		case 3:
			readimagefile("images//3.jpg",700,595,750,640);
			break;
		case 4:
			readimagefile("images//4.jpg",700,595,750,640);
			break;
		case 5:
			readimagefile("images//5.jpg",700,595,750,640);
			break;
		case 6:
			readimagefile("images//6.jpg",700,595,750,640);
			break;
		case 7:
			readimagefile("images//7.jpg",700,595,750,640);
			break;
		case 8:
			readimagefile("images//8.jpg",700,595,750,640);
			break;
		case 9:
			readimagefile("images//9.jpg",700,595,750,640);
			break;
		}
		switch(satuan){
			case 1:
				readimagefile("images//1.jpg",750,595,800,640);
				break;
			case 2:
				readimagefile("images//2.jpg",750,595,800,640);
				break;
			case 3:
				readimagefile("images//3.jpg",750,595,800,640);
				break;
			case 4:
				readimagefile("images//4.jpg",750,595,800,640);
				break;
			case 5:
				readimagefile("images//5.jpg",750,595,800,640);
				break;
			case 6:
				readimagefile("images//6.jpg",750,595,800,640);
				break;
			case 7:
				readimagefile("images//7.jpg",750,595,800,640);
				break;
			case 8:
				readimagefile("images//8.jpg",750,595,800,640);
				break;
			case 9:
				readimagefile("images//9.jpg",750,595,800,640);
				break;
			case 0:
				readimagefile("images//0.jpg",750,595,800,640);
				break;
		}
	}
//	outtextxy(710,600,t);
//	outtextxy(660,600,":");
//	readimagefile("images//titikdua.jpg",6)

//	readimagefile("images//titikdua.jpg",650,595,700,640);

}

void levelGame(int tk){
	char t[10];
	setbkcolor(3);
	settextstyle(3,0,15);
	switch(tk){
		case 1:
			readimagefile("images//1.jpg",1025,595,1075,640);
			break;
		case 2:
			readimagefile("images//2.jpg",1025,595,1075,640);
			break;
		case 3:
			readimagefile("images//3.jpg",1025,595,1075,640);
			break;
		case 4:
			readimagefile("images//4.jpg",1025,595,1075,640);
			break;
		case 5:
			readimagefile("images//5.jpg",1025,595,1075,640);
			break;
		case 6:
			readimagefile("images//6.jpg",1025,595,1075,640);
			break;
		case 7:
			readimagefile("images//7.jpg",1025,595,1075,640);
			break;
		case 8:
			readimagefile("images//8.jpg",1025,595,1075,640);
			break;
		case 9:
			readimagefile("images//9.jpg",1025,595,1075,640);
			break;
		case 10:
			readimagefile("images//1.jpg",1025,595,1075,640);
			readimagefile("images//0.jpg",1075,595,1125,640);
			break;
		}
//	sprintf(t, "%d", tk);
//	outtextxy(1200,600,t);
//	outtextxy(800,600,"LEVEL");

//	readimagefile("images//titikdua.jpg",65,595,115,640);
}
