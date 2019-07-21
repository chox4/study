//
//  main.cpp
//  No.9461
//
//  Created by kyuhwan cho on 21/07/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
unsigned long mem[101];
unsigned long tri(int num){
    if(mem[num] != -1){
        return mem[num];
    }else{
        if(num<4){
            mem[num]=1;
            return mem[num];
        }else{
            mem[num-2] = tri(num-2);
            mem[num-3] = tri(num-3);
            mem[num]= mem[num-2]+mem[num-3];
            //cout<<mem[num]<<" "<<mem[num-2]<<" "<<mem[num-3]<<endl;
            return mem[num];
        }
    }
}
int main(int argc, const char * argv[]) {
    int testCase;
    int num;
    cin>>testCase;
    fill_n(mem,101,-1);
    while(testCase--){
        cin>>num;
        cout<<tri(num)<<endl;
    }
}


// 1 1 1 2 2 3 4 5 7 9 12 16
// f(n) = f(n-2)+f(n-3)
// f(12) = f(10)+f(9)
