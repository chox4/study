//
//  main.cpp
//  No.17298
//
//  Created by kyuhwan cho on 11/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
int stack[1000001];
int nge[1000001];
int ans[1000001];
int size=-1;
void push(int num){
    stack[++size] = num;
}
int pop(){
    if(size==-1){
        return -1;
    }
    return stack[size--];
}
int top(){
    if(size==-1){
        return -1;
    }
    return stack[size];
}
bool empty(){
    if(size==-1)
        return true;
    return false;
}

int main(int argc, const char * argv[]) {
    int num, number, max_val=-1;
    cin>>num;
    int cnt = num-1;
    fill_n(nge,1000001,-1);
    fill_n(ans,1000001,-1);
    for(int i=1; i<num+1; i++){
        cin>>number;
        push(number);
        if(max_val<number){
            max_val = number;
        }
    }
    while(!empty()){
        int pop_val = pop();
        if(pop_val>top()){
                nge[top()] = pop_val;
                ans[cnt--] = pop_val;
        }else{
            int temp = pop_val;
            while(1){
                if(temp>top()){
                    nge[top()] = temp;
                    ans[cnt--] = temp;
                    break;
                }else{
                    if(temp == max_val||temp==-1){
                        nge[top()] = -1;
                        cnt--;
                        break;
                    }else{
                        temp = nge[temp];
                    }
                }
            }
        }
    }
    for(int i=1; i<num+1; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
