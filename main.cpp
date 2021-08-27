/*****************************************************************//**
 * \file   main.cpp
 * \mainpage Программа считывает строки из файла и сортирует их лексикографически
 * \section Ввод
 * Строки читаются из файла, по умолчанию название файла source.txt; \nпараметр -n задаёт новое имя файла для чтения; \n параметр -o задаёт новое имя файля для записи
 * \section Вывод
 *  Печатает строки в отсортированном виде в файл, по умолчанию имя файла result.txt
 * \section Анекдот
 * Выпускник морского училища пришел работать в судоходную компанию штурманом. Долго, хорошо работал, капитаном стал.
 * \nИ была всю жизнь у него одна привычка: каждое утро он начинал вахту с того, что открывал левый верхний ящичек штурманского стола, заглядывал в него, а потом закрывал на ключ. 
 * \nКогда он ушёл на пенсию, экипаж бросился к столу и вскрыл этот ящичек — там лежала старая-старая, потрёпанная бумажка, на которой было написано: «Нос — перёд, зад — корма».
 * 
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
    info.strs = merge_sort (info.strs, 0, info.lines_num);

    printf ("Printing output...\n");
    show_res(&info, output_name);

    free_info (&info);

    printf ("Done!\n");
    return 0;
}
