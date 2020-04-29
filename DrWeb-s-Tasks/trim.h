#pragma once

/**
	@file
	@brief Task for DrWeb's Junior C++ Developer (Windows, UNIX) position
	@author Selivanov Anatoliy
	@date 29 апреля 2020

	Junior C++ Developer (Windows, UNIX)
	Напишите функцию, которая обрезает пробелы в конце переданной ей строки. 
	Функция должна быть написана в расчёте на работу с очень длинными строками с очень большим количеством пробелов, 
	оптимизирована по количеству обращений к памяти. 
	Сигнатура: void TrimRight( char *s );
	P.S.
	Время выполнения теста неважно.
 */

/**
	@brief The function trims spaces in the end or received string
	@param s string to be trimmed
*/
void TrimRight(char *s);

void TestTrimRight();
