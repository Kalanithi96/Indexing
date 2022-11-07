#ifndef STACK
#define STACK 0
namespace Stack{
    template<class T>
    class Link{
        private:
            T elt;
            Link<T> *next;
            template<class U>friend class Stack;
        public:
            Link();
    };
    template<class T>
    class Stack{
        private:
            Link<T> *head;
        public:
            Stack();
            T& Pop();
            void Push(const T&);
    };
    template<class T>
    T& Stack<T>::Pop(){
        if(head==0){
            cout<<"Stack is Empty";
            exit(0);
        }
        else{
            T *p=new T;
            *p=head->elt;
            Link<T> *tfree=head;
            head=head->next;
            delete tfree;
            return *p;
        }
    }
    template<class T>
    void Stack<T>::Push(const T &p){
        Link<T> *temp=new Link<T>;
        temp->elt=p;
        temp->next=head;
        head=temp;
    }
    template<class T>
    Stack<T>::Stack(){
        head=0;
    }
    template<class T>
    Link<T>::Link(){
        elt=0;
        next=0;
    }
}
#endif // STACK
