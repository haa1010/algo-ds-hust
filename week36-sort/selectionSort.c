#include <stdio.h>
int a[10000];
int length;
void loadData(char *filename)
{
    FILE *f = fopen(filename, "r");

    fscanf(f, "%d", &length);
    for (int i = 0; i < length; i++)
    {
        fscanf(f, "%d", &a[i]);
    }
    fclose(f);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *a, int length)
{
    int i, j, index_min;
    for (int i = 0; i < length - 1; i++)
    {
        index_min = i;
        for (j = i + 1; j < length; j++)
        {
            if (a[j] < a[index_min])
            {
                index_min = j;
                swap(&a[i], &a[index_min]);
            }
        }
    }
}

int main()
{
    loadData("merge_input");
    printf("Before sorting : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
    }
    selectionSort(a, length);
    printf("\nAfter sorting : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}