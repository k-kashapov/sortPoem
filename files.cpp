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

int read_all_lines (file_info *info, const char* file_name)
{
    assert (info != NULL);

    FILE *source = NULL;
    open_file_loop (&source, file_name, "rt");

    char *text_buff = read_to_end (source);

    fclose (source);

    char **strings = (char **) calloc (BUFF_SIZE, sizeof (char*));
    assert (strings);

    char **strings_ptr = strings;

    for (char *token = strtok (text_buff, "\n"); token; token = strtok (NULL, "\n"))
    {
        if (*token != '\n') 
        {           
            while (*token == ' ') token++;
            *strings_ptr++ = token;
        } 
    } 
    
    info->str_ptrs = strings;
    info->text = text_buff;
    info->lines_num = strings_ptr - strings;
    
    return 0;
}

void open_file_loop (FILE **ptr, const char* file_name, const char* mode)
{
    for (*ptr = fopen (file_name, mode); !(*ptr); *ptr = fopen (file_name, mode))
    {
         printf ("Couldn't open source file \nPress enter button to try again...\n");
         getchar ();
    }
}

char* read_to_end (FILE *source) 
{
    fseek (source, 0, SEEK_END);
    int length = ftell (source);

    char *text_buff = (char *) calloc ( length + 1, sizeof ( char ) );
    assert (text_buff);

    fseek (source, 0, SEEK_SET);

    int sym_read = fread (text_buff, sizeof (char), length, source);
    
    // Останавливает дальнейшее чтение, т.к. дальше лежит мусор
    text_buff[sym_read] = '\0';
    
    return text_buff;
}

void show_res (file_info *source, char* output_file)
{
    assert (source);
    
    FILE *destination = fopen (output_file, "w");

    if (!destination)
    {
         printf ("Couldn't open source file\n");
         // TODO adequate return
    }

    for (int i = 0; i < source->lines_num; i++)
    {
        fputs (*(source->str_ptrs + i), destination);
        fputs ("\n", destination);
    }
    fclose (destination);
}

void free_info (file_info *info)
{
    free (info->text);
    free (info->str_ptrs);
}
