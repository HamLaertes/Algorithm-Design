#include <iostream>
#include <stdlib.h>
#include <condition_variable>
#include <string.h>

using namespace std;

void LCSLength(int m, int n, char *x, char *y, int **c, int **b){//m对应x n对应y
    int i, j;
    for(i=0; i<=m; i++) c[i][0]=0;
    for(i=0; i<=n; i++) c[0][i]=0;
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(x[i]==y[j]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    }
}

void LCS(int i, int j, char *x, int **b){
    if(i==0||j==0) return;
    if(b[i][j]==1){
        LCS(i-1, j-1, x, b);
        cout << x[i];
    }
    else if(b[i][j]==2) LCS(i-1, j, x, b);
    else LCS(i, j-1, x, b);
}

int main(){
    int m, n;
    char *x=NULL, *y=NULL;
    cout << "how long are the two strings:";
    cin >> m >> n;
    x=(char*)malloc(sizeof(char)*(m+1));
    y=(char*)malloc(sizeof(char)*(n+1));
    cout << "tell me which two strings you get:" << endl;
    cin >> (x+1) >> (y+1);
    x[0] = y[0] = '\0';
    int *c[m+1], *b[m+1];
    for (int i = 0; i <= m; i++){
        c[i] = (int*)malloc(sizeof(int) * (n + 1));
        b[i] = (int *)malloc(sizeof(int) * (n + 1));
        for (int j = 0; j <= n; j++){
            c[i][j] = 0;
            b[i][j] = 0;
        }
    }
    LCSLength(m, n, x, y, c, b);
    cout << "the LCSLength is " << c[m][n] << endl;
    cout << "And it is:" << endl;
    LCS(m, n, x, b);
    for (int i = 0; i <= m; i++){
        free(c[i]);
        free(b[i]);
    }
    free(x);
    free(y);
    return 0;
}
