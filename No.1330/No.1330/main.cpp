//
//  main.cpp
//  No.1330
//
//  Created by kyuhwan cho on 04/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num1,num2;
    cin>>num1>>num2;
    string answer = num1==num2?"==": num1>num2?">":"<";
    cout<<answer<<"\n";
}
