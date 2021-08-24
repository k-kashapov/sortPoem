/*****************************************************************//**
 * \file   main.cpp
 * \brief  Sorts a Poem by W. Shakespeare lexicographically
 * 
 * \author Kamil
 * \date   August 2021
 *********************************************************************/

#include <stdio.h>
#include <string.h>

/// Hides "str... function is unsafe" warning
#pragma warning(disable:4996);

const int STR_BUFF_SIZE = 80;
const int BUFF_SIZE = 5000;

/**
 * Читает все строки из файла, помещает в dest
 * 
 * \param dest
 * \param source
 * \param num
 * \return Количество прочитанных строк
 */
int read_all_lines (char **dest, FILE *source);

/**
 * Merge sort для массивов строк
 * 
 * \param str
 * \param left
 * \param right
 * \return 
 */
char **merge_sort (char **str, int left, int right);

char **merge (char **str, int left, int middle, int right);

int main (int argc, char* argv[])
{
    FILE *source = fopen ("source.txt", "r");
    char *strings[BUFF_SIZE];

    int lines_num = read_all_lines (strings, source);

    for (int i = 0; i < lines_num; i++)
        printf ("%s", strings[i]);

    merge_sort (strings, 0, lines_num);
    return 0;
}

int read_all_lines (char **dest, FILE *source)
{
    char buff[STR_BUFF_SIZE];

    char **dest_ptr = dest;
    while (*dest++ = fgets (buff, STR_BUFF_SIZE, source));

    return dest - dest_ptr;
}


char **merge_sort (char **str, int left, int right)
{
    
    if (right > left + 1)
    {
        int middle = (left + right) / 2;
        merge_sort (str, left, middle);
        merge_sort (str, middle, right);
        return merge (str, left, middle, right);
    }

    return str;
}


char **merge (char **str, int left, int middle, int right)
{ 
    //char *buff[BUFF_SIZE];
    int left_iter = 0, right_iter = middle, buff_iter = 0;  

    while (left_iter < middle && right_iter < right)
    {
        int compared_str = strcmp (str [left_iter], str [right_iter]); 

        //paste merge code here ~~~
        
        left_iter++;
        right_iter++;
        buff_iter++;
    }
    return str;
}
