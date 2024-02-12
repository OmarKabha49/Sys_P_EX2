#include <stdio.h>
#define MAX_WEIGHT 20
#define ARR_SIZE 5

int knapSack(int weights[], int values[], int selected_bool[]) {
    int i, w;
    int table[ARR_SIZE + 1][MAX_WEIGHT + 1];

    for (i = 0; i <= ARR_SIZE; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                table[i][w] = 0;
            else if (weights[i - 1] <= w)
                table[i][w] = (values[i - 1] + table[i - 1][w - weights[i - 1]] > table[i - 1][w]) ?
                              (values[i - 1] + table[i - 1][w - weights[i - 1]]) : table[i - 1][w];
            else
                table[i][w] = table[i - 1][w];
        }
    }

    int res = table[ARR_SIZE][MAX_WEIGHT];
    w = MAX_WEIGHT;
    for (i = ARR_SIZE; i > 0 && res > 0; i--) {
        if (res == table[i - 1][w])
            continue;
        else {
            selected_bool[i - 1] = 1;
            res -= values[i - 1];
            w -= weights[i - 1];
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
