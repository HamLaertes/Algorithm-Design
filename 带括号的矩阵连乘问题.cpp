#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int Calculate(int *A, int *B){
    return A[0]*B[0]*B[1];
}

void findMin(int *Check, int ***Matrix, int *index, int N){//index[0]到index[1]代价最小
    int min=INT_MAX;
    int t=0;
    for(int i=0; i<N; i++){
        if(Calculate(Matrix[t][Check[t]], Matrix[Check[t]+1][Check[Check[t]+1]])<min){//当前这两个相邻矩阵的计算乘法数量是最小的
            min=Calculate(Matrix[t][Check[t]], Matrix[Check[t]+1][Check[Check[t]+1]]);
            index[0]=t; index[1]=Check[t]+1; index[2]=Check[Check[t]+1];//[t,Check[t]],[Check[t]+1,Check[Check[t]+1]]是需要合并的矩阵
            t=Check[t]+1;

        }
    }     
    cout << min << endl;
    cout << index[0] << " " << index[1] << " " << index[2] << endl;
    return;
}

void Plan(int *Check, int ***Matrix, int N){
    int *index=new int[3];
    for(int i=1; i<N; i++){
        cout << "-----------------------------" << endl;
        findMin(Check, Matrix, index, N-i);
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
        Matrix[index[0]][index[2]][0]=Matrix[index[0]][Check[index[0]]][0];
        Matrix[index[0]][index[2]][1]=Matrix[index[1]][Check[index[1]]][1];
        Check[index[0]]=index[1];
    }
    return;
}

int main(int argc, char **argv){
    cout << "Total Matrix Numbers:";
    int num;
    cin >> num;
    int ***Matrix;
    int *Check;
    Check=new int[num];
    Matrix=new int**[num];
    for(int i=0; i<num; i++){
        Matrix[i]=new int*[num];
        for(int j=0; j<num; j++){
                Matrix[i][j]=new int[2]; 
                Matrix[i][j][0]=0; Matrix[i][j][1]=0;
            }
    }
    for(int i=0; i<num; i++) Check[i]=i;
    cout << "The feature of the Matrix:" << endl;
    for(int i=0; i<num; i++){
        cin >> Matrix[i][Check[i]][0];
        cin >> Matrix[i][Check[i]][1];
    }
    Plan(Check, Matrix, num);
    return 0;
}