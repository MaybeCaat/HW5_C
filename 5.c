#include <stdio.h>

// функция, которая меняем местами в исходной матрице столбцы с минимальной и максимальной суммой
void swap_min_and_max_columns(int n, int m, int matrix[n][m]) {
    // создаём переменные для минимальной и максимальной сумм, а также индексами этих столбцов
    int min = 0, max = 0, min_index = 0, max_index = 0;

    // перебираем все столбцы
    for (int j=0; j<m; j++) {
        // создаём переменную sum с суммой текущего столбца
        int sum = 0;
        // считаем сумму с помощью перебора строк в столбце
        for (int i=0; i<n; i++) {
            sum += matrix[i][j];
        }

        // обновляем максимальную сумму и индекс столбца с ней,
        // если текущая сумма больше или если это первый столбец
        if (j == 0 || sum > max) {
            max = sum;
            max_index = j;
        }
        // обновляем минимальную сумму и индекс столбца с ней,
        // если текущая сумма меньше или если это первый столбец
        if (j == 0 || sum < min) {
            min = sum;
            min_index = j;
        }
    }

    // меняем местами столбцы с помощью дополнительной переменной
    for (int i = 0; i < n; i++){
        int temp = matrix[i][min_index];
        matrix[i][min_index] = matrix[i][max_index];
        matrix[i][max_index] = temp;
    }
}

int main() {
    // создаём переменные n, m и вводим их с клавиатуры
    int n, m;
    scanf("%d %d", &n, &m);

    // создаём матрицу размером n на m и вводим её
    int matrix[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // с помощью функции swap_min_and_max_columns меняем местами столбцы
    swap_min_and_max_columns(n, m, matrix);
    // а также выводим изменённую матрицу
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
