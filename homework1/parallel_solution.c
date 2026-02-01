#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000
#define NUM_THREADS 2

int main() {
    int *A = (int*)malloc(N * sizeof(int));
    int *B = (int*)malloc(N * sizeof(int));
    int *C = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
        B[i] = i + N + 1;
    }

    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    printf("Array A:\n[");
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i != N - 1) printf(", ");
    }
    printf("]\n\n");

    printf("Array B:\n[");
    for (int i = 0; i < N; i++) {
        printf("%d", B[i]);
        if (i != N - 1) printf(", ");
    }
    printf("]\n\n");

    printf("Result array C = A + B:\n[");
    for (int i = 0; i < N; i++) {
        printf("%d", C[i]);
        if (i != N - 1) printf(", ");
    }
    printf("]\n\n");

    free(A);
    free(B);
    free(C);

    return 0;
}
