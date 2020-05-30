#include <stdio.h>
#define max 1000001
int a[max];
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

int partition(int *a, int low, int high)
{
    int pivot = a[high];
    int i = low-1, j;
    for(j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

void quickSort(int *a, int low, int high)
{
    if(low<high)
    {
        int p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
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
    quickSort(a,0, length-1);
    printf("\nAfter sorting : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}