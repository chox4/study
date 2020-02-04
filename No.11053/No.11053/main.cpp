//
//  main.cpp
//  No.11053
//
//  Created by kyuhwan cho on 02/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int seq[1001];
int mem[1001];

void max_len(int len){
    for(int i=0; i<len; i++){
        mem[i] = 1;
        for(int j=0; j<i; j++){
            if(seq[j]<seq[i] && mem[j]+1>mem[i]){
                mem[i] = mem[j]+1;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fill_n(seq,1001,-1);
    fill_n(mem,1001,-1);
    int testCase,num;
    cin>>testCase;
    for(int i=0; i<testCase; i++){
        cin>>num;
        seq[i] = num;
    }
    max_len(testCase);
    sort(mem,mem+testCase);
    cout<<mem[testCase-1]<<"\n";
}
