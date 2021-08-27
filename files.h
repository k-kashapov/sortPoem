#pragma once

#include "sort.h"

/**
 * @brief Структура, содержащая в себе полный текст файла и информацию о нём
 * 
 * \param text      Полный текст файла
 * \param str_ptrs  Массив указателей на строки в файле
 * \param lines_num Количество строк
 */
struct file_info 
{
    char *text;
    char **str_ptrs;
    int  lines_num;
};

/**
 * @brief Читает все строки из файла
 * 
 * \param  info         Указатель в который будет записана информация о файле
 * \param  file_name    Имя файла, который будет прочитан
 * \return              Количество прочитанных строк
 */
int read_all_lines (file_info *info, const char *file_name);

/**
 * \brief Пробует открыть файл. В случае провала предлагает попробовать снова
 */
void open_file_loop (FILE **ptr, const char* file_name, const char* mode);

/**
 * @brief Читает файл, помещает все символы в буфер
 * 
 * \param  source Файл, который нужно прочитать
 * \return        Указатель на буфер
 */
char* read_to_end (FILE *source);

/**
 * @brief Записывает все строки из структуры source в файл output_file
 * 
 * \param source      Структура, откуда будут напечатаны строки
 * \param output_file Название файла, в который необходимо напечатать строки
 */
void show_res (file_info *source, char* output_file);

/**
 * @brief      Очищает строки, содержащиеся в структуре info
 * \param info Структура, память которой будет очищена
 */
void free_info (file_info *info);
