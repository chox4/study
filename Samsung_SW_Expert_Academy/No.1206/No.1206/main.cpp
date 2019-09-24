//
//  main.cpp
//  No.1206
//
//  Created by kyuhwan cho on 24/09/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

int building[1004];

int main(int argc, const char * argv[]) {
    for(int i=1; i<11; i++){
        int testCase;
        int cnt=0;
        cin>>testCase;
        for(int i=0; i<testCase; i++){
            cin>>building[i+2];
        }
        for(int i=0; i<testCase; i++){
            int l_res1 = building[i+2]-building[i+1];
            int l_res2 = building[i+2]-building[i];
            int r_res1 = building[i+2]-building[i+3];
            int r_res2 = building[i+2]-building[i+4];
            if(l_res1>0&&l_res2>0&&r_res1>0&&r_res2>0){
                cnt = cnt+ min(min(l_res1,l_res2),min(r_res1,r_res2));
            }
        }
        cout<<"#"<<i<<" "<<cnt<<endl;
    }
}
