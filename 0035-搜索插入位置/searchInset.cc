#include<iostream>
#include<vector>

using namespace std;
/*
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 *
 * 你可以假设数组中无重复元素。
 *
 * 示例 1:
 * 输入: [1,3,5,6], 5
 * 输出: 2
 *
 * 示例 2:
 * 输入: [1,3,5,6], 2
 * 输出: 1
 *
 * 示例 3:
 * 输入: [1,3,5,6], 7
 * 输出: 4
 *
 * 示例 4:
 * 输入: [1,3,5,6], 0
 * 输出: 0
 *
 *
 * 输入:
 *  0,1
 * [1,3]
 * 2
 */

int binarySearch(vector<int> &nums, int target){
    if(nums.size()==0)
        return 0;
    if(target<nums[0])
        return 0;
    int left = 0;
    int right= nums.size()-1;
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    /*
     * 如果没有重新计算 mid = (left+right)/2;
     * 示例5错误
     */
    mid = (left+right)/2;
    return nums[mid]>target?:mid-1,mid+1;
}
int main(int argc, char *argv[]){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    cout<<binarySearch(nums,5)<<endl;
    cout<<binarySearch(nums,2)<<endl;
    cout<<binarySearch(nums,7)<<endl;
    cout<<binarySearch(nums,0)<<endl;
    nums.clear();
    nums.push_back(1);
    nums.push_back(3);
    cout<<binarySearch(nums,2)<<endl;
    return 0;
}
