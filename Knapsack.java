import java.util.*;
class Knapsack
{
	public static void greedy(Item items[],double m,int n)
	{
		int j,u;
		double x=0,prof=0;
		for(j=0;j<n;j++)
		{
			if(items[j].wt > m)
				break;
			x=1;
			m=m-items[j].wt;
			System.out.println(items[j].no+" ("+x+")");
			prof=prof+items[j].profit;
		}
		if(j<n)
		{
			x=m/items[j].wt;
			System.out.println(items[j].no+" ("+x+")");
			prof=prof+items[j].profit*x;
		}
		System.out.println("Profit earned is "+prof);
	}	
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		Item i = new Item();
		int n, j;
		double w , p , m;
		System.out.print("Enter number of items: ");
		n = sc.nextInt();
		Item items[] = new Item[n];

		for (j=0; j<n ; j++) 
		{
			System.out.println("Enter weight and profit of the item:");
			w = sc.nextDouble();
			p = sc.nextDouble();
			items[j] = new Item(j+1, w, p);
		}
		
		System.out.println("\nitem_no\tweight\tprofit\tp/w");
		for (j=0; j<n ; j++) 
			System.out.println(items[j].no+"\t"+items[j].wt+"\t"+items[j].profit+"\t"+items[j].p_by_w);
		
		i.mergeSort(items,0,n-1);
		
		System.out.println("\nitem_no\tweight\tprofit\tp/w");
		for (j=0; j<n ; j++) 
			System.out.println(items[j].no+"\t"+items[j].wt+"\t"+items[j].profit+"\t"+items[j].p_by_w);
		System.out.println("\nEnter maximum capacity of the sack:");
		m=sc.nextDouble();
		System.out.println("Items selected are :");
		greedy(items,m,n);
	}
}

class Item
{
	int no;
	double p_by_w, wt, profit;

	public Item()
	{}

	public Item(int n, double w, double p)
	{
		no = n;
		wt = w;
		profit = p;
		p_by_w = p/w;
	}

	public Item(Item i)
	{
		no = i.no;
		wt = i.wt;
		profit = i.profit;
		p_by_w = i.p_by_w;
	}

	public void merge(Item arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
 
        Item L[] = new Item [n1];
        Item R[] = new Item [n2];
        for (int i=0; i<n1; ++i)
		{	
            L[i] = new Item(arr[l + i]);
		}
        for (int j=0; j<n2; ++j)
		{
            R[j] = new Item(arr[m + 1+ j]);
		}
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i].p_by_w > R[j].p_by_w)
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
	
    public void mergeSort(Item arr[], int l, int r)
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