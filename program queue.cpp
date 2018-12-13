#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int pilih;
int tambah_pilihan();
int tambah_belakang();
int hapus_belakang();
int tampil();



struct tumpuk
{
   char nama[35], posisi[20];
  int no_punggung;
   struct tumpuk *next;
} *baru, *awal=NULL, *akhir=NULL,*hapus,*temp;

int main()
{
   do
   {
     cout <<"---------------------------------------"<<'\n';
     cout << "	QUEUE MENGGUNAKAN LINKED LIST" << '\n';
     cout <<"---------------------------------------"<<'\n';
     cout <<" "<<'\n';
     cout << "1. Enqueue" << '\n';
     cout << "2. Dequeue" << '\n';
     cout << "3. Tampil" << '\n';
     cout << "4. Exit" << '\n';
     cout << "Pilih (1-4) : ";
     cin>>pilih;
     tambah_pilihan();
   }while(pilih!=4);
  return 0;
}

int tambah_pilihan()
{
   if(pilih==1)
       tambah_belakang();
   else if(pilih==2)
       hapus_belakang();
   else if(pilih==3)
       tampil();
   else
       return 0;
}

int tambah_belakang()
{
   baru=(tumpuk*)malloc(sizeof(struct tumpuk));
   cout<<"Data pemain bola"<<endl;
   cout<<"---------------------"<<endl;
   cin.ignore();
   cout<<"No Punggung   : ";
   cin>>baru->no_punggung;
   cin.ignore();
   cout<<"Nama  : ";
   cin.getline(baru->nama,35);
   cout<<"Posisi  : ";
   cin.getline(baru->posisi,20);
 cin.ignore();
   baru->next=NULL;
   if(awal==NULL)
   {
       awal=baru;
   }
   else
   {
       akhir->next=baru;
   }
   akhir=baru;
   akhir->next=NULL;
   cout<<endl<<endl;

}

int hapus_belakang()
{
   if (awal==NULL)
       cout<<"Kosong"<<endl;
   else if(awal==akhir)
   {
        hapus=awal;
        awal=awal->next;
    
   }
   else
   {
       hapus=awal;
       while(hapus->next!=akhir)
            hapus=hapus->next;
       akhir=hapus;
       hapus=akhir->next;
       akhir->next=NULL;
   
   }
   cout<<endl<<endl;

}

int tampil()
{
    if (awal==NULL)
         cout<<"Kosong"<<endl;
    else
    {
        temp=awal;
        while(temp!=NULL)
        {
           	cout<<temp->no_punggung<<" -> "<<temp->nama<<" -> "<<temp->posisi<<endl;
           temp=temp->next;
        }
    }
    getch();
}
