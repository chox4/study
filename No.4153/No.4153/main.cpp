//
//  main.cpp
//  No.4153
//
//  Created by kyuhwan cho on 2020/03/07.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long a[3];
    while(cin>>a[0]>>a[1]>>a[2]){
        if(a[0]==0 && a[1]==0 && a[2]==0){
            break;
        }else{
            for(int i=0; i<4; i++){
                a[i] *= a[i];
            }
            sort(a,a+3);
            if(a[0]+a[1]==a[2]){
                cout<<"right"<<"\n";
            }else{
                cout<<"wrong"<<"\n";
            }
        }
    }
    return 0;
}
