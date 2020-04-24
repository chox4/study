//
//  main.cpp
//  No.5086
//
//  Created by kyuhwan cho on 2020/04/24.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#define endl "\n"
using namespace std;

int main(int argc, const char * argv[]) {
    int a,b;
    while(cin>>a>>b){
        if(a==0 && b==0){
            break;
        }
        if(a>b){
            int q = a/b;
            if(q*b==a){
                cout<<"multiple"<<endl;
            }
            else{
                cout<<"neither"<<endl;
            }
            
        }else{
            int q = b/a;
            if(q*a==b){
                cout<<"factor"<<endl;
            }else{
                cout<<"neither"<<endl;
            }
        }
    }
    return 0;
}
