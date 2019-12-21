#include<iostream>
#include<limits.h>

using namespace std;

int div(long a, long b){
    // 递归第一步: 停止条件
    if(a<b)
        return 0;
    int count = 1;
    long tb    = b;
    while((tb+tb)<a){
        count = count + count;
        tb    = tb    + tb;
    }
    return count + div(a-tb, b);
}

int divide(int dividend, int divisor) {
    long a = dividend;
    long b = divisor;
    // a/b
    if(a==0)
        return 0;
    if(b==1)
        return a;
    if(b==-1){
        /* 
         * 如果 a =-2147483648
         * 则  -a = 2147483648
         *     -a > 2147483647
         */
        if(a<=INT_MIN)
            return INT_MAX;
        else
            return -a;
    }
    int sign_a = a<0?-1:1;
    int sign_b = b<0?-1:1;
    a = a<0?-a:a;
    b = b<0?-b:b;
    int ans = div(a,b);
    if((sign_a<0&&sign_b>0) ||(sign_a>0 && sign_b<0))
        return -ans;
    else
        return ans;
}

int main(int argc, char * argv[]){
    cout<<INT_MIN<<endl;
    cout<<INT_MAX<<endl;
    cout<<"11/3 = "<<divide(11,3)<<endl;
    cout<<"11/-3 = "<<divide(11,-3)<<endl;
    cout<<"11/-1 = "<<divide(11,-1)<<endl;
    cout<<"2147483647/2 = "<<divide(2147483647,2)<<endl;
    cout<<"-2147483648/2 = "<<divide(-2147483648,2)<<endl;
    return 0;
}
/*
 *
 *
 * 输入：
 * -2147483648
 * -1
 * 输出：
 * -2147483648
 * 预期：
 * 2147483647
 */
