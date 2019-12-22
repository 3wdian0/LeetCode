#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int core(int x){
		int len = 0;
		while(x){
			len+=1;
            x /=10;
		}
		return len;
	}

    int findNumbers(vector<int>& nums) {
		int count = 0;
 		for(int i=0; i<nums.size(); i++){
			if(core(nums[i])%2==0)
                count++;
		}       
		return count;
    }
};

int main(int argc, char*argv[]){

	vector<int> nums;
	nums.push_back(555);
	nums.push_back(901);
	nums.push_back(482);
	nums.push_back(1771);
    Solution * s = new Solution();
    cout<<s->findNumbers(nums)<<endl;
    return 0;
}
