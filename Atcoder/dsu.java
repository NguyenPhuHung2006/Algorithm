import java.io.*;
import java.util.*;

public class dsu {
    static FastScanner sc;
    static PrintWriter out;

    static final boolean hasMultipleTests = false;

    public static void main(String[] args) {
        sc = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        int t = 1;
        if (hasMultipleTests) t = sc.nextInt();
        while (t-- > 0) {
            solve();
        }

        out.flush();
    }

    static void print(Object... args) {
        for (Object x : args) out.print(x);
    }

    static void println(Object... args) {
        for (Object x : args) out.print(x);
        out.println();
    }

    static void p(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) out.print(" ");
            out.print(arr[i]);
        }
        out.println();
    }

    static void p(long[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) out.print(" ");
            out.print(arr[i]);
        }
        out.println();
    }

    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) {
            in = is;
        }

        private int readByte() {
            if (ptr >= len) {
                ptr = 0;
                try {
                    len = in.read(buffer);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        String next() {
            int c;
            while ((c = readByte()) != -1 && c <= ' ') ;
            StringBuilder sb = new StringBuilder();
            while (c != -1 && c > ' ') {
                sb.append((char) c);
                c = readByte();
            }
            return sb.toString();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

static class DSU 
{
    private int[] Parent, Size;

    public DSU(int n) 
	{
        Parent = new int[n];
        Size = new int[n];
        for (int i = 0; i < n; i++) Parent[i] = i;
        Arrays.fill(Size, 1);
    }

    public int find(int u) {
        if (Parent[u] != u) Parent[u] = find(Parent[u]);
        return Parent[u];
    }

    public void unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (Size[u] < Size[v]) {
            int tmp = u; u = v; v = tmp;  
        }
        Parent[v] = u;
        Size[u] += Size[v];
    }

    public boolean same(int u, int v) {
        return find(u) == find(v);
    }

    public int size(int u) {
        return Size[find(u)];
    }
}
		
	static DSU dsu;

    static void solve() 
	{
		int N, Q;
		N = sc.nextInt();
		Q = sc.nextInt();
		dsu = new DSU(N);
		while(Q-- > 0)
		{
			int q, u, v;
			q = sc.nextInt();
			u = sc.nextInt();
			v = sc.nextInt();
			if(q == 0)
				dsu.unite(u, v);
			else
				println((dsu.same(u, v)) ? 1 : 0);
		}
    }
}

