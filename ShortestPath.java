import java.util.*;

class ShortestPath{
	public static void path(int cost[][] , int dist[], int edge[][], int e, int n ){
		 for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=e; j++)
            {
                int u = edge[j][1];
                int v = edge[j][2];
                int weight = cost[u][v];
                if (dist[u]!=Integer.MAX_VALUE &&
                    dist[u]+weight<dist[v])
                    dist[v]=dist[u]+weight;
            }
        }
		for (int i=1; i<=n; i++){
			System.out.println("Distance from source:");
			System.out.println(i+"\t"+dist[i]);
		}
    }


	public static void main(String[] args) {
		int i, n, source, j, cost[][], edge[][], dist[], ch, k=1;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of vertices: ");
		n = sc.nextInt();
		cost = new int[n+1][n+1];
		dist = new int[n+1];
		edge = new int[n*n-n][3];
		System.out.println("NOTE: Enter 1  you want to connect two vertices else enter 0 ");
		for(i=1;i<=n;i++){
		 	for(j=1;j<=n;j++){
		 		System.out.println("Do you want to connect "+j+" to vertex "+i);
		 		ch = sc.nextInt();
		 		if(ch==1){
		 			System.out.println("Enter cost from vertex "+i+" to vertex "+j);
		 			cost[i][j] = sc.nextInt();
					edge[k][1] = i;
					edge[k++][2] = j;
		 		}
		 	}
		}

		for (i=1;i<=n ;i++ ){
			for (j=1 ;j<=n ;j++ ){
				System.out.print(cost[i][j]+"\t");
			}
			System.out.println();
		}

		System.out.println("Enter source vertex :");
		source = sc.nextInt();
		for(i=1 ;i<=n ;i++)
			dist[i] = Integer.MAX_VALUE;
		dist[source] = 0;
		path(cost,dist,edge,k,n);
	}
}