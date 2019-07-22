//
//  main.cpp
//  No.2579
//
//  Created by kyuhwan cho on 21/07/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

unsigned long stair[301];
unsigned long mem[301];

unsigned long max_score(int num){
    if(mem[num]!= -1){
        return mem[num];
    }else{
        if(num==0){
            mem[num] = stair[num];
            return mem[num];
        }else if(num==1){
            mem[num] = max(stair[1],stair[0]+stair[1]);
            return mem[num];
        }else if(num==2){
            mem[num] = max(stair[0]+stair[2],stair[1]+stair[2]);
            return mem[num];
        }else{
            mem[num-3] = max_score(num-3);
            mem[num-2] = max_score(num-2);
            mem[num-1] = max_score(num-1);
            mem[num] = max(mem[num-3]+stair[num-1]+stair[num],mem[num-2]+stair[num]);
            return mem[num];
        }
    }
    return mem[num-1];
}

int main(){
    fill_n(mem,301,-1);
    int stair_num;
    cin>>stair_num;
    for(int i=0; i<stair_num; i++){
        cin>>stair[i];
    }
    cout<<max_score(stair_num-1)<<endl;
//    for(int i=0; i<stair_num; i++){
//        cout<<mem[i]<<" ";
//    }
//    cout<<endl;
}
