// File			: linked.cpp			//
/* File		: doublelinkedlist.c
/* Dibuat oleh	: Alya Maharani Putri J. (181511038)
/* Dibuat tanggal	: 6 April 2019*/

#include <stdlib.h>
#include <stdio.h>
#include "linked.h"

bool isEmpty(address p)
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
{
	if (p==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Create_Node (address *p)
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
{
	*p = (address) malloc(sizeof (ElmtList));
}

void Isi_Node (address *p)
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
{
	next(*p) = Nil;
}

void Isi_Info(address *p, int b, int k, infotype nilai)
{
	(*p)->info[b][k]=nilai;
}

//void Tampil_List (address p)
//// Tujuan : Menampilkan seluruh isi Linked List
//// Parameter : p (parameter input)
//{
//	address current;
//	current=p;
//	printf("\n");
//	while (isEmpty((current))!=true)
//	{
//		printf("\n");
//		while((isEmpty((current)))==false)
//		{
//			printf("\t%d", info(current));
//			current=next(current);
//		}
//		current=bfr(p);
//		p=current;
//	}
//	printf("\n");
//}

void Ins_Akhir (address *p, address PNew)
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */
{
	address current=*p;
	
	while(isEmpty(next(current))==false)
	{
		current=next(current);	
	}
	next(current)=PNew;
}

//void Connect_Column(address *p, address PNew)
///* Tujuan : menyambungkan elemen yang berada pada kolom yang sama di baris sebelumnya ke PNew*/ 
//{
//	address current=*p;
//	while(isEmpty(bfr(current))==false)
//	{
//		current=bfr(current);	
//	}
//	bfr(current)=PNew;
//}
//
//void Connect_Kanan(address *p, address PNew)
////Tujuan : menyambungkan elemen yang berada pada baris yang sama di kolom sebelumnya ke PNew*/
//{
//	address current=*p,r;
//	while(isEmpty(bfr(current))==false)
//	{
//		current=bfr(current);	
//	}
//	while(isEmpty(next(current))==false)
//	{
//		current=next(current);	
//	}
//	next(current)=PNew;
//}
//
//void Connect_Bawah(address *p, address PNew)
////Tujuan : menyambungkan elemen yang berada pada kolom yang sama di baris sebelumnya ke PNew*/
//{
//	address current,r;
//	
//	r=next(*p);
//	current=r;
//	while(isEmpty(bfr(current))==false)
//	{
//		current=next(current);
//		while(isEmpty((current))==true)
//		{
//			current=bfr(r);
//			r=current;
//		}
//	}
//	bfr(current)=PNew;
//}
