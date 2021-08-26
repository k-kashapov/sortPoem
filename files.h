#pragma once

#include "sort.h"

/**
 * @brief Читает все строки из файла
 * 
 * \param  num_of_lines Указатель на количество линий
 * \param  file_name    Имя файла, который будет прочитан
 * \return              Количество прочитанных строк
 */
char** read_all_lines (int *num_of_lines, const char *file_name);

/**
 * @brief Читает файл, помещает все символы в буфер
 * 
 * \param  source Файл, который нужно прочитать
 * \return        Указатель на буфер
 */
char* read_to_end (FILE *source);

/**
 * @brief Записывает lines_num строк массива res в файл result.txt
 * 
 * \param res       Массив строк
 * \param lines_num Количество строк для записи
 */
void show_res (char **res, int lines_num);
