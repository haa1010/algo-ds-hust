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

void insertionSort(int *a, int length)
{
    int k, pos, temp;
    for (k = 1; k < length; k++)
    {
        temp = a[k];
        pos = k;
        while ((pos > 0) && (a[pos - 1] > temp))
        {
            a[pos] = a[pos - 1];
            pos = pos - 1;
        }
        a[pos] = temp;
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
    insertionSort(a,length);
    printf("\nAfter sorting : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}