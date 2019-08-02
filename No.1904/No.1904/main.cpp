//
//  main.cpp
//  No.1904
//
//  Created by kyuhwan cho on 16/07/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#define MOD 15746
using namespace std;

unsigned long long int mem[1000001];

unsigned long long int floor(int num){
    if(mem[num]!= -1){
        return mem[num]%MOD;
    }else{
        if(num<3){
            mem[num] = num;
            return mem[num];
        }else{
            mem[num-1] = floor(num-1)%MOD;
            mem[num-2] = floor(num-2)%MOD;
            mem[num] = mem[num-1]+mem[num-2];
            return mem[num];
        }
    }
}

int main(int argc, const char * argv[]) {
    fill_n(mem,1000001,-1);
    int num;
    cin>>num;
    cout<<floor(num)%MOD<<endl;
}

// n -> n-2+n-1;
// n -> 두자리 빠진 길이에서 00 추가 + 한자리 빠진 길이에서 1 추가

