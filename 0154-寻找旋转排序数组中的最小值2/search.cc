#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:

    int findMin(vector<int>& nums) {
        int left = 0;
        int right= nums.size()-1;
    while(left+1<right){
        //cout<<left<<" "<<right<<endl;
        int mid = (left+right)/2;
        if(nums[mid]>nums[right]){
            left = mid;
        }else{
            right = mid;
        }
    }
    int index = nums[left]<nums[right]?left:right;
    if(nums[0]==nums[index] && nums[index]==nums[nums.size()-1]){
        int m = INT_MAX;
        for(int i=0;i<nums.size();i++){
            m = min(m, nums[i]);
        }
        return m;
    }else{
        return nums[left]<nums[right]?nums[left]:nums[right];
    }
    }
};
int main(int argc, char *argv[]){
    //int a[] = {4,5,1,2,3};
    //int a[] = {2,5,6,0,0,1,2};
    int a[] = {1};
    vector<int> nums;
    for(int i=0; i<1; i++){
        nums.push_back(a[i]);
    }
    Solution * s = new Solution();
    cout<<s->findMin(nums)<<endl;
    return 0;
}
