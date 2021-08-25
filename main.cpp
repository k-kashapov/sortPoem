/*****************************************************************//**
 * \file   main.cpp
 * \brief  Сортирует строки в файле лексикографически
 * 
 * \author Kamil
 * \date   August 2021
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


//  Убирает предупреждение о функциях библиотеки string.h в Visual Studio
#pragma warning(disable:4996);

/// <summary>
/// Максимальная длина строки
/// </summary>
const int STR_BUFF_SIZE = 80;

/// <summary>
/// Максимальное количество строк
/// </summary>
const int BUFF_SIZE = 5000;

/**
 * @brief Читает все строки из файла, помещает в dest
 * 
 * \param  dest   Указатель на массив строк
 * \param  source Файл, который будет прочитан
 * \return        Количество прочитанных строк
 */
int read_all_lines (char **dest, FILE *source);

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

void show_res (char **res, int lines_num);

int main (int argc, char* argv[])
{
    FILE *source = fopen ("source.txt", "rb");
    char **strings = (char **) calloc (BUFF_SIZE, sizeof (char[STR_BUFF_SIZE]));

    int lines_num = read_all_lines (strings, source);

    strings = merge_sort (strings, 0, lines_num);

    show_res(strings, lines_num);
    
    fclose (source);

    return 0;
}

char* read_to_end (FILE *source) 
{
    fseek (source, 0, SEEK_END);
    int length = ftell (source);
    char *text_buff = (char *) calloc ( length, sizeof ( char ) );
    fseek (source, 0, SEEK_SET);

    fread (text_buff, sizeof (char), length, source);
    
    return strdup (text_buff);
}

void show_res (char **strings, int lines_num)
{
    FILE *destination = fopen ("result.txt", "w");
    for (int i = 0; i < lines_num; i++)
    {
        fputs (*(strings + i), destination);
    }
    fclose (destination);
}

int read_all_lines (char **dest, FILE *source)
{
    char *text_buff = read_to_end (source);

    char *str_buff = (char *) calloc (STR_BUFF_SIZE, sizeof (char) );
    char **dest_ptr = dest;
    
    str_buff = strtok (text_buff, "\n");

    do
    {
        if (*str_buff != '\n' && *str_buff != '\r') 
        {
            int spaces_num = 0;            
            while (*(str_buff+spaces_num) == ' ') spaces_num++;
            *dest++ = strdup (str_buff + spaces_num);
        }        
        str_buff = strtok (NULL, "\n");
    } while (str_buff);

    free (text_buff);
    
    int num_of_lines = dest - dest_ptr;
    return num_of_lines;
}


char **merge_sort (char **str, int left, int right)
{

    if (right > left + 1)
    {
        int middle = (left + right) / 2;
        merge_sort (str, left, middle);
        merge_sort (str, middle, right);
        return merge (str, left, right);
    }

    return str;
}


char **merge (char **str, int left, int right)
{ 
    int middle = (left + right) / 2;  
    char **buff = (char **) calloc ( BUFF_SIZE, sizeof (char*) );
    int left_iter = left, right_iter = middle, buff_iter = 0;  

    while (left_iter < middle || right_iter < right)
    {
        int compared_str;
        if (left_iter == middle) compared_str = 1;
        else if (right_iter == right) compared_str = -1;
        else compared_str = strcmp (str [left_iter], str [right_iter]); 

        if (compared_str <= 0)
        {
            buff [buff_iter] = str [left_iter];
            left_iter++;
            buff_iter++;
        }
        else
        {
            buff [buff_iter] = str [right_iter];
            right_iter++;
            buff_iter++;
        }
    }

    for (int i = 0; i < right - left; i++)
        *(str + left + i) = *(buff + i);
    
    free (buff);

    return str;
}
