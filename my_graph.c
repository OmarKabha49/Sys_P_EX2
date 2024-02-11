#include <stdio.h>
#include "my_mat.h"


int main() {

    int mat[100];
    int *p_mat = mat;
    int i,j;
    char c = 0;

    while (c != 'D'){
        scanf("%c",&c);
        switch (c) {
            case 'A':

                inputMatrix(p_mat);
                break;

            case 'B':

                scanf("%d %d",&i,&j);
                int result = isThereAPath(mat,i,j);
                if(result > 0){ printf("True\n");}
                else{ printf("False\n");}
                break;

            case 'C':

                scanf("%d %d",&i,&j);
                int sp = shortestPath(p_mat,i,j);
                if(sp == 0) { printf("%d\n",-1);}
                else {printf("%d\n",sp);}
                break;

            case 'D':
                break;
        }


    }



    return 0;
}
