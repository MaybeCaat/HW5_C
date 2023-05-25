#include <stdio.h>

// объявляем структуру Person
struct Person
{
    int age;
    char name[30];
};

// функция, считающая средний возраст в массиве из структур типа Person
float averageAge(struct Person arr[], int n) {
    // создаём переменную sumAges, где будет храниться сумма всех возрастов из массива
    // изначально равна 0 (ещё не начали читать массив)
    float sumAges = 0;

    // создаём указатель ptr на массив
    struct Person *ptr = arr;
    // перебираем с помощью указателя все структуры в массиве
    for (int i=0; i<n; ptr++, i++) {
        // добавляем возраст из текущей структуры к sumAges
        // явно приводим к float, чтобы потом при делении получить float (все age у нас - int)
        sumAges += (float) (ptr->age);
    }

    // средний возраст = сумма всех возрастов / на их количество (в данном случае на количество структур)
    return sumAges / (float) n;
}

int main() {
    // создаём переменную n и вводим в неё число с клавиатуры
    int n;
    scanf("%d", &n);

    // создаём массив persons из структур типа Person и указатель *ptr на него
    struct Person persons[n], *ptr=persons;
    // вводим поля текущей структуры с клавиатуры и записываем с помощью указателя ptr
    for (int i=0; i<n; ptr++, i++) {
        scanf("%d", &ptr->age);
        fgets(ptr->name, 30, stdin);
    }

    // выводим результат функции averageAge, которая вернёт средний возраст
    printf("%f", averageAge(persons, n));
    return 0;
}
