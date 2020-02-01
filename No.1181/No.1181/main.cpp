//
//  main.cpp
//  No.1181
//
//  Created by kyuhwan cho on 01/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool compare(string str1, string str2){
    if(str1.length()==str2.length()){
        return str1<str2;
    }
    return str1.length()<str2.length();
}
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio();
    int testCase;
    string str;
    vector<string> v;
    cin>>testCase;
    for(int i=0; i<testCase; i++){
        cin>>str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), compare);
    //remove dup
    v.erase(unique(v.begin(), v.end()),v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"\n";
    }
    return 0;
}
