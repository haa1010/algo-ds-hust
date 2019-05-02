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

void merge(int *a, int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[i + p];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[i + q + 1];
    }
    int i = 0, j = 0;
    int k=p;
    while(i<n1 && j<n2)    
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void MS(int *a, int p, int r)
{
    if (p < r)
    {
        int q = p +(r-p)/ 2;
        MS(a, p, q);
        MS(a, q + 1, r);
        merge(a, p, q, r);
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
    MS(a, 0, length - 1);
    printf("\nAfter sorting : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}