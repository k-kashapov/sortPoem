/*****************************************************************//**
 * \file   sort.cpp
 * \brief  В файле собраны функции, отвечающие за сортировку
 *********************************************************************/
#include "sort.h"

const int QSORT_LIMIT = 18;

void quick_sort (void **str_ptr, int len, int(*cmp_method)(void *str1, void *str2))
{
    assert (str_ptr); // TODO void ebaniy
    
    /*if (len < 11)
    {
         string **aaaa = (string **)str_ptr;
         for (int i = 0; i < len; i++)
         {
            printf ("%s\n", aaaa [i]->text);   
         }
         printf ("==============");
    }*/

    if (len < QSORT_LIMIT)
    {
        bubble_sort (str_ptr, len, cmp_method);
        return;
    }

    swap (str_ptr, (str_ptr + len / 2), sizeof (string **));    
    int left_iter = 0;
    
    if (len < 2)
        return;

                          

    for (int curr = 1; curr < len; curr++)
    {
        int compared = cmp_method (*str_ptr, *(str_ptr + curr));
        if (compared >= 0) 
        {
            left_iter++;
            swap (str_ptr + left_iter, str_ptr + curr, sizeof (string **));
        }
    }
    
    swap (str_ptr + left_iter, str_ptr, sizeof (string **));

    quick_sort (str_ptr, left_iter, cmp_method);
    quick_sort (str_ptr + left_iter + 1, len - left_iter - 1, cmp_method);
}

void bubble_sort (void **str_ptr, int len, int(*cmp_method)(void *str1, void *str2))
{
    assert (str_ptr);

    if (len < 2)
        return;
    
    string **str = (string **)str_ptr;

    for (len; len >= 2; --len )
    {
        int swapped = 0;
        for (int iter = 0; iter < len - 1; iter++)
        {
            int jojo = cmp_method(*(str + iter), *(str + iter + 1));
            if (jojo > 0)
            {
                swap (str_ptr + iter, str_ptr + iter + 1, sizeof (string **));
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
    void *temp = malloc (len);
    assert (temp);
    memcpy (temp, a, len);
    memcpy (a, b, len);
    memcpy (b, temp, len);
    free (temp);
}

int strncmp_reverse (void * str1_ptr, void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);
    
    string *ptr1 = (string *)str1_ptr;
    string *ptr2 = (string *)str2_ptr;

    char *str1 = ptr1->text;
    char *str2 = ptr2->text;

    char *end1 = str1 + ptr1->len;
    char *end2 = str2 + ptr2->len;

    return end_cmp (str1, str2, end1, end2);
}

int strncmp_reverse_smart (void * str1_ptr, void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);
    
    string *ptr1 = (string *)str1_ptr;
    string *ptr2 = (string *)str2_ptr;

    char *str1 = ptr1->text;
    char *str2 = ptr2->text;

    char *end1 = str1 + ptr1->len + 1;
    char *end2 = str2 + ptr2->len + 1;
    
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

int strncmp_norm (void * str1_ptr, void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);

    string *ptr1 = (string *)str1_ptr;
    string *ptr2 = (string *)str2_ptr;

    int curr = (string **) str2_ptr - (string **) str1_ptr;

    //printf ("%s\n", ptr2->text);

    char *str1 = ptr1->text;
    char *str2 = ptr2->text;

    int max_len = ptr1->len;
    if (ptr2->len > max_len) max_len = ptr2->len;    
    return strncmp (str1, str2, max_len);
}

int strncmp_norm_smart (void * str1_ptr, void * str2_ptr)
{
    string *ptr1 = (string *)str1_ptr;
    string *ptr2 = (string *)str2_ptr;

    char *str1 = ptr1->text;
    char *str2 = ptr2->text;                          
    
   
    assert (str1);
    assert (str2);

    while (!isalnum (*str1)) str1++;
    while (!isalnum (*str2)) str2++;        
   
    int max_len = ptr1->len;
    if (ptr2->len > max_len) max_len = ptr2->len;    
    return strncmp (str1, str2, max_len);
}

int cmpr_len (void * str1_ptr, void * str2_ptr)
{
    assert (str1_ptr);
    assert (str2_ptr);

    string *ptr1 = (string *)str1_ptr;
    string *ptr2 = (string *)str2_ptr;

    return ptr1->len - ptr2->len;
}
