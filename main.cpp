/*****************************************************************//**
 * \file   main.cpp
 * \brief  Сортирует строки в файле лексикографически
 * 
 * \author Kamil
 * \date   August 2021
 *********************************************************************/

#include "files.h"
#include "sort.h"

int main (int argc, char* argv[])
{
    int num_of_lines = 0;

    printf ("Reading file...\n");
    char **strings = read_all_lines (&num_of_lines, "source.txt");
    
    printf ("Sorting...\n");
    strings = merge_sort (strings, 0, num_of_lines);
    
    printf ("Printing output...\n");
    show_res(strings, num_of_lines);

    printf ("Done!\n");
    return 0;
}
