#include "RELASI.h"
#include <iostream>
using namespace std;

void createListR(ListR &L) {
    firstR(L)=NULL;
    lastR(L)=NULL;
}

addressR alokasi(infotypeR x) {
    addressR P;
      P = new elmListR;
      info(P)=x;
      nextR(P)=NULL;
      prevR(P)=NULL;
    return P;
}

void dealokasiR(addressR &P) {
    delete P;
}

void insertFirstR(ListR &L, addressR P) {
    if (firstR(L)==NULL){
        firstR(L)=P;
        lastR(L)=P;
    }
    else{
        nextR(P)=firstR(L);
        firstR(L)->prevR=P;
        firstR(L)=P;
    }
}

void insertLastR(ListR &L, addressR P) {
    if (firstR(L)==NULL)
        insertFirstR(L,P);
    else{
        lastR(L)->nextR=P;
        prevR(P)=lastR(L);
        lastR(L)=P;
    }
}

void deleteFirstR(ListR &L, addressR &P) {
    if (firstR(L)==NULL)
        cout<<"Data Kosong"<<endl;
    else if (firstR(L)== lastR(L)){
        P = firstR(L);
        firstR(L)=NULL;
        lastR(L) = NULL;
    }
    else{
      P = firstR(L);
      firstR(L)=nextR(P);
      firstR(L)->prevR=NULL;
      nextR(P)=NULL;
    }
}

void deleteLastR(ListR &L, addressR &P) {
    if (firstR(L)==NULL)
        cout<<"Data Kosong"<<endl;
    else if(firstR(L)==lastR(L)){
            P = firstR(L);
            firstR(L)=NULL;
            lastR(L) = NULL;
    }
    else{
        P = lastR(L);
        lastR(L)=prevR(P);
        lastR(L)->nextR=NULL;
        prevR(P)=NULL;
    }
}

void printinfo(ListR L) {
    addressR P = firstR(L);
    while(P!=NULL){
        cout<<info(info(P).penunjukP).id<<endl;
        cout<<info(info(P).penunjukC).id<<endl;
        P = nextR(P);
    }

}


addressR findElmSosialdanMahasiswa(ListR L, addressP P, addressC C) {
    addressR P=firstR(L);
    while(P!=NULL){
        if((info(P(P).penunjukP).namaweb==sosialmedia) && (info(info(P).penunjukC).nama==namamahasiswa))
            return P;
        P = nextR(P);
    }
    return NULL;
}

void insertAfterR(ListR &L, addressR Prec, addressR P) {
    if(Prec!=NULL) {
        if(nextR(Prec)==NULL) {
            insertLastR(L, P);
        } else {
            nextR(P) = nextR(Prec);
            prevR(P) = Prec;
            prevR(nextR(Prec)) = P;
            nextR(Prec) = P;
        }
    } else {
        cout<<"gagal insert after, prec null"<<endl;
    }
}

void deleteAfterR(ListR &L, addressR Prec, addressR &P) {
    if(firstR(L)!=NULL) {
        if(Prec!=NULL&&Prec!=lastR(L)) {
            if(nextR(Prec)==lastR(L)) {
                deleteLastR(L,P);
            } else {
                P = nextR(Prec);
                nextR(Prec) = nextR(P);
                prevR(nextR(P)) = Prec;
                prevR(P) = NULL;
                nextR(P) = NULL;
            }
        } else {
            cout<<"gagal delete after"<<endl;
        }
    } else {
        cout<<"gagal delete after, list kosong"<<endl;
    }
}

void sorting(ListR L){
    addressR P;
    addressR Q;

    if(firstR(L)==NULL){
        insertFirstR(L,P);
    }
    else {
        Q=firstR(L);
        while ((info(info(P).penunjukC).id > info(info(Q).penunjukC).id) && (Q!=NULL)){
            Q=nextR(Q);
        }
        if (Q==NULL){
            insertLastR(L,P);
        }
        else if (firstR(L)==Q){
            insertFirstR(L,P);
        }
        else{
            insertAfterR(L,prevR(Q),P);
        }
    }
}
