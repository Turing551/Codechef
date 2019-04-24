import java.io.*;
import java.util.*;

class PPATTERN {

    private static InputStream stream;
    private static byte[] buf = new byte[1024];
    private static int curChar;
    private static int numChars;
    private static SpaceCharFilter filter;
    static BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        InputReader(System.in);
        int t = nI();
        while (t-- > 0) {
            int n = nI();
            int current = 1, i = 0, k, l;
            int[][] a = new int[n][n];

            // upper half
            for (int j = 0; j < n; j++) {
                a[i][j] = current++;
                k = i + 1;
                l = j - 1;
                while (k < n && l >= 0) {
                    a[k][l] = current++;
                    k++;
                    l--;
                }
            }

            // lower half
            i = n - 1;
            current = n * n;
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = current--;
                k = i - 1;
                l = j + 1;
                while (k >= 0 && l <= n - 1) {
                    a[k][l] = current--;
                    k--;
                    l++;
                }
            }
            print(a);
        }
        log.flush();
    }

    public static void print(int[][] a) throws IOException {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                log.write(String.valueOf(a[i][j]) + " ");
            }
            log.write("\n");
        }
    }

    public static boolean isValid(long a, long b, long c) {
        if (a + b < c || a + c < b || b + c < a) {
            return false;
        }
        return true;
    }

    public static void InputReader(InputStream stream1) {
        stream = stream1;
    }

    private static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private static int read() {
        if (numChars == -1) {
            throw new InputMismatchException();
        }
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0) {
                return -1;
            }
        }
        return buf[curChar++];
    }

    private static int nI() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    private static boolean isSpaceChar(int c) {
        if (filter != null) {
            return filter.isSpaceChar(c);
        }
        return isWhitespace(c);
    }

    private interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}
