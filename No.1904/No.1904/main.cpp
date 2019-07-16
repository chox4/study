//
//  main.cpp
//  No.1904
//
//  Created by kyuhwan cho on 16/07/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

unsigned long mem[1000001];

unsigned long floor(int num){
    if(mem[num]!=-1){
        return mem[num];
    }else{
        if(num==1){
            mem[num]=1;
            return mem[num];
        }else if(num==2){
            mem[num]=2;
            return mem[num];
        }else{
            mem[num-1] = floor(num-1);
            mem[num-2] = floor(num-2);
            return mem[num-1]+mem[num-2];
        }
    }
}

int main(int argc, const char * argv[]) {
    fill_n(mem,1000000,-1);
    int num;
    cin>>num;
    unsigned long res = floor(num);
    cout<<res%15746<<endl;
    
}
// 1-> 1
// 2-> 2
// 3-> 001 , 100, 111 -> 3
// 4 -> 0000, 0011, 1001, 1100, 1111 -> 5
// 5 -> 00001, 00100, 10000, 00111, 10011, 11001, 11100, 11111 -> 8
// n -> n-2+n-1;
