//
//  main.cpp
//  No.10845
//
//  Created by kyuhwan cho on 12/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//


// 일부러 linked list 방식으로 구현
#include <iostream>
using namespace std;

class Node{
public:
    int num;
    Node* next;
    Node(int num){
        this->num = num;
        this->next = NULL;
    }
    Node(){
        this->next = NULL;
    };
};

class Queue{
public:
    int q_size=0;
    Node* head;
    void push(int num){
        Node* newNode = new Node(num);
        Node* temp;
        if(size()==0){
            head = newNode;
            q_size++;
        }else{
            temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            q_size++;
        }
    }
    int pop(){
        if(size()==0){
            return -1;
        }else{
            Node* temp = head;
            head = temp->next;
            temp->next=NULL;
            int temp_num = temp->num;
            delete temp;
            q_size--;
            return temp_num;
        }
    }
    int size(){
        return q_size;
    }
    bool empty(){
        return size()==0?true:false;
    }
    int front(){
        if(size()==0){
            return -1;
        }
        return head->num;
    }
    int back(){
        if(size()==0){
            return -1;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        return temp->num;
    }
};


int main(int argc, const char * argv[]) {
    int op_num;
    cin>>op_num;
    int cnt=0;
    Queue q;
    while(1){
        if(cnt++==op_num)break;
        string op;
        cin>>op;
        if(op=="push"){
            int num;
            cin>>num;
            q.push(num);
        }else if(op=="pop"){
            cout<<q.pop()<<endl;
        }else if(op=="size"){
            cout<<q.size()<<endl;
        }else if(op=="empty"){
            cout<<q.empty()<<endl;
        }else if(op=="front"){
            cout<<q.front()<<endl;
        }else if(op=="back"){
            cout<<q.back()<<endl;
        }
    }
}


/*
 push X: 정수 X를 큐에 넣는 연산이다.
 pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 size: 큐에 들어있는 정수의 개수를 출력한다.
 empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
 front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 
 
 
 */
