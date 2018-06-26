import java.io.*;
import java.util.*;
class Sort
{
    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
 
        int L[] = new int [n1];
        int R[] = new int [n2];
        for (int i=0; i<n1; ++i)
		{	
            L[i] = arr[l + i];
		}
        for (int j=0; j<n2; ++j)
		{
            R[j] = arr[m + 1+ j];
		}
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
 
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
	
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = (l+r)/2; 
            mergeSort(arr, l, m);
            mergeSort(arr , m+1, r);
            merge(arr, l, m, r);
        }
    }
	
	void quick(int arr[],int lb,int ub)
	{
		int j;
		if(lb<ub)
		{
			j=partition(arr,lb,ub);
			quick(arr,lb,j-1);
			quick(arr,j+1,ub);
		}
	}
	
	int partition(int arr[],int lb,int ub)
	{
		int a,down,up,temp;
		a=arr[lb];
		up=ub;
		down=lb;
		while(down<up)
		{
			while(arr[down]<=a&&down<ub)
				down++;
			while(arr[up]>a)
				up--;
			if(down<up)
			{
				temp=arr[down];
				arr[down]=arr[up];
				arr[up]=temp;
			}
		}
		arr[lb]=arr[up];
		arr[up]=a;
		return up;
	}
    /*.......
	static void print(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
	.......*/
    public static void main(String args[])
        {
		System.out.println("Enter no. of elements");
		Scanner sc=new Scanner(System.in);
		Random r=new Random(100000);
		long start1,start2,end1,end2;
		int n=sc.nextInt();
		int arr[]=new int[n];
		int arr2[]=new int[n];
		
		for(int i=0;i < n;i++)
		{
			arr[i]=r.nextInt();	
			arr2[i]=arr[i];
		}
        Sort s = new Sort();
		
		start1=System.currentTimeMillis();
        s.mergeSort(arr, 0, arr.length-1);	
		end1=System.currentTimeMillis();

		System.out.println("Time for merge sort in milli seconds :"+(end1-start1));
		//print(arr);

		start2=System.currentTimeMillis();		
		s.quick(arr2,0,n-1);
		end2=System.currentTimeMillis();
		System.out.println("Time for quick sort in milli seconds :"+(end2-start2));
		//print(arr2);
	}
}