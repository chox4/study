//
//  main.cpp
//  No.10870
//
//  Created by kyuhwan cho on 2020/03/07.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
int mem[21];
using namespace std;

int fibo(int num){
    if(mem[num]!=-1){
        return mem[num];
    }else{
        if(num<2){
            mem[num]=num;
            return mem[num];
        }else{
            mem[num-1] = fibo(num-1);
            mem[num-2] = fibo(num-2);
            mem[num] = mem[num-1]+mem[num-2];
            return mem[num];
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fill_n(mem,21,-1);
    int num;
    cin>>num;
    int answer = fibo(num);
    cout<<answer<<"\n";
    return 0;
}
