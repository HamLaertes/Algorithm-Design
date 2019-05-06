#include <iostream>
#include <limits.h>

using namespace std;

void Plan(int *P, int **Matrix, int N, int **S){
    for(int i=1; i<=N; i++) Matrix[i][i]=0;//对角线元素为0;
    for(int r=2; r<=N; r++){//计算N-i个值
        for(int i=1; i<=N-r+1; i++){
            int j=i+r-1;//当前计算的矩阵
            Matrix[i][j]=Matrix[i+1][j]+P[i-1]*P[i]*P[j];
            S[i][j]=i;//将线画在第I个矩阵后
            for(int k=i+1; k<j; k++){//不同的画线的位置
                int t=Matrix[i][k]+Matrix[k+1][j]+P[i-1]*P[k]*P[j];
                if(t<Matrix[i][j]){
                    Matrix[i][j]=t;
                    S[i][j]=k;
                }
            }
        }
    }
}

int main(int argc, char **argv){
    cout << "Total Matrix Numbers:";
    int nums;
    cin >> nums;
    cout << "Please define your matrixs:" << endl;
    int tmp;
    int *P=new int[nums+1];
    for(int i=0; i<nums-1; i++) P[i]=0;
    for(int i=0; i<nums-1; i++){
        cin >> P[i];
        cin >> tmp;
    }
    cin >> P[nums-1];
    cin >> P[nums];
    for(int i=0; i<=nums; i++){cout << P[i] << " ";}
    int **Matrix; int **S;
    Matrix=new int*[nums+1];
    S=new int*[nums+1];
    for(int i=0; i<nums+1; i++){
        Matrix[i]=new int[nums+1];
        S[i]=new int[nums+1];
        for(int j=0; j<nums+1; j++) Matrix[i][j]=S[i][j]=0;
    }
    Plan(P, Matrix, nums, S);
    cout << Matrix[1][nums] << endl;
    for(int i=0; i<nums+1; i++){
        delete []Matrix[i];
        delete []S[i];
    }
    delete []Matrix;
    delete []S;
    delete []P;
    return 0;
}