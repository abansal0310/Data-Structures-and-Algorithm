// #include<iostream>
// using namespace std;

// struct Queue{
//     int size,capacity;
//     int rear,front;
//     int *arr;
//     Queue(int x){
//         size=0;
//         capacity =x;
//         rear=front=0;
//         int *arr= new int [size];
//     }

//     bool isEmpty();
//     bool isFull();
//     void enqueue(int x);
//     void dequeue();
//     int peek();
// };

// bool Queue::isEmpty(){
//     if(size==0){
//         return true;
//     }
//     return false;
// }

// bool Queue::isFull(){
//     if(size==capacity){
//         return true;
//     }
//     return false;
// }

// void Queue::enqueue(int x){
//     if(isFull()){
//         cout<<"Overflow"<<endl;
//         return;
//     }
//     arr[rear]=x;
//     rear++;
//     size++;
// }

// void Queue::dequeue(){
//     if(isEmpty()){
//         cout<<"Underflow"<<endl;
//         return;
//     }
//     front++;
// }

// int Queue::peek(){
//     return arr[front]; 
// }

// int main(){
//     struct Queue s(5);
//     cout<<s.isEmpty()<<endl;
//     s.enqueue(1);
//     cout<<s.isEmpty()<<endl;
//     s.enqueue(2);
//     s.enqueue(3);
//     s.enqueue(4);
//     s.enqueue(5);
//     cout<<s.isFull()<<endl;
//     s.enqueue(6);
//     s.dequeue();
//     s.dequeue();
//     cout<<s.peek()<<endl;
// }

#include<iostream>
using namespace std;

// int min(int arr[],int a,int n){
//     int minn = a;
//     for(int i=a+1;i<n;i++){
//         if(arr[a]>arr[i]){
//             a=i;
//         }
//     }
//     return a;
// }

// void swap(int *a, int *b){
//     int temp;
//     temp=*a;
//     *a=*b;
//     *b=temp;
// }

// void sSort(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         int index = min(arr,i,n);
//         if(i!=index){
//             swap(arr[i],arr[index]);
//         }
//     }
// }

// int main(){
//     int arr[5]={4,3,5,1,2};
//     sSort(arr,5);
//     cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[4];
// }

struct Node{
    Node *next;
    int data;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void display(Node *head){
    Node *print = head;
    while(print != NULL){
        cout<<print->data<<" ";
        print=print->next;
    }
}

void delPos(Node * &head, int pos){
    Node* curr = head;
    Node * prev = NULL;

    if(head == NULL){
        return;
    }

    // if(pos == 1){
    //     head = head->next;
    //     delete curr;
    // }
    // else{
    //     int cnt = 1;
    //     while(cnt<pos && curr != NULL){
    //         prev=curr;
    //         curr=curr->next;
    //         cnt++;
    //     }

    //     prev->next=curr->next;
    //     delete curr;
    // }

    while(curr->next != NULL){
        
    }

    display(head);
}

int main(){
    Node *head = new Node(10);
    Node *num1 = new Node(20);
    Node *num2 = new Node(30);
    Node *num3 = new Node(40);
    Node *num4 = new Node(50);
    Node *num5 = new Node(60);

    head->next=num1;
    num1->next=num2;
    num2->next=num3;
    num3->next=num4;
    num4->next=num5;

    delPos(head,1);
}