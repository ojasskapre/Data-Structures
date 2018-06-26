import java.util.*;

class Selection
{
	public static void main(String args[])
	{
		int arr[], size, i, j, a, max, pos;
		long start, end;
		Random r = new Random();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter size");
		size = sc.nextInt();
		arr = new int[size];
		
		for (i=0; i<size; i++)
			arr[i] = r.nextInt(10000);
		
				
		start = System.currentTimeMillis();
		
		for(i=0; i<size-1; i++)
		{
			max = arr[0];
			pos = 0;
			for(j=1; j<size-i; j++)
				if(arr[j]>max)
				{
					max = arr[j];
					pos = j;
				}
			arr[pos] = arr[size-i-1];
			arr[size-1-i] = max;
		}
		
		end = System.currentTimeMillis();
		
		System.out.println("Time taken = " + (end-start) + "Milliseconds");
	}
}