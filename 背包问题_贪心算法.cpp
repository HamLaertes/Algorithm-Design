#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mycmp(vector<float> V1, vector<float> V2){
    return V1[2] > V2[2];
}

void Knapsack(int n, float tw, vector<vector<float>> goods, float x[]){
    int i;
    for (i = 0; i < n; i++)
        x[i] = 0;
    float c = tw;
    for (i = 0; i < n; i++){
        if(goods[i][1]>c)
            break;
        x[i] = 1;
        c -= goods[i][1];
    }
    if(i<=n)
        x[i] = c / goods[i][1];
}

int main(){
    vector<vector<float>> goods;
    cout << "Please Inpute the Number of Goods you have:";
    int n;
    float tw;
    cin >> n;
    cout << "Please Inpute the size of your backage:";
    cin >> tw;
    float i = 0;
    float v, w;
    cout << "Tell me the value and weight of each good:" << endl;
    vector<float> tmp;
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    goods.push_back(tmp);
    while (i < n)
    {
        vector<float> tmp;
        cin >> v >> w;
        tmp.push_back(v);
        tmp.push_back(w);
        tmp.push_back(v / w);
        goods.push_back(tmp);
        i++;
    }
    sort(goods.begin(), goods.end(), mycmp);
    float x[n + 1];
    float result=0;
    Knapsack(n, tw, goods, x);
    for (int i = 0; i <= n; i++){
        if(x[i]!=0){
            result += x[i] * goods[i][0];
        }
    }
    cout << "The Total Weight you bring is:" << result << endl;
    return 0;
}