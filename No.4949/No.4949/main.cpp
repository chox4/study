//
//  main.cpp
//  No.4949
//
//  Created by kyuhwan cho on 05/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
char stack[101];
int size;
void push(char c){
    stack[++size] = c;
}
char pop(){
    if(size == -1){
        return -1;
    }
    return stack[size--];
}
char top(){
    if(size == -1){
        return -1;
    }
    return stack[size];
}
int main(int argc, const char * argv[]) {
    while(1){
        string str;
        bool flag=true;
        size = -1;
        cin.clear();
        getline(cin,str);
        if(str[0]=='.'){
            break;
        }else{
            for(int i=0; i<str.length(); i++){
                if(str[i]=='(' || str[i]=='['){
                    push(str[i]);
                }else if(str[i]==')'){
                    if(pop()!='('){
                        flag = false;
                    }
                }else if(str[i]==']'){
                    if(pop()!='['){
                        flag = false;
                    }
                }
            }
        }
        if(top()!=-1){
            flag = false;
        }
        flag==true?cout<<"yes"<<endl:cout<<"no"<<endl;
    }
}
