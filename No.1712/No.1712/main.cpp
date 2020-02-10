//
//  main.cpp
//  No.1712
//
//  Created by kyuhwan cho on 10/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int base, ele, sel,answer;
    cin>>base>>ele>>sel;
    if(ele>=sel){
        answer = -1;
    }else{
        answer = base/(sel-ele)+1;
    }
    cout<<answer<<"\n";
}

