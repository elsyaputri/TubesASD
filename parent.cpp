#include "parent.h"
#include <iostream>
using namespace std;

void createListP(ListP &L){
    firstP(L) = NULL;
}

addressP alokasi(infotypeP x){
    addressP P = new elmListP;
    info(P) = x;
    nextP(P) = NULL;
    return P;
}

void dealokasiP(addressP &P){
    delete P;
}

void insertFirstP(ListP &L, addressP P){
    if (firstP(L) != NULL)
    {
        nextP(P) = firstP(L);
        firstP(L) = P;
    }

    else
    {
        firstP(L) = P;
    }
}

void insertLastP(ListP &L, addressP P){
    addressP Prec;
    if (firstP(L) != NULL)
    {
        nextP (Prec) = firstP(L);
        while (nextP(Prec) != NULL)
        {
            Prec = nextP(Prec);
        }
    }
    else
        {
            insertFirstP(L, P);
        }
}

void insertAfterP(ListP &L, addressP Prec, addressP P){
        if (firstP(L) != NULL)
        {
            nextP(P) = nextP(Prec);
            nextP(Prec) = P;
        }

        else
        {
            insertFirstP(L, P);
        }
}

addressP findElmP(ListP L, infotypeP x){
    addressP Prec;
    nextP(Prec) = firstP(L);

    while (info(Prec).id != x.id && nextP(Prec) != NULL)
        {
            Prec = nextP(Prec);
        }
    return Prec;
}

void deleteFirstP(ListP &L, addressP &P){
    if (firstP(L) != NULL )
        {
            P = firstP(L);
            firstP(L) = nextP(P);
            nextP(P) = NULL;
            dealokasiP (P);
        }


    else
        {
            cout << " List kosong " << endl;
        }
}

void deleteLastP(ListP &L, addressP &P){
    addressP Prec;
    if(firstP(L)==NULL){
        insertFirstP(L,P);
    }
    else{
      Prec =  firstP(L);
        while (nextP(nextP(Prec)) != NULL)
        {
            Prec = nextP(Prec);
            nextP(Prec) = nextP(P);
            nextP(P) = NULL;
        }
    }
}

void deleteAfterP(ListP &L, addressP &Prec, addressP &P){
    if (nextP(Prec)== NULL)
    {
        deleteLastP(L, P);
    }
    else
    {
        deleteAfterP(L,Prec,P);
        P = nextP(Prec);
        nextP(P) = NULL;
    }

}

void printinfo(ListP L){
    addressP Prec;
    cout<<"print info: ";
    if (firstP(L)==NULL)
        cout<<"List Kosong"<<endl;
    else{
         addressP P = firstP(L);
         while(P!=NULL){
            cout<<info(Prec).id<<"  ";
            cout<<info(Prec).namaweb<<"  ";
            cout<<info(Prec).sosialmedia<<"  ";
            cout<<info(Prec).idsosialmedia<<"  ";
            cout<<info(Prec).pembuat<<"  ";
            cout<<info(Prec).lokasi<<"  ";
            P=nextP(P);
         }
         cout<<endl;
    }
}
