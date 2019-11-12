//
//  main.cpp
//  ssafy
//
//  Created by kyuhwan cho on 26/10/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

void f(int a, double b){
    cout<<a<<b<<endl;
}
void f(double c, int a){
    cout<<"-"<<c<<a<<endl;
}

int main(int argc, const char * argv[]) {
    int a;
    double b;
    cin>>a>>b;
    f(a,b);
    f(b,a);
}
