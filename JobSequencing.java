import java.util.*;
class JobSequencing
{
	public static void greedy(Job jobs[],int m,int n)
	{
		int i,fill,k,prof=0,p;
		int sol[]=new int[m+1];
		fill=0;
		for(i=1;i<=m;i++)
			sol[i]=-1;
		for(i=1;i<=n;i++)
		{
			if(m > jobs[i].deadline)
				k=jobs[i].deadline;
			else
				k=m;
			
			while(k>=1)
			{
				if(sol[k] == -1)
				{
					sol[k]=jobs[i].no;
					fill++;
					break;
				}
				k--;
			}
			if(fill==m)
				break;
		}	
		System.out.println("Sequence of jobs to be performed is ");
		for(i=1;i<=m;i++)
		{
			if(sol[i]!=-1)
				System.out.print(" Job "+sol[i]);
			if(i<m && sol[i]!=-1)
				System.out.print(" --> ");
		}
		
		System.out.println("\nProfit earned is ");
		for(i=1;i<=m;i++)
		{
			k=sol[i];
			for(p=1;p<=n;p++)
			{	
				if(k==jobs[p].no)
					prof=prof+jobs[p].profit;
			}
		}
		System.out.println(prof);

	}
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		Job j = new Job();
		int n, i, d , p , m;
		System.out.print("Enter number of Jobs: ");
		n = sc.nextInt();
		Job jobs[] = new Job[n+1];

		for (i=1; i<=n ; i++) 
		{
			System.out.println("Enter deadline and profit of the Job:");
			d = sc.nextInt();
			p = sc.nextInt();
			jobs[i] = new Job(i, d, p);
		}
		
		System.out.println("\nJob_no\tdeadline\tprofit");
		for (i=1; i<=n ; i++) 
			System.out.println(jobs[i].no+"\t"+jobs[i].deadline+"\t\t"+jobs[i].profit);
		
		j.mergeSort(jobs,1,n);
		
		System.out.println("\nJob_no\tdeadline\tprofit");
		for (i=1; i<=n ; i++) 
			System.out.println(jobs[i].no+"\t"+jobs[i].deadline+"\t\t"+jobs[i].profit);

		m=jobs[1].deadline;
		for(i=1;i<=n;i++)
		{
			if(m<jobs[i].deadline)
				m=jobs[i].deadline;
		}
		System.out.println("Maximum slots are "+m);
		greedy(jobs,m,n);
	}
}

class Job
{
	int no,deadline, profit;

	public Job()
	{}

	public Job(int n, int d,int p)
	{
		no = n;
		deadline = d;
		profit = p;
	}

	public Job(Job j)
	{
		no = j.no;
		deadline = j.deadline;
		profit = j.profit;
	}

	public void merge(Job arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
 
        Job L[] = new Job [n1];
        Job R[] = new Job [n2];
        for (int i=0; i<n1; ++i)
		{	
            L[i] = new Job(arr[l + i]);
		}
        for (int j=0; j<n2; ++j)
		{
            R[j] = new Job(arr[m + 1+ j]);
		}
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i].profit > R[j].profit)
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
	
    public void mergeSort(Job arr[], int l, int r)
    {
        if (l < r)
        {
            int m = (l+r)/2; 
            mergeSort(arr, l, m);
            mergeSort(arr , m+1, r);
            merge(arr, l, m, r);
        }
    }
	
}