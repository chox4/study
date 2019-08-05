//
//  main.cpp
//  No.10828
//
//  Created by kyuhwan cho on 05/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
int arr[10001];
int topIndex;
void push(int val){
    arr[++topIndex]=val;
}
int pop(){
    return topIndex==-1?-1:arr[topIndex--];
}
int size(){
    return topIndex+1;
}
bool empty(){
    return topIndex==-1?true:false;
}
int top(){
    return topIndex==-1?-1:arr[topIndex];
}
int main(int argc, const char * argv[]) {
    int num,val;
    cin>>num;
    topIndex=-1;
    string op;
    while(num--){
        cin>>op;
        if(op=="push"){
            cin>>val;
            push(val);
        }else if(op=="pop"){
            cout<<pop()<<endl;
        }else if(op=="size"){
            cout<<size()<<endl;
        }else if(op=="empty"){
            cout<<empty()<<endl;
        }else if(op=="top"){
            cout<<top()<<endl;
        }
    }
}

