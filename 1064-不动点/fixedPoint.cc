#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

#define min(x,y) ((x<y)?x:y)

/*
 * 给定已经按升序排列、由不同整数组成的数组 A，返回满足 A[i] == i 的最小索引 i。如果不存在这样的 i，返回 -1。
 *
 *  
 *
 * 示例 1：
 * 输入：[-10,-5,0,3,7]
 * 输出：3
 * 解释：
 * 对于给定的数组，A[0] = -10，A[1] = -5，A[2] = 0，A[3] = 3，因此输出为 3 。
 *
 * 示例 2：
 * 输入：[0,2,5,8,17]
 * 输出：0
 * 示例：
 * A[0] = 0，因此输出为 0 。
 *
 * 示例 3：
 * 输入：[-10,-5,3,4,7,9]
 * 输出：-1
 * 解释： 
 * 不存在这样的 i 满足 A[i] = i，因此输出为 -1 。
 *  
 */
class Solution {
    public:
         int fixedPoint(vector<int>& A) {
            // 返回数组内的最小不动索引
            if(A.size()==0)
                return -1;
            int left = 0;
            int right= A.size()-1;
            int mid;
            int m = INT_MAX;
            while(left<=right){
                mid = (left+right)/2;
                if(A[mid]==mid){
                    right = mid - 1;
                    m = min(m,mid);
                }else if(A[mid]>mid){
                    right = mid - 1;
                }else{
                    left = mid+1;
                }
            }
            return m!=INT_MAX?m:-1;
        }
       int fixedPoint2(vector<int>& A) {
            // 返回数组内的最小不动索引
            if(A.size()==0)
                return -1;
            int left = 0;
            int right= A.size()-1;
            int mid;
            while(left<=right){
                mid = (left+right)/2;
                if(A[mid]==mid){
                    return mid;
                }else if(A[mid]>mid){
                    right = mid - 1;
                }else{
                    left = mid+1;
                }
            }
            return -1;
        }
};

void _print(vector<int> &A){
    for(int i=0; i<A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char *argv[]){

    Solution * s = new Solution();

    vector<int> A;

    A.push_back(-10);A.push_back(-5);A.push_back(0);A.push_back(3);A.push_back(7);A.push_back(9);_print(A);cout<<s->fixedPoint(A)<<" "<<s->fixedPoint2(A)<<endl;

    A.clear();A.push_back(0);A.push_back(2);A.push_back(5);A.push_back(8);A.push_back(17);_print(A);cout<<s->fixedPoint(A)<<" "<<s->fixedPoint2(A)<<endl;
    A.clear();A.push_back(-10);A.push_back(-5);A.push_back(3);A.push_back(4);A.push_back(7);A.push_back(9);_print(A);cout<<s->fixedPoint(A)<<" "<<s->fixedPoint2(A)<<endl;
    A.clear();A.push_back(0);A.push_back(1);A.push_back(2);A.push_back(4);A.push_back(5);A.push_back(6);_print(A);cout<<s->fixedPoint(A)<<" "<<s->fixedPoint2(A)<<endl;

    return 0;
}
