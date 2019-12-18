#include<iostream>
#include<vector>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

using namespace std;

int findKth(vector<int> nums1, int start1, int end1, vector<int> nums2, int start2, int end2, int k){
    int len1 = end1-start1+1;
    int len2 = end2-start2+1;
    if(len1>len2) return findKth(nums2,start2,end2,nums1,start1,end1,k);
    if(len1==0)   return nums2[start2+k-1];

    if(k==1) return min(nums1[start1], nums2[start2]);

    /*
     * nums1 = [1,3,5,7]
     * nums2 = [2,4,6,8]
     * 
     * 找第3小
     * i = 0 + 3/2 -1 --> index = 1 --> nums1 = [1,3,5,7]
     * j = 0 + 3/2 -1 --> index = 1 --> nums2 = [2,4,6,8]
     * 
     * 找第4小
     * i = 0 + 4/2 -1 --> index = 1 --> nums1 = [1,3,5,7]
     * j = 0 + 4/2 -1 --> index = 1 --> nums2 = [2,4,6,8]
     *
     *
     */
    int i = start1 + k/2 -1;
    int j = start2 + k/2 -1;
    
    // 考虑, 数组长度可能小于第k小

    /*
     * bug      : #define max(x,y)  x>y?x:y
     * bug fixed: #define max(x,y) (x>y?x:y)
     */
    i = start1 + min(len1,k/2) -1;
    j = start2 + min(len2,k/2) -1;
    if(nums1[i]>nums2[j]){
        /*
         *    |
         * [1,9]                    k=7
         * 
         *      |
         * [1,2,3,4,5,6,7,8,9,10]   k/2-1=index=2
         */
        return findKth(nums1,start1,end1, nums2,j+1,end2, k-(j-start2+1));
    }else{
        /*
         *    |
         * [1,2]                    k=7
         * 
         *      |
         * [1,2,3,4,5,6,7,8,9,10]   k/2-1=index=2
         */
        //return findKth(nums1,2,1,nums2,0,9,k-(1-0+1));
        return findKth(nums1,i+1, end1, nums2,start2,end2, k-(i-start1+1));
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int a = nums1.size();
    int b = nums2.size();
    if((a+b)%2==0){
        cout<<"第"<<(a+b)/2<<" "<<(a+b)/2+1<<endl;
        return (findKth(nums1,0,a-1, nums2,0, b-1, (a+b)/2) + findKth(nums1,0,a-1, nums2,0,b-1, (a+b)/2+1))/2;
    }else{
        cout<<"第"<<(a+b)/2+1<<endl;
        return findKth(nums1,0,a-1, nums2,0,b-1, (a+b)/2+1) ;
    }
}


int main(int argc, char *argv[]){
    vector<int> A, B;
    A.push_back(1);A.push_back(3);A.push_back(5);A.push_back(7);A.push_back(9);
    B.push_back(2);B.push_back(4);B.push_back(6);B.push_back(8);B.push_back(10);B.push_back(11);
    for(int i=1; i<=11; i++){
        int k = i;
        cout<<"\ninput="<<k<<" output="<<findKth(A,0,A.size()-1,B,0,B.size()-1,k)<<endl;
    }

    cout<<findMedianSortedArrays(A,B)<<endl;
    return 0;
}
