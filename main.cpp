/**
 * \mainpage Quadratic equations caclulator
 *
 * Написано на С. Решает квадратные уравнения вида ax^2 + bx + c = 0. \n 
 * 
 * \section Ввод
 *  Коэффициенты а, b и с формата long double вводятся с клавиатуры через пробел \n
 *  Аргумент --test запустит программу в режиме юнит-тестов \n
 * 
 * \section Вывод
 *  Программа печатает в терминал найденные корни.     
 * 
 * \section Коды выхода                    
 * 1 - Неверное количество корней
 * 
 * \section Анекдот
 *  Идёт Мюллер по коридору, усталый и раздражённый — русские уже у Берлина, работы невпроворот, ещё и фюрер опять наорал. Навстречу ему Штирлиц, несёт здоровую папку документов. \n
 *  — Герр Мюллер, позвольте...\n
 *  — Не до Вас сейчас, Штирлиц!\n
 *  — Но документы...\n
 *  — Подавитесь своими документами, дайте уже пройти!\n
 *  — Вы даже не хотите спросить...\n
 *  — Сгиньте с этими бумажками!\n
 *  — Но из Вашего же сейфа...\n
 *  — Последнее предупреждение!\n
 *  — Но советская разведка, гриф «Совершенно Секретно»...\n
 *  — ДА КАК ВЫ ДОСТАЛИ! НЕ ПОПАДУСЬ Я СНОВА НА ВАШИ УЛОВКИ!\n
 *  С этими словами Мюллер в ярости выхватывает папку из рук Штирлица и бьет ей его по голове.\n
 *  Гестапо озарила яркая вспышка. В документах лежала противопехотная мина. В фуражке Штирлица — ещё одна.\n
 */

#include <stdio.h>
#include <string.h>
#include "test.h"

// Отключает ошибку, связанную со scanf, в Visual Studio
#pragma warning(disable:4996) 

const int BAD_ROOTS_NUM = 1;

int main (int argc, char* argv[])
{
    if (argc == 2 && !strcmp (argv[1], "--test"))
    {
        return start_tests();
    }

    double a_coeff = 0.0, b_coeff = 0.0, c_coeff = 0.0; // Коэф-ы в конечном уравнении
    
    printf ("ax^2 + bx + c = 0\n");
    printf ("Input coefficients: a b c\n");
    scanf ("%lf %lf %lf", &a_coeff, &b_coeff, &c_coeff); // Считываем коэф-ы

    double x1 = 0.0, x2 = 0.0;
    
    char roots = solve_quadratic (a_coeff, b_coeff, c_coeff, &x1, &x2);

    switch (roots) // Смотрим, сколько корней
    {
        case 0:
            printf ("No roots");
            break; 
        case 1:    
            printf ("One root: x = %lf", x1);
            break; 
        case 2:    
            printf ("Roots: x1 = %lf, x2 = %lf", x1, x2);
            break; 
        case INF_ROOTS:
            printf ("Any x will do");
            break; 
        default:   
            printf ("FATAL ERROR: Something went wrong, roots = %d", roots);
            return BAD_ROOTS_NUM;
    }
    printf ("\n");

    return 0;
}
