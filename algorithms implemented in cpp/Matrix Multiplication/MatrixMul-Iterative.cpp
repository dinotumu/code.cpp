#include <iostream>
#define N 4
using namespace std;

void multiply(int A[][N], int B[][N], int C[][N]);

int main()
{
    int A[N][N] = { {1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};

    int B[N][N] = { {1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};

    int C[N][N];
    int i, j;
    multiply(A, B, C);
    cout<<"Result matrix is \n";
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
           cout<<C[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}

void multiply(int A[][N], int B[][N], int C[][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < N; k++)
                C[i][j] += A[i][k]*B[k][j];
        }
    }
}
