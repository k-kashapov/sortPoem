#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

struct string
{
    char *text;
    int len;
};

/// <summary>
/// Максимальное количество строк
/// </summary>

//  Убирает предупреждение о функциях библиотеки string.h в Visual Studio
#pragma warning(disable:4996)

/**
 * \brief Быстрая сортировка массива
 * 
 * \param  str   Массив указателей
 * \param  left  Левая граница сортировки
 * \param  right Правая граница сортировки
 * \return       Указатель на отсортированный массив
 */
void  quick_sort (void ** ptr, int len, int(*cmp_method)(void *str1, void *str2));

/**
 * \brief Cортировка массива пузырьком
 * 
 * \param  str   Массив указателей
 * \param  left  Левая граница сортировки
 * \param  right Правая граница сортировки
 * \return       Указатель на отсортированный массив
 */
void  bubble_sort (void ** ptr, int len, int(*cmp_method)(void *str1, void *str2));

/**
 * \brief Сравнивает строки по их окончаниям
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1 
 */
int strncmp_reverse (void * str1_ptr, void * str2_ptr);

/**
 * \brief Сравнивает строки по их окончаниям, пропускает все знаки препинания в конце строки
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1  
 */
int strncmp_reverse_smart (void * str1_ptr, void * str2_ptr);

/**
 * \brief Сравнивает строки от end до str, end > str
 * 
 * \param str1, str2 Указатели на начало строк
 * \param end1, end2 Указатели на окончание строк
 * 
 * \return           Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1  
 */
int end_cmp (const char *str1, const char *str2, const char *end1, const char *end2);

/**
 * \brief Сравнивает строки по их началам
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1 
 */
int strncmp_norm (void *str1, void *str2);

/**
 * \brief Сравнивает строки с начала, пропускает все знаки препинания перед строкой
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1 
 */
int strncmp_norm_smart (void *str1, void *str2);

/**
 * \brief Сравнивает строки по длине
 * 
 * \param  str1, str2 Строки
 * \return            Значение меньше нуля, если длина str1 < длины str2; ноль, если они равны; больше нуля, если длина str2 > длины str1 
 */
int cmpr_len (void *str1, void *str2);

/**
 * \brief Вычисляет длину большей строки
 * 
 * \param  str1, str2 Строки
 * \return            Длина самой длинной строки из str1 и str2
 */
//int max_len (const char * str1, const char * str2);

/**
 * \brief Меняет местами строки a и b по указателям
 * 
 * \param a, b Указатели на строки
 */
void swap (void **a, void **b, int len);

/**
 * \brief Находит длину строки, останавливается, если встретит '\\n' или '\\0'
 * 
 * \param  str Указатель на строку
 * \return     Длина строки
 */
//int str_len (const char * str);
