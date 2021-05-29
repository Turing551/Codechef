#include<bits/stdc++.h>
using namespace std;

int x,y,z;
string arr[3];

bool res(char ch) {
    if(arr[0][0]==ch && arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2])
        return 1;

    if(arr[0][2]==ch && arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0])
        return 1;

    for(int i=0;i<3;i++) {
        if(arr[i][0]==ch && arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2])
            return 1;
        if(arr[0][i]==ch && arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i])
            return 1;
    }

    return 0;
}
int validate() {
    if(x<y)
        return 3;
    if(x>y+1)
        return 3;
    bool x1 = res('X');
    bool y1 = res('O');
    if(x1 && y1)
        return 3;
    else if(x1 && x==y)
        return 3;
    else if(y1 && x>y)
        return 3;
    else if(x1 || y1)
        return 1;
    else if(z == 0)
        return 1;
    else
        return 2;
}

void temp() {
    x=y=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) {
            if(arr[i][j] == 'O')
                y++;
            if(arr[i][j] == 'X')
                x++;
        }
    z=9-x-y;
}

void solve() {
    for(int i=0;i<3;i++) 
        cin >> arr[i];
    temp();
    cout << validate() << endl;
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) 
        solve();
    return 0;
}
