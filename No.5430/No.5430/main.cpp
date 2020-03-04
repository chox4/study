//
//  main.cpp
//  No.5430
//
//  Created by kyuhwan cho on 2020/03/04.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//
//comment : 단순히 reverse 함수를 사용한다면 시간초과 발생 -> 인덱스를 나타내는 변수를 선언한뒤 활용.
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase,len;
    cin>>testCase;
    string fnc,num;
    while(testCase--){
        int idx[100001];
        fill_n(idx,100001,-1);
        deque<int> v;
        cin>>fnc>>len>>num;
        for(int i=0; i<num.length(); i++){
            if(num[i]=='['||num[i]==']'||num[i]==','){
                continue;
            }else{
                int tmp = num[i]-'0';
                while(num[i+1]-'0'<=9 && num[i+1]-'0'>=0){
                    tmp = tmp*10+(num[i+1]-'0');
                    i++;
                }
                v.push_back(tmp);
            }
        }
        int st_idx = 0;
        int end_idx = (int)v.size()-1;
        //r_cnt -> 정방향 출력, 역방향 출력 결정변수
        int r_cnt = 0;
        for(int i=0; i<fnc.length(); i++){
            if(fnc[i]=='R'){
                r_cnt++;
            }else if(fnc[i]=='D'){
                if(r_cnt%2==0){
                    //정방향일때
                    st_idx++;
                }else{
                    end_idx--;
                }
            }
        }
        //-1일경우는 출력할 리스트가 비어있을 때.
        if(end_idx-st_idx>=-1){
            cout<<"[";
            if(r_cnt%2==0){
                for(int i=st_idx; i<end_idx+1; i++){
                    if(i!=end_idx){
                        cout<<v[i]<<",";
                    }else{
                        cout<<v[i];
                    }
                }
            }else{
                for(int i=end_idx; i>st_idx-1; i--){
                    if(i!=st_idx){
                        cout<<v[i]<<",";
                    }else{
                        cout<<v[i];
                    }
                }
            }
            cout<<"]\n";
        }else{
            cout<<"error"<<"\n";
        }
    }
    return 0;
}
