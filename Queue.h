#ifndef QUEUE
#define QUEUE 0
namespace Queue{
    template<class T>
    class Link{
        private:
            T elt;
            Link<T> *left;
            Link<T> *right;
            template<class U>friend class Queue;
        public:
            Link();
            Link(T&);
    };
    template<class T>
    class Queue{
        private:
            int count;
            Link<T> *front;
            Link<T> *rear;
        public:
            Queue();
            Link<T>* getFront();
            void Push(T&);
            T& Pop();
    };
    template<class T>
    Link<T>::Link(){
        elt=0;
        left=0;
        right=0;
    }
    template<class T>
    Link<T>::Link(T &elt){
        this->elt=elt;
        left=0;
        right=0;
    }
    template<class T>
    Queue<T>::Queue(){
        count=0;
        front=0;
        rear=0;
    }
    template<class T>
    Link<T>* Queue<T>::getFront(){
        return front;
    }
    template<class T>
    T& Queue<T>::Pop(){
        if(count==0){
            cout<<"Queue is empty";
            exit(0);
        }
        else{
            Link<T> *tfree=front;
            T *ret=new T;
            *ret=tfree->elt;
            if(count==1)
            {
                front=rear=0;
                delete tfree;
                count--;
                return *ret;
            }
            else
            {
                front=front->right;
                tfree->right->left=tfree->left;
                tfree->left->right=tfree->right;
                delete tfree;
                count--;
                return *ret;
            }
        }
    }
    template<class T>
    void Queue<T>::Push(T &I){
        if(count!=0)
        {
            Link<T> *temp=new Link<T>(I);
            temp->right=front;
            temp->left=rear;
            rear->right=temp;
            front->left=temp;
            rear=rear->right;
            count++;
        }
        else
        {
            Link<T> *temp=new Link<T>(I);
            rear=temp;
            rear->left=rear;
            rear->right=rear;
            front=rear;
            count++;
        }
    }
}
#endif // QUEUE
