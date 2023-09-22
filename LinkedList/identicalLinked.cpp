#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x=0){
        data=x;
        next = nullptr;
    }
};

// struct LinkedList{

//     Node *head;
//     Node *ptr;
    
//     LinkedList(){
//     }

//     void push(int x){
//         Node *temp= new Node(x);
//         if(head->next == nullptr){
//             head = temp;
//             ptr = head;
//             ptr = ptr->next;
//         }
//         else{

//         }
//     }
// };

void checkList(Node *l1, Node *l2){
    Node *ptr1 = l1;
    Node *ptr2 = l2;

    while(ptr1->next != nullptr && ptr2->next != nullptr){
        if(ptr1->data != ptr2->data){
            cout<<"Not Identical"<<endl;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
}

int main(){
    Node *head1 = new Node(10);
    Node *head2 = new Node(10);
    Node *num1 = new Node(20);
    Node *num2 = new Node(30);
    Node *num3 = new Node(40);
    Node *num4 = new Node(50);
    Node *num5 = new Node(60);

    head1->next=num1;
    head2->next=num1;
    num1->next=num2;
    num2->next=num3;
    num3->next=num4;
    num4->next=num5;

    checkList(head1,head2);
}