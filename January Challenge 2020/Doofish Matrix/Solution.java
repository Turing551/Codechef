import java.io.*;
import java.util.*;
class Solution {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        Solution s = new Solution();
        s.calculate();
        s.close();
    }
    void close() throws IOException {
        pw.flush();
        pw.close();
        br.close();
    }
    void calculate() throws IOException {
        int n = Integer.parseInt(br.readLine());
        for (int p = 0; p < n; p++) {
            int x = Integer.parseInt(br.readLine());
            if (x == 1) {
                pw.println("Hooray");
                pw.println("1");
            } else if (x % 2 == 1) {
                pw.println("Boo");
            } else {
                int[][][] arr1 = new int[x - 1][x / 2][];
                for (int i = 0; i <= x - 2; i++) {
                    arr1[i][0] = new int[]{x - 1, i};
                    for (int k = 1; k <= x / 2 - 1; k++) {
                        arr1[i][k] = new int[]{(i + k) % (x - 1), (i - k + x - 1) % (x - 1)};
                    }
                }
                int[][] arr2 = new int[x][x];
                for (int i = 0; i < x; i++) arr2[i][i] = 1;
                for (int i = 0; i < arr1.length; i++) {
                    for (int[] vi : arr1[i]) {
                        arr2[vi[0]][vi[1]] = 2+i;
                        arr2[vi[1]][vi[0]] = x+1+i;
                    }
                }
                pw.println("Hooray");
                for (int[] a : arr2) {
                    for (int b : a) {
                        pw.print(b + " ");
                    }
                    pw.println();
                }
            }
        }
    }
}
