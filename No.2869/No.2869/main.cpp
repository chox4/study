//
//  main.cpp
//  No.2869
//
//  Created by kyuhwan cho on 10/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    unsigned long long len, day, night,answer;
    cin>>day>>night>>len;
    answer = ceil(double(len-day)/(day-night));
    cout<<answer+1<<"\n";
    
}
