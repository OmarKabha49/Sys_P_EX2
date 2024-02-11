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

void print_example1(){
    int weights[ARR_SIZE], values[ARR_SIZE], selected_bool[ARR_SIZE] = {0};

    // example 1 Input
    int example1_values[] = {35, 60, 100, 120, 130};
    int example1_weights[] = {2, 5, 6, 9, 10};

    for (int i = 0; i < ARR_SIZE; i++) {
        weights[i] = example1_weights[i];
        values[i] = example1_values[i];
    }

    int max_value = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", max_value);
    printf("Items that give the maximum profit: [");
    for (int i = ARR_SIZE - 1; i >= 0; i--) {
        if (selected_bool[i]) {
            printf("%c, ", 'A' + i);
        }
    }
    printf("\b\b]\n"); //remove the trailing comma and space
}

void print_example2(){
    int weights[ARR_SIZE], values[ARR_SIZE], selected_bool[ARR_SIZE] = {0};

    
     //example 2 Input
     int example2_values[] = {35, 60, 100, 120, 130};
     int example2_weights[] = {2, 5, 6, 9, 9};
   

    for (int i = 0; i < ARR_SIZE; i++) {
        weights[i] = example2_weights[i];
        values[i] = example2_values[i];
    }

    int max_value = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", max_value);
    printf("Items that give the maximum profit: [");
    for (int i = ARR_SIZE - 1; i >= 0; i--) {
        if (selected_bool[i]) {
            printf("%c, ", 'A' + i);
        }
    }
    printf("\b\b]\n"); //remove the trailing comma and space
}

void print_example3(){
    int weights[ARR_SIZE], values[ARR_SIZE], selected_bool[ARR_SIZE] = {0};


    // example 3 Input
    int example3_values[] = {35, 60, 100, 120, 130};
    int example3_weights[] = {2, 5, 6, 9, 7};


    for (int i = 0; i < ARR_SIZE; i++) {
        weights[i] = example3_weights[i];
        values[i] = example3_values[i];
    }

    int max_value = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", max_value);
    printf("Items that give the maximum profit: [");
    for (int i = ARR_SIZE - 1; i >= 0; i--) {
        if (selected_bool[i]) {
            printf("%c, ", 'A' + i);
        }
    }
    printf("\b\b]\n"); //remove the trailing comma and space
}

int main() {
    
    print_example1();
    printf("\n");
    print_example2();
    printf("\n");
    print_example3();

    return 0;
}
