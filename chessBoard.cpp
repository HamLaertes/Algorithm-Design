#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution
{
    private:
        int** board;
        int size;
        int tile=0;
    public:
        Solution(int size, int bx, int by){
            this->size=size;
            board=new int*[size];
            for(int i=0; i<size; i++) board[i]=new int[size];
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++) board[i][j]=0;
            }
            board[bx][by] = -1;
        }
        ~Solution(){
            for(int i=0; i<size; i++)
                delete[] board[i];
            delete[] board;
        }
        void solution(int ax, int ay, int bx, int by, int size){
           if(size==1) return;
           int s=size/2;
           int t=tile++;
           //覆盖左上棋盘
           if(bx<ax+s&&by<ay+s){//特殊方格在棋盘中
               solution(ax, ay, bx, by, s);
           }
           else{//特殊方格不在棋盘中
               //cout<< "use tile covering top-left corner." << endl;
               board[ax+s-1][ay+s-1]=t;
               solution(ax, ay, ax+s-1, by+s-1, s);
           }
            //覆盖右上棋盘
            if(ax+s<=bx&&by<ay+s){//特殊方格在棋盘中
                solution(ax+s, ay, bx, by, s);
            }
            else{//特殊方格不在棋盘中
                board[ax+s][ay+s-1]=t;
                solution(ax+s, ay, ax+s, ay+s-1, s);
            }
            //覆盖左下棋盘
            if(bx<ax+s&&by>=ay+s){//特殊方格在棋盘中
                solution(ax, ay+s, bx, by, s);
            }
            else{//特殊方格不在棋盘中
                board[ax+s-1][ay+s]=t;
                solution(ax, ay+s, ax+s-1, ay+s, s);
            }
            //覆盖右下棋盘
            if(bx>=ax+s&&by>=ay+s){//特殊方格在棋盘中
                solution(ax+s, ay+s, bx, by, s);
            }
            else{//特殊方格不在棋盘中
                board[ax+s][ay+s]=t;
                solution(ax+s, ay+s, ax+s, ay+s, s);
            }
       }
       void show(){
           for(int i=0; i<size; i++){
               for(int j=0; j<size; j++) cout << board[i][j] << "\t";
               cout << endl;
           }
       }
};

int main(){
    int bx, by, size;
    cin >> bx >> by >> size;
    Solution chessBoard(size, bx, by);
    chessBoard.solution(0, 0, bx, by, size);
    chessBoard.show();
    system("pause");
    return 0;
}