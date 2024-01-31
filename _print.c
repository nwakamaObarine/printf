#include "main.h"
/**
 * _printf - prints to standard output
 *@format: string tobe printed
 *Return: 0
*/
int _printf(const char *format, ...)
{
	int string_counter = 0;
	int str_len = 0;
	char *temi;
	char arine;
	va_list string_list;

	va_start(string_list, format);
	if (format == NULL)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			string_counter++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				string_counter++;
			}
			else if (*format == 'c')
			{
				arine = va_arg(string_list, int);
				write(1, &arine, 1);
				string_counter++;
			}
			else if (*format == 's')
			{
				temi = va_arg(string_list, char*);
				while (temi[str_len] != '\0')
				{
					str_len++;
				}
				write(1, temi, str_len);
				string_counter += str_len;
			}
		}
		format++;
	}
		va_end(string_list);
		return (string_counter);
	}
}
