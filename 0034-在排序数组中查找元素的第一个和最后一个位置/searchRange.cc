#include<iostream>
#include<vector>

using namespace std;

/*
 *  0,1,2,3,4,5
 * [5,7,7,8,8,10]
 * 
 * [7,7,7]
 */
int leftIndex(vector<int> & nums, int target){
    // 先考虑特殊情况
    if(nums.size()==0)
        return -1;
    if(nums[0]==target)
        return 0;

    int left = 0;
    int right= nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]==target){
            //   leftIndex
            if(mid-1>=0 && nums[mid-1]!=target){
                return mid;
            }else{
                right = mid-1; 
            }
            //   leftIndex
        }else if(nums[mid] > target){
            right = mid-1;
        }else {
            left = mid+1;
        }
    }
    return -1;
}

int rightIndex(vector<int> & nums, int target){
    if(nums.size()==0)
        return -1;
    if(nums[nums.size()-1]==target)
        return nums.size()-1;

    int left = 0;
    int right= nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]==target){
            //   rightIndex
            if(mid+1<nums.size() && nums[mid+1]!=target){
                return mid;
            }else{
                left = mid+1;
            }
            //   rightIndex
        }else if(nums[mid] > target){
            right = mid-1;
        }else {
            left = mid+1;
        }
    }
    return -1;
}


vector<int> searchRange(vector<int>& nums, int target) {
    /*
     * 思考1:
     * 找比8小的最大index+1(index可以为0)
     * 找比8大的最小index-1(index至少为1)
     *
     * 思考2:
     * 找到8, 从8开始向前后遍历. 最坏情况数组元素都是8.考虑翻倍遍历
     */
    vector<int> ans;
    int left = leftIndex(nums,target);
    int right= rightIndex(nums,target);
    ans.push_back(left);
    ans.push_back(right);
    return  ans;
}


int main(int argc, char *argv[]){
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    // [5,7,7,8,8,10]
    cout<<leftIndex(nums,5)<<endl;
    cout<<leftIndex(nums,6)<<endl;
    cout<<leftIndex(nums,8)<<endl;
    cout<<leftIndex(nums,10)<<endl;

    cout<<rightIndex(nums,5)<<endl;
    cout<<rightIndex(nums,6)<<endl;
    cout<<rightIndex(nums,8)<<endl;
    cout<<rightIndex(nums,10)<<endl;
 
    vector<int> ans = searchRange(nums,5);cout<<ans[0]<<" "<<ans[1]<<endl;
                ans = searchRange(nums,6);cout<<ans[0]<<" "<<ans[1]<<endl;
                ans = searchRange(nums,8);cout<<ans[0]<<" "<<ans[1]<<endl;
                ans = searchRange(nums,10);cout<<ans[0]<<" "<<ans[1]<<endl;
    nums.clear();
    // [1,2,3,3,3,3,4,5,9]
    //
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(9);
    cout<<leftIndex(nums,3)<<endl;
    cout<<rightIndex(nums,3)<<endl;
    ans = searchRange(nums,3);cout<<ans[0]<<" "<<ans[1]<<endl;
}
