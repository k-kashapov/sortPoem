#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

/// <summary>
/// Максимальное количество строк
/// </summary>

//  Убирает предупреждение о функциях библиотеки string.h в Visual Studio
#pragma warning(disable:4996)

/**
 * \brief Merge sort для массивов строк
 * 
 * \param  str   Массив указателей на строки
 * \param  left  Левая граница сортировки
 * \param  right Правая граница сортировки
 * \return       Указатель на отсортированный массив
 */
char **merge_sort (char **str, int left, int right, int (*sort_method) (char*, char*));

/**
 * \brief Сливает два отрезка массива (от left до middle и от middle до right) строк в отсортированном порядке
 * 
 * \param  str    Массив строк
 * \param  left   Левая граница отрезка слияния
 * \param  right  Правая граница отрезка слияния
 * \return        Отсортированный массив строк
 */
char **merge (char **str, int left, int right, int (*sort_method) (char*, char*));

/**
 * \brief Быстрая сортировка массива строк
 * 
 * \param  str   Массив указателей на строки
 * \param  left  Левая граница сортировки
 * \param  right Правая граница сортировки
 * \return       Указатель на отсортированный массив
 */
void quick_sort (char **str, int len, int (*cmp_method) (const char* str1, const char* str2));

/**
 * \brief Cортировка массива строк пузырьком
 * 
 * \param  str   Массив указателей на строки
 * \param  left  Левая граница сортировки
 * \param  right Правая граница сортировки
 * \return       Указатель на отсортированный массив
 */
void bubble_sort (char **str, int len, int (*cmp_method) (const char* str1, const char* str2));

/**
 * \brief Сравнивает строки по их окончаниям
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1 
 */
int strncmp_reverse (const char *str1, const char *str2);

/**
 * \brief Сравнивает строки по их окончаниям, пропускает все знаки препинания в конце строки
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1  
 */
int strncmp_reverse_smart (const char *str1, const char *str2);

/**
 * \brief Сравнивает строки по их началам
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1 
 */
int strncmp_norm (const char *str1, const char *str2);

/**
 * \brief Сравнивает строки с начала, пропускает все знаки препинания перед строкой
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1 
 */
int strncmp_norm_smart (const char *str1, const char *str2);

/**
 * \brief Сравнивает строки по длине
 * 
 * \param  str1, str2 Строки
 * \return            Значение меньше нуля, если длина str1 < длины str2; ноль, если они равны; больше нуля, если длина str2 > длины str1 
 */
int cmpr_len (const char *str1, const char *str2);

/**
 * \brief Вычисляет длину большей строки
 * 
 * \param  str1, str2 Строки
 * \return            Длина самой длинной строки из str1 и str2
 */
int max_len (const char *str1, const char *str2);

/**
 * \brief Меняет местами строки a и b по указателям
 * 
 * \param a, b Указатели на строки
 */
void swap (char **a, char **b);

/**
 * \brief Находит длину строки, останавливается, если встретит '\\n' или '\\0'
 * 
 * \param  str Указатель на строку
 * \return     Длина строки
 */
int str_len (const char *str);
