/*****************************************************************//**
 * \file   files.cpp
 * \brief  В файле собраны все функции, связанные с работой с файловой системой
 * 
 * \author Kamil
 * \date   August 2021
 *********************************************************************/
#include "files.h"

//  Убирает предупреждение о функциях библиотеки string.h в Visual Studio
#pragma warning(disable:4996)

file_info read_all_lines (const char *file_name)
{
    FILE *source = fopen (file_name, "rt");
    if (!source)
    {
         printf ("Couldn't open source file\n");
         exit (-1);
    }

    char *text_buff = read_to_end (source);

    char **strings = (char **) calloc (BUFF_SIZE, sizeof (char*));
    char **strings_ptr = strings;

    char *token;

    token = strtok (text_buff, "\n");

    while (token)
    {
        if (*token != '\n') 
        {
            int spaces_num = 0;            
            while (*token == ' ') token++;
            *strings_ptr++ = token;
        } 
        token = strtok (NULL, "\n");
    } 
    
    file_info result;
    result.str_ptrs = strings;
    result.text = text_buff;
    result.lines_num = strings_ptr - strings;

    fclose (source);
    
    return result;
}

char* read_to_end (FILE *source) 
{
    fseek (source, 0, SEEK_END);
    int length = ftell (source);
    if (length == 0)
    {
        printf ("Source file is empty!");
        exit (-2);
    }

    char *text_buff = (char *) calloc ( length, sizeof ( char ) );
    fseek (source, 0, SEEK_SET);

    int sym_read = fread (text_buff, sizeof (char), length, source);
    
    // Останавливает дальнейшее чтение, т.к. дальше лежит мусор
    text_buff[sym_read] = '\0';
    
    return text_buff;
}

void show_res (file_info source)
{
    FILE *destination = fopen ("result.txt", "w");
    
    if (!destination)
    {
         printf ("Couldn't open source file\n");
         exit (-1);
    }

    for (int i = 0; i < source.lines_num; i++)
    {
        fputs (*(source.str_ptrs + i), destination);
        fputs ("\n", destination);
    }
    fclose (destination);
}
