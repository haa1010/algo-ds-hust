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

void bubbleSort(int *a, int length)
{
    int sorted = 0;
    for(int i = 1; i<=length-1;i++)
    {
        if(sorted==0)
        {
            sorted=1;
            for(int j = 0; j<=length-i-1; j++)
            {
                if(a[j]>=a[j+1])
                swap(&a[j],&a[j+1]);
                sorted=0;
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
    bubbleSort(a,length);
    printf("\nAfter sorting : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}