/*****************************************************************//**
 * \file   sort.cpp
 * \brief  В файле собраны функции, отвечающие за сортировку
 *********************************************************************/

#include "sort.h"
#include "stdint.h"

#define SWAP_BITS(buff, buff_type, buffer_size)                                             \
            while (len >= buffer_size)                                                      \
            {                                                                               \
                buff_type * a_ptr = ((buff_type *)a + iter);                                \
                buff_type * b_ptr = ((buff_type *)b + iter);                                \
                buff = *a_ptr;                                                              \
                *a_ptr = *b_ptr;                                                            \
                *b_ptr = buff;                                                              \
                iter += 1;                                                                  \
                len -= buffer_size;                                                         \
            }
                                                                                            \
#define TO_STRING()                                                                         \
            string **ptr1 = (string **)str1_ptr;                                        \
            string **ptr2 = (string **)str2_ptr;                                        \
                                                                                        \
            char *str1 = (*ptr1)->text;                                                 \
            char *str2 = (*ptr2)->text;                                                 \

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

    swap (arr, (arr + len / 2 * type_size), type_size);    
    int left_iter = 0;
    
    if (len < 2)
        return;                    

    for (int curr = 1; curr < len; curr++)
    {
        int compared = cmp_method (arr, (arr + curr * type_size));
        if (compared >= 0) 
        {
            left_iter++;
            swap ((arr + left_iter * type_size), (arr + curr * type_size), type_size);
        }
    }
    
    swap ((arr + left_iter * type_size), arr, type_size);

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
                swap ((arr + iter * type_size), (arr + (iter + 1) * type_size), type_size);
                swapped++;
            }
        }
        if (!swapped) return;
    }
}

void swap (void * a_ptr, void * b_ptr, int len)
{   
    char *a = (char *)a_ptr;
    char *b = (char *)b_ptr;
    int iter = 0;
    int64_t buff64_bits = 0;
    int32_t buff32_bits = 0;
    int16_t buff16_bits = 0;
    int8_t buff8_bits = 0;

    SWAP_BITS (buff64_bits, int64_t, 8);
    SWAP_BITS (buff32_bits, int32_t, 4);
    SWAP_BITS (buff16_bits, int16_t, 2);
    SWAP_BITS (buff8_bits, int8_t, 1);
}

int strncmp_reverse (const void * str1_ptr, const void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);
    
    TO_STRING();

    char *end1 = str1 + (*ptr1)->len + 1;
    char *end2 = str2 + (*ptr2)->len + 1;

    return end_cmp (str1, str2, end1, end2);
}

int strncmp_reverse_smart (const void * str1_ptr, const void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);
    
    TO_STRING();

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

    TO_STRING();

    int max_len = (*ptr1)->len;
    if ((*ptr2)->len > max_len) max_len = (*ptr2)->len;    
    return strncmp (str1, str2, max_len);
}

int strncmp_norm_smart (const void * str1_ptr, const void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);

    TO_STRING();

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
