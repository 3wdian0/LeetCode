#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        if(nums.size()>=2){
            if(nums[0]>nums[1])
                return 0;
            if(nums[nums.size()-1]>nums[nums.size()-2])
                return nums.size()-1;
        }
        int left = 0;
        int right= nums.size()-1;
        int mid = -1;
        while(left<right){
            mid = (left+right)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
                return mid;
            int x_1 = mid, x_2 = mid+1; // 如果mid+1>=nums.size()
            int y_1 = nums[x_1], y_2 = nums[x_2];
            int k   = (y_1-y_2)/(x_1-x_2);
            if(k>0){ 
                left = mid;
            }else{
                right = mid;
            }   
        }
        return mid;
    }
};



int main(int argc, char* argv[]){
    int a[] = {1,2,3};
    vector<int> nums;
    for(int i=0; i<5; i++){
        nums.push_back(a[i]);
    }
    Solution * s = new Solution();
    cout<<s->findPeakElement(nums)<<endl;
}
