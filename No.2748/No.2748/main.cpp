//
//  main.cpp
//  No.2748
//
//  Created by kyuhwan cho on 21/07/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
unsigned long mem[91];
unsigned long fibonacci(int num){
    if(mem[num]!= -1){
        return mem[num];
    }else{
        if(num<2){
            mem[num] = num;
            return mem[num];
        }
        mem[num-1] = fibonacci(num-1);
        mem[num-2] = fibonacci(num-2);
        mem[num] = mem[num-1]+mem[num-2];
        return mem[num];
    }
}

int main(int argc, const char * argv[]) {
    int num;
    fill_n(mem,91,-1);
    cin>>num;
    unsigned long res = fibonacci(num);
    cout<<res<<endl;
}
