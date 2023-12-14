#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE* input_file, * output_file;
    char line[100];

    // Открытие файла для чтения
    input_file = fopen("c:\\Users\\eliza\\Desktop\\text6.txt", "r");
    if (input_file == NULL) {
        printf("Не удалось открыть файл text6.txt.\n");
        return 1;
    }

    // Открытие файла для записи
    output_file = fopen("c:\\Users\\eliza\\Desktop\\out6.txt", "w");
    if (output_file == NULL) {
        printf("Не удалось открыть файл out6.txt.\n");
        return 1;
    }

    // Чтение и обработка строк
    while (fgets(line, sizeof(line), input_file) != NULL) {
        int count = 0; // счетчик символа ";"

        // Подсчет количества символов ";"
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ';') {
                count++;
            }
        }

        // Запись измененной строки в выходной файл
        fprintf(output_file, "%s %d\n", line, count);
    }

    // Закрытие файлов
    fclose(input_file);
    fclose(output_file);

    printf("Преобразование завершено.\n");

    return 0;
}