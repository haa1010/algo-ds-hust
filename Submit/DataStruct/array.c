
#include<stdio.h>

typedef struct {
    int arr[100];
    int size;
}arr_integer;
int check(arr_integer statues, int i)
{
  for(int j = 1; j < statues.size; j++)
  {
    if(statues.arr[j]-statues.arr[i]==1)
        return 0;
    
  }
  return 1;
}
   
int makeArrayConsecutive2(arr_integer statues) 
{
    int max, min, i;
    if(statues.size==1)
        return 0;
    max=min=statues.arr[0];
    for(i=0;i<statues.size;i++)
    {
        if(min>statues.arr[i])
        {
            min = statues.arr[i];
            statues.arr[0]=statues.arr[i];
            statues.arr[i]=min;
        }
        if(max<statues.arr[i])
        {
            max = statues.arr[i];
            statues.arr[0]=statues.arr[i];
            statues.arr[i]=max;
        }
    }
    int ans=0;
    for(i=0;i<statues.arr[i];i++)
    {
       ans+=check(statues,i); 
    }
    return ans;
    
}

int main()
{
    int n;
    scanf("%d",&n);
    arr_integer statues[n];
    for(int i=0; i<n ; i++)
    {
        scanf("%d",&statues.arr[i]);
    }
    printf("---- %d \n", makeArrayConsecutive2 ( statues));
    return 0;
}

