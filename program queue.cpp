#include <iostream>
#include <conio.h>
#include <string.h>

 using namespace std;
 
 struct simpul{
    char nama[50],posisi[50];
    int no;
    simpul *next;
}*depan=NULL,*belakang=NULL,*temp=NULL;
 class Queue{
public:
    void enQueue(int no,char nama[],char posisi[]);
    void deQueue();
    void displayQueue();
};

void Queue::enQueue(int no, char nama[], char posisi[]){
    temp = new simpul;
    temp->no = no;
    strcpy(temp->nama,nama);
    strcpy(temp->posisi,posisi);
    temp->next = NULL;
    if(depan == NULL){
        depan = temp;
        belakang = temp;
    } else{
        belakang->next = temp;
        belakang =temp;
    }
}

 void Queue::deQueue() {
    if (depan==NULL){
        cout<<"Queue Empty"<<endl;
    } else{
        temp = depan;
        depan=depan->next;
        delete temp;
    }
}

void Queue::displayQueue() {
    if(depan==NULL){
        cout<<"Queue Empty"<<endl;
        return;
    }
    for (temp = depan; temp !=NULL ; temp=temp->next){
        cout<<temp->no<<"->"<<temp->nama<<"->"<<temp->posisi<<endl;
    }
}

int main() {
    Queue queue;
    int pilih;
    while (true){
        cout<<"-------------------"<<endl;
        cout<<"	|QUEUE|"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1. EnQueue"<<endl;
        cout<<"2. DeQueue"<<endl;
        cout<<"3. Display Queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Masukkan Pilihan : ";cin>>pilih;
        switch (pilih){
            case 1: {
                simpul node;
                cout<<endl;
                cout << "Data Pemain Sepak Bola"<< endl;
                cout << "----------------------" << endl;
                cout << "Masukkan Nomor Punggung : ";
                cin>>node.no;
                cout << "Masukkan Nama Pemain    : ";
                cin.ignore(1);
                cin.getline(node.nama,50);
                cout << "Masukkan Posisi Pemain  : ";
                cin.getline(node.posisi,50);
                queue.enQueue(node.no, node.nama, node.posisi);
                break;
            }
            case 2:
                queue.deQueue();
                break;
            case 3:
                queue.displayQueue();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Out of Range";
        }
    }
}
