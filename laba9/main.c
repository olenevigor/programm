#include <stdio.h>
#define MAXLINE 1024 
void main(void)
{
	FILE *fpin;   // входной файл  
	FILE *fpout;  // выходной файл  
	char line[MAXLINE]; // текущая строка  
	char *ptr;
	int i, n = 0, flag = 0, number = 0, string = 0, cnt = 0, max = 0;
	fopen_s(&fpin, "test.txt", "rt"); // открыть файл для чтения  
	if (fpin == NULL)
		return;    // ошибка при открытии файла 
	fopen_s(&fpout, "result.txt", "wt"); // открыть файл для записи  
	if (fpout == NULL)
		return;    // ошибка при открытии файла 
	while (!feof(fpin))// цикл до конца входного файла
	{
		ptr = fgets(line, MAXLINE, fpin); // чтение строки 
		if (ptr == NULL)
			break; // файл исчерпан 
		while (*ptr != '\0') // цикл до конца строки
		{
			for (i = 0; i < n; i++)
				(*ptr == line[i]) ? (flag = 1) : (0);
			((flag == 0) && (*ptr != '\n')) ? (cnt++) : (0);

			n++;
			flag = 0;
			ptr++; // продвигаем указатель по строке
		}
		if (cnt > max)
		{
			max = cnt;
			number = string;
		}
		n = 0;
		cnt = 0;
		string++;
	}
	fseek(fpin, 0, SEEK_SET);
	for (i = 0; i < string; i++)
	{
		ptr = fgets(line, MAXLINE, fpin); // чтение строки 
		if (ptr == NULL)
			break; // файл исчерпан 
		if (i == number)
			continue;
		else
			fputs(line, fpout); // запись строки
	}

	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл
}
