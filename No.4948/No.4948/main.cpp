//
//  main.cpp
//  No.4948
//
//  Created by kyuhwan cho on 10/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//
#include <iostream>
#include <math.h>

using namespace std;
bool num[246913];


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    num[1] = true;
    int n;
    int cnt=0;
    for(int i=2; i<sqrt(246913); i++){
        for(int j=i+i; j<246913; j+=i){
            num[j] = true;
        }
    }
    while(1){
        cin>>n;
        cnt=0;
        if(n==0){
            break;
        }else{
            for(int i=n+1; i<=2*n; i++){
                if(!num[i]){
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
