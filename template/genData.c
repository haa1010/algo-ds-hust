void genData(char* filename, int n)
{
    FILE* fo = fopen( filename, "w");
    fprintf(fo,"%d\n",n);
    srand(time(NULL));
    for(int i = 1; i<=n ; i++)
    {
        int x = rand()%1000000;
        fprintf(fo,"%d ",x);
    }
    fclose(fo);
}

void loadData(char* filename)
{
    FILE* f =fopen(filename, "r");
    fscanf(f,"%d",&n);
    for(int i = 1; i<=n ; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    fclose(f);
}

int main()
{
    genData("in",1000) //file name is in with n=10
    loadData("in");
    //print.....
}
