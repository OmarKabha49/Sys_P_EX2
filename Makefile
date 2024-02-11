CC = gcc
CFLAGS = -g -Wall
TARGET1 = my_graph
TARGET2 = my_Knapsack
SOURCE1 = my_graph.o my_mat.o
SOURCE2 = my_Knapsack.o
HEADER = my_mat.h

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(SOURCE1) $(HEADER)
	$(CC) $(CFLAGS) -o $(TARGET1) $(SOURCE1)

$(TARGET2): $(SOURCE2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(SOURCE2)


my_graph.o: my_graph.c $(HEADER)
	$(CC) $(CFLAGS) -c -o my_graph.o my_graph.c

my_Knapsack.o: my_Knapsack.c
	$(CC) $(CFLAGS) -c -o my_Knapsack.o my_Knapsack.c

my_mat.o: my_mat.c
	$(CC) $(CFLAGS) -c -o my_mat.o my_mat.c

.PHONY: clean

clean:
	rm -f $(TARGET1) $(TARGET2) my_graph.o my_Knapsack.o my_mat.o