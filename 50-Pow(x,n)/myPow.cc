#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double mul(double x, int n){
        if(n==1)
            return x;
        int m = 1;
        double tx = x;
        while((m+m)<n){
            m = m+m;
            tx = tx*tx;
        }
        return tx*mul(x,n-m);
    }
    double myPow(double x,int n){
        if(n==0)
            return 1.0;
        if(x==0.0)
            return 0.0;
        if(n>0)
            return mul(x,n);
        else
            return 1/mul(x,-n);
    }
};

int main(int argc, char *argv[]){
    double x=2.0;
    int    n=10;
    Solution * s = new Solution();
              cout<<s->myPow(x,n)<<endl;
    x=2.1;n=3;cout<<s->myPow(x,n)<<endl;
    x=2.0;n=-2;cout<<s->myPow(x,n)<<endl;
    x=0;n=-2;cout<<s->myPow(x,n)<<endl;
    x=2.0;n=0;cout<<s->myPow(x,n)<<endl;
    return 0;
}
