
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * @author ahmed
 */
public class HelpAshu {

    /**
     * @param args the command line arguments
     */
    static final int MAX = 500009;

    static int N, Q;
    static int[] Arr;
    static int[] tree;

    static void Build(int node, int s, int e) {
        if (s == e) {
            tree[node] = Arr[s];
        } else {
            int md = (s + e) >> 1;
            Build(2 * node + 1, s, md);
            Build(2 * node + 2, md + 1, e);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    static void update(int node, int s, int e, int indx, int val) {
        if (s == e) {
            tree[node] = val;
            Arr[indx] = val;

        } else {
            int md = (s + e) >> 1;
            if (indx >= s && indx <= md) {
                update(2 * node + 1, s, md, indx, val);
            } else {
                update(2 * node + 2, md + 1, e, indx, val);
            }

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    static int query(int node, int s, int e, int l, int r) {
        if (l > e || r < s) {
            return 0;
        }

        if (s >= l && e <= r) {
            return tree[node];
        }

        int md = (s + e) >> 1;

        int p1 = query(2 * node + 1, s, md, l, r);
        int p2 = query(2 * node + 2, md + 1, e, l, r);

        return p1 + p2;

    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk;
        Arr = new int[MAX];
        tree = new int[4 * MAX + 10];

        tk = new StringTokenizer(in.readLine());
        N = Integer.parseInt(tk.nextToken());
        tk = new StringTokenizer(in.readLine());
        for (int i = 0; i < N; i++) {
            Arr[i] = Integer.parseInt(tk.nextToken()) % 2 == 0 ? 1 : 0;
        }

        Build(0, 0, N - 1);
        tk = new StringTokenizer(in.readLine());
        Q = Integer.parseInt(tk.nextToken());
        int C, X, Y;
        while (Q-- > 0) {
            tk = new StringTokenizer(in.readLine());
            C = Integer.parseInt(tk.nextToken());
            X = Integer.parseInt(tk.nextToken());
            Y = Integer.parseInt(tk.nextToken());

            switch (C) {
                case 0:
                    // Update
                    X--;
                    int k = (Y % 2 == 0) ? 1 : 0;
                    update(0, 0, N - 1, X, k);
                    break;
                case 1:
                    // num of even .
                    X--;
                    Y--;
                    System.out.println(query(0, 0, N - 1, X, Y));
                    break;
                default:

                    if (X == Y) {
                        X--;
                        Y--;
                        System.out.println(query(0, 0, N - 1, X, Y));
                    } else {
                        int r = (Y - X + 1);
                        X--;
                        Y--;
                        System.out.println(r - query(0, 0, N - 1, X, Y));
                    }

                    // num of odd .
                    break;
            }

        }

    }

}

