/*****************************************************************//**
 * \file   main.cpp
 * \mainpage Программа считывает строки из файла и сортирует их лексикографически
 * \section Ввод
 * Строки читаются из файла, по умолчанию название файла source.txt, параметр -n задаёт новое имя файла для чтения, \n параметр -o задаёт новое имя файля для записи
 * \section Вывод
 *  Печатает строки в отсортированном виде в файл, по умолчанию имя файла result.txt
 * \author Kamil
 * \date   August 2021
 *********************************************************************/

#include "files.h"
#include "sort.h"

int main (int argc, char* argv[])
{
    char *input_name = (char *) "source.txt";
    char *output_name = (char *) "result.txt";
    
    while (--argc)
    {
        char* arg = *++argv;
        if (!strcmp (arg, "-n"))
        {
            input_name = *++argv;
            argc--;
        }
        else 
        {
            if (!strcmp (arg, "-o"))
            {
                output_name = *++argv;
                argc--;
            }
        }
    }

    printf ("Reading file...\n");
    file_info info;
    read_all_lines (&info, input_name);
    assert (info.text != NULL);

    printf ("Sorting...\n");
    info.str_ptrs = merge_sort (info.str_ptrs, 0, info.lines_num);

    printf ("Printing output...\n");
    show_res(&info, output_name);

    free_info (&info);

    printf ("Done!\n");
    return 0;
}
