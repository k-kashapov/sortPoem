#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/// <summary>
/// Максимальное количество строк
/// </summary>
const int BUFF_SIZE = 5000;

//  Убирает предупреждение о функциях библиотеки string.h в Visual Studio
#pragma warning(disable:4996)

/**
 * @brief Merge sort для массивов строк
 * 
 * \param  str   Массив указателей на строки
 * \param  left  Левая граница сортировки
 * \param  right Правая граница сортировки
 * \return       Указатель на отсортированный массив
 */
char **merge_sort (char **str, int left, int right);

/**
 * @brief Сливает два отрезка массива (от left до middle и от middle до right) строк в отсортированном порядке
 * 
 * \param  str    Массив строк
 * \param  left   Левая граница отрезка слияния
 * \param  right  Правая граница отрезка слияния
 * \return        Отсортированный массив строк
 */
char **merge (char **str, int left, int right);
