#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution
{
    public:
        void Hanoi(int n, char from, char bridge, char to);
};
void Solution::Hanoi(int n, char from, char bridge, char to){
    if(n==1) cout << "from " << from << " to " << to << endl;
    else
    {
        Hanoi(n-1, from, to, bridge);
        cout << "from " << from << " to " << to << endl;
        Hanoi(n-1, bridge, from, to);
    }
    
}

int main(){
    int n;
    char front, to, bridge;
    cin >> n >> front >> to >> bridge;
    Solution st;
    st.Hanoi(n, front, to, bridge);
    system("pause");
}