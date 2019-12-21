#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector <int> >& matrix, int target) {
        if(matrix.size()==0)
            return false;
        if(matrix[0].size()==0)
            return false;

        int i = 0, j = matrix.size()-1;
        // 先确定在哪一行，row中
        int row = -1;
        while(i<=j){
            int mid = (i+j)/2;

            if(matrix[mid][0]<=target && target<=matrix[mid][ (matrix[mid].size()-1) ]){
                row = mid;
                break;
            }else if(matrix[mid][0]>target){
                j = mid - 1;
            }else{
                i = mid+1;
            }

        }
        if(row != -1){
            vector<int> nums = matrix[row];
            i = 0, j = nums.size()-1;
            while(i<=j){
                int mid =  (i+j)/2;
                if(nums[mid]==target){
                    return true;
                }else if(nums[mid]>target){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            }
        }
        return false;
        
    }
};

int main(int argc, char * argv[]){
    Solution *s = new Solution();
	vector<vector <int> > matrix;
	vector<int> t;
	t.push_back(1);t.push_back(3);t.push_back(5);t.push_back(7); matrix.push_back(t);t.clear();
	t.push_back(10);t.push_back(11);t.push_back(16);t.push_back(20); matrix.push_back(t);t.clear();
	t.push_back(23);t.push_back(30);t.push_back(34);t.push_back(50); matrix.push_back(t);t.clear();
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[0].size(); j++){
            cout<<s->searchMatrix(matrix,matrix[i][j])<<" ";
		}
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<<s->searchMatrix(matrix,-1)<<endl;
    cout<<s->searchMatrix(matrix,0)<<endl;
    cout<<s->searchMatrix(matrix,13)<<endl;
    cout<<s->searchMatrix(matrix,51)<<endl;

    matrix.clear();
    cout<<s->searchMatrix(matrix,51)<<endl;
    matrix.push_back(t);
    cout<<s->searchMatrix(matrix,51)<<endl;
	t.push_back(23);t.push_back(30);t.push_back(34);t.push_back(50); matrix.push_back(t);t.clear();
    cout<<s->searchMatrix(matrix,50)<<endl;
	return 0;
}
