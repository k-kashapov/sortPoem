#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/// <summary>
/// ������������ ����� ������
/// </summary>
const int STR_BUFF_SIZE = 80;

/// <summary>
/// ������������ ���������� �����
/// </summary>
const int BUFF_SIZE = 5000;

//  ������� �������������� � �������� ���������� string.h � Visual Studio
#pragma warning(disable:4996)

/**
 * @brief Merge sort ��� �������� �����
 * 
 * \param  str   ������ ���������� �� ������
 * \param  left  ����� ������� ����������
 * \param  right ������ ������� ����������
 * \return       ��������� �� ��������������� ������
 */
char **merge_sort (char **str, int left, int right);

/**
 * @brief ������� ��� ������� ������� (�� left �� middle � �� middle �� right) ����� � ��������������� �������
 * 
 * \param  str    ������ �����
 * \param  left   ����� ������� ������� �������
 * \param  right  ������ ������� ������� �������
 * \return        ��������������� ������ �����
 */
char **merge (char **str, int left, int right);
