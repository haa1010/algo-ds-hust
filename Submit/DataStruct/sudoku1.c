#include <stdio.h>
int arr[9][9];
int r[9][10], c[9][10], d[3][3][10];
int found = 0;
void init()
{
    for (int v = 1; v <= 9; v++)
    {
        for (int j = 0; j < 9; j++)
        {
            r[j][v] = c[j][v] = 0;
        }

        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                d[k][j][v] = 0;
    }
}
int check(int v, int i, int j)
{
    return r[i][v] == 0 && c[j][v] == 0 && d[i / 3][j / 3][v] == 0;
}
void solution()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void sudoku(int i, int j)
{

    int v;
    if (found == 3)
        return;
    for (v = 1; v <= 9; v++)
    {
        if (check(v, i, j))
        {
            arr[i][j] = v;
            //mark appearance
            r[i][v] = 1;
            c[j][v] = 1;
            d[i / 3][j / 3][v] = 1;
            if (j == 8 && i == 8)
            {
                solution();
                found++;
            }
            else
            {
                if (j == 8)
                    sudoku(i + 1, 0);
                else
                    sudoku(i, j + 1);
            }
            //recover
            r[i][v] = 0;
            c[j][v] = 0;
            d[i / 3][j / 3][v] = 0;
        }
    }
}

int main()
{
    init();
    sudoku(0,0);
    return 0;
}