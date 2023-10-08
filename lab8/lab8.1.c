
#include <stdio.h>
#include <Windows.h>

void aboutMe() {
    printf("Бочкарёва\n");
    printf("Елизавета\n");
    printf("Павловна\n");
    printf("\n");
    printf("Группа: ПИбд-14-2023\n");
    printf("Дата:13.09.2023\n");
    printf("Предмет: Основы программирования\n");
    printf("Лабораторная работа №8\n");
}
void main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    aboutMe();

    
}
