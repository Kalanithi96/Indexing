#include"avl.h"

template<class U>
class index{
    private:
        avl::avl<pair<int,int>> Ind;
        int last;
    public:
        index(char *name){
            ifstream f;
            f.open(name,ios::in);
            U obj;
            int i=0;
            while(f.read((char*)&obj, sizeof(U))){
                pair<int,int> p(obj.id,i);
                Ind+=p;
                i++;
            }
            last=i;
            f.close();
        }
        void print(avl::node<pair<int,int>> *root){
            if(root!=0)
            {
                print(root->getLeft());
                cout<<root->getData().first<<" "<<root->getData().second<<endl;
                print(root->getRight());
            }
        }
        void dis(){
            print(Ind.getRoot());
        }
        bool getIndex(int a,int &ind){
            avl::node<pair<int,int>> *parent=0,*temp=Ind.getRoot();
            while(temp!=0){
                if(a==temp->getData().first){
                    ind=temp->getData().second;
                    return true;
                }
                else if (a<temp->getData().first){
                    parent=temp;
                    temp=temp->getLeft();
                }
                else{
                    parent=temp;
                    temp=temp->getRight();
                }
            }
            return false;
        }
        void reset(){
            avl::node<pair<int,int>> *r=Ind.getRoot();
            while(r!=0){
                pair<int,int> p=r->getData();
                Ind-=p;
                r=Ind.getRoot();
            }
            last=0;
        }
        void setIndices(char *name){
            ifstream f;
            f.open(name,ios::in);
            U obj;
            int i=0;
            while(f.read((char*)&obj, sizeof(U))){
                pair<int,int> p(obj.id,i);
                Ind+=p;
                i++;
            }
            last=i;
            f.close();
        }
        void ins(U &obj){
            pair<int,int> p(obj.id,last);
            Ind+=p;
            last++;
        }
        ~index(){
            avl::node<pair<int,int>> *r=Ind.getRoot();
            while(r!=0){
                pair<int,int> p=r->getData();
                Ind-=p;
                r=Ind.getRoot();
            }
        }
};
