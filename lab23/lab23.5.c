#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

char filenameIn[] = "c:\\Users\\eliza\\Desktop\\text1.txt";
char filenameHTML[] = "c:\\Users\\eliza\\Desktop\\text1_out.html";

int main() {
    printf("BEGIN!!!\n");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // открыть файл текстовый (ВХОДНОЙ)
    FILE* fin = fopen(filenameIn, "rt");
    if (fin == NULL) {
        // если файл не смогли открыть - сообщаем об этом
        printf("File %s doesn't opened!\n", filenameIn);
        return 1;
    }
    // открыть HTML файл (выходной файл)  
    FILE* fout = fopen(filenameHTML, "wt");
    if (fout == NULL) {
        // закрываем ранее успешно открытый входной файл 
        fclose(fin);
        // если файл не смогли открыть - сообщаем об этом
        printf("File %s doesn't opened!\n", filenameHTML);
        return 1;
    }

    // Выводим в выходной файл заголовок HTML документа
    fprintf(fout, "<!DOCTYPE html>");
    fprintf(fout, "<html>");
    fprintf(fout, "<head>");
    fprintf(fout, "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />");
    fprintf(fout, "<title>HTML Document</title>");
    fprintf(fout, "</head>");
    fprintf(fout, "<body>");

    int ch;
    while ((ch = getc(fin)) != EOF) {
        // в HTML файл добавляем только что прочитанный 
        // символ "КАК ЕСТЬ"
        fprintf(fout, "%c", ch);

        // если в тексте был символ новой строки – 
        // в HTML добавляем тег <BR> - новая строка
        if (ch == '\n')
            fprintf(fout, "<br>");
    }

    // выводит в HTML завершающие теги документа HTML
    fprintf(fout, "</body>");
    fprintf(fout, "</html>");

    // Закрываем файл с текстом
    fclose(fin);
    // Закрываем HTML файл 
    fclose(fout);

    printf("END!!!\n");

    return 0;
}


