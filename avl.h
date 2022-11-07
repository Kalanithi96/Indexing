#include"Stack.h"
#include"Queue.h"
#ifndef AVL
#define AVL 0
namespace avl{
    template<class T>
    class node{
        private:
            node<T> *right;
            node<T> *left;
            T data;
        public:
            template<class U>friend class avl;
            template<class V>friend void display(node<V>*);
            template<class V>friend void level_order(node<V>*);
            template<class V>friend void pre_order(node<V>*);
            template<class V>friend void in_order(node<V>*);
            template<class V>friend void post_order(node<V>*);
            template<class V>friend void pre_order_iter(node<V>*);
            template<class V>friend void in_order_iter(node<V>*);
            template<class V>friend void post_order_iter(node<V>*);
            template<class Y>friend int height(node<Y>*);
            template<class Y>friend int difference(node<Y>*);
            node<T>();
            node<T>(T);
            node<T>* getLeft();
            node<T>* getRight();
            T getData();
    };
    template<class T>
    node<T>::node(){
        right=0;
        left=0;
        data=0;
    }
    template<class T>
    node<T>::node(T data){
        right=0;
        left=0;
        this->data=data;
    }
    template<class T>
    node<T>* node<T>::getLeft(){
        return left;
    }
    template<class T>
    node<T>* node<T>::getRight(){
        return right;
    }
    template<class T>
    T node<T>::getData(){
        return data;
    }
    template<class T>
    class avl{
        private:
            node<T> *root;
            int size;
            node<T>* LRRotation(node<T>*);
            node<T>* LLRotation(node<T>*);
            node<T>* RLRotation(node<T>*);
            node<T>* RRRotation(node<T>*);
            node<T>* balance(node<T>*);
            node<T>* del_balance(node<T>*);
        public:
            avl<T>();
            avl<T>(T[],int);
            node<T>* getRoot() const;
            int getSize() const;
            void setRoot(node<T>*);
            node<T>* insertion(node<T>*,T);
            void ins(T);
            node<T>* deletion(node<T>*,node<T>*,T);
            void del(T);
            void search(T) const;
            void operator += (T&);
            void operator -= (T&);
            T* GetSorted();
    };
    template<class T>
    avl<T>::avl(){
        size=0;
        root=0;
    }
    template<class T>
    avl<T>::avl(T data[],int n){
        root=0;
        for(int i=0;i<n;i++)
            ins(data[i]);
    }
    template<class T>
    node<T>* avl<T>::getRoot() const{
        return root;
    }
    template<class T>
    int avl<T>::getSize() const{
        return size;
    }
    template<class T>
    void avl<T>::setRoot(node<T> *root){
        this->root=root;
    }
    template<class T>
    void avl<T>::search(T se)const{
        node<T> *parent=0,*temp=root;
        while(temp!=0)
        {
            if(se==temp->data)
            {
                cout<<"Element Found!!!";
                return;
            }
            else if (se<temp->data)
            {
                parent=temp;
                temp=temp->left;
            }
            else
            {
                parent=temp;
                temp=temp->right;
            }
        }
        if(temp==0)
        {
            cout<<"Element Not Found!!!";
            return;
        }
    }
    template<class T>
    void display(node<T> *root){
        if(root!=0)
        {
            display(root->left);
            cout<<root->data<<" ";
            display(root->right);
        }
    }
    template<class T>
    node<T>* avl<T>::RRRotation(node<T> *parent) {
       node<T> *temp;
       temp = parent->right;
       parent->right = temp->left;
       temp->left = parent;
       //cout<<"Right-Right Rotation";
       return temp;
    }
    template<class T>
    node<T>* avl<T>::LLRotation(node<T> *parent){
       node<T> *temp;
       temp = parent->left;
       parent->left = temp->right;
       temp->right = parent;
       //cout<<"Left-Left Rotation";
       return temp;
    }
    template<class T>
    node<T>* avl<T>::LRRotation(node<T> *parent){
       node<T> *temp;
       temp = parent->left;
       parent->left = RRRotation(temp);
       //cout<<"Left-Right Rotation";
       return LLRotation(parent);
    }
    template<class T>
    node<T>* avl<T>::RLRotation(node<T> *parent){
       node<T> *temp;
       temp = parent->right;
       parent->right = LLRotation(temp);
       //cout<<"Right-Left Rotation";
       return RRRotation(parent);
    }
    template<class T>
    node<T> *avl<T>::balance(node<T> *root) {
       if(root!=0){
            int bal = difference(root);
           if (bal > 1) {
              if (difference(root->left) > 0)
                 root = LLRotation(root);
              else
                 root = LRRotation(root);
           } else if (bal < -1) {
              if (difference(root->right) > 0)
                 root = RLRotation(root);
              else
                 root = RRRotation(root);
           }
       }
       return root;
    }
    template<class T>
    node<T> *avl<T>::del_balance(node<T> *root) {
       if(root!=0){
            int bal = difference(root);
           if (bal > 1) {
              if (difference(root->left) >= 0)
                 root = LLRotation(root);
              else
                 root = LRRotation(root);
           } else if (bal < -1) {
              if (difference(root->right) < 1)
                 root = RLRotation(root);
              else
                 root = RRRotation(root);
           }
       }
       return root;
    }
    template<class T>
    int height(node<T> *root){
        int h=0;
        if(root!=0){
            int l_height=height(root->left);
            int r_height=height(root->right);
            int max_h=((l_height>r_height)?l_height:r_height);
            h=max_h+1;
        }
        return h;
    }
    template<class T>
    int difference(node<T> *root){
        if(root==0)
            return 0;
        int l_height=height(root->left);
        int r_height=height(root->right);
        return (l_height-r_height);
    }
    template<class T>
    node<T>* avl<T>::insertion(node<T> *root, T value) {
       if (root==0) {
          root = new node<T>(value);
          return root;
       } else if (value < root->data) {
          root->left=insertion(root->left,value);
          root=balance(root);
       } else if (value >= root->data) {
          root->right=insertion(root->right, value);
          root=balance(root);
       }
       return root;
    }
    template<class T>
    void avl<T>::ins(T value){
        size++;
        root=insertion(root,value);
    }
    template<class T>
    void avl<T>::operator += (T &value){
        ins(value);
    }
    template<class T>
    void avl<T>::del(T value){
        root=deletion(root,0,value);
    }
    template<class T>
    void avl<T>::operator -= (T &value){
        del(value);
    }
    template<class T>
    node<T>* avl<T>::deletion(node<T> *root,node<T> *parent,T out){
        if(root==0){
            cout<<"Element Not Found!!";
        }
        else{
            size--;
            if(out<root->data){
                root->left=deletion(root->left,root,out);
            }
            else if(out>root->data){
                root->right=deletion(root->right,root,out);
            }
            else{
                node<T> *temp;
                if(root->left==0 && root->right==0){
                    temp=root;
                    if(parent==0){
                        root=0;
                    }
                    else
                        if(parent->data > out){
                            parent->left=0;
                            root=0;
                        }
                        else{
                            parent->right=0;
                            root=0;
                        }
                    delete temp;
                }
                else if(root->left==0){
                    temp=root;
                    if(parent==0){
                        root=root->right;
                    }
                    else{
                        if(parent->data > out){
                            parent->left=root->right;
                            root=parent->left;
                        }
                        else{
                            parent->right=root->right;
                            root=parent->right;
                        }
                    }
                    delete temp;
                }
                else if(root->right==0){
                    temp=root;
                    if(parent==0){
                        root=root->left;
                    }
                    else{
                        if(parent->data > out){
                            parent->left=root->left;
                            root=parent->left;
                        }
                        else{
                            parent->right=root->left;
                            root=parent->right;
                        }
                    }
                    delete temp;
                }
                else
                {
                    node<T> *temp1=root->right,*parent1=0;
                    T mini=temp1->data;
                    while(temp1->left!=0)
                    {
                        parent1=temp1;
                        temp1=temp1->left;
                        mini=temp1->data;
                    }
                    if(mini == root->right->data)
                    {
                        root->data=mini;
                        temp1=root->right;
                        root->right=root->right->right;
                        delete (temp1);
                    }
                    else
                    {
                        root->data=mini;
                        parent1->left=temp1->right;
                        delete temp1;
                    }
                }
            }
            root=del_balance(root);
        }
        return root;
    }
    template<class T>
    T* avl<T>::GetSorted(){
        T *ret=new T[size];
        int i=0;
        Stack::Stack<node<T>*> S;
        S.Push(0);
        node<T> *ptr=root;
        L1:
        while(ptr!=0)
        {
            S.Push(ptr);
            ptr=ptr->left;
        }
        ptr=S.Pop();
        if(ptr)ret[i++]=ptr->data;
        while(ptr!=0)
        {
            if(ptr->right!=0)
            {
                ptr=ptr->right;
                goto L1;
            }
            ptr=S.Pop();
            if(ptr)ret[i++]=ptr->data;
        }
        return ret;
    }
    template<class T>
    void level_order(node<T> *root){
        int n=0;
        Queue::Queue<node<T>*> Q;
        node<T> *temp;
        cout<<root->data<<" ";
        Q.Push(root);
        while(Q.getFront()!=0)
        {
            temp=Q.Pop();
            if(temp->left!=0)
            {
                cout<<temp->left->data<<" ";
                Q.Push(temp->left);
            }
            if(temp->right!=0)
            {
                cout<<temp->right->data<<" ";
                Q.Push(temp->right);
            }
        }
    }
    template<class T>
    void pre_order(node<T> *root){
        if(root!=0)
        {
            cout<<root->data<<" ";
            pre_order(root->left);
            pre_order(root->right);
        }
    }
    template<class T>
    void in_order(node<T> *root){
        if(root!=0)
        {
            in_order(root->left);
            cout<<root->data<<" ";
            in_order(root->right);
        }
    }
    template<class T>
    void post_order(node<T> *root){
        if(root!=0)
        {
            post_order(root->left);
            post_order(root->right);
            cout<<root->data<<" ";
        }
    }
    template<class T>
    void pre_order_iter(node<T> *root){
        Stack::Stack<node<T>> S;
        S.Push(0);
        node<T> *ptr=root;
        while(ptr!=0)
        {
            cout<<ptr->data<<" ";
            if(ptr->right!=0)
                S.Push(ptr->right);
            if(ptr->left!=0)
                ptr=ptr->left;
            else
                ptr=S.Pop();
        }
    }
    template<class T>
    void in_order_iter(node<T> *root){
        Stack::Stack<node<T>> S;
        S.Push(0);
        node<T> *ptr=root;
        L1:
        while(ptr!=0)
        {
            S.Push(ptr);
            ptr=ptr->left;
        }
        ptr=S.Pop();
        cout<<ptr->data<<" ";
        while(ptr!=0)
        {
            if(ptr->right!=0)
            {
                ptr=ptr->right;
                goto L1;
            }
            ptr=S.Pop();
            cout<<ptr->data<<" ";
        }
    }
    template<class T>
    void post_order_iter(node<T> *root){
        Stack::Stack<node<T>*> S;
        S.Push(0);
        node<T> *ptr=root;
        Stack::Stack<node<T>*> SI;
        SI.Push(0);
        node<T> *si;
        L1:
        while(ptr!=0)
        {
            S.Push(ptr);
            si=new node<T>;
            si->data=1;
            SI.Push(si);
            if(ptr->right!=0)
            {
                S.Push(ptr->right);
                si=new node<T>;
                si->data=-1;
                SI.Push(si);
            }
            ptr=ptr->left;
        }
        ptr=S.Pop();
        si=SI.Pop();
        while(si!=0 && si->data>0)
        {
            cout<<ptr->data<<" ";
            ptr=S.Pop();
            si=SI.Pop();
        }
        if(si!=0 && si->data<0)
        {
            si->data *= -1;
            goto L1;
        }
    }
    /*
    template<class T>
    void in_order_iter_own(node<T> *root)
    {
        Stack::Stack<node<T>> S;
        S.Push(0);
        node<T> *ptr=root;
        while(ptr!=0)
        {
            if(ptr->left!=0)
            {
                S.Push(ptr);
                ptr=ptr->left;
            }
            else
            {
                if(ptr->right!=0)
                {
                    cout<<ptr->data<<" ";
                    ptr=ptr->right;
                }
                else
                {
                    while(ptr!=0 && ptr->right==0)
                    {
                        cout<<ptr->data<<" ";
                        ptr=S.Pop();
                    }
                    if(ptr!=0)
                    {
                        cout<<ptr->data<<" ";
                        ptr=ptr->right;
                    }
                }
            }
        }
    } */
}
#endif
