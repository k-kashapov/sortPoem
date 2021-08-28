#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/// <summary>
/// Максимальное количество строк
/// </summary>
const int BUFF_SIZE = 5000;

const int READING_TEXT_FAILED = -1;

const int WRITING_TEXT_FAILED = -2;

const int OPEN_FILE_FAILED = -3;

const int MODE_NORM = 1;

const int MODE_REV = 1;

const int MODE_LEN = 2;

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
char **merge_sort (char **str, int left, int right, char reverse);

/**
 * \brief Сливает два отрезка массива (от left до middle и от middle до right) строк в отсортированном порядке
 * 
 * \param  str    Массив строк
 * \param  left   Левая граница отрезка слияния
 * \param  right  Правая граница отрезка слияния
 * \return        Отсортированный массив строк
 */
char **merge (char **str, int left, int right, char reverse);

/**
 * \brief  Разворачивает строку
 * 
 * \param  str Строка
 * \return     Указатель на отзеркаленную строку
 */
char *reverse_str (char *str);

/**
 * \brief Сравнивает строки по их окончаниям
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1 
 */
int strncmp_reverse (char *str1, char *str2);

/**
 * \brief Сравнивает строки по их началам
 * 
 * \param  str1, str2 Строки для сравнения
 * \return            Значение меньше нуля, если str1 < str2; ноль, если они равны; больше нуля, если str2 > str1 
 */
int strncmp_norm (char *str1, char *str2);

/**
 * \brief Сравнивает строки по длине
 * 
 * \param  str1, str2 Строки
 * \return            Значение меньше нуля, если длина str1 < длины str2; ноль, если они равны; больше нуля, если длина str2 > длины str1 
 */
int cmpr_len (char *str1, char *str2);

/**
 * \brief Вычисляет длину большей строки
 * 
 * \param  str1, str2 Строки
 * \return            Длина самой длинной строки из str1 и str2
 */
int max_len (char *str1, char *str2);
