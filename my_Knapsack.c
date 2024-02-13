#include <stdio.h>
#define MAX_WEIGHT 20
#define ARR_SIZE 5

int knapSack(int weights[], int values[], int selected_bool[]) {
    int toItem, w;
    int table[ARR_SIZE + 1][MAX_WEIGHT + 1];


    //according to algo1 we can fill the table using this  T[toItem,B] = max(T[toItem-1,B], vi + T[toItem-1,B-wi])
    for (toItem = 0; toItem <= ARR_SIZE; toItem++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (toItem == 0 || w == 0) {
                table[toItem][w] = 0;
            }
            else {
                if (weights[toItem - 1] <= w) {
                    int newValue = values[toItem - 1] + table[toItem - 1][w - weights[toItem - 1]];
                    if (newValue > table[toItem - 1][w]) {
                        table[toItem][w] = newValue;
                    } else {
                        table[toItem][w] = table[toItem - 1][w];
                    }
                }
                else {
                    table[toItem][w] = table[toItem - 1][w];
                }
            }
        }
    }



    int res = table[ARR_SIZE][MAX_WEIGHT];
    w = MAX_WEIGHT;
    for (toItem = ARR_SIZE; toItem > 0 && res > 0; toItem--) {
        if (res == table[toItem - 1][w])
            continue;
        else {
            w -= weights[toItem - 1];
            selected_bool[toItem - 1] = 1;
            res -= values[toItem - 1];
        }
    }

    return table[ARR_SIZE][MAX_WEIGHT];
}

int main() {
    int weights[ARR_SIZE], values[ARR_SIZE], selected_bool[ARR_SIZE] = {0};


    for (int i = 0; i < ARR_SIZE; ++i) {
        char name;
        scanf(" %c %d %d", &name, &values[i], &weights[i]);
    }


    int max_value = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", max_value);
    printf("Selected items:");
    for (int i = 0 ; i < ARR_SIZE;i++) {
        if (selected_bool[i]) {
            printf(" %c", 'a' + i);
        }
    }

    return 0;
}
