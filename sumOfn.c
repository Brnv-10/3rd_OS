#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

typedef struct {
    int* array;
    int start;
    int end;
    long long sum;
} ThreadParams;

void* calculateSum(void* args) {
    ThreadParams* params = (ThreadParams*)args;
    for (int i = params->start; i <= params->end; i++) {
        params->sum += params->array[i];
    }
    return NULL;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    if (!array) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    pthread_t threads[MAX_THREADS];
    ThreadParams params[MAX_THREADS];

    int segmentSize = n / MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++) {
        params[i] = (ThreadParams){array, i * segmentSize, (i == MAX_THREADS - 1) ? n - 1 : (i + 1) * segmentSize - 1, 0};
        pthread_create(&threads[i], NULL, calculateSum, &params[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    long long totalSum = 0;
    for (int i = 0; i < MAX_THREADS; i++) {
        totalSum += params[i].sum;
    }

    printf("Sum of %d numbers: %lld\n", n, totalSum);

    free(array);
    return EXIT_SUCCESS;
}
