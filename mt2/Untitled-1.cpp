#include<bits/stdc++.h>
using namespace std;
int max(int *arr,int *brr,int n,int m){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > max)
            max = arr[i];
    }
    for(int i=0;i<m;i++){
        if(brr[i] > max)
            max = brr[i];
    }
    return max;
}
int common(int * arr,int* brr,int n,int m){
	int dem =0;
	int maximum = max(arr,brr,n,m);
	int * count = (int *)malloc((maximum+1) * sizeof(int));
	for(int i=0;i<maximum;i++){
	    count[i] = 0;
	}
	for(int i=0;i<n;i++){
		count[arr[i]] ++; 
	}
	for(int j=0;j<m;j++){
		count[brr[j]] ++;
	}
	for(int i=0;i<maximum;i++){
		if(count[i] >1)
			dem++;
	}
	return dem;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int * arr = (int *)malloc(n* sizeof(int));
	int * brr = (int *)malloc(m* sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int j=0;j<m;j++){
		scanf("%d",&brr[j]);
	}
	
	printf("%d\n",common(arr,brr,n,m));
	free(arr);
}