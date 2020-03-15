//
//  main.cpp
//  No.2231
//
//  Created by kyuhwan cho on 2020/03/15.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int each_sum(int num){
    int sum = 0;
    int tmp = num;
    while(tmp!=0){
        sum += tmp%10;
        tmp /= 10;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int answer = 0;
    for(int i=0; i<=n; i++){
        if(i+each_sum(i)==n){
            answer = i;
            break;
        }
    }
    cout<<answer<<"\n";
    return 0;
}
