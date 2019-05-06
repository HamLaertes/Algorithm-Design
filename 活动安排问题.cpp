#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mycmp(vector<int> V1,vector<int> V2){
    return V1.at(1) < V2.at(1);
}

void GreedySelector(int n, vector<vector<int>> activities, bool A[]){
    A[0] = true;
    int j = 0;
    for (int i = 1; i < n; i++){
        if(activities[i][0]>=activities[j][1]){
            A[i] = true;
            j = i;
        }
        else{
            A[i] = false;
        }
    }
}

void DisplayActivities(int n, vector<vector<int>> activities, bool A[]){
    int counter = 0;
    for (int i = 0; i < n; i++){
        if(A[i]){
            counter++;
            cout << counter << " start at:" << activities[i][0] << " end at:" << activities[i][1] << endl;
        }else{
            continue;
        }
    }
}

int main(){
    vector<vector<int>> activities;
    cout << "Please tell me the total number of activities you have:" << endl;
    int n;
    cin >> n;
    int i = 0;
    int start_time, end_time;
    while(i<n){
        cin >> start_time >> end_time;
        vector<int> tmp;
        tmp.push_back(start_time);
        tmp.push_back(end_time);
        activities.push_back(tmp);
        i++;
    }
    sort(activities.begin(), activities.end(), mycmp);
    cout << "1" << endl;
    bool A[n];
    GreedySelector(n, activities, A);
    DisplayActivities(n, activities, A);
    return 0;
}