#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "parent.h"
#include "childs.h"
#include<iostream>
using namespace std;

//#define first(L) L.first
//#define next(P) P->next
//#define last(L) L.last
//#define prev(P) P->prev

typedef struct elmListR *addressR;
struct elmListR{
    addressR nextR;
    addressR prevR;
    addressP P;
    addressC Q;
};

struct ListR{
    addressR first;
    addressR last;
};

void createListR(ListR &L);
addressR alokasi(addressP P, addressC C);
void dealokasiR(addressR &P);
void insertFirstR(ListR &L, addressR P);
void insertLastR(ListR &L, addressR P);
void insertAfterR(ListR &L, addressR P);
addressR findElmSosialdanMahasiswa(ListR L, addressP P, addressC C);
void deleteFirstR(ListR &L, addressR &P);
void deleteLastR(ListR &L, addressR &P);
void deleteAfterR(ListR &L, addressR &P);
void printInfoR(ListR L);
void sorting(ListR L);
#endif // RELASI_H_INCLUDED
