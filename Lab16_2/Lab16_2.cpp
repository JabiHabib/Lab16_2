#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>

#define SIZE 10

int main() {
    setlocale(LC_ALL, "Ukr");

    srand(time(NULL));

    // Введення користувачем розмірності матриці
    printf("Введiть розмiр масиву (N x N, N <= 10): ");
    int N;

    scanf_s("%d", &N);

    if (N > 10) {
        printf("Ви ввели неправильний розмiр матриці N > 10");
        return 0;
    }

    // Оголошення та заповнення матриці "рандомними" числами
    int a[SIZE][SIZE];
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            a[j][i] = rand() % 100;
        }
    }

    // Вивід матриці у консоль
    printf("Початкова матриця: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("[%0.2d]", a[i][j]);
        }
        printf("\n");
    }

    // Пошук найбільшого елемента та суми елементів рядка, в якому розташований найбільший елемент
    int maxRowIndex = 0;
    int maxElement = a[0][0];
    int sumRowWithMaxElement = 0;

    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += a[i][j];

            if (a[i][j] > maxElement) {
                maxElement = a[i][j];
                maxRowIndex = i;
            }
        }

        if (i == maxRowIndex) {
            sumRowWithMaxElement = rowSum;
        }
    }

    // Вивід результатів
    printf("\nНайбiльший елемент: %d\n", maxElement);
    printf("Сума елементiв рядка, в якому розташований найбiльший елемент: %d\n", sumRowWithMaxElement);

    return 0;
}