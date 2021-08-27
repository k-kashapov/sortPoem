/*****************************************************************//**
 * \file   sort.cpp
 * \brief  В файле собраны функции, отвечающие за сортировку
 * 
 * \author Kamil
 * \date   August 2021
 *********************************************************************/
#include "sort.h"
char **merge_sort (char **strs, int left, int right)
{
    assert (strs);
    assert (left <= right);

    if (right > left + 1)
    {
        int middle = (left + right) / 2;
        merge_sort (strs, left, middle);
        merge_sort (strs, middle, right);
        return merge (strs, left, right);
    }

    return strs;
}


char **merge (char **str, int left, int right)
{ 
    assert (str);
    assert (left <= right);

    int middle = (left + right) / 2;  
    char **buff = (char **) calloc ( BUFF_SIZE, sizeof (char*) );
    assert (buff);

    int left_iter = left, right_iter = middle, buff_iter = 0;  

    while (left_iter < middle || right_iter < right)
    {
        int compared_str = 0;
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
