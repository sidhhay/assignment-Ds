#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;

public:
    Node(int value){
        data = value;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = NULL;
    }

    
};
int main(){

}