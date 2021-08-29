#pragma once

#include "sort.h"

/**
 * \brief Структура, содержащая конфигурацию программы
 * 
 * \param input_file  Имя файла, откуда производится чтение
 * \param output_file Имя файла для записи
 * \param mode        Режим сортировки строк
 * \param reverse     bool Сортировать строки по их окончанию
 */
struct config
{
    const char *input_file = "source.txt";
    const char *output_file = "result.txt";
    int (*mode) (char*, char*) = *strncmp_reverse;
};

/**
 * \brief Структура, содержащая в себе полный текст файла и информацию о нём
 * 
 * \param text      Полный текст файла
 * \param str_ptrs  Массив указателей на строки в файле
 * \param lines_num Количество строк
 */
struct file_info
{
    char *text;
    char **strs;
    int  lines_num;
};

/**
 * \brief Читает все строки из файла
 * 
 * \param  info         Указатель в который будет записана информация о файле
 * \param  file_name    Имя файла, который будет прочитан
 * \return              Количество прочитанных строк
 */
int read_all_lines (file_info *info, const char *file_name);

/**
 * \brief Пробует открыть файл. В случае провала программа завершится
 */
void open_file_loop (FILE **ptr, const char* file_name, const char* mode);

/**
 * \brief Читает файл, помещает все символы в буфер
 * 
 * \param  source Файл, который нужно прочитать
 * \return        Указатель на буфер
 */
char* read_to_end (FILE *source);

/**
 * \brief Возвращает количество символов в файле
 * 
 * \param  file Указатель на файл
 * \return      Длина файла
 */
int get_len (FILE *file);

/**
 * \brief Записывает все строки из структуры source в файл output_file
 * 
 * \param source      Структура, откуда будут напечатаны строки
 * \param output_file Название файла, в который необходимо напечатать строки
 */
void show_res (file_info *source, const char * output_file);

/**
 * \brief Очищает строки, содержащиеся в структуре info
 * 
 * \param info Структура, память которой будет очищена
 */
void free_info (file_info *info);

/**
 * \brief Получает список аргументов программы. Аргументы задают имена входного и выходного файлов
 * 
 * \param argc    Количество аргументов программы
 * \param argv    Массив аргументов
 * \param current Структура, хранящая имена файлов
 */
void get_params (int argc, char **argv, config *current);
