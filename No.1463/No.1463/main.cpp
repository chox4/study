//
//  main.cpp
//  No.1463
//
//  Created by kyuhwan cho on 30/07/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;
int mem[1000001];


int min_op(int number){
    if(mem[number]!=-1){
        return mem[number];
    }else{
        int temp1=INT_MAX, temp2=INT_MAX, temp3=INT_MAX;
        mem[number-1] = min_op(number-1);
        temp1 = mem[number-1];
        if(number%2==0){
            mem[number/2] = min_op(number/2);
            temp2 = mem[number/2];
        }if(number%3 == 0){
            mem[number/3] = min_op(number/3);
            temp3 = mem[number/3];
        }

        mem[number] = min(min(temp1,temp2),temp3)+1;
        return mem[number];
    }
}
int main(int argc, const char * argv[]) {
    fill_n(mem,1000001,-1);
    mem[1] = 0; mem[2] = 1; mem[3] = 1;
    int number;
    cin>>number;
    cout<<min_op(number)<<endl;
}

// 1  0
// 2  1
// 3  1
// 4  2
// 5  3
// 6  2
// 7  3
// 8  3
// 9  2
// 10 3
// 11 4
// 12 3
// 13 4
// 14 4
// 15 4
// 16 4
// 17 5
// 18 3
// 19 4
// 20 4
// 21 4
