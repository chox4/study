//
//  main.cpp
//  No.1629
//
//  Created by kyuhwan cho on 2020/04/25.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#define endl "\n"
using namespace std;

long long div(int a, int b, int c){
    if(b==1){
        return a%c;
    }
    long long tmp = div(a,b/2,c);
    if(b%2 == 0){
        return ((tmp%c)*(tmp%c))%c;
    }else{
        return ((a*tmp%c)*(tmp%c))%c;
    }
}



int main(int argc, const char * argv[]) {
    int a,b,c;
    cin>>a>>b>>c;
    long long res = div(a,b,c);
    cout<<res<<endl;
    return 0;
}
