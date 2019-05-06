#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution
{
    public:
        void fill(int** A, int** B, int size){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    A[i][j]=rand() % 5;
                    B[i][j]=rand() % 5;
                }
            }
        }
        void print(int** A, int size){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    cout << A[i][j] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }
        void MUL(int** A, int** B, int** R, int size){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    R[i][j]=0;
                    for(int k=0; k<size; k++){
                        R[i][j]=R[i][j]+A[i][k]*B[k][j];
                    }
                }
            }
        }
        void ADD(int** A, int** B, int** R, int size){
            for (int i=0; i<size; i++){
                for (int j=0; j<size; j++){
                    R[i][j]=A[i][j]+B[i][j];
                }
            }
        }
        void SUB(int** A, int** B, int** R, int size){
            for (int i=0; i<size; i++){
                for (int j=0; j<size; j++){
                    R[i][j]=A[i][j]-B[i][j];
                }
            }
        }
        void Strassen(int size, int** A, int** B, int** C){
            int newSize=size/2;
            int HalfSize=size/2;
            if(size<=4) MUL(A, B, C, size);
            else{
                int** A11;
                int** A12;
                int** A21;
                int** A22;
                int** B11;
                int** B12;
                int** B21;
                int** B22;
                int** C11;
                int** C12;
                int** C21;
                int** C22;
                int** M1;
                int** M2;
                int** M3;
                int** M4;
                int** M5;
                int** M6;
                int** M7;
                int** AResult;
                int** BResult;
                A11 = new int *[newSize];
                A12 = new int *[newSize];
                A21 = new int *[newSize];
                A22 = new int *[newSize];
                B11 = new int *[newSize];
                B12 = new int *[newSize];
                B21 = new int *[newSize];
                B22 = new int *[newSize];
                C11 = new int *[newSize];
                C12 = new int *[newSize];
                C21 = new int *[newSize];
                C22 = new int *[newSize];
                M1 = new int *[newSize];
                M2 = new int *[newSize];
                M3 = new int *[newSize];
                M4 = new int *[newSize];
                M5 = new int *[newSize];
                M6 = new int *[newSize];
                M7 = new int *[newSize];
                AResult = new int *[newSize];
                BResult = new int *[newSize];
                int newLength=newSize;
                for ( int i = 0; i < newSize; i++){
                    A11[i] = new int[newLength];
                    A12[i] = new int[newLength];
                    A21[i] = new int[newLength];
                    A22[i] = new int[newLength];
                    B11[i] = new int[newLength];
                    B12[i] = new int[newLength];
                    B21[i] = new int[newLength];
                    B22[i] = new int[newLength];
                    C11[i] = new int[newLength];
                    C12[i] = new int[newLength];
                    C21[i] = new int[newLength];
                    C22[i] = new int[newLength];
                    M1[i] = new int[newLength];
                    M2[i] = new int[newLength];
                    M3[i] = new int[newLength];
                    M4[i] = new int[newLength];
                    M5[i] = new int[newLength];
                    M6[i] = new int[newLength];
                    M7[i] = new int[newLength];
                    AResult[i] = new int[newLength];
                    BResult[i] = new int[newLength];
                }
                for (int i=0; i<size/2; i++)
                {
                    for (int j=0; j<size/2; j++)
                    {
                        A11[i][j]=A[i][j];
                        A12[i][j]=A[i][j+size/2];
                        A21[i][j]=A[i+size/2][j];
                        A22[i][j]=A[i+size/2][j+size/2];
                        B11[i][j]=B[i][j];
                        B12[i][j]=B[i][j+size/2];
                        B21[i][j]=B[i+size/2][j];
                        B22[i][j]=B[i+size/2][j+size/2];
                    }
                }
                ADD( A11,A22,AResult, HalfSize);
                ADD( B11,B22,BResult, HalfSize);
                Strassen( HalfSize, AResult, BResult, M1 );
                ADD( A21,A22,AResult, HalfSize);
                Strassen(HalfSize, AResult, B11, M2);
                SUB( B12,B22,BResult, HalfSize);
                Strassen(HalfSize, A11, BResult, M3);
                SUB( B21, B11, BResult, HalfSize);
                Strassen(HalfSize, A22, BResult, M4);
                ADD( A11, A12, AResult, HalfSize);
                Strassen(HalfSize, AResult, B22, M5);
                SUB( A21, A11, AResult, HalfSize);
                ADD( B11, B12, BResult, HalfSize);
                Strassen( HalfSize, AResult, BResult, M6);
                SUB(A12, A22, AResult, HalfSize);
                ADD(B21, B22, BResult, HalfSize);
                ADD( M1, M4, AResult, HalfSize);
                SUB( M7, M5, BResult, HalfSize);
                ADD( AResult, BResult, C11, HalfSize);
                ADD( M3, M5, C12, HalfSize);
                ADD( M2, M4, C21, HalfSize);
                ADD( M1, M3, AResult, HalfSize);
                SUB( M6, M2, BResult, HalfSize);
                ADD( AResult, BResult, C22, HalfSize);
                for (int i = 0; i < size/2 ; i++)
                {
                    for (int j = 0 ; j < size/2 ; j++)
                    {
                        C[i][j] = C11[i][j];
                        C[i][j + size / 2] = C12[i][j];
                        C[i + size / 2][j] = C21[i][j];
                        C[i + size / 2][j + size / 2] = C22[i][j];
                    }
                }
			for (int i = 0; i < newLength; i++)
			{
				delete[] A11[i];delete[] A12[i];delete[] A21[i];
				delete[] A22[i];
				delete[] B11[i];delete[] B12[i];delete[] B21[i];
				delete[] B22[i];
				delete[] C11[i];delete[] C12[i];delete[] C21[i];
				delete[] C22[i];
				delete[] M1[i];delete[] M2[i];delete[] M3[i];delete[] M4[i];
				delete[] M5[i];delete[] M6[i];delete[] M7[i];
				delete[] AResult[i];delete[] BResult[i] ;
			}
				delete[] A11;delete[] A12;delete[] A21;delete[] A22;
				delete[] B11;delete[] B12;delete[] B21;delete[] B22;
				delete[] C11;delete[] C12;delete[] C21;delete[] C22;
				delete[] M1;delete[] M2;delete[] M3;delete[] M4;delete[] M5;
				delete[] M6;delete[] M7;
				delete[] AResult;
				delete[] BResult ;
        }
    }
};

int main(){
    int size;
    cin >> size;
    int** A=new int*[size];
    int** B=new int*[size];
    int** C=new int*[size];
    for(int i=0; i<size; i++){
        A[i]=new int[size];
        B[i]=new int[size];
        C[i]=new int[size];
    }
    Solution Strassen;
    Strassen.fill(A, B, size);
    Strassen.print(A, size);
    Strassen.print(B, size);
    Strassen.Strassen(size, A, B, C);
    cout << "the result is:" << endl;
    Strassen.print(C, size);
    system("pause");
}