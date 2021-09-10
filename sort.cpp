/*****************************************************************//**
 * \file   sort.cpp
 * \brief  В файле собраны функции, отвечающие за сортировку
 *********************************************************************/
#include "sort.h"
#include "stdint.h"

const int QSORT_LIMIT = 18;

void quick_sort (void * ptr, size_t type_size, size_t len, int(*cmp_method)(const void *str1, const void *str2))
{
    assert (ptr);
    
    if (len < QSORT_LIMIT)
    {
        bubble_sort (ptr, type_size, len, cmp_method);
        return;
    }

    char *arr = (char *)ptr;

    swap ((void **)arr, (void **)(arr + len / 2 * type_size), type_size);    
    int left_iter = 0;
    
    if (len < 2)
        return;                    

    for (int curr = 1; curr < len; curr++)
    {
        int compared = cmp_method (arr, (arr + curr * type_size));
        if (compared >= 0) 
        {
            left_iter++;
            swap ((void **)(arr + left_iter * type_size), (void **)(arr + curr * type_size), type_size);
        }
    }
    
    swap ((void **)(arr + left_iter * type_size), (void **) arr, type_size);

    quick_sort (arr, type_size, left_iter, cmp_method);
    quick_sort (arr + (left_iter + 1) * type_size, type_size, len - left_iter - 1, cmp_method);
}

void bubble_sort (void * ptr, size_t type_size, size_t len, int(*cmp_method)(const void *str1, const void *str2))
{
    assert (ptr);

    if (len < 2)
        return;

    char *arr = (char *)ptr;
    for (len; len >= 2; --len )
    {
        int swapped = 0;
        for (int iter = 0; iter < len - 1; iter++)
        {
            int compared = cmp_method((arr + iter * type_size), (arr + (iter + 1) * type_size));
            if (compared > 0)
            {
                swap ((void **)(arr + iter * type_size), (void **)(arr + (iter + 1) * type_size), type_size);
                swapped++;
            }
            else {
            }
        }
        if (!swapped) return;
    }
}

void swap (void **a, void **b, int len)
{   
    int iter = 0;
    int64_t buff64_bits = 0;
    int32_t buff32_bits = 0;
    int16_t buff16_bits = 0;
    int8_t buff8_bits = 0;

    while (len / 8 > 0)
    {
        int64_t * a_ptr = ((int64_t *)a + iter);
        int64_t * b_ptr = ((int64_t *)b + iter);
        buff64_bits = *a_ptr;
        *a_ptr = *b_ptr;
        *b_ptr = buff64_bits;
        iter += 1;
        len -= 8;
    }
    
    while (len / 4 > 0)
    {
        int32_t * a_ptr = ((int32_t *)a + iter);
        int32_t * b_ptr = ((int32_t *)b + iter);
        buff32_bits = *a_ptr;
        *a_ptr = *b_ptr;
        *b_ptr = buff32_bits;
        iter += 1;
        len -= 4;
    }

    while (len / 2 > 0)
    {
        int16_t * a_ptr = ((int16_t *)a + iter);
        int16_t * b_ptr = ((int16_t *)b + iter);
        buff16_bits = *a_ptr;
        *a_ptr = *b_ptr;
        *b_ptr = buff16_bits;
        iter += 1;
        len -= 2;
    }

    while (len > 0)
    {
        char * a_ptr = ((char *)a + iter);
        char * b_ptr = ((char *)b + iter);
        buff8_bits = *a_ptr;
        *a_ptr = *b_ptr;
        *b_ptr = buff8_bits;
        iter += 1;
        len -= 1;
    }

    return;
}

int strncmp_reverse (const void * str1_ptr, const void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);
    
    string **ptr1 = (string **)str1_ptr;
    string **ptr2 = (string **)str2_ptr;

    char *str1 = (*ptr1)->text;
    char *str2 = (*ptr2)->text;

    char *end1 = str1 + (*ptr1)->len + 1;
    char *end2 = str2 + (*ptr2)->len + 1;

    return end_cmp (str1, str2, end1, end2);
}

int strncmp_reverse_smart (const void * str1_ptr, const void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);
    
    string **ptr1 = (string **)str1_ptr;
    string **ptr2 = (string **)str2_ptr;

    char *str1 = (*ptr1)->text;
    char *str2 = (*ptr2)->text;

    char *end1 = str1 + (*ptr1)->len + 1;
    char *end2 = str2 + (*ptr2)->len + 1;
    
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

int strncmp_norm (const void * str1_ptr, const void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);

    string **ptr1 = (string **)str1_ptr;
    string **ptr2 = (string **)str2_ptr;

    char *str1 = (*ptr1)->text;
    char *str2 = (*ptr2)->text;

    int max_len = (*ptr1)->len;
    if ((*ptr2)->len > max_len) max_len = (*ptr2)->len;    
    return strncmp (str1, str2, max_len);
}

int strncmp_norm_smart (const void * str1_ptr, const void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);

    string **ptr1 = (string **)str1_ptr;
    string **ptr2 = (string **)str2_ptr;

    char *str1 = (*ptr1)->text;
    char *str2 = (*ptr2)->text;

    while (!isalnum (*str1)) str1++;
    while (!isalnum (*str2)) str2++;        

    int max_len = (*ptr1)->len;
    if ((*ptr2)->len > max_len) max_len = (*ptr2)->len;
        
    return strncmp (str1, str2, max_len);
}

int cmpr_len (const void * str1_ptr, const void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);

    string **ptr1 = (string **)str1_ptr;
    string **ptr2 = (string **)str2_ptr;

    return (*ptr1)->len - (*ptr2)->len;
}
