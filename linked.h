/* File : linked.h */
/* Deskripsi : ADT linked list dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* InfoType adalah integer */
/* Dibuat oleh 	: Ade Chandra Nugraha */
/* Direvisi oleh	: Alya Maharani dan Nadira Arasya */

#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "universal.h"

#define info(P) (P)->info
#define next(P) (P)->next

#define Nil NULL 

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
 infotype info[brs][klm];
 address next;
 } ElmtList;
void Isi_Info(address *p, int b, int k, infotype nilai);
bool isEmpty(address p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
void Create_Node (address *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Isi_Node (address *p);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Tampil_List (address p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
void Ins_Awal (address *p, address PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
// PNew (input)
void Ins_Akhir (address *p, address PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

#endif
