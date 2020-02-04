//
//  main.cpp
//  No.2753
//
//  Created by kyuhwan cho on 04/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int year;
    cin>>year;
    bool answer = false;
    answer = year%400==0?true:year%4==0?year%100==0?false:true:false;
    cout<<answer<<"\n";
}
