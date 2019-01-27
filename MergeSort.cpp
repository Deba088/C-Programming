// Merge-Sort in C programming


#include<stdio.h>
#include<stdlib.h>

void mergeSort(int arr[],int p,int r);
void merge(int arr[],int p,int q,int r);

void mergeSort(int arr[],int p,int r)
{
	if(p<r)
	{
		int q = (p+r-1)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void merge(int arr[],int p,int q,int r)
{
	int n1=q-p+1,n2=r-q;
	int L[n1],R[n2];
	int i,j,k;
	
	for(i=0;i<n1;i++)
		L[i]=arr[p+i];
	for(j=0;j<n2;j++)
		R[j]=arr[q+j+1];
	
	i=0;
	j=0;
	k=p;
	
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			i++;		
		}
		else
		{
			arr[k]=L[j];
			j++;	
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
	
}

int main()
{
	int arr[]={3,5,7,2,9,6,8,12,4,24,76,47};
	int p=0,r=sizeof(arr)/sizeof(arr[0]);
	int n=r;
	mergeSort(arr,p,r-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
