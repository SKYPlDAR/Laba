#include "base.h"

void read_t(t **tov, int *n, const char *fil_n) 
{
    FILE *file = fopen(fil_n, "r");
    if (!file) 
    {
        printf("Ошибка открытия файла\n");
        *n=-10;
        return;
    }
    *n = 0;
    while (!feof(file)) 
    {
        *tov = realloc(*tov, (*n + 1) * sizeof(t));
        if(*tov==NULL) *n=-10;
        if (fscanf(file, "%19s %f %19s %i", (*tov)[*n].name,&(*tov)[*n].price,(*tov)[*n].brend,&(*tov)[*n].kolvo) == 4) (*n)++;     
    }
    fclose(file);
    return;
}

void save_t(t *tov, int *n, const char *fil_n) 
{
    FILE *file = fopen(fil_n, "w");
    if (!file) 
    {
        printf("Ошибка открытия файла для записи\n");
        *n=-10;
        return;
    }
    for (int i = 0; i < *n; i++) fprintf(file, "%s %.2f %s %i\n", tov[i].name,tov[i].price,tov[i].brend,tov[i].kolvo);
    fclose(file);
}

void print_t(t *tov, int n) 
{
    if (n == 0) 
    {
        printf("Нет доступных товаров дл вывода\n");
        return;
    }
    printf("Список товаров:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%i: %s \t| Цена: %.2f \t| Бренд: %s \t| Количество: %i\n",i,tov[i].name,tov[i].price,tov[i].brend,tov[i].kolvo);
    }
}

void add_t(t **tov, int *n) 
{
    *tov = realloc(*tov, (*n + 1) * sizeof(t));
    if(*tov==NULL) *n=-10;
    printf("Введите название товара: ");
    scanf("%19s", (*tov)[*n].name);
    printf("Введите цену товара: ");
    scanf("%f", &(*tov)[*n].price);
    printf("Введите бренд товара: ");
    scanf("%19s", (*tov)[*n].brend);
    printf("Введите количество товара: ");
    scanf("%i", &(*tov)[*n].kolvo);
    (*n)++;
}

void del_t(t *tov, int *n) 
{
    int b;
    print_t(tov, *n);
    printf("Введите номер товара для удаления: ");
    scanf("%i", &b);
    if (b < 0 || b >= *n) 
    {
        printf("Неверный номер\n");
        return;
    }
    for (int i = b; i < *n; i++) 
    {
        tov[i] = tov[i + 1];
    }
    (*n)--;
}

void edit_t(t *tov, int n) 
{
    int b;
    print_t(tov, n);
    printf("Введите номер товара для редактирования: ");
    scanf("%i", &b);
    if (b < 0 || b >= n) 
    {
        printf("Неверный номер\n");
        return;
    }
    b;
    printf("Введите новое название товара: ");
    scanf("%19s", tov[b].name);
    printf("Введите новую цену товара: ");
    scanf("%f", &tov[b].price);
    printf("Введите новый бренд товара: ");
    scanf("%19s", tov[b].brend);   
    printf("Введите новое количество товара: ");
    scanf("%i", &tov[b].kolvo);
}

void poisk_t(t *tov, int n) 
{
    char name[20];
    char brend[20];
    printf("Введите название товара для поиска: ");
    scanf("%19s", name);
    printf("Введите бренд товара для поиска: ");
    scanf("%19s", brend);
    printf("Результаты поиска:\n");
    for (int i = 0; i < n; i++) 
    {
        if (strcmp(tov[i].name, name) == 0 && strcmp(tov[i].brend, brend) == 0) 
        {
            printf("%i: %s | Цена: %.2f | Количество: %i\n", i, tov[i].name,tov[i].price,tov[i].kolvo);
            return;
        }
    } 
    printf("Товар не найден\n");
}