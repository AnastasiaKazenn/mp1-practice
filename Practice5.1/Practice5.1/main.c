#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <memory.h>
#include <time.h>
#include "omp.h"
#include <locale.h>


void bubble_sort(struct _finddata_t* a, size_t size)
{
    int i, j;
    struct _finddata_t temp;
    for (i = 0; i < size; i++)
    {
        for (j = size - 1; j > i; j--)
        {
            if (a[j - 1].size > a[j].size)
            {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void select_sort(struct _finddata_t* a, int size)
{
    int i, j, k;
    struct _finddata_t temp;

    for (i = 0; i < size; i++)
    {
        k = i; temp = a[i];

        for (j = i + 1; j < size; j++)
            if (a[j].size < temp.size)
            {
                k = j; temp = a[j];
            }

        a[k] = a[i]; a[i] = temp;
    }
}


void quick_sort(struct _finddata_t* a, int N)
{
    int i = 0, j = N - 1;
    struct _finddata_t temp, q;

    q = a[N >> 1];
    do {
        while (a[i].size < q.size)
            i++;
        while (a[j].size > q.size)
            j--;

        if (i <= j)
        {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
        quick_sort(a, j);
    if (N > i)
        quick_sort(a + i, N - i);
}


void print_file(struct _finddata_t c_file)
{
    char buffer[30];
    ctime_s(buffer, _countof(buffer), &c_file.time_write);
    printf("%-30.30s   %.24s  %10lu\n", c_file.name, buffer, c_file.size);
}

void list_dir(int sort_method, char* path)
{
    char search[_MAX_PATH + 4 + 1];
    strcpy(search, sizeof(search), path);
    strcat(search, sizeof(search), "\\*.*");
    search[_MAX_PATH + 4] = '\0';

    intptr_t hFile;
    struct _finddata_t c_file;
    size_t count = 0, i = 0;

    do {
        count++;
    } while (_findnext(hFile, &c_file) == 0);
    _findclose(hFile);

    struct _finddata_t* arr = malloc(count * sizeof(struct _finddata_t));

    hFile = _findfirst(search, &c_file);
    for (i; i < count; i++)
    {
        _findnext(hFile, &c_file);
        arr[i] = c_file;
    }
    _findclose(hFile);

    double start_time = omp_get_wtime();

    switch (sort_method)
    {
    case 1:
        bubble_sort(arr, count);
        break;
    case 2:
        select_sort(arr, count);
        break;
    case 3:
        ShellSort(arr, count);
        break;
    default:
        printf("incorrect\n");
        free(arr);
        return;
    }

    double end_time = omp_get_wtime();

    for (size_t i = 0; i < count; i++)
    {
        print_file(arr[i]);
    }


    printf("sorting time: %lf сек.\n", end_time - start_time);
    textcolor(WHITE);
    free(arr);
}


void main()
{
    int last_selected_sort = -1, selected_sort;
    char last_path[_MAX_PATH + 1] = "#";
    char path[_MAX_PATH + 1];
    char c;

    printf("Enter path:\n");
    gets_s(path, sizeof(path)); //scanf("%s", s\path)
    //задает м аксимальное кол-во символов, которое может быть прочитано

    do
    {
        printf("\nWhich sorting do you want to select?:\n");
        if (last_selected_sort != -1)
        {
            printf(" 0 - ѕоследний выбранный алгоритм\n");
        }

        printf("0 - exit")
        printf(" 1 - bubble sort\n");
        printf(" 2 - selection sort\n");
        printf(" 3 - quick sort\n");
        scanf("%d", &selected_sort);

        if (selected_sort == 0)
        {
            return 0;
        }

        last_selected_sort = selected_sort;

        list_dir(last_selected_sort, last_path);
        getchar();
    } while (selected_sort != 0);
}
