//
//  main.cpp
//  No.11866
//
//  Created by kyuhwan cho on 13/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
public:
    int num;
    Node* next;
    Node(){
        this->next=NULL;
    }
    Node(int num){
        this->num = num;
        this->next=NULL;
    }
};
class Queue{
public:
    Node* head;
    Node* tail;
    Node* pre_node;
    int q_size=0;
    void push(int num){
        Node* newNode = new Node(num);
        if(empty()){
            head = newNode;
            tail = newNode;
            pre_node = head;
        }else{
            tail->next = newNode;
            tail = newNode;
            newNode->next = head;
        }
        q_size++;
    }
    int n_pop(int num){
        int val=0;
        Node* pop_node;
        Node* post_node;
        if(num==1){
            pop_node = head;
            val = pop_node->num;
            head = pop_node->next;
            delete pop_node;
            q_size--;
            return val;
        }
        num = num-2;
        for(int i=0; i<num; i++){
            pre_node = pre_node->next;
        }
        pop_node = pre_node->next;
        post_node = pre_node->next->next;
        val = pop_node->num;
        pop_node->next = NULL;
        pre_node->next = post_node;
        pre_node = post_node;
        q_size--;
        return val;
    }
    bool empty(){
        return q_size==0?true:false;
    }
};

int main(int argc, const char * argv[]) {
    int N, k;
    cin>>N>>k;
    Queue q;
    for(int i=0; i<N; i++){
        q.push(i+1);
    }
    cout<<"<";
    while(!q.empty()){
        if(q.q_size==1){
            cout<<q.n_pop(k);
        }else{
            cout<<q.n_pop(k)<<", ";
        }
    }
    cout<<">"<<endl;
    
}

/*
 
  이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-조세퍼스 순열이라고 한다. 예를 들어 (7, 3)-조세퍼스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
 */

//1 2 3 4 5 6 7
//6 3 1 7 5 2 4
