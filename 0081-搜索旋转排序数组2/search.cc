#include<iostream>
#include<vector>

using namespace std;

/*
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 *
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 *
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 *
 * 你可以假设数组中不存在重复的元素。
 *
 * 你的算法时间复杂度必须是 O(log n) 级别。
 *
 */


/*
 *  0,1,2,3,4,5,6
 * [4,5,6,7,0,1,2]
 *
 *  0,1,2,3,4,5,6
 *       [7,0,1,2]
 *
 *
 */
int find_rotate_index(vector<int> &nums, int left,int right){
    // while停止条件, 只剩两个时, 在return中选最小
    while(left+1<right){
        //cout<<left<<" "<<right<<endl;
        int mid = (left+right)/2;
        if(nums[mid]>nums[right]){
            left = mid;
        }else{
            right = mid;
        }
    }
    //cout<<nums[left]<<":"<<nums[right]<<endl;
    return nums[left]<nums[right]?left:right;
}

bool binarySearch(vector<int> &nums, int left, int right, int target){
    // 二分查找while条件left<=right, 可以聚焦到left=right
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]==target){
            return false;
        }else if(nums[mid]>target){
            right = mid-1;
        }else{
            left = mid +1;
        }
    }
    return false;
}

bool search(vector<int> &nums, int target){
    if(nums.size()==0)
        return false;
    int index = find_rotate_index(nums,0,nums.size()-1);
    if(index==0){
        return binarySearch(nums,0,nums.size()-1,target);
    }
    if(nums[0]==nums[index] && nums[index]==nums[nums.size()-1]){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==target)
                return true;
        }
        return false;
    }

    bool ans = false;
    ans = binarySearch(nums,0,index-1, target);
    if(ans!=false)
        return true;
    ans = binarySearch(nums,index,nums.size()-1, target);
    if(ans!=false)
        return true;
    return false;
}

int main(int argc, char *argv[]){
    //int a[] = {4,5,1,2,3};
    //int a[] = {2,5,6,0,0,1,2};
    int a[] = {1};
    vector<int> nums;
    for(int i=0; i<1; i++){
        nums.push_back(a[i]);
    }
    cout<<search(nums,0)<<endl;
    return 0;
}
