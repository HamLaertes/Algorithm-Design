#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution
{
    public:
        int halfsearch(vector<int> nums, int target);//flag=true 向右查找 flag=false 向左查找
};

int Solution::halfsearch(vector<int> nums, int target){
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

int main()
{
    vector<int> nums;
    
    system("pause");
    return 0;
}