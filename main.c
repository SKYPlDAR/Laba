#include "base.h"

int er;

int main() 
{

    printf("Добро пожаловать в магаз стройки ._.\n");
    t *tov = NULL;
    int n = 0;
    const char *fil_n = "0.txt";
    read_t(&tov, &n, fil_n);
    int a;
    do {
        if(n==-10) 
        {
            printf("Обнаружена ошибка. Программа будет завершена\n");
            break;
        }
        else
        {
            printf("\nМеню:\n1. Вывести товары на экран\n2. Добавить новый товар\n3. Удалить товар\n4. Редактировать товар\n5. Поиск товара\n6. Выход\n");
            scanf("%i", &a);
        }
        switch (a) {
            case 1:
                print_t(tov, n);
                break;
            case 2:
                add_t(&tov, &n);
                save_t(tov, &n, fil_n);
                break;
            case 3:
                del_t(tov, &n);
                save_t(tov, &n, fil_n);
                break;
            case 4:
                edit_t(tov, n);
                save_t(tov, &n, fil_n);
                break;
            case 5:
                poisk_t(tov, n);
                break;
            case 6:
                break;
            default:
                printf("Чет не так. Попробуйте снова.\n");
                break;
        }
        
    } while (a != 6);

    free(tov);
    return 0;
}