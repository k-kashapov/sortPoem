/*****************************************************************//**
 * \file   files.cpp
 * \brief  В файле собраны все функции, связанные с работой с файловой системой
 *********************************************************************/
#include "files.h"

//  Убирает предупреждение о функциях библиотеки string.h в Visual Studio
#pragma warning(disable:4996)

int read_all_lines (file_info *info, const char* file_name)
{
    assert (info);
    assert (file_name);

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
    
    info->text = text_buff;
    info->strs = strings;
    info->lines_num = strings_ptr - strings;
    
    return 0;
}

void open_file_loop (FILE **ptr, const char* file_name, const char* mode)
{
    *ptr = fopen (file_name, mode);
    if (!ptr)
    {
        printf ("Couldn't open file \"%s\"\n", file_name);
        exit (OPEN_FILE_FAILED);
    }
}

char* read_to_end (FILE *source) 
{
    assert (source);
    
    int length = get_len (source);

    char *text_buff = (char *) calloc ( length + 1, sizeof ( char ) );
    assert (text_buff);

    int sym_read = fread (text_buff, sizeof (*text_buff), length, source);
    
    if (sym_read < 0 || sym_read > length)
    {
         free (text_buff);
         printf ("FATAL: Reading text file failed");
         exit (READING_TEXT_FAILED);
    }

    // Останавливает дальнейшее чтение, т.к. дальше лежит мусор
    text_buff[sym_read] = '\0';
    
    return text_buff;
}

int get_len (FILE *file)
{
    assert (file);

    fseek (file, 0, SEEK_END);
    int length = ftell (file); 
    fseek (file, 0, SEEK_SET);

    return length;
}

void show_res (file_info *text, const char * output_file)
{
    assert (text);
    
    FILE *destination = NULL;
    open_file_loop (&destination, output_file, "wt");

    for (int i = 0; i < text->lines_num; i++)
    {
        char printed = fputs (*(text->strs + i), destination);
        if (printed == EOF || fputs ("\n", destination) == EOF)
        {
            printf ("Writing to file failed!");
            free_info (text);
            exit (WRITING_TEXT_FAILED);
        }
    }
    fclose (destination);
}

void free_info (file_info *info)
{
    assert (info);

    free (info->text);
    free (info->strs);
}

void get_params (int argc, char **argv, config *current)
{
    assert (argv);
    assert (current);
    
    while (--argc)
    {
        char* arg = *++argv;
        if (!strncmp (arg, "-n", 2))
        {
            current->input_file = *++argv;
            argc--;
        }
        else 
        {
            if (!strncmp (arg, "-o", 2))
            {
                current->output_file = *++argv;
                argc--;
            }
            else if (!strncmp (arg, "-r", 2))
            {   
                current->mode = *strncmp_reverse;
            }
            else if (!strncmp (arg, "-l", 2))
            {
                current->mode = *cmpr_len;
            }
        }
    }
}
