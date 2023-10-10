/* Write a program to count the number of occurrences of a given key in a singly linked
 list and then delete all the occurrences. For example, if given linked list is 1->2->1-
 >2->1->3->1 and given key is 1, then output should be 4. After deletion of all the
 occurrences of 1, the linked list is 2->2->3.*/

 #include<iostream>
 using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x=0){
        data=x;
        next=NULL;
    }
};

int deleteKey(Node *head,int key){
    Node *curr = head->next;
    Node *prev=head;
    Node *nt = curr->next;

    while(nt!=NULL){
        if(curr->data == key){
            Node *temp = curr;
            curr=nt;
            delete temp;
            prev->next = curr;
            nt=nt->next;
        }
    }

    Node *print = head;
    while(print != NULL){
        cout<<print->data<<" ";
    }
}

int main(){

    Node *head = new Node(5);
    Node *num1 = new Node(2);
    Node *num2 = new Node(3);
    Node *num3 = new Node(1);
    Node *num4 = new Node(1);
    Node *num5 = new Node(6);

    head->next=num1;
    num1->next=num2;
    num2->next=num3;
    num3->next=num4;
    num4->next=num5;

    cout<<deleteKey(head,1)<<endl;
}