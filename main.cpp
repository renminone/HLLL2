//В новом файле в  строках перед первым словом указать его длину.

#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAXL 100

int main()
{
	setlocale(LC_ALL, "Rus");
	FILE* fpin;
	FILE* fpout;

	fopen_s(&fpin, "test.txt", "rt");
	if (fpin == NULL)
		return; // ошибка при открытии файла

	fopen_s(&fpout, "result.txt", "rt");
	if (fpin == NULL)
		return; // ошибка при открытии файла

	int i = 0;
	int c = 0;
	char line[MAXL];
	char* ptr;

	while (!feof(fpin))
	{
		ptr = fgets(line, MAXL, fpin);
		if (ptr == NULL)
			break; // файл исчерпан

		while (*ptr != '\0')
		{
			if ((*ptr != ' ') && (*ptr != '.') && (*ptr != ','))
				c++;
			else
				break;
			*ptr++;
		}
		fprintf(fpout, "%d ", c);
		fputs(line, fpout);
	}
	fclose(fpin);
	fclose(fpout);
	return 0;
}
