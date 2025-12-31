#include <stdio.h>

void print_array(int arr[], int n)
{
    printf("Array elements: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void sort_array(int arr[],int n)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	print_array(arr,n);
}



void merge_array(int arr1[], int arr2[],int arr3[],int n1,int n2)
{
	int i;
	for(i=0;i<n1;i++)
	{
		arr3[i]=arr1[i];
	}
	for(int j=0;j<n2;j++)
	{
		arr3[i]=arr2[j];
		i++;
	}
}





int main()
{
	int arr1[10], arr2[10],arr3[20];
       	int n1,n2,i;

        printf("Enter The Number of Elements of array 1: ");
        scanf("%d",&n1);
	if(n1<=10)
	{
	        printf("Enter the Elements Of Array 1\n");
		for(i=0;i<n1;i++)
		{
	                printf("Enter the  %d th  element : ",i);
			scanf("%d",&arr1[i]);
		}
	}
	else
	{
		printf("Size of Array is Lesser Than 10");
	}

        printf("Enter The Number of Elements of array 2: ");
        scanf("%d",&n2);
        if(n2<=10)
	{
		printf("Enter the Elements Of Array 2\n");
		for(i=0;i<n2;i++)
	        {
	                printf("Enter the  %d th  element : ",i);
	                scanf("%d",&arr2[i]);
		}
	}
        else
        {
                printf("Size of Array is Lesser Than 10");
        }

	printf("Array 1:\n ");
	print_array(arr1, n1);
        printf("Sorted Array 1:\n ");
	sort_array(arr1,n1);

        printf("Array 2:\n ");
        print_array(arr2, n2);
        printf("Sorted Array 2:\n ");
	sort_array(arr2,n2);

	printf("Merged Array : \n");
	merge_array(arr1,arr2,arr3,n1,n2);
	sort_array(arr3,n1+n2);
	
	return 0;
}

