/*****************************************************************//**
 * \file   sort.cpp
 * \brief  В файле собраны функции, отвечающие за сортировку
 *********************************************************************/
#include "sort.h"


const int QSORT_LIMIT = 18;

char **merge_sort (char **strs, int left, int right, int (*sort_method) (char*, char*))
{
    assert (strs);
    assert (left <= right);

    if (right > left + 1)
    {
        int middle = (left + right) / 2;
        merge_sort (strs, left, middle, sort_method);
        merge_sort (strs, middle, right, sort_method);
        return merge (strs, left, right, sort_method);
    }

    return strs;
}

char **merge (char **str, int left, int right, int (*cmp_method) (char*, char*))
{ 
    assert (str);
    assert (left <= right);

    int middle = (left + right) / 2;  
    char **buff = (char **) calloc ( 5000, sizeof (*buff) );
    assert (buff);

    int left_iter = left, right_iter = middle, buff_iter = 0;  

    while (left_iter < middle || right_iter < right)
    {
        int compared_str = 0;
        if (left_iter == middle) compared_str = 1;
        else if (right_iter == right) compared_str = -1;
        else 
        {
            compared_str = cmp_method (str [left_iter], str [right_iter]);
        }

        if (compared_str <= 0)
        {
            buff [buff_iter++] = str [left_iter++];
        }
        else
        {
            buff [buff_iter++] = str [right_iter++];
        }
    }

    for (int i = 0; i < right - left; i++)
        *(str + left + i) = *(buff + i);
    
    free (buff);

    return str;
}

void quick_sort (char **str, int len, int (*cmp_method) (const char* str1, const char* str2))
{
    assert (str);

    if (len < QSORT_LIMIT)
    {
        bubble_sort (str, len, cmp_method);
        return;
    }

    swap (str, str + len / 2);    
    int left_iter = 0;
    
    if (len < 2)
        return;

    for (int curr = 1; curr < len; curr++)
    {
        int compared = cmp_method (*str, str [curr]);
        if (compared >= 0) 
        {
            left_iter++;
            swap (&str [left_iter], &str [curr]);
        }
    }
    
    swap (&str [left_iter], str);

    quick_sort (str, left_iter, cmp_method);
    quick_sort (str + left_iter + 1, len - left_iter - 1, cmp_method);
}

void bubble_sort (char **str, int len, int (*cmp_method) (const char* str1, const char* str2))
{
    assert (str);

    if (len < 2)
        return;
    
    for (len; len >= 2; --len )
    {
        int swapped = 0;
        for (int iter = 0; iter < len - 1; iter++)
        {
            if (cmp_method(str [iter], str [iter + 1]) > 0)
            {
                swap (&str [iter], &str[iter + 1]);
                swapped++;
            }
            else {
            }
        }
        if (!swapped) return;
    }
}

void swap (char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int strncmp_reverse (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);
    
    const char *end1 = str1 + str_len (str1);
    const char *end2 = str2 + str_len (str2);

    return end_cmp (str1, str2, end1, end2);
}

int strncmp_reverse_smart (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);
   
    const char *end1 = str1 + str_len (str1) + 1;
    const char *end2 = str2 + str_len (str2) + 1;
    
    while (!isalnum (*--end1)) ;
    while (!isalnum (*--end2)) ;

    return end_cmp (str1, str2, end1, end2);
}

int end_cmp (const char *str1, const char *str2, const char *end1, const char *end2)
{
    while (end1 >= str1 && end2 >= str2)
    {
        int difference = *end1 - *end2;
        
        if (difference != 0)
            return difference;
        
        end1--;
        end2--;
    }

    if (end1 < str1 && end2 < str2)
    {
         return 0;
    }

    else if (end1 < str1)
    {
         return -1;
    }
    
    else if (end2 < str2)
    {
         return 1;
    }
}

int strncmp_norm (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);

    int n = max_len (str1, str2);    
    return strncmp (str1, str2, n);
}

int strncmp_norm_smart (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);

    while (!isalnum (*str1)) str1++;
    while (!isalnum (*str2)) str2++;

    int n = max_len (str1, str2);    
    return strncmp (str1, str2, n);
}

int cmpr_len (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);

    int len_left = str_len (str1);
    int len_right = str_len (str2);
    return len_right - len_left;
}

int str_len (const char *str)
{
    const char *str_ptr = str;
    while (*str_ptr != '\n' && *str_ptr) str_ptr++;
    return (str_ptr - str);
}

int max_len (const char *str1, const char *str2)
{
    assert (str1);
    assert (str2);

    int len_left = str_len (str1);
    int len_right = str_len (str2);
    return len_left < len_right ? len_right : len_left;
}
