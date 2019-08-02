//
//  main.cpp
//  No.10844
//
//  Created by kyuhwan cho on 02/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#define MOD 1000000000
using namespace std;
unsigned long long int mem[101][10];

unsigned long long int floor(int size, int lastNum){
    if(mem[size][lastNum]!=0){
        return mem[size][lastNum];
    }
    if(size==1){
        return 1;
    }
    if(lastNum==0){
        mem[size][lastNum] = floor(size-1,1)%MOD;
        return mem[size][lastNum];
    }else if(lastNum==9){
        mem[size][lastNum] = floor(size-1,8)%MOD;
        return mem[size][lastNum];
    }else{
        mem[size][lastNum] = floor(size-1,lastNum-1)%MOD + floor(size-1,lastNum+1)%MOD;
        return mem[size][lastNum];
    }
}

int main(){
    for(int i=0; i<101; i++){
        fill_n(mem[i],10,0);
    }
    int size;
    unsigned long long int sum = 0;
    cin>>size;
    for(int i=1; i<10; i++){
        sum += floor(size,i)%MOD;
    }
    cout<<sum%MOD<<endl;
}

// 1 9
// 2 17
// 3 32
// 4 61
// 5 116
// 6 222
// 7 424
// 8 813
// 9 1556
// 10 2986
