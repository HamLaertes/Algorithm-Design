#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class MergeSort
{
    private:
        int* tmp;
    public:
        MergeSort(int size){
            tmp=new int[size];
            for(int i=0; i<size; i++) tmp[i]=0;
        }
        ~MergeSort(){delete[] tmp;}
        void down(int* nums, int left, int right){
            if(left >= right) return;
            int middle = (right+left)/2;
            down(nums, left, middle);
            down(nums, middle+1, right);
            up(nums, left, middle, right);
        }

        void up(int* nums, int left, int middle, int right){
            int first=left;
            int second=middle+1;
            int index=left;
            while((first<=middle)&&(second<=right)){
                if(nums[first]>=nums[second])
                    tmp[index++]=nums[second++];
                else
                    tmp[index++]=nums[first++];
                }
                while(first<=middle) tmp[index++]=nums[first++];
                while(second<=right) tmp[index++]=nums[second++];
                for(first=left; first<=right; first++)
                    nums[first]=tmp[first];
            }

        void show(int* nums, int size){
            for(int i=0; i<size; i++) 
                cout << nums[i] <<" ";
        }
};

int main(){
    int size;
    cin >> size;
    int nums[size];
    for(int i=0; i<size; i++) cin >> nums[i];
    MergeSort solution(size);
    solution.down(nums, 0, size-1);
    solution.show(nums, size);
    system("pause");
}