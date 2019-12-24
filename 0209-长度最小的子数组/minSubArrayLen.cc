#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int m = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int sum = nums[i];
            int left=i;
            int right=i;
            while(sum < s && (left-1>=0 || right+1<nums.size())){
                if(left-1>=0){
                    left--;
                    sum += nums[left];
                    if(sum>=s){
                        m = min(m, right-left+1);
                        break;
                    }
                }
                if(right+1<nums.size()){
                    right++;
                    sum += nums[right];
                    if(sum>=s){
                        m = min(m, right-left+1);
                        break;
                    }
                }
            }
            if(sum>=s)
                m = min(m,right-left+1);
        }

        return m==INT_MAX?0:m;
    }
};
int main(int argc, char* argv[]){
    vector<int> nums;
    int a[] = {2,3,1,2,4,3};
    for(int i=0; i<6; i++){
        nums.push_back(a[i]);
    }
    Solution *s = new Solution();
    cout<<s->minSubArrayLen(7,nums)<<endl;
    cout<<s->minSubArrayLen(8,nums)<<endl;
    return 0;
}
