//
//  main.cpp
//  No.14499
//
//  Created by kyuhwan cho on 2020/04/09.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    int map[21][21],
        row,
        col,
        x,
        y,
        op,
        dice[6] = {0,0,0,0,0,0};
    vector<int> dir;
    for(int i=0; i<21; i++){
        fill_n(map[i],21,-1);
    }
    cin>>col>>row>>x>>y>>op;
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            int num;
            cin>>num;
            map[i][j] = num;
        }
    }
    for(int i=0; i<op; i++){
        int num;
        cin>>num;
        dir.push_back(num);
    }
    for(int i=0; i<dir.size(); i++){
        if(dir[i]==1){
            //E
            if(map[x][y+1]==-1){
                continue;
            }
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[3];
            dice[3] = dice[4];
            dice[4] = temp;
            if(map[x][y+1]==0){
                map[x][y+1] = dice[1];
            }else{
                dice[1] = map[x][y+1];
                map[x][y+1] = 0;
            }
            y++;
        }else if(dir[i]==2){
            //W
            if(map[x][y-1]==-1 || y<1){
                continue;
            }
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[3];
            dice[3] = dice[5];
            dice[5] = temp;
            if(map[x][y-1]==0){
                map[x][y-1] = dice[1];
            }else{
                dice[1] = map[x][y-1];
                map[x][y-1] = 0;
            }
            y--;
        }else if(dir[i]==3){
            //N
            if(map[x-1][y]==-1 || x<1){
                continue;
            }
            int temp = dice[1];
            dice[1] = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[2];
            dice[2] = temp;
            if(map[x-1][y]==0){
                map[x-1][y] = dice[1];
            }else{
                dice[1] = map[x-1][y];
                map[x-1][y] = 0;
            }
            x--;
        }else if(dir[i]==4){
            //S
            if(map[x+1][y]==-1){
                continue;
            }
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[3];
            dice[3] = dice[0];
            dice[0] = temp;
            if(map[x+1][y]==0){
                map[x+1][y] = dice[1];
            }else{
                dice[1] = map[x+1][y];
                map[x+1][y] = 0;
            }
            x++;
        }
        cout<<dice[3]<<"\n";
    }
    return 0;
}
