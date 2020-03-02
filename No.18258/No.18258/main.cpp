//
//  main.cpp
//  No.18258
//
//  Created by kyuhwan cho on 2020/03/02.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase;
    cin>>testCase;
    string str;
    int q[2000000];
    int f_idx=0;
    int b_idx=0;
    while(testCase--){
        cin>>str;
        if(str=="push"){
            int num;
            cin>>num;
            q[b_idx++] = num;
        }else if(str=="pop"){
            b_idx==f_idx?cout<<"-1"<<"\n":cout<<q[f_idx++]<<"\n";
        }else if(str=="size"){
            cout<<b_idx-f_idx<<"\n";
        }else if(str=="empty"){
            b_idx==f_idx?cout<<"1"<<"\n":cout<<"0"<<"\n";
        }else if(str=="front"){
            b_idx==f_idx?cout<<"-1"<<"\n":cout<<q[f_idx]<<"\n";
        }else if(str=="back"){
            b_idx==f_idx?cout<<"-1"<<"\n":cout<<q[b_idx-1]<<"\n";
        }
    }
}
