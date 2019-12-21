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
        int m = 0;
        for(int i=1; i<=nums.size(); i++){
            dp[i] = max(nums[i-1], dp[i-1]+nums[i-1]);
            //dp[i] = max(dp[i-1], dp[i-1]+nums[i-1]); //错误
            m = max(m,dp[i]);
            //cout<<dp[i]<<" ";
        }
        cout<<endl;
        return m;
    }
    int maxProfit(vector<int> &prices){
        vector<int> nums;
        for(int i=1;i<prices.size(); i++){
            nums.push_back(prices[i]-prices[i-1]);
        }
        return maxSubArray(nums);
    }
};

int main(int argc, char *argv[]){
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(4);
    Solution *s = new Solution();
    cout<<s->maxProfit(nums)<<endl;
    nums.clear();
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(1);
    cout<<s->maxProfit(nums)<<endl;
    return 0;
}
