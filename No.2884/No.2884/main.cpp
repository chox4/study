//
//  main.cpp
//  No.2884
//
//  Created by kyuhwan cho on 04/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int h,m;
    cin>>h>>m;
    int new_h, new_m;
    new_h = m<45?h-1:h;
    new_m = m<45?m+15:m-45;
    cout<<(new_h+24)%24<<" "<<new_m<<"\n";
}
