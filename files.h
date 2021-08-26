#pragma once

#include "sort.h"

/**
 * @brief ������ ��� ������ �� �����
 * 
 * \param  num_of_lines ��������� �� ���������� �����
 * \param  file_name    ��� �����, ������� ����� ��������
 * \return              ���������� ����������� �����
 */
char** read_all_lines (int *num_of_lines, const char *file_name);

/**
 * @brief ������ ����, �������� ��� ������� � �����
 * 
 * \param  source ����, ������� ����� ���������
 * \return        ��������� �� �����
 */
char* read_to_end (FILE *source);

/**
 * @brief ���������� lines_num ����� ������� res � ���� result.txt
 * 
 * \param res       ������ �����
 * \param lines_num ���������� ����� ��� ������
 */
void show_res (char **res, int lines_num);
