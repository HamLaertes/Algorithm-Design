#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mycmp(vector<int> V1, vector<int> V2){
    return V1[1] < V2[1];
}

void Solve(int n, int tw, int *c[], vector<vector<int>> goods){
    for (int i = 1; i <= n; i++){
        for (int w = 1; w <= tw; w++){
            if(goods[i][1]>w){
                c[i][w] = c[i - 1][w];
            }else{
                int temp = c[i - 1][w - goods[i][1]] + goods[i][0];
                if(c[i-1][w]>temp){
                    c[i][w] = c[i - 1][w];
                }
                else{
                    c[i][w] = temp;
                }
            }
        }
    }
}

int main(){
    vector<vector<int>> goods;
    cout << "Please Inpute the Number of Goods you have:";    
    int n, tw;
    cin >> n;
    cout << "Please Inpute the size of your backage:";
    cin >> tw;
    int i = 0;
    int v, w;
    cout << "Tell me the value and weight of each good:" << endl;
    vector<int> tmp;
    tmp.push_back(0);
    tmp.push_back(0);
    goods.push_back(tmp);
    while (i < n)
    {
        vector<int> tmp;
        cin >> v >> w;
        tmp.push_back(v);
        tmp.push_back(w);
        goods.push_back(tmp);
        i++;
    }
    sort(goods.begin(), goods.end(), mycmp);
    int *c[n + 1];
    for (int i = 0; i < n + 1; i++){
        c[i] = (int*)malloc(sizeof(int) * (tw + 1));
        for (int j = 0; j < tw + 1; j++){
            c[i][j] = 0;
        }
    }
    Solve(n, tw, c, goods);
    cout << "The maximum value you can take is: " << c[n][tw] << endl;
    for (int i = 0; i <= n; i++){
        free(c[i]);
    }
    return 0;
}