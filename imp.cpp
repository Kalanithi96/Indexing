#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include"Index.h"
int main()
{
    struct emp{
        int id;
        char name[30];
    };


    emp e1={1,"kala"};
    emp e2={2,"kavi"};
    emp e3={3,"karu"};
    emp e4={4,"karl"};

    char name[]="EMP.txt";

    ofstream of;
    of.open(name,ios::out);

    of.write((char*)&e1,sizeof(e1));
    of.write((char*)&e2,sizeof(e2));

    of.close();

    index<emp> I(name);
    I.dis();

    I.reset();

    I.dis();

    of.open(name,ios::app);
    of.write((char*)&e3,sizeof(e3));
    of.close();

    I.setIndices(name);
    I.dis();

    of.open(name,ios::app);
    of.write((char*)&e4,sizeof(e4));
    I.ins(e4);
    of.close();

    I.dis();
/*
    avl::avl<int> temp;
    int ch,t;

    do{
        cout<<"\nMenu\n";
        cout<<"\t1.Insert\n";
        cout<<"\t2.Delete\n";
        cout<<"\t3.Search\n";
        cout<<"\t4.Display\n";
        cout<<"\t5.Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter the value to be inserted: ";
                    cin>>t;
                    temp+=t;
                    break;
            case 2: cout<<"Enter the value to be deleted: ";
                    cin>>t;
                    temp-=t;
                    break;
            case 3: cout<<"Enter the value to be searched: ";
                    cin>>t;
                    temp.search(t);
                    break;
            case 4: display(temp.getRoot());
                    break;
            case 5: break;
        }
    }while(ch!=5);

    int str[]={75,84,23,12,58,63,90,46};
    avl::avl<int> tr(str,8);

    display(tr.getRoot());
    int *srt=tr.GetSorted();
    cout<<endl<<tr.getSize()<<endl;
    for(int i=0;i<tr.getSize();i++)
        cout<<srt[i]<<" ";

    post_order_iter(tr.getRoot());
    cout<<endl;
    level_order(tr.getRoot());

*/


    return 0;
}
