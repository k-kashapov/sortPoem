/*****************************************************************//**
 * \file   main.cpp
 * \brief  My implementations of stdio library functions: puts, strlen, strchr, strcpy,
 *         strncpy, ~~~
 * 
 *********************************************************************/

#include <stdio.h>   
#include <string.h>
#include <assert.h> 
#include <stdlib.h> 

/// Hides "str... function is unsafe" warning
#pragma warning(disable:4996)

/**
 * Prints string to stdout
 * 
 * \param const char* str String
 * \return 1, if printing succeeded; else EOF.
 */
int puts_ (const char *str)
{
    assert (str != NULL);

    while (*str != '\0')
        if (putc (*str++, stdout) == EOF)
            return EOF;
    putc ('\n', stdout);
    return 1;
}

/**
 * Counts amount of symbols is a string
 * 
 * \param const char* str String
 * \return unsigned long long Number of symbols 
 */
unsigned long long strlen_ (const char *str)
{
    assert (str != NULL);

    const char *ptr = str;
    while (*ptr++);
    return ptr - str - 1;        
}

/**
 * Finds the first letter in str that matches the chr
 * 
 * \param const char *str String
 * \param char chr Char to be found
 * \return A pointer to the char if found, NULL if not
 */
const char* strchr_ (const char *str, char chr)
{
    assert (str != NULL);
    
    while (*str != chr && *str) str++;
    return *str == '\0' ? NULL : str;
}

/**
 * Copies contents of one string into another
 * 
 * \param char* copy_to
 * \param const char* copy_from
 * \return char* Pointer to the copied string
 */
char *strcpy_ (char *copy_to, const char *copy_from)
{
    assert (copy_from != NULL);
    assert (copy_to != NULL);

    char *copied = copy_to;
    while (*copy_to++ = *copy_from++);
    return copied;
}

/**
 * Copies first n symbols of one string into another
 * 
 * \param char* copy_to
 * \param const char* copy_from
 * \param n Amount of symbols to be copied
 * \return Pointer to the copied string
 */
char *strncpy_ (char *copy_to, const char *copy_from, int n)
{
    assert (copy_from != NULL);
    assert (copy_to != NULL);

    int i = n;
    char *result = copy_to;

    while (*copy_to++ = *copy_from++ && i) i--;   
    
    while (i) 
    {
        *copy_to++ = '\0';
        i--;   
    }
        
    return result;
}

/**
 * Alternative version of strncpy
 */
char *strncpy_alt (char *copy_to, const char *copy_from, int n)
{
    assert (copy_from != NULL);
    assert (copy_to != NULL);

    memset (copy_to, '\0', n);
    int size = strlen (copy_from);
    size = size < n ? size : n;
    memcpy (copy_to, copy_from, size);
        
    return copy_to;
}

/**
 * Concatenates destination and source strings
 * 
 * \param  char* dest
 * \param  char* source 
 * \return Pointer to the result string 
 */
char *strcat_ (char *dest, const char *source)
{
    char *result = dest;
    
    dest += strlen (dest); // Now points on \0
    while (*dest++ = *source++);
    
    return result;
}

/**
 * Adds n symbols of source string to the end of the destination string
 * 
 * \param  char* dest
 * \param  char* source
 * \param  n Number of symbols to copy 
 * \return Pointer to the result string 
 */
char *strncat_ (char *dest, const char *source, int n)
{
    char *result = dest;
    
    dest += strlen (dest); // Now points on \0
    while ((*dest++ = *source++) && (dest - result < n));
    
    return result;
}

/**
 * Creates a duplicate of str, memory allocated with malloc
 * 
 * \param const char* str String to be duplicated
 * \return Pointer to the duplicate or NULL
 */
char *strdup_ (const char *str)
{
    assert (str != NULL);
    
    char *str_ptr = (char *) malloc (sizeof (str));

    if (str_ptr == NULL)
        return NULL;

    strcpy (str_ptr, str);

    return str_ptr;
}

/**
 * Reads first num chars from file. Stops if \\n or EOF found.
 * 
 * \param  str    String where chars would be put
 * \param  num    Amount of symbols to read
 * \param  source File to read symbols from
 * \return Pointer to the string
 */
char *fgets_ (char *str, int num, FILE *source)
{
    assert (str != NULL);
    assert (source != NULL);

    char *result = str;
    
    if (num < 1)
        return NULL;

    int count = num;

    while (--count)
    {
        char ch = fgetc (source);
        if (ch && ch != EOF)
        {    
            *str++ = ch;        
            if (ch == '\n') break;
        }
        else
        {
            if (count - num == 1) return NULL;
            if (ch == NULL) return NULL;
        }            
    }
    *str = '\0';
    
    return result;
}

int main (int argc, char *argv[])
{
    

    return 0;
}
