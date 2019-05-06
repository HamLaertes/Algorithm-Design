#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> res;
int result=0;
int main()
{
    int num;
    cin>>num;
    void resolve(int n, int min);
    resolve(num, 1);
    cout << result;
    system("pause");
    return 0;
}

void resolve(int n, int min){
    if(n<=0) result++;
    else{
       for(int i=min; i<=n; i++){
           res.push_back(i);
           resolve(n-i, i);
           res.pop_back();
       } 
    }
}