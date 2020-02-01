//
//  main.cpp
//  No.1427
//
//  Created by kyuhwan cho on 01/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int num;
    cin>>num;
    vector<int> v;
    int tmp = num;
    while(tmp!=0){
        v.push_back(tmp%10);
        tmp = tmp/10;
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i<v.size();i++){
        cout<<v[i];
    }
    cout<<endl;
}

