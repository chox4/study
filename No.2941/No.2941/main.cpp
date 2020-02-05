//
//  main.cpp
//  No.2941
//
//  Created by kyuhwan cho on 05/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string ori_str,temp_str;
    cin>>ori_str;
    vector<string> str;
    temp_str=ori_str;
    int str_len = temp_str.length();
    str.reserve(8);
    str.push_back("c=");
    str.push_back("c-");
    str.push_back("dz=");
    str.push_back("d-");
    str.push_back("lj");
    str.push_back("nj");
    str.push_back("s=");
    str.push_back("z=");
    for(int i=0; i<str.size(); i++){
        int idx = temp_str.find(str[i]);
        int len = str[i].length();
        while(idx!=-1){
            temp_str.replace(idx,len,"!");
            str_len = str_len-len+1;
            idx = temp_str.find(str[i]);
        }
    }
    cout<<str_len<<"\n";
    return 0;
}
