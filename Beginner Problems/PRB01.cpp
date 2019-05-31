#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define ll long long

#define MIN(a, b) a < b ? a : b

using namespace std;

int is_prime(int n) {
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    char ans[2][8] = {"no", "yes"};
    while( t-- ) {
        int n;
        scanf("%d", &n);
        printf("%s\n", ans[is_prime(n)]);
    }
    return 0;
}
