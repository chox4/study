//
//  main.cpp
//  No.2164
//
//  Created by kyuhwan cho on 13/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
int queue[10000001];
int head;
int tail;
int q_size=0;

void pop(){
    queue[head] = -1;
    head++;
    q_size--;
}
void go_tail(){
    queue[tail+1] = queue[head];
    queue[head] = -1;
    tail++;
    head++;
}
int size(){
    return q_size;
}
int last_card(){
    int flag=1;
    while(1){
        if(size()==1){
            break;
        }
        else{
            if(flag==1){
                pop();
                flag=2;
            }else{
                go_tail();
                flag=1;
            }
        }
    }
    return queue[head];
}
int main(int argc, const char * argv[]) {
    int number;
    cin>>number;
    fill_n(queue,500001,-1);
    head = 1; tail = number; q_size = number;
    for(int i=1; i<=number; i++){
        queue[i] = i;
    }
    cout<<last_card()<<endl;
}

/*
 예를 들어 N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다. 1을 버리면 234가 남는다.
 여기서 2를 제일 아래로 옮기면 342가 된다. 3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다. 마지막으로 2를 버리고 나면, 남는 카드는 4가 된다.
 
 */
