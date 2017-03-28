#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include<iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define infoP(P) P->info


struct infotypeP{
    string id;
    string namaweb;
    string sosialmedia;
    string idsosialmedia;
    string pembuat;
    string lokasi;
};

typedef struct elmListP *addressP;
struct elmListP {
    infotypeP info;
    addressP next;
};

struct ListP{
    addressP first;
};

void createListP(ListP &L);
addressP alokasi(infotypeP x);
void dealokasiP(addressP &P);
void insertFirstP(ListP &L, addressP P);
void insertLastP(ListP &L, addressP P);
void insertAfterP(ListP &L, addressP P);
addressP findElmP(ListP L, infotypeP x);
void deleteFirstP(ListP &L, addressP &P);
void deleteLastP(ListP &L, addressP &P);
void deleteAfterP(ListP &L, addressP &P);
void printInfoP(ListP L);


#endif // PARENT_H_INCLUDED
