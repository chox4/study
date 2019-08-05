//
//  main.cpp
//  No.10773
//
//  Created by kyuhwan cho on 05/08/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
int arr[100001];

int main(int argc, const char * argv[]) {
    int num, val, arrIndex=0;
    unsigned long long int sum=0;
    cin>>num;
    while(num--){
        cin>>val;
        if(val!=0){
            arr[arrIndex++]=val;
            sum += val;
        }else{
            sum -= arr[--arrIndex];
        }
    }
    cout<<sum<<endl;
}
