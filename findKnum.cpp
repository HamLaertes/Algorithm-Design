#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    private:
        bool comp(vector<int> a, vector<int> b);
        void sortEach(vector<vector<int>> &num);
        void sortCol(vector<vector<int>> &num);
    public:
        void show(vector<vector<int>> &num){
            for(int i=0;i<num.size();i++){
                for(int j=0; j<num[i].size();i++){
                    cout << num[i][j] << " ";
                }
                cout << endl;
            }
        }
        void findKnum(vector<vector<int>> &num, int k);
};

bool Solution::comp(vector<int> a, vector<int> b){
    if(a[a.size()/2] < b[b.size()/2]) return true;
    else return false;
}

void Solution::sortEach(vector<vector<int>> &num){
    for(int i=0;i<num.size();i++){
        sort(num[i].begin(), num[i].end());
    }
}

void Solution::sortCol(vector<vector<int>> &num){
    sort(num.begin(), num.end(), comp);
}

void Solution::findKnum(vector<vector<int>> &num, int k){
    sortEach(num); sortCol(num);
    int middle=num.size()*num[0].size()/2+1; //中间的那个数是这个数列中的第middle个数
    if(middle>k){
        vector<vector<int>> tmp(num.begin(), num.begin()+num.size()/2+1);
        for(int i=tmp.back().size()/2;i<tmp.back().size();i++) tmp.back().at(i)=10000;
        findKnum(tmp, k);
    }
    else if(middle==k){
        cout << "第" << middle << "小的数为" << num[num.size()/2][num[0].size()/2+1];
    }
    else{
        vector<vector<int>> tmp(num.begin()+num.size()/2, num.end());
        for(int i=0;i<tmp.front().size()/2+1;i++) tmp.front().at(i)=0;
        findKnum(tmp, k-middle);       
    }
}