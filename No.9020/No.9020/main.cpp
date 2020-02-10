//
//  main.cpp
//  No.9020
//
//  Created by kyuhwan cho on 10/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;
bool num[10001];


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    num[1] = true;
    for(int i=2; i<sqrt(10001); i++){
        for(int j=i+i; j<10001; j+=i){
            num[j] = true;
        }
    }
    int testCase,number;
    cin>>testCase;
    int min;
    int n1,n2;
    for(int i=0; i<testCase; i++){
        cin>>number;
        min=9999;
        for(int i=2; i<=number/2; i++){
            if(!num[i] && !num[number-i]){
                if(min>(number-2*i)){
                    n1 = i;
                    n2 = number-i;
                    min = number-2*i;
                }
            }
        }
        cout<<n1<<" "<<n2<<"\n";
    }
    return 0;
}

