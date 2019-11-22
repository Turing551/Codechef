#include <bits/stdc++.h>
using namespace std;
template<typename x1, unsigned long y1> struct ans;
struct X;
struct Y;
void count(unsigned int x1);
X solve(unsigned long y1);
void steps(unsigned long y1, Y x2, X& y2);
static unsigned long calculate(unsigned long n);
static unsigned long calculate(unsigned long n, const unsigned long(&a)[10000UL]);
static const ans<unsigned long, 10000UL>& square();
void solve(unsigned long y1, unsigned long sep, X& y2);
void temp(unsigned long y1, unsigned long sep, unsigned long ul, Y x2, X& y2);
void result(unsigned long y1, unsigned long sep, Y x2, X& y2);
void result(unsigned long y1, unsigned long sep, Y x2, X& y2, bool isExist, const array<unsigned long, 8>& a);
struct Euclid{
    static Euclid make(unsigned long a, unsigned long b){
        return Euclid(a / b, a % b);
    }
    Euclid(unsigned long q, unsigned long c) : q(q), c(c){}
    const unsigned long q;
    const unsigned long c;
};
struct X{
    X() : x(0), y{}, z(0){}
    X(unsigned long x, const array<unsigned long, 8>& y) : x(x), y(y), z(accumulate(y.cbegin(), y.cend(), 0ul)){}
    void set(unsigned long x, const array<unsigned long, 8>& y, unsigned long z){
        this->x = x;
        this->y = y;
        this->z = z;
        assert(this->z == accumulate(y.cbegin(), y.cend(), 0ul));
    }
    string str1() const{
        return string().append(x,'1');
    }
    string str2() const{
        static constexpr char charr[8] = { '2','3','4','5','6','7','8','9' };
        string str3;
        str3.append(y[0],charr[0]);
        str3.append(y[1],charr[1]);
        str3.append(y[2],charr[2]);
        str3.append(y[3],charr[3]);
        str3.append(y[4],charr[4]);
        str3.append(y[5],charr[5]);
        str3.append(y[6],charr[6]);
        str3.append(y[7],charr[7]);
        return str3;
    }
    bool isExist(){
        return x+z>0;
    }
    unsigned long x;
    array<unsigned long,8> y;
    unsigned long z;
};
struct Y{
    constexpr Y() : q{},z(0){}
    Y(const Y& x2) : q(x2.q), z(x2.z){}
    Y& set(unsigned long i, unsigned long k){
        assert(q[i]==0);
        q[i]=k;
        z=z+k;
        return *this;
    }
    Y& add(unsigned long i, unsigned long k){
        q[i]=q[i]+k;
        z=z+k;
        return *this;
    }
    Y& add(const array<unsigned long, 8>& a){
        q[0]=q[0]+a[0];
        q[1]=q[1]+a[1];
        q[2]=q[2]+a[2];
        q[3]=q[3]+a[3];
        q[4]=q[4]+a[4];
        q[5]=q[5]+a[5];
        q[6]=q[6]+a[6];
        q[7]=q[7]+a[7];
        z += a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7];
        return *this;
    }
    array<unsigned long, 8> q;
    unsigned long z;
};
bool operator<(const X& a, const X& b){
    return a.x > b.x || (a.x == b.x && a.y > b.y);
}
ostream& operator<<(ostream& os, const X& b){
    cout<<b.str1()<<b.str2()<< flush;
    return os;
}
struct answer{
    constexpr answer() : a{
        {true,{0,0,0,0,0,0,0,0}},{false,{0,0,0,0,0,0,0,0}},{false,{0,0,0,0,0,0,0,0}},{true ,{1,0,0,0,0,0,0,0}},
        {false,{0,0,0,0,0,0,0,0}},{false,{0,0,0,0,0,0,0,0}},{true,{2,0,0,0,0,0,0,0}},{false,{0,0,0,0,0,0,0,0}},
        {true,{0,1,0,0,0,0,0,0}},{true,{3,0,0,0,0,0,0,0}},{false,{0,0,0,0,0,0,0,0}},{true,{1,1,0,0,0,0,0,0}},
        {true,{4,0,0,0,0,0,0,0}},{false,{0,0,0,0,0,0,0,0}},{true,{2,1,0,0,0,0,0,0}},{true,{0,0,1,0,0,0,0,0}},
        {true,{0,2,0,0,0,0,0,0}},{true,{3,1,0,0,0,0,0,0}},{true,{1,0,1,0,0,0,0,0}},{true,{1,2,0,0,0,0,0,0}},
        {true,{4,1,0,0,0,0,0,0}},{true,{2,0,1,0,0,0,0,0}},{true,{2,2,0,0,0,0,0,0}},{true,{0,1,1,0,0,0,0,0}},
        {true,{0,0,0,1,0,0,0,0}},{true,{3,2,0,0,0,0,0,0}},{true,{1,1,1,0,0,0,0,0}},{true,{1,0,0,1,0,0,0,0}},
        {true,{4,2,0,0,0,0,0,0}},{true,{2,1,1,0,0,0,0,0}},{true,{0,0,2,0,0,0,0,0}},{true,{0,2,1,0,0,0,0,0}},
        {true,{0,1,0,1,0,0,0,0}},{true,{1,0,2,0,0,0,0,0}},{true,{1,2,1,0,0,0,0,0}},{true,{0,0,0,0,1,0,0,0}},
        {true,{2,0,2,0,0,0,0,0}},{true,{2,2,1,0,0,0,0,0}},{true,{1,0,0,0,1,0,0,0}},{true,{0,0,1,1,0,0,0,0}},
        {true,{0,2,0,1,0,0,0,0}},{true,{2,0,0,0,1,0,0,0}},{true,{1,0,1,1,0,0,0,0}},{true,{0,1,0,0,1,0,0,0}},
        {true,{3,0,0,0,1,0,0,0}},{true,{0,0,3,0,0,0,0,0}},{true,{1,1,0,0,1,0,0,0}},{true,{0,1,1,1,0,0,0,0}},
        {true,{0,0,0,0,0,1,0,0}},{true,{2,1,0,0,1,0,0,0}},{true,{0,0,1,0,1,0,0,0}},{true,{1,0,0,0,0,1,0,0}},
        {true,{3,1,0,0,1,0,0,0}},{true,{1,0,1,0,1,0,0,0}},{true,{2,0,0,0,0,1,0,0}},{true,{0,2,1,1,0,0,0,0}},
        {true,{0,1,0,0,0,1,0,0}},{true,{3,0,0,0,0,1,0,0}},{true,{0,1,1,0,1,0,0,0}},{true,{1,1,0,0,0,1,0,0}},
        {true,{0,0,4,0,0,0,0,0}},{true,{1,1,1,0,1,0,0,0}},{true,{1,0,0,1,1,0,0,0}},{true,{0,0,0,0,0,0,1,0}},
        {true,{0,2,0,0,0,1,0,0}},{true,{0,0,2,0,1,0,0,0}},{true,{1,0,0,0,0,0,1,0}},{true,{0,1,0,1,1,0,0,0}},
        {true,{1,0,2,0,1,0,0,0}},{true,{2,0,0,0,0,0,1,0}},{true,{0,0,0,0,2,0,0,0}},{true,{0,1,0,0,0,0,1,0}},
        {true,{0,0,0,1,0,1,0,0}},{true,{1,0,0,0,2,0,0,0}},{true,{1,1,0,0,0,0,1,0}},{true,{1,0,0,1,0,1,0,0}},
        {true,{2,0,0,0,2,0,0,0}},{true,{2,1,0,0,0,0,1,0}},{true,{0,0,1,0,0,0,1,0}},{true,{0,2,0,0,0,0,1,0}} 
        }
    {
    }
    unsigned long tot(const array<unsigned long, 8> & a) const{
        static constexpr unsigned long arr1[8] = { 3,8,15,24,35,48,63,80 };
        unsigned long c(0);
        for (unsigned long i=0;i<8;++i)
            c += a[i] * arr1[i];
        return c;
    }
    const tuple< bool, array<unsigned long,8>> a[80];
};
template<typename x1> x1 read(){
    x1 n;
    cin >> n;
    return n;
}
template<typename x1, unsigned long y1> struct ans{
    constexpr ans() : a(){
        for(unsigned long i=0;i<y1;++i)
            a[i] = (i+1)*(i+1);
    }
    x1 a[y1];
};
void temp(unsigned long y1, unsigned long sep, unsigned long ul, Y x2, X& y2){
    static constexpr unsigned long arr1[8] = { 3,8,15,24,35,48,63,80 };
    unsigned m(arr1[ul]);
    if(sep <= m * (y1 - x2.z)){
        if(!y2.isExist() || x2.z < y2.z){
            if(sep<80)
                result(y1,sep,x2,y2);
            else{
                Euclid euclid(Euclid::make(sep, m));
                if(ul>0){
                    unsigned int i = 0;
                    while(i <= euclid.q){
                        temp(y1, i * m + euclid.c, ul - 1, Y(x2).set(ul, euclid.q - i), y2);
                        ++i;
                    }
                }
                else{
                    if (euclid.c == 0)
                        steps(y1, Y(x2).set(ul, euclid.q), y2);
                }
            }
        }
    }
}
void count(unsigned int x1){
    for(unsigned int i=0;i<x1;++i)
        cout << solve(read<unsigned int>()) << endl;
}
X solve(unsigned long y1){
    unsigned long sol(calculate(y1-1));
    unsigned long sep(sol-y1);
    if(sep==0)
        return X(y1, array<unsigned long, 8>{});
    else{
        X y2;
        while(sep <= y1 * 80 && (!y2.isExist() || sep <= y2.z * 80)){
            solve(y1, sep, y2);
            sol = calculate(sol);
            sep = sol - y1;
        }
        return y2;
    }
}
void solve(unsigned long y1, unsigned long sep, X& y2){
    static constexpr Y x2;
    temp(y1, sep, 7, x2, y2);
}
void steps(unsigned long y1, Y x2, X& y2){
    if(x2.z <= y1)
        if(!y2.isExist() || x2.z < y2.z || (x2.z == y2.z && x2.q > y2.y))
            y2.set(y1 - x2.z, x2.q, x2.z);
}
void result(unsigned long y1, unsigned long sep, Y x2, X& y2, bool isExist, const array<unsigned long, 8>& a){
    if(isExist)
        steps(y1, Y(x2).add(a), y2);
}
void result(unsigned long y1, unsigned long sep, Y x2, X& y2){
    static constexpr answer finalSolution;
    result(y1, sep, x2, y2, get<0>(finalSolution.a[sep]), get<1>(finalSolution.a[sep]));
}
static unsigned long calculate(unsigned long n, const unsigned long(&a)[10000UL]){
    return *upper_bound(a, a + 10000UL, n);
}
static unsigned long calculate(unsigned long n){
    return calculate(n, square().a);
}
static const ans<unsigned long, 10000UL>& square(){
    static constexpr ans<unsigned long, 10000UL> str3;
    return str3;
}
int main(){
    count(read<unsigned int>());
    return 0;
}
