import java.util.*;

class SumOfSubsets{
	static int m, w[], n, x[];
	public static void main(String[] args) {
		int i, r=0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter  number of elements:");
		n = sc.nextInt();
		w = new int[n];
		x = new int[n+1];
		System.out.println("Enter the elements:");
		for (i=0; i<n ; i++ )
			w[i] = sc.nextInt();
 		for (i=0; i<n; i++)
 			r = r + w[i];
 		System.out.println("Enter the total sum:");
 		m = sc.nextInt();
 		System.out.println("Subsets whose sum is "+m+" is as follows");
 		SumOfSub(0,0,r);
	}

	public static void SumOfSub(int s,int k,int r){
		int i;
		x[k] = 1;
		if(s+w[k] == m){
			System.out.println("\nElements of the set are");
			for(i=0;i<=k;i++)
				if(x[i] == 1)
					System.out.print(w[i]+" ");
				System.out.println();
			System.out.println("Elements included are");
			for (i=0; i<=n-1; i++)
				System.out.print(w[i]+"\t");
			System.out.println();
			for (i=0; i<=n-1; i++)
				System.out.print(x[i]+"\t");
		}
		else if((s+w[k]+w[k+1]) <= m)
			SumOfSub(s+w[k],k+1,r-w[k]);
		if((s+r-w[k]>=m)&&(s+w[k+1])<=m){
			x[k] = 0;
			SumOfSub(s,k+1,r-w[k]);
		}		
	}
}