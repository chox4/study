//
//  main.cpp
//  No.9012
//
//  Created by kyuhwan cho on 05/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int num;
    string str;
    cin>>num;
    while(num--){
        int cnt=0;
        cin>>str;
        for(int i=0; i<str.length(); i++){
            str[i]=='('?cnt++:cnt--;
            if(cnt<0)break;
        }
        cnt==0?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}
