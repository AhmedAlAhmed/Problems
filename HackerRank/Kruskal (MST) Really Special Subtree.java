/*
	Rename the file to Main.java
	https://www.hackerrank.com/challenges/kruskalmstrsub/problem
	Just Apply MST
*/
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	private static Edge[] edges;
	private static int[] P,rnk;
	public static void main(String[] args) throws IOException  {
		
		new MST().solve();
	}
	
	static private int Int(String s) {
		return Integer.parseInt(s);
	}
	static private void init(int n) {
		P = new int [n+10];
		rnk = new int[n+10];
		
		for(int i=0;i<n+10;i++) {
			P[i] = i;
			rnk[i] = 0;
		}
	}
	static private int findp(int u) {
		if(P[u] != u) P[u] = findp(P[u]);
		return P[u];
	}
	static private int merge(int u, int v) {
		u = findp(u);
		v = findp(v);
		if(u == v) return 0;
		
		if(rnk[u] > rnk[v]) {
			rnk[u]++;
			P[v] = u;
		}else {
			rnk[v]++;
			P[u] = v;
		}
		
		return 1;
	}
	static private class MST {
		private void solve() throws IOException{
			
			DataInputStream in = new DataInputStream(new 
					BufferedInputStream(System.in));
			StringTokenizer tk;
			PrintWriter out = new PrintWriter(System.out);
			String s = in.readLine(); 
			tk = new StringTokenizer(s);
			int n = Int(tk.nextToken()), m = Int(tk.nextToken());
			edges = new Edge[m];
			for (int i = 0; i < m; i++) {
				s = in.readLine();
				tk = new StringTokenizer(s);
				int a = Int(tk.nextToken());
				int b = Int(tk.nextToken());
				int w = Int(tk.nextToken());
				edges[i] = new Edge(a,b,w);
			}
			Arrays.sort(edges);
			init(n);
			long sum = 0;
			int count = 0;
			for(int i=0;i<m;i++) {
				if(count == n-1) break;
				Edge e = edges[i];
				if (findp(e.u) != findp(e.v)) {
					sum += e.w;
					count += merge(e.u, e.v);
				}
			}
			out.println(sum);
			out.flush();
			in.close();
			out.close();
		}
	}
	
	static private class Edge implements Comparable<Edge>{
		public int u,v,w;
		public Edge() {
		}
		public Edge(int a, int b, int c) {
			this.u = a;
			this.v = b;
			this.w = c;
		}
		@Override
		public int compareTo(Edge arg0) {
			return this.w - arg0.w;
		}
		
	}

}


