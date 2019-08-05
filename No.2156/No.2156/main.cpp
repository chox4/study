//
//  main.cpp
//  No.2156
//
//  Created by kyuhwan cho on 02/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
int wine[10001];
int mem[10001];

int max_wine(int wineNum){
    if(mem[wineNum]!=-1){
        return mem[wineNum];
    }else{
        if(wineNum==1){
            mem[wineNum] = wine[1];
            return mem[wineNum];
        }else if(wineNum==2){
            mem[wineNum] = wine[1]+wine[2];
            return mem[wineNum];
        }else if(wineNum==3){
            mem[wineNum] = max(max(wine[1],wine[2])+wine[3],wine[1]+wine[2]);
            return mem[wineNum];
        }else{
            mem[wineNum-1] = max_wine(wineNum-1);
            mem[wineNum-2] = max_wine(wineNum-2);
            mem[wineNum-3] = max_wine(wineNum-3);
            mem[wineNum] = max(mem[wineNum-2],mem[wineNum-3]+wine[wineNum-1])+wine[wineNum];
            return max(mem[wineNum-1],mem[wineNum]);
        }
    }
}

int main(int argc, const char * argv[]) {
    fill_n(mem,10001,-1);
    int wineNum;
    cin>>wineNum;
    for(int i=1; i<=wineNum; i++){
        cin>>wine[i];
    }
    cout<<max_wine(wineNum)<<endl;
}

// n -> n-2 + n-3;
// n -> n-1 + n-3;

//6
//10
//13
//9           mem.10 + wine.9 ? mem.6+wine.13+wine.9
//                mem[n] = max(mem[n-2]+wine[n],mem[n-3]+wine[n0-1]+wine[]
//8
//1

