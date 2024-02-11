
#include <stdio.h>

#define N 100
int shortestPath(int *mat,int x,int y);

void inputMatrix(int *mat){
    for (int i = 0; i < N; ++i) {
        scanf("%d",&mat[i]);
    }
}

int isThereAPath(int *mat,int i, int j){
    int reslt = shortestPath(mat,i,j);
    return reslt;
}

//Floyd–Warshall_algorithm
int shortestPath(int *mat,int x,int y){
    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10 ; ++j) {

                if(mat[i*10 + k] != 0 &&  mat[k*10 + j] != 0  &&
                (mat[i*10 + j] == 0  ||  mat[i*10 + k] + mat[k*10 + j]  < mat[i*10 + j]))
                    mat[i*10 + j] = mat[i*10 + k] + mat[k*10 + j];
            }
        }
    }
    if(x == y) {return -1;}
    return mat[x*10 + y];
}
