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

char** read_all_lines (int *lines_num, const char *file_name)
{
    FILE *source = fopen (file_name, "rb");
    char *text_buff = read_to_end (source);

    char **dest = (char **) calloc (BUFF_SIZE, sizeof (char[STR_BUFF_SIZE]));
    char **dest_ptr = dest;

    char *str_ptr = strtok (text_buff, "\n");

    do
    {
        if (*str_ptr != '\n' && *str_ptr != '\r') 
        {
            int spaces_num = 0;            
            while (*(str_ptr + spaces_num) == ' ') spaces_num++;
            *dest++ = strdup (str_ptr + spaces_num);
        }        
        str_ptr = strtok (NULL, "\n");
    } while (str_ptr);

    assert (dest != NULL);
    //memcpy (read_to, dest, BUFF_SIZE * sizeof (char[STR_BUFF_SIZE]));
    
    *lines_num = dest - dest_ptr;

    free (text_buff);
    fclose (source);
    
    return dest_ptr;
}

char* read_to_end (FILE *source) 
{
    fseek (source, 0, SEEK_END);
    int length = ftell (source);
    char *text_buff = (char *) calloc ( length, sizeof ( char ) );
    fseek (source, 0, SEEK_SET);

    fread (text_buff, sizeof (char), length, source);
    
    return strdup (text_buff);
}

void show_res (char **strings, int lines_num)
{
    FILE *destination = fopen ("result.txt", "w");
    for (int i = 0; i < lines_num; i++)
    {
        fputs (*(strings + i), destination);
    }
    fclose (destination);
}
