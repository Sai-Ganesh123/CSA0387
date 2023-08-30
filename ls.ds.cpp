#include<stdio.h>
int search(int arr[], int N, int X)
{
	for(int i=0;i < N;i++)
	  if(arr[i]==X)
	    return i;
	return -1;
}
int main()
{
	int arr[]={1,2,3,4,5,6};
	int X=10;
	int N=sizeof(arr)/sizeof(arr[0]);
	int result=search(arr,N,X);
	(result==-1)
	   ?printf("search element is not present in array ")
	   :printf("search element is found at index %d",result);
	return 0;
}
