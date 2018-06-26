import java.util.*;

class NQueens{
	public static void main(String args[]){
		int n , column[];
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of queens:");
		n=sc.nextInt();
		column = new int[n+1];
		nqueen(1,n,column);
	}
	
	public static void nqueen(int r,int n,int column[]){
		int i,c;
		for(c=1 ; c<=n ; c++){
			if(place(r,c,column)){
				column[r]=c;
				
				if(r==n){
					for(i=1 ; i<=n ; i++){
						for(int l=1 ; l<=n ; l++){		
							if(l==column[i]){
								System.out.print("Q  ");
							}
							else{
								System.out.print("*  ");
							}
						}
						System.out.println();	
					}
					System.exit(0);
				}
				else
					nqueen(r+1,n,column);
			}
		}
	}
	
	public static boolean place(int r,int c,int column[]){
		int j;
		for(j=1; j<=r-1; j++ ){
			if((column[j]==c) || ((Math.abs(column[j]-c))==(Math.abs(j-r))))
				return false;
		}
		return true;
	}
}