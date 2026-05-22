#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;


    //Constructor created that accepts the value val of int data type 
    node(int val) : data(val), next(nullptr){}
};

/*Void function: gives no return; this functioon is
used to print the list, untill the nullptr is found
the value of the list is printed and the next value
is stored in the current */
void printList(node* head){
    node* current=head;

    cout<<"List: ";
    while(current!=nullptr){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"NULL\n";
}

/*This function is used to find the target value in the
linked list, by checking every data value and then
findign the right one*/
bool searchList(node* head, int target){
    node* current=head;

    while(current!=nullptr){
        if(current->data==target){
            return true;
        }
        current=current->next;
    }
    return false;
}

/*in C++ it is important to free the memory that we are using*/

void freeList(node* head){
    node* current=head;
    while(current!=nullptr){
        node* nextNode=current->next;

        /*delete: A unique C++ keyword. It unallocates the heap memory 
        used by that node and safely hands it back to your computer system.*/
        delete current;
        current=nextNode;
    }
}

int main(){

    node* head=new node(10);
    node* second=new node(20);
    node* third=new node(30);

    head->next=second;//we are setting the poi
    second->next=third;

    printList(head);

    int lookFor=20;

    if(searchList(head,lookFor)){
        cout<<"target"<<lookFor<<"was found in the list!\n";
    }
    else{
        cout<<"target"<<lookFor<<"is not in the list.\n";
    }

    freeList(head);
    head=nullptr;

    return 0;
}
