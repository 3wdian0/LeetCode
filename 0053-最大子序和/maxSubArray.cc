#include<iostream>
#include<vector>
#include<limits.h>

#define max(x,y) (x>y?x:y)

using namespace std;
class Solution {
public:
    /*
     * 输入: [-2,1,-3,4,-1,2,1,-5,4],
     *
     */
    int maxSubArray(vector<int> &nums){
        vector<int> dp;
        for(int i=0; i<=nums.size(); i++){
            dp.push_back(0);
        }
        int m = INT_MIN;
        for(int i=1; i<=nums.size(); i++){
            dp[i] = max(nums[i-1], dp[i-1]+nums[i-1]);
            //dp[i] = max(dp[i-1], dp[i-1]+nums[i-1]); //错误
            m = max(m,dp[i]);
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        return m;
    }
    int divideAndConquer(vector<int> &nums){
        return 0;
    }
};

int main(int argc, char *argv[]){
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    Solution *s = new Solution();
    cout<<s->maxSubArray(nums)<<endl;
    return 0;
}
