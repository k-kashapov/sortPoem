/*****************************************************************//**
 * \file   main.cpp
 * \mainpage Программа считывает строки из файла и сортирует их лексикографически
 * \section Ввод
 * Строки читаются из файла, по умолчанию название файла source.txt; \n
 * параметр -n задаёт новое имя файла для чтения; \n
 * параметр -o задаёт новое имя файля для записи; \n
 * параметр -r задаёт сортировку строки по окончанию; \n
 * параметр -l задаёт сортировку строк по длине.
 * \section Вывод
 *  Печатает строки в отсортированном виде в файл, по умолчанию имя файла result.txt
 * \section Анекдот
 * Выпускник морского училища пришел работать в судоходную компанию штурманом. Долго, хорошо работал, капитаном стал.\n 
 * И была всю жизнь у него одна привычка: каждое утро он начинал вахту с того, что открывал левый верхний ящичек штурманского стола, заглядывал в него, а потом закрывал на ключ. \n 
 * Когда он ушёл на пенсию, экипаж бросился к столу и вскрыл этот ящичек — там лежала старая-старая, потрёпанная бумажка, на которой было написано: «Нос — перёд, зад — корма».
 * 
 * \author Kamil
 * \date   August 2021
 *********************************************************************/

#include "files.h"
#include "sort.h"

int main (int argc, char* argv[])
{
    config files;
    get_params (argc, argv, &files);

    printf ("Reading file...\n");
    file_info info = {};
    read_all_lines (&info, files.input_file);

    printf ("Sorting...\n");
    quick_sort (info.strs, info.lines_num, files.mode);

    printf ("Printing output...\n");
    show_res (&info, files.output_file);

    free_info (&info);

    printf ("Done!\n");
    return 0;
}
