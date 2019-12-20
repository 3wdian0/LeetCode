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
    return nums[left]<nums[right]?:left,right;
}

int binarySearch(vector<int> &nums, int left, int right, int target){
    // 二分查找while条件left<=right, 可以聚焦到left=right
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>target){
            right = mid-1;
        }else{
            left = mid +1;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target){
    if(nums.size()==0)
        return -1;
    return binarySearch(nums,0,nums.size()-1,target);
}

int main(int argc, char *argv[]){
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(12);
    //cout<<find_rotate_index(nums,0,nums.size()-1)<<endl;
    cout<<search(nums,0)<<endl;
    cout<<search(nums,3)<<endl;
    cout<<search(nums,5)<<endl;
    nums.clear();
    nums.push_back(5);
    cout<<search(nums,5)<<endl;
    return 0;
}
