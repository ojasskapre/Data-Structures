import java.util.*;

class Knapsack_dy{
	public static int dynamic(Item	items[], int m, int n){
		if(n == 0 || m == 0)
			return 0;

		if(items[n-1].wt > m)
			return dynamic(items,m,n-1);
		else
			return max((items[n-1].profit + dynamic(items ,(m-items[n-1].wt) ,n-1)) , dynamic(items,m,n-1));
	}
		
	public static int max(int a, int b){
		if(a>b)
			return a;
		else 
			return b;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Item i = new Item();
		int n, j, m, w , p;
		System.out.print("Enter number of items: ");
		n = sc.nextInt();
		Item items[] = new Item[n];

		for (j=0; j<n ; j++) 
		{
			System.out.println("Enter weight and profit of the item:");
			w = sc.nextInt();
			p = sc.nextInt();
			items[j] = new Item(j+1, w, p);
		}

		System.out.println("\nitem_no\tweight\tprofit");
		for (j=0; j<n ; j++) 
			System.out.println(items[j].no+"\t"+items[j].wt+"\t"+items[j].profit);	

		System.out.println("\nEnter maximum capacity of the sack:");
		m=sc.nextInt();
		int sol = dynamic(items,m,n);
		System.out.println("maximum profit for "+n+" items is "+sol);
	}
}

class Item
{
	int no, wt, profit;

	public Item()
	{}

	public Item(int n, int w, int p)
	{
		no = n;
		wt = w;
		profit = p;
	}

	public Item(Item i)
	{
		no = i.no;
		wt = i.wt;
		profit = i.profit;
	}
}