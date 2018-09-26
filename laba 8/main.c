#include <stdio.h>
#include <conio.h>

void main()
{
    char str[100];
    printf("Vvedite kolicestvo simvolov < 100\n");
    gets(str);
    char *ptr;                                      //Объявление указателеля для первого пробела
    char *ptr2;                                     //Объявление указателеля для второго пробела
    char *ptr3;
    char *ptr4;

    ptr = &str[0];
    ptr2 = &str[1];
    while (*ptr2!='\0')
    {
        if (*ptr == *ptr2 && *ptr == ' ')
        {
            ptr3=ptr;
            ptr4=ptr2;
                while ((*ptr3++ = *ptr4++) != '\0');         //Цикл перемещения всех символов стоящих после двойного пробела(удаление пробела)
            ptr--;
            ptr2--;
        }
        *ptr++;
        *ptr2++;
    }



printf("%s", str);                                      //вывод результата
_getch();
}
