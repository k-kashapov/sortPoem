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
    printf ("Reading file...\n");
    file_info source = read_all_lines ("source.txt");
    assert (source.text != NULL);

    printf ("Sorting...\n");
    source.str_ptrs = merge_sort (source.str_ptrs, 0, source.lines_num);

    printf ("Printing output...\n");
    show_res(source);

    printf ("Done!\n");
    return 0;
}
