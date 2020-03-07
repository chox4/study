//
//  main.cpp
//  No.1011
//
//  Created by kyuhwan cho on 2020/03/06.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        long long x, y, len, n = 1, maxx = 1;
        cin >> x >> y;
        len = y - x;
        while (len > maxx)
        {
            maxx = maxx + (n / 2) + 1;
            n++;
        }
        cout << n << "\n";
    }
    return 0;
}
