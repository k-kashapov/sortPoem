/*****************************************************************//**
 * \file   sort.cpp
 * \brief  В файле собраны функции, отвечающие за сортировку
 *********************************************************************/
#include "sort.h"

char **merge_sort (char **strs, int left, int right, char mode)
{
    assert (strs);
    assert (left <= right);

    if (right > left + 1)
    {
        int middle = (left + right) / 2;
        merge_sort (strs, left, middle, mode);
        merge_sort (strs, middle, right, mode);
        return merge (strs, left, right, mode);
    }

    return strs;
}


char **merge (char **str, int left, int right, char mode)
{ 
    assert (str);
    assert (left <= right);

    int middle = (left + right) / 2;  
    char **buff = (char **) calloc ( BUFF_SIZE, sizeof (*buff) );
    assert (buff);

    int left_iter = left, right_iter = middle, buff_iter = 0;  

    while (left_iter < middle || right_iter < right)
    {
        int compared_str = 0;
        if (left_iter == middle) compared_str = 1;
        else if (right_iter == right) compared_str = -1;
        else 
        {
            if (mode == MODE_NORM)
            {
                compared_str = strncmp_norm (str [left_iter], str [right_iter]);
            }
            if (mode == MODE_REV)
            {
                compared_str = strncmp_reverse (str [left_iter], str [right_iter]);
            }
            else if (mode == MODE_LEN)
            {
                compared_str = cmpr_len (str [left_iter], str [right_iter]);
            }
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

char *reverse_str (char *str)
{
    char *end_ptr = str + strlen (str);
    char *res = (char *) calloc (end_ptr - str, sizeof (*res));
    assert (res);

    char *res_ptr = res;
    end_ptr--;

    for (; end_ptr >= str; end_ptr--)
    {
        *res_ptr++ = *end_ptr;   
    }
    *res_ptr = '\0';

    return res;
}

int strncmp_reverse (char *str1, char *str2)
{
    assert (str1);
    assert (str2);
    
    int n = max_len (str1, str2);
    return strncmp (reverse_str (str1), reverse_str (str2), n);
}

int strncmp_norm (char *str1, char *str2)
{
    assert (str1);
    assert (str2);

    int n = max_len (str1, str2);    
    return strncmp (str1, str2, n);
}

int cmpr_len (char *str1, char *str2)
{
    assert (str1);
    assert (str2);

    int len_left = strlen (str1);
    int len_right = strlen (str2);
    return len_right - len_left;
}

int max_len (char *str1, char *str2)
{
    assert (str1);
    assert (str2);

    int len_left = strlen (str1);
    int len_right = strlen (str2);
    return len_left < len_right ? len_right : len_left;
}
