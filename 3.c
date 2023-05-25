#include <stdio.h>

// объявляем структуру Move
struct Move
{
    int x;
    int y;
};

// функция, считающая сдвиг для попадания в конечную точку и возвращающая его в виде структуры типа Move
// посчитать её можно просто сложив все координаты x и y
struct Move getFinishPoint(struct Move moves[], int n) {
    // создаём структуру res типа Move для результата, а также указатель на массив из структур типа Move
    struct Move res = {0, 0}, *ptr=moves;
    // перебираем с помощью указателя все структуры в массиве
    for (int i=0; i<n; ptr++, i++) {
        // прибавляем координаты текущей структуры к res
        res.x += (ptr->x);
        res.y += (ptr->y);
    }
    // возвращаем res
    return res;
}

int main() {
    // создаём переменную n и вводим в неё число с клавиатуры
    int n;
    scanf("%d", &n);

    // создаём массив moves из структур типа Move и указатель *ptr на него,
    // а также структуру res для результата
    struct Move moves[n], *ptr=moves, res;
    // вводим поля текущей структуры с клавиатуры и записываем с помощью указателя ptr
    for (int i=0; i<n; ptr++, i++) {
        scanf("%d %d", &ptr->x, &ptr->y);
    }

    // результат функции getFinishPoint записываем в созданную выше переменную res,
    // а затем выводим его
    res = getFinishPoint(moves, n);
    printf("%d %d", res.x, res.y);
    return 0;
}
