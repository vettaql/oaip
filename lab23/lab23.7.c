//Вариант 5: Все цифры заменить символом  ‘X’.  

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h>
#include <ctype.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

        FILE* input_file, * output_file;
        char ch;

        // Открытие файла для чтения
        input_file = fopen("c:\\Users\\eliza\\Desktop\\text7.txt", "r");
        if (input_file == NULL) {
            printf("Не удалось открыть файл text7.txt.\n");
            return 1;
        }

        // Открытие файла для записи
        output_file = fopen("c:\\Users\\eliza\\Desktop\\out7.txt", "w");
        if (output_file == NULL) {
            printf("Не удалось открыть файл out7.txt.\n");
            return 1;
        }

        // Чтение и обработка символов
        while ((ch = getc(input_file)) != EOF) {
            // Замена цифр символом 'X'
            if (ch >= '0' && ch <= '9') {
                ch = 'X';
            }

            // Запись измененного символа в выходной файл
            putc(ch, output_file);
        }

        // Закрытие файлов
        fclose(input_file);
        fclose(output_file);

        printf("Преобразование завершено.\n");

        return 0;
    }