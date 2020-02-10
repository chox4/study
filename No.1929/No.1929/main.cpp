//
//  main.cpp
//  No.1929
//
//  Created by kyuhwan cho on 10/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;
bool num[1000001];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    num[1] = true;
    for(int i=2; i<sqrt(1000001); i++){
        for(int j=i+i; j<1000001; j+=i){
            num[j] = true;
        }
    }
    int min,max;
    cin>>min>>max;
    for(int i=min; i<=max; i++){
        if(!num[i]){
            cout<<i<<"\n";
        }
    }
    return 0;
}
