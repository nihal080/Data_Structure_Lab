#include <stdio.h>
int main()
{
	int arr[50];
	int n,i,sum=0;
	printf("Enter The Number of Elements : ");
	scanf("%d",&n);
	if(n<=50)
	{
		printf("Enter the Elements Of Array\n");
		for(i=0;i<n;i++)
		{
			printf("Enter the  %d th  element : ",i);
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n;i++)
		{
			sum=sum+arr[i];
		}
		printf("sum of %d elements is : %d\n",n,sum);
	}
	else
	{
		printf("The Entered Size Is larger Than Array Size\n");
	}
	return 0;
}
