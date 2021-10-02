#include "Alya_181511038.h"
#include "Ichwan_181511046.h"
#include "Iqbal_181511022.h"
#include "universal.h"
#include <math.h>
/*
	Nama file		:	ichwan181511046.cpp
	deskripsi		:	modul untuk menentukan skor dan pengambilan treasure pada game
						dan layout pada game
	dibuat oleh		:	Ichwan Latif	/	181511046
	last update		:	30/03/2019
*/

int moveLeft(int b, int k, int map[brs][klm], int n, int code, bool *tCode)
//Modul ini akan dipanggil saat user menekan tombol down
//variabel posisi adalah penampung dari isi map[b][k]
//Variabel posisibawah adalah penampung dari nilai yang dikembalikan oleh function checkmapsebelah
{
	int posisi,posisiKiri;
	posisi=map[b][k];
	posisiKiri=map[b][k-1];
	switch(posisi)
	{
		case 40 : {
			switch(posisiKiri)
			{
				case 4 : change(b,k,map,n,4,code);k--;change(b,k,map,n,40,code);break;
				//Jika isi posisi bawah karakter tangga
				case 3 : change(b,k,map,n,4,code);k--;change(b,k,map,n,30,code);break;
				//Jika posisi bawah karakter tali
				case 0 : change(b,k,map,n,4,code);k--;change(b,k,map,n,71,code);break;
		//		b=jatuh(b,k,map,n);break;
				case 8 : change(b,k,map,n,4,code);k--;play_coin();change(b,k,map,n,71,code);stop_coin();
				if(code==2)
				{
					*tCode=true;
				}break;
			}
			break;
		}
		//Jika karakter sedang memanjat tangga, maka yang akan dipanggil adalah modul outputdown40
		case 7 : {
			switch(posisiKiri)
			{
				case 8 : change(b,k,map,n,0,code);k--;play_coin();change(b,k,map,n,71,code);stop_coin();break;
				//jika isi posisi sebelah kiri adalah treasure
				case 4 : 
				change(b,k,map,n,0,code);k--;change(b,k,map,n,40,code);
				break;
				//Jika isi posisi bawah karakter tangga
				case 0 : change(b,k,map,n,0,code);	
				if((n%4==0))
					k--;
				change(b,k,map,n,71,code);
				break;
	//			case 7: change(b,k,map,n,0,2);k--;change(b,k,map,n,71,2);break;
				//jika isi posisi jalan kiri biasa
			}
			break;
		}
		//Jika karakter sedang berjalan biasa di atas bata, maka yang akan dipanggil adalah modul outputdown7 
		case 30 : {
			switch(posisiKiri)
			{
				case 4 :	change(b,k,map,n,3,code);k--;change(b,k,map,n,40,code);break;
				//Jika isi posisi bawah karakter tangga
				case 3 	:	change(b,k,map,n,3,code);k--;change(b,k,map,n,30,code);break;
				//Jika posisi bawah karakter tali
				case 0 : change(b,k,map,n,3,code);k--;change(b,k,map,n,71,code);break;
			}	
			break;
		}
		//Jika karakter sedang ada di tali, maka yang akan dipanggil adalah modul outputdown30
		case 10 : {
			switch(posisiKiri)
			{
				case 8 : {
					if(*tCode==false)
				{
					change(b,k,map,n,0,code);k--;play_coin();change(b,k,map,n,71,code);stop_coin();*tCode=true;break;
				}
					break;
				}
//				else
//				{
//					change(b,k,map,n,0,code);	
//					if((n%4==0))
//						k--;
//					change(b,k,map,n,12,code);
//					break;
//				}
				//jika isi posisi sebelah kiri adalah treasure
				case 4 : 
				change(b,k,map,n,0,code);k--;change(b,k,map,n,40,code);
				break;
				//Jika isi posisi bawah karakter tangga
				case 0 : change(b,k,map,n,0,code);	
				if((n%4==0))
					k--;
				change(b,k,map,n,71,code);
				break;
				case 7: change(b,k,map,n,0,2);k--;change(b,k,map,n,71,2);break;
				//jika isi posisi jalan kiri biasa
			}
			break;
		}
//		case 12:{
//			switch(posisiKiri){
//				case 4 : 
//				change(b,k,map,n,8,code);k--;change(b,k,map,n,40,code);
//				break;
//				//Jika isi posisi bawah karakter tangga
//				case 0 : change(b,k,map,n,8,code);	
//				if((n%4==0))
//					k--;
//				change(b,k,map,n,71,code);break;
//				case 7: change(b,k,map,n,8,2);k--;change(b,k,map,n,71,2);break;
//			}
//			break;
//		}
	}
	return k;//Modul ini akan mengembalikan suatu nilai baris yang telah diproses
}

int moveRight(int b, int k, int map[brs][klm], int n, int code, bool *tCode)
//Modul ini akan dipanggil saat user menekan tombol down
//variabel posisi adalah penampung dari isi map[b][k]
//Variabel posisibawah adalah penampung dari nilai yang dikembalikan oleh function checkmapsebelah
{
	int posisi,posisiKanan;
	posisi=map[b][k];
	printf("%d",posisi);
	posisiKanan=map[b][k+1];
	printf("%d",posisiKanan);
	switch(posisi)
	{
		case 40 :{
			switch(posisiKanan)
			{
				case 4 :	change(b,k,map,n,4,code);k++;change(b,k,map,n,40,code);break;
				//Jika isi posisi bawah karakter tangga
				case 3 	:	change(b,k,map,n,4,code);k++;change(b,k,map,n,30,code);break;
				//Jika posisi bawah karakter tali
				case 0 : change(b,k,map,n,4,code);k++;change(b,k,map,n,72,code);break;
				
				case 8 : change(b,k,map,n,4,code);k++;play_coin();change(b,k,map,n,72,code);stop_coin();
				if(code==2)
				{
					*tCode=true;
				}
				break;
			}
			break;
		}
		//Jika karakter sedang memanjat tangga, maka yang akan dipanggil adalah modul outputdown40
		case 7 : {
			switch(posisiKanan)
			{
				case 8 : change(b,k,map,n,0,code);
				if(n%4==0)
					k++;
					play_coin();
				change(b,k,map,n,72,code);stop_coin();break;
				case 4 : 
				change(b,k,map,n,0,code);k++;change(b,k,map,n,40,code);
				break;
				case 0 : change(b,k,map,n,0,code);
				if(n%4==0)
					k++;
				change(b,k,map,n,72,code);	break;
				//jika isi posisi jalan kiri biasa
				case 7: change(b,k,map,n,0,2);k++;change(b,k,map,n,72,2);break;
			}
			break;
		}
		//Jika karakter sedang berjalan biasa di atas bata, maka yang akan dipanggil adalah modul outputdown7 
		case 30 : {
			switch(posisiKanan)
			{
				case 4 :	change(b,k,map,n,3,code);k++;change(b,k,map,n,40,code);break;
				//Jika isi posisi bawah karakter tangga
				case 3 	:	change(b,k,map,n,3,code);k++;change(b,k,map,n,30,code);break;
			}
			break;
		}
		//Jika karakter sedang ada di tali, maka yang akan dipanggil adalah modul outputdown30
		case 10 :{
			switch(posisiKanan)
			{
				case 8 : {
					if(*tCode==false)
				{
					change(b,k,map,n,0,code);k++;play_coin();change(b,k,map,n,72,code);stop_coin();*tCode=true;break;
				}
					break;
				}
//				else
//				{
//					change(b,k,map,n,0,code);	
//					if((n%4==0))
//						k++;
//					change(b,k,map,n,12,code);
//					break;
//				}
				case 4 : 
				change(b,k,map,n,0,code);k++;change(b,k,map,n,40,code);
				break;
				case 0 : change(b,k,map,n,0,code);
				if(n%4==0)
					k++;
				change(b,k,map,n,72,code);	break;
				//jika isi posisi jalan kiri biasa
				case 7: change(b,k,map,n,0,2);k++;change(b,k,map,n,72,2);
			}
			break;
		}
//		case 12:{
//			switch(posisiKanan){
//				case 4 : 
//				change(b,k,map,n,8,code);k++;change(b,k,map,n,40,code);
//				break;
//				//Jika isi posisi bawah karakter tangga
//				case 0 : change(b,k,map,n,8,code);	
//				if((n%4==0))
//					k++;
//				change(b,k,map,n,71,code);break;
//				case 7: change(b,k,map,n,8,2);k++;change(b,k,map,n,71,2);break;
//			}
//			break;
//		}
	}
	return k;//Modul ini akan mengembalikan suatu nilai baris yang telah diproses
}

void read_highscore(infotype *p){
	FILE *f_highscore;
	
	if((f_highscore = fopen("High_Score.txt", "r")) != NULL){
		while(!feof(f_highscore)){
			
			fscanf(f_highscore, "%d", &(*p));
		}
	}
	fclose(f_highscore);
}

void write_highscore(infotype scr, infotype *p){
	
	if(*p < scr){
		*p = scr;
	}
	Hapus_File();
	Update_File(*p);
}

void Hapus_File(){
	FILE *f_highscore;
	
	f_highscore = fopen("High_Score.txt", "w");
	fclose(f_highscore);
	
}

void Update_File(infotype p){
	FILE *f_highscore;
	
	int scr;
	
	f_highscore = fopen("High_Score.txt", "a");
	fscanf(f_highscore, "\t%d\t", &scr);
	if(scr < p){
		Hapus_File();
		fprintf(f_highscore, "\t%d\t", p);
	}
	fclose(f_highscore);
}

void read_map(int a[brs][klm], int lv){
	FILE *f_map;
	
	int i,j;
	
	
	switch(lv){
		case 0:{
			if((f_map = fopen("map1.txt", "r")) != NULL){
				for(i=0; i<13; i++){
					for(j=0; j<25; j++){
						fscanf(f_map, "%d ", &a[i][j]);
					}
				}
			}
			break;
		}
		case 1:{
			if((f_map = fopen("map2.txt", "r")) != NULL){
				for(i=0; i<13; i++){
					for(j=0; j<25; j++){
						fscanf(f_map, "%d ", &a[i][j]);
					}
				}
			}
			break;
		}
		case 2:{
			if((f_map = fopen("map3.txt", "r")) != NULL){
				for(i=0; i<13; i++){
					for(j=0; j<25; j++){
						fscanf(f_map, "%d ", &a[i][j]);
					}
				}
			}
			break;
		}
		case 3:{
			if((f_map = fopen("map4.txt", "r")) != NULL){
				for(i=0; i<13; i++){
					for(j=0; j<25; j++){
						fscanf(f_map, "%d ", &a[i][j]);
					}
				}
			}
			break;
		}
		case 4:{
			if((f_map = fopen("map5.txt", "r")) != NULL){
				for(i=0; i<13; i++){
					for(j=0; j<25; j++){
						fscanf(f_map, "%d ", &a[i][j]);
					}
				}
			}
			break;
		}
	}
	fclose(f_map);

}

void bot(int map[brs][klm], int *kolom, int *baris, int b, int k, int nbot, bool *tCode){
	
	bool sama_baris = false;
//	if(map[*baris][*kolom] == 11){
//		printf("oooooooo");
//		change(*baris,*kolom,map,nbot,11,2);
//	}
	
	if(b > *baris){
		if(map[*baris+1][*kolom] == 4){
			*baris=moveDown(*baris, *kolom, map, nbot, 2);
		}
		else{
			if(k > *kolom){
				*kolom=moveRight(*baris, *kolom, map, nbot, 2,&*tCode);
			}
			if(k < *kolom){
				*kolom=moveLeft(*baris, *kolom, map, nbot, 2,&*tCode);
			}
		}
	}
	if((b < *baris)){
		if(map[*baris-1][*kolom] == 4){
			*baris=moveUp(*baris, *kolom, map, nbot, 2);	
		}
		else{
			if(k > *kolom){
				*kolom=moveRight(*baris, *kolom, map, nbot, 2,&*tCode);
			}
			if(k < *kolom){
				*kolom=moveLeft(*baris, *kolom, map, nbot, 2,&*tCode);
			}
		}
	}
	if(b == *baris){
		if(k > *kolom){
			*kolom=moveRight(*baris, *kolom, map, nbot, 2,&*tCode);
		}
		if(k < *kolom){
			*kolom=moveLeft(*baris, *kolom, map, nbot, 2,&*tCode);
		}
	}
}

void reset_posisi(int *bbot1, int *kbot1, int *bbot2, int *kbot2, int *bbot3, int *kbot3,int level){
	switch(level){
		case 0:{
			*bbot1 = 2;
			*kbot1 = 2;
			*bbot2 = 3;
			*kbot2 = 21;
			*bbot3 = 1;
			*kbot3 = 14;
			break;
		}
		case 1:{
			*bbot1 = 5;
			*kbot1 = 4;
			*bbot2 = 4;
			*kbot2 = 20;
			*bbot3 = 2;
			*kbot3 = 13;
			break;
		}
		case 2:{
			*bbot1 = 1;
			*kbot1 = 5;
			*bbot2 = 1;
			*kbot2 = 20;
			*bbot3 = 7;
			*kbot3 = 14;			
			break;
		}
		case 3:{
			*bbot1 = 1;
			*kbot1 = 3;
			*bbot2 = 4;
			*kbot2 = 11;
			*bbot3 = 6;
			*kbot3 = 13;			
			break;
		}
		case 4:{
			*bbot1 = 3;
			*kbot1 = 8;
			*bbot2 = 11;
			*kbot2 = 4;
			*bbot3 = 11;
			*kbot3 = 20;			
			break;
		}
	}
}




