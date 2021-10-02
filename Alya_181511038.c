//File 		: Alya_181511038.cpp 
//Nama		: Alya Maharani P.J (181511038)
//Deskripsi	: Modul untuk gerak ke bawah, saat user menekan tombol w
#include "Alya_181511038.h"
#include "Ilham_181511016.h"
#include "Iqbal_181511022.h"
#include "Ichwan_181511046.h"
#include "Adhitya_181511002.h"

int moveUp(int b, int k, int map[brs][klm], int n, int code)
//Modul ini akan dipanggil saat user menekan tombol down
//variabel posisi adalah penampung dari isi map[b][k]
//Variabel posisibawah adalah penampung dari nilai yang dikembalikan oleh function checkmapsebelah
{
	int posisi,posisiAtas;
	posisi=map[b][k];
	printf("%d",posisi);
	posisiAtas=map[b-1][k];
	printf("%d",posisiAtas);
	switch(posisi)
	{
		case 40 : {
			switch(posisiAtas)
			{
				case 4 : printf("MASUK");change(b,k,map,n,4,code);
				if(n%2==0)
					b--;
				change(b,k,map,n,40,code);break;
				//Jika isi posisi bawah karakter tangga
				case 0 : change(b,k,map,n,4,code);b--;change(b,k,map,n,72,code);break;
				case 9 : change(b,k,map,n,4,code);b--;change(b,k,map,n,72,code); map[b][k] = 9; break;
			}
			break;
		}
		//Jika karakter sedang memanjat tangga, maka yang akan dipanggil adalah modul outputdown40
		case 30 : {
			switch(posisiAtas)
			{
				case 4 :	change(b,k,map,n,3,code);b--;change(b,k,map,n,40,code);break;
				//Jika isi posisi bawah karakter tangga
			}
			break;
		}
		//Jika karakter sedang ada di tali, maka yang akan dipanggil adalah modul outputdown30
//		case 47 : b=outputUp47(b,k,map,posisiAtas,n);break;
	}
	return b;//Modul ini akan mengembalikan suatu nilai baris yang telah diproses
}

int moveDown(int b, int k, int map[brs][klm], int n, int code)
//Modul ini akan dipanggil saat user menekan tombol down
//variabel posisi adalah penampung dari isi map[b][k]
//Variabel posisibawah adalah penampung dari nilai yang dikembalikan oleh function checkmapsebelah
{
	int posisi,posisiBawah;
	posisi=map[b][k];
	printf("%d",posisi);
	posisiBawah=map[b+1][k];
	printf("%d",posisiBawah);
	switch(posisi)
	{
		case 40 : {
			switch(posisiBawah)
			{
				case 4 :	change(b,k,map,n,4,code);
				if(n%2==0)
					b++;
				change(b,k,map,n,41,code);break;
				//Jika isi posisi bawah karakter tangga
				case 0 	:	change(b,k,map,n,4,code);b++;change(b,k,map,n,72,code);break;
				//Jika isi posisi bawah karakter kosong
				case 3 	:	change(b,k,map,n,4,code);b++;change(b,k,map,n,30,code);;break;
				//Jika posisi bawah karakter tali
			}
			break;
		}
		//Jika karakter sedang memanjat tangga, maka yang akan dipanggil adalah modul outputdown40
		case 7 : {
			switch(posisiBawah)
			{
				case 4 :change(b,k,map,n,0,code);b++;change(b,k,map,n,40,code);break;
				//Jika di bawah posisi karakter ada tangga
			}			
			break;
		}
		//Jika karakter sedang berjalan biasa di atas bata, maka yang akan dipanggil adalah modul outputdown7 
		case 30 : {
			switch(posisiBawah)
			{
				case 4 : change(b,k,map,n,3,code);b++;change(b,k,map,n,40,code);break;
				//Jika di bawah posisi karakter ada tangga
				case 0  : change(b,k,map,n,3,code);b++;change(b,k,map,n,72,code);break;
				//Jika di bawah posisi karakter kosong, maka karakter akan jatuh
				case 8 : change(b,k,map,n,3,code);b++;change(b,k,map,n,72,code);break;
			}
			break;
		}
		//Jika karakter sedang ada di tali, maka yang akan dipanggil adalah modul outputdown30
		case 10 : {
			switch(posisiBawah)
			{
				case 4 :change(b,k,map,n,0,code);b++;change(b,k,map,n,40,code);break;
			//Jika di bawah posisi karakter ada tangga
			}
			break;
		}
		
	}
	return b;//Modul ini akan mengembalikan suatu nilai baris yang telah diproses
}

void reset(int b, int k, int map[brs][klm], int n)
{
	switch(map[b][k])
	{
		case 30 :{
			change(b,k,map,n,3,2);
			break;
		}
		case 40 : {
			change(b,k,map,n,4,2);
			break;
		}
		case 7 : {
			change(b,k,map,n,0,2);
			break;
		}
		case 10 :{
			change(b,k,map,n,0,2);
			break;
		}
		case 11 :{
			change(b,k,map,n,1,2);
			break;
		}
	}
}

int jatuh(int b, int k, int map[brs][klm], int n, int code, bool *botStatus)
//modul yang berfungsi mengatur pergerakan jatuh ketika karakter sedang berada di tali
{
	while(((map[b+1][k]==0)||(map[b+1][k]==8)||(map[b+1][k]==100))&& ((map[b][k]!=30)&&(map[b][k]!=40)))//looping untukk turun dengan jatuh
	{
		delay(75);
		if(map[b+1][k]==100)
		{
			change(b,k,map,n,0,code);
			play_fall();
			b++;
			change(b,k,map,n,11,code);
			*botStatus=true;
		}
		else
		{
			change(b,k,map,n,0,code);
			play_fall();
			b++;
			change(b,k,map,n,72,code);
		}
		//ganti posisi satu baris dari posisi awal karakter dengan 7, 7 berarti karakter dengan background 0	
	}
	if(map[b+1][k]==3)
	{
		change(b,k,map,n,0,code);//ganti posisi awal karakter dengan 0, 0 berarti kosong
		b++;//turun satu baris
		change(b,k,map,n,30,code);
	}
	stop_fall();
	return b;//mengembalikan nilai baris agar posisi terupdate
}

void loading()
{
	int x=410,i;
	readimagefile("images//welcome screen.jpg",0,0,klm*kotakmenu,brs*kotakmenu);
	for(i=0;i<400;++i)
	{
		delay(10);
		line(x,450,x,500);
		x++;
	}
	getch();
}

void change(int b, int k, int map[brs][klm], int n, int newFill, int code)
{
	int jum;
	switch(newFill)
	{
		case 0 : {
			map[b][k] = 0;
			readimagefile("images//backgroundfix.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);
			break;
		}
		case 1 : {
			map[b][k] = 1;
			readimagefile("images//brick.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);
			break;
		}	
		case 3 : {
			map[b][k]=3;
			readimagefile("images//talifix.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);
			break;
		}
		case 4 : {
			map[b][k] = 4;
			readimagefile("images//tanggakosong.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);
			break;
		}
		case 9 : {
			map[b][k] = 9;
			readimagefile("images//pintu5.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);
			break;
		}
		case 30 : {
			map[b][k]=30;
			jum=n%2;
			if(code==1)
			{
				switch(jum)
				{
					case 0 :readimagefile("images//taliorg1.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 1 :readimagefile("images//taliorg2.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}
			}
			else
			{
				switch(jum)
				{
					case 0 :readimagefile("images//taliorg1bot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 1 :readimagefile("images//taliorg2bot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}
			}
			
			break;
		}
		case 40 : {
			jum=n%2;
			map[b][k]=40;
			if(code==1)
			{
				switch(jum)
				{
					case 0 :readimagefile("images//manjat1edit.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 1 :readimagefile("images//manjat2edit.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}
			}
			else
			{
				switch(jum)
				{
					case 0 :readimagefile("images//manjat1editbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 1 :readimagefile("images//manjat2editbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}
			}
		
			break;
		}
		case 41 : {
			jum=n%2;
			map[b][k]=40;
			if(code==1)
			{
				switch(jum)
				{
					case 1 :readimagefile("images//manjat1edit.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 0 :readimagefile("images//manjat2edit.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}
			}
			else
			{
				switch(jum)
				{
					case 1 :readimagefile("images//manjat1editbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 0 :readimagefile("images//manjat2editbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}
			}
			break;
		}
		case 71 : {//7 kiri
			
			jum = n%4;
			if(code==1)
			{
				map[b][k] = 7;
				switch(jum)
				{
					case 0 : readimagefile("images//walk1l.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 1 : readimagefile("images//walk2l.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 2 : readimagefile("images//walk3l.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 3 : readimagefile("images//walk4l.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}					
			}
			else
			{
				map[b][k] = 10;
				switch(jum)
				{
					case 0 : readimagefile("images//walk1lbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 1 : readimagefile("images//walk2lbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 2 : readimagefile("images//walk3lbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 3 : readimagefile("images//walk4lbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}	
			}
			break;
		}
		case 72 : {// 7 kanan
			
			
			jum = n%4;
			printf("%d",jum);
			printf("%d",n);
			if(code==1)
			{
				map[b][k] = 7;
				switch(jum)
				{
					case 0 : readimagefile("images//walk1r.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 1 : readimagefile("images//walk2r.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 2 : readimagefile("images//walk3r.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 3 : readimagefile("images//walk4r.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}				
			}
			else
			{
				map[b][k] = 10;
				switch(jum)
				{
					case 0 : readimagefile("images//walk1rbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 1 : readimagefile("images//walk2rbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 2 : readimagefile("images//walk3rbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
					case 3 : readimagefile("images//walk4rbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				}
			}

			break;
		} 
		case 100 : {
			map[b][k] = 100;
			readimagefile("images//backgroundfix.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);
			break;
		}
		case 11 : {
			map[b][k]=11;
			if(code==2)
			{
				readimagefile("images//walk1rbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);				
			}
			else
			{
				readimagefile("images//walk1r.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);
			}

			break;			
		}
		case 12 : {
			jum = n%4;
			map[b][k]=12;
			switch(jum)
			{
				case 0 : readimagefile("images//walk1rbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				case 1 : readimagefile("images//walk2rbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				case 2 : readimagefile("images//walk3rbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
				case 3 : readimagefile("images//walk4rbot.jpg",0+kotak*k,0+kotak*b,kotak+kotak*k,kotak+kotak*b);break;
			}
			break;
		}
	}
}

void createLevel()
{
	int level,scr=0, maps[brs][klm];
	address head, pNew;
	level=0;
	while(level<5)
	{
		read_map(maps, level);	
		Create_Node(&pNew);
		Isi_Node(&pNew);
		switch(level)
		{
			case 0 : {createInfo(maps,&pNew);break;}
			case 1 : {createInfo(maps,&pNew);break;}
			case 2 : {createInfo(maps,&pNew);break;}
			case 3 : {createInfo(maps,&pNew);break;}
			case 4 : {createInfo(maps,&pNew);break;}
		} 
		if (level==0)
		{
			head=pNew;
		}
		else
		{
			Ins_Akhir(&head, pNew);
		}
		level++;
	}
	playNow(head,scr);
}

void createInfo(int map[brs][klm], address *pNew)
{
	int i,j;

	for(i=0;i<brs;i++)
	{
		for(j=0;j<klm;j++)
		{
			Isi_Info(&*pNew,i,j,map[i][j]);
		}
	}
}

int countTreasure(int map[brs][klm])
{
	int i,j,jumTrs=0;

	for(i=0;i<brs;i++)
	{
		for(j=0;j<klm;j++)
		{
			if(map[i][j]==8)
			{
				jumTrs++;
			}
		}
	}
	return jumTrs;
}

void playNow (address head, int scr)
{
	address temp=head;
	int level=0, cek;
	while(level<5)
	{
		Show(temp->info);
		levelGame(level+1);
		gerak(temp->info,&scr,level);
getch();
		temp=temp->next;
		level++;
	}
}

void viewScore()
{
	int scr;
	char t[10];
	FILE *f_runner;
	if((f_runner=fopen("High_Score.txt", "r"))==NULL)
	{
		printf("Data belum ada");
	}
	else
	{
		while(1)
		{
			if(feof(f_runner))
				break;
			fscanf(f_runner,"\t%d\t",&scr);
		switch(scr){
			case 1:
				readimagefile("images//1-.jpg",500,200,700,500);
				break;
			case 2:
				readimagefile("images//2-.jpg",500,200,700,500);
				break;
			case 3:
				readimagefile("images//3-.jpg",500,200,700,500);
				break;
			case 4:
				readimagefile("images//4-.jpg",500,200,700,500);
				break;
			case 5:
				readimagefile("images//5-.jpg",500,200,700,500);
				break;
			case 6:
				readimagefile("images//6-.jpg",500,200,700,500);
				break;
			case 7:
				readimagefile("images//7-.jpg",500,200,700,500);
				break;
			case 8:
				readimagefile("images//8-.jpg",500,200,700,500);
				break;
			case 9:
				readimagefile("images//9-.jpg",500,200,700,500);
				break;
			case 0:
				readimagefile("images//0-.jpg",500,200,700,500);
				break;
		}
	}
		fclose(f_runner);
	}
}


