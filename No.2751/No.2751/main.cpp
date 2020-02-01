//
//  main.cpp
//  No.2751
//
//  Created by kyuhwan cho on 01/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];
int main(int argc, const char * argv[]) {
    // insert code here...
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cnt,num;
    cin>>cnt;
    for(int i=0; i<cnt; i++){
        cin>>num;
        arr[i] =num;
    }
    sort(arr,arr+cnt);
    for(int i=0; i<cnt; i++){
        cout<<arr[i]<<"\n";
    }
}
