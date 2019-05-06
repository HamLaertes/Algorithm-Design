#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution
{
    public:
        vector<vector<int>> permute(vector<int> &num){
            vector<vector<int>> res;
            permute(num, 0, res);
            return res;
        }
        void permute(vector<int>& num, int start, vector<vector<int>>& res) {
            if (start>=num.size()) res.push_back(num);
            for(int i=start; i<num.size(); i++){
                Swap(num[start], num[i]);
                permute(num, start+1, res);
                Swap(num[start], num[i]);
            }
        }
        void Swap(int &e1, int &e2){
            int tmp;
            tmp=e1;
            e1=e2;
            e2=tmp;
        }
};

int main()
{
    Solution A;
    vector<int> num;
    int tmp, length;
    cin>>length;
    while(num.size()<length){
        cin>>tmp;
        num.push_back(tmp);
    }
    vector<vector<int>> res;
    res=A.permute(num);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j];
        }
        cout<<endl;
    }
    system("pause");
}