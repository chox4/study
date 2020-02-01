//
//  main.cpp
//  No.10814
//
//  Created by kyuhwan cho on 01/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string str[100001];

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> v;
    int age,testCase;
    string name;
    cin>>testCase;
    for(int i=0; i<testCase; i++){
        cin>>age>>name;
        v.push_back(make_pair(age,i));
        str[i] = name;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<testCase; i++){
        cout<<v[i].first<<" "<<str[v[i].second]<<"\n";
    }
    return 0;
}
