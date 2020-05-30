#include <stdio.h>
#include <stdlib.h>
int count[10000001]={0};
int max(long long int *arr,long long int *brr,long long int n,long long int m){
    int max = arr[0];
    for(long long int i=0;i<n;i++){
        if(arr[i] > max)
            max = arr[i];
    }
    for(long long int i=0;i<m;i++){
        if(brr[i] > max)
            max = brr[i];
    }
    return max;
}

int common(int maximum)
{
    int dem = 0;
    for(int i=0;i<maximum;i++){
		if(count[i] >1)
			dem++;
	}
	return dem;
}

int main()
{
    long long int n, m;
    scanf("%lld%lld", &n, &m);
    long long int * arr = (long long int *)malloc(n* sizeof(long long int));
	long long int * brr = (long long int *)malloc(m* sizeof(long long int));
    for ( long long int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        count[arr[i]]++;
    }
    for ( long long int j = 0; j < m; j++)
    {
        scanf("%lld", &brr[j]);
        count[brr[j]]++;
    }
    int maximum = max(arr,brr,n,m);
    printf("%d\n", common(maximum));
    free(arr);
}
