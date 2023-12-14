#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 40

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[], int maxLen);

char filename[] = "c:\\Users\\eliza\\Desktop\\text1.txt";

int main() {
    printf("BEGIN!!!\n");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // открываем файл с текстом
    FILE* fin = fopen(filename, "rt");
    if (fin == NULL) {
        // если файл не смогли открыть - сообщаем об этом
        printf("File %s doesn't opened!\n", filename);
        return 1;
    }
    char token[MAX_LEN];

    // пока не конец файла
    while (!feof(fin)) {
        // пока есть разделитель - берем его
        while (getNextDelim(fin, token)) {
            // выводим разделитель в консоль
            printf("<DELIM>%s</DELIM>\n", token);
        }
        // если есть слово - берем его
        if (getNextWord(fin, token, MAX_LEN)) {
            // выводим слово в консоль
            printf("<WORD>%s</WORD>\n", token);
        }
    }

    // Закрываем файл с текстом
    fclose(fin);
    printf("END!!!\n");

    return 0;
}

int isalpha_my(unsigned char ch);

int getNextDelim(FILE* fp, char token[])
{
    int ch = getc(fp);
    if (ch == EOF) {
        return 0;
    }
    if (isalpha_my((unsigned char)ch)) {
        ungetc(ch, fp);
        return 0;
    }
    token[0] = (unsigned char)ch;
    token[1] = '\0';
    return 1;
}

int getNextWord(FILE* fp, char token[], int maxLen)
{
    int i = 0;
    int ch;
    while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
        if (!isalpha_my((unsigned char)(ch))) {
            break;
        }
        token[i++] = ch;
    }
    ungetc(ch, fp);
    token[i] = '\0';
    if (i == 0)
        return 0;
    return 1;
}

int isalpha_my(unsigned char ch) {
    if (isalpha(ch))
        return 1;

    // ANSI кодировка!!!
    if (ch >= 192 && ch <= 223)
        return 1;
    if (ch >= 224 && ch <= 255)
        return 1;

    return 0;
}
