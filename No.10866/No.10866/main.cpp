//
//  main.cpp
//  No.10866
//
//  Created by kyuhwan cho on 2020/03/04.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    Node(int num){
        this->num = num;
        this->next = NULL;
        this->prev = NULL;
    }
    int num;
    Node* next;
    Node* prev;
};
class deq{
private :
    Node* _front;
    Node* _back;
    int cnt=0;
public:
    void push_front(int num){
        if(!empty()){
            Node* newNode = new Node(num);
            newNode->next = _front;
            _front->prev = newNode;
            _front = newNode;
        }else{
            Node* newNode = new Node(num);
            _front = newNode;
            _back = newNode;
        }
        cnt++;
    }
    void push_back(int num){
        if(!empty()){
            Node* newNode = new Node(num);
            _back->next = newNode;
            newNode->prev = _back;
            _back = newNode;
        }else{
            Node* newNode = new Node(num);
            _front = newNode;
            _back = newNode;
        }
        cnt++;
    }
    int pop_front(){
        int rtn_num = -1;
        if(!empty()){
            Node* rtn_node = _front;
            rtn_num = rtn_node->num;
            if(size()==1){
                _front = NULL;
                _back = NULL;
                delete rtn_node;
                rtn_node=NULL;
            }else{
                Node* tmp = rtn_node->next;
                tmp->prev = NULL;
                rtn_node->next = NULL;
                delete rtn_node;
                rtn_node=NULL;
                _front = tmp;
            }
            cnt--;
        }
        return rtn_num;
    }
    int pop_back(){
        int rtn_num = -1;
        if(!empty()){
            Node* rtn_node = _back;
            rtn_num = rtn_node->num;
            if(size()==1){
                _back = NULL;
                _front = NULL;
                delete rtn_node;
                rtn_node=NULL;
            }else{
                Node* tmp = rtn_node->prev;
                tmp->next = NULL;
                rtn_node->prev = NULL;
                _back = tmp;
                delete rtn_node;
                rtn_node=NULL;
            }
            cnt--;
        }
        return rtn_num;
    }
    int size(){
        return this->cnt;
    }
    int empty(){
        if(size())
            return 0;
        else
            return 1;
    }
    int front(){
        int rtn_num = -1;
        if(!empty()){
            rtn_num = _front->num;
        }
           return rtn_num;
    }
    int back(){
        int rtn_num = -1;
        if(!empty()){
            rtn_num = _back->num;
        }
        return rtn_num;
    }
    void print(){
        Node* tmp = _front;
        while(tmp!=NULL){
            cout<<tmp->num<<" ";
            tmp = tmp->next;
        }
        cout<<"\n";
    }
};


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    deq d;
    int testCase;
    cin>>testCase;
    string str;
    while(testCase--){
        cin>>str;
        if(str=="push_back"){
            int num;
            cin>>num;
            d.push_back(num);
        }else if(str=="push_front"){
            int num;
            cin>>num;
            d.push_front(num);
        }else if(str=="pop_front"){
            cout<<d.pop_front()<<"\n";
        }else if(str=="pop_back"){
            cout<<d.pop_back()<<"\n";
        }else if(str=="size"){
            cout<<d.size()<<"\n";
        }else if(str=="empty"){
            cout<<d.empty()<<"\n";
        }else if(str=="front"){
            cout<<d.front()<<"\n";
        }else if(str=="back"){
            cout<<d.back()<<"\n";
        }
        d.print();
    }
    return 0;
}
