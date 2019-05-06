#include <iostream>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

void Init_Graph(int N,int k,int** S, int **C)
{
	int X;
	int i,j;
	int temp=N;
	cout<<"输入边的长度：输入1 2 4 表示点1 与 2的边的长度为 4：首数字为0表示结束输入"<<endl;
	cin>>i;
	while (i!=0)
	{
		cin>>j;
		cin>>C[i][j]; //eg:C[2][5]表示2和5这个点之间的cost
		cin>>i;
	}
	cout<<"输入每个阶段有哪些点：输入：X 1 2 3表示该阶段有X个点，分别为1,2,3："<<endl;
	for (i=1;i<=k;i++)
	{
		cout<<"输入第"<<i<<"阶段的状态的点数：";
		cin>>X;
		cout<<"这些点分别为：";
		for (j=0;j<X;j++)
		{
			cin>>S[i][j]; //eg:S[2][5]表示阶段2的第5个点
		}
	}
}
void Solution(int N, int K, int **S, int **F, int **C, int *result){
    int i, j, t=N;
    int m;
    int point;
    point=S[K][0];//从第一个点开始
    for(i=K-1; i>=1; i--){//第i个阶段
        j=0;
        while(S[i][j]!=0){//当前阶段的点还未计算完
            m=0;
            F[i][j]=INT_MAX;
            if(C[S[i][j]][point]==INT_MAX){//当前这个点不是在倒数第二层上
                while(S[i+1][m]!=0){//如果第i+1个阶段还有点的话
                    if(C[S[i][j]][S[i+1][m]]!=INT_MAX){//这两个点之间有联系
                        if(F[i][j]>(F[i+1][m]+C[S[i][j]][S[i+1][m]])){//i+1层中的m点入选
                            F[i][j] = F[i+1][m] + C[S[i][j]][S[i+1][m]];
                            result[S[i][j]]=S[i+1][m];//第i层的第j个元素后续是第i+1层的m元素
                            t--;
                        }
                        m++;
                    }
                }
            }
            else{
                while (S[i+1][m]!=0){
                    if (F[i][j]>(F[i+1][m]+C[S[i][j]][S[i+1][m]])){
                        F[i][j] = F[i+1][m] + C[S[i][j]][S[i+1][m]];
                        result[S[i][j]]=S[i+1][m];
                        t--;
                    }
                    m++;
                }
            }
            j++;
        }
        cout<<"符合条件的点为："<<endl;
        t=0;
        result[t]=1;
        cout<<result[t]<<" ";
        t=result[t];
	    while (t<N){
		    cout<<result[t]<<" ";
		    t=result[t];
	    }
	    cout<<endl<<"最短距离为：";
	    cout<<F[i+1][0]<<endl;
        }
}

int main(int argc, char *argv[]){
    int N,K;
    int i,j;
    int **C, **S, **F;//C表示边的长度；S表示每个阶段的状态（有哪些点）；F记录每个阶段中的点到终点的成本
    int *result;
    cout << "输入点的个数:";
    cin >> N;
    cout << "输入阶段数:";
    cin >> K;
    for(i=0; i<N+1; i++){
        C[i]=new int[N+1];
        for(j=0; j<N+1; j++){
            C[i][j]=INT_MAX; //因为要比较最小值，所以将初始值置为INI_MAX
        }
    }
    S=new int*[N+1];
    for(i=0; i<N+1; i++){
        S[i]=new int[N+1];
        for(j=0; j<N+1; j++){
            S[i][j]=0;
        }
    } //初始化阶段数组，没有的话就全部为0
    F=new int *[N+1];
    for (i=0;i<N+1;i++){
        F[i]=new int [N+1];
        for (j=0;j<N+1;j++){
            F[i][j]=0;
        }
    }//没计算 设为0
    result=new int[N+1];
    for(i=0; i<N+1; i++){
        result[i]=0;
    }
    Init_Graph(N,K,S,C);
	Solution(N,K,S,F,C,result);
	delete []result;
	for (i=0;i<N+1;i++){
		delete []C[i];
	}
	delete []C;
	for (i=0;i<N+1;i++){
        delete []S[i];
    }
    delete []S;
	for (i=0;i<N+1;i++){
		delete []F[i];
	}
	delete []F;
	return 0;
}