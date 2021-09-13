#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;


    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
void insertAtTail(node * &head , int val){
    // Function to insert node at tail
    node * n  = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node * temp =   head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = n;

}




void display(node * head){
    // Function to display all elements 
    node * temp = head;
    while (temp!=NULL)
    {
        cout << temp ->data << "->";
        temp = temp ->next;
    }
    cout <<"NULL"<< endl;
    
}



void insertAtHead(node * &head , int val){
    // Function to insert at head
    node * n = new node(val);
    n -> next = head;
    head = n;
}



void deleteAtHead(node * &head){
    // Function to delete at head
    node * todelete = head;
    head = head -> next;
    delete todelete;
}



void deletion(node * &head,int key){
    // Function to delete
    if(head == NULL){
        return;
    }
    if(head -> next == NULL){
        deleteAtHead(head);
        return;
    }
    node * temp = head;
    while(temp -> next -> data!= key){
        temp = temp -> next;
    }
    node * todelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete todelete;
}



bool search(node * head , int val){
    // Linear Search
    node * temp = head;
    while(temp!=NULL){
        if(temp -> data == val){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}



node * reverse(node * head){
    node * prevptr = NULL;
    node * currptr = head;
    node * nextptr;
    while(currptr!=NULL){
        nextptr = currptr -> next;
        currptr -> next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;

}



node * recursiveReverse(node * head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    node * newhead = recursiveReverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newhead;

}


node * kReverse(node *& head , int k){
    // Reverse liked list by k nodes
    node * currptr = head;
    node * prevptr = NULL;
    node * nextptr;
    int count = 0;
    while(currptr!= NULL && count < k){
        nextptr = currptr ->next;
        currptr -> next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(currptr!=NULL){
        head -> next = kReverse(currptr,k);
    }
    return prevptr;
}


void makeCycle(node * head , int pos){
    node * temp = head;
    node * cycleStart;
    int count = 1;
    while(temp -> next != NULL){
        if(count == pos){
            cycleStart = temp;
        }
        temp = temp -> next;
        count ++;
    }
    temp -> next = cycleStart;
}

bool cycleDetect(node * &head){
    node * slow = head;
    node * fast = head;

    while(fast!= NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void removeCycle(node * &head){
    node * slow = head;
    node * fast = head;
    do
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    } while (slow!=fast);
    fast = head;
    while(slow->next!=fast->next){
        slow = slow -> next;
        fast = fast -> next;
    }
    slow -> next = NULL;
}


int main(){
    node * head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    display(head);
    makeCycle(head,5);
    // display(head);
    // node * newhead = reverse(head);
    // display(newhead);
    // node * newhead2 = recursiveReverse(newhead);
    // node * newhead2 = kReverse(head,3);
   cout << cycleDetect(head) << endl;
   removeCycle(head);
   display(head);
}
