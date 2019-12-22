#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool searchMatrixCore(vector<vector <int> >& matrix, int target, int starti,int startj, int endi, int endj) {
        //cout<<starti<<" "<<startj<<" "<<endi<<" "<<endj<<endl;
        if(starti<=endi && startj<=endj){
        int midi = (starti+endi)/2;
        int midj = (startj+endj)/2;
        if(matrix[midi][midj]==target){
            return true;
        }else if(matrix[midi][midj]>target){
            return searchMatrixCore(matrix,target,starti,startj,midi-1,endj)||searchMatrixCore(matrix,target,starti,startj,endi,midj-1);
        }else {
            return searchMatrixCore(matrix,target,starti,midj+1,midi,endj)||searchMatrixCore(matrix,target,midi+1,startj,endi,endj);
        }
        }else{
            return false;
        }


    }
    bool searchMatrix(vector<vector <int> >& matrix, int target) {
        if(matrix.size()==0)
            return false;
        if(matrix[0].size()==0)
            return false;
        return searchMatrixCore(matrix,target,0,0, matrix.size()-1, matrix[0].size()-1);
    }
        
};

int main(int argc, char * argv[]){
    Solution *s = new Solution();
	vector<vector <int> > matrix;
	vector<int> t;
	t.push_back(1);t.push_back(4);t.push_back(7);t.push_back(11);t.push_back(15); matrix.push_back(t);t.clear();
	t.push_back(2);t.push_back(5);t.push_back(8);t.push_back(12);t.push_back(19); matrix.push_back(t);t.clear();
	t.push_back(3);t.push_back(6);t.push_back(9);t.push_back(16);t.push_back(22); matrix.push_back(t);t.clear();
	t.push_back(10);t.push_back(13);t.push_back(14);t.push_back(17);t.push_back(24); matrix.push_back(t);t.clear();
	t.push_back(18);t.push_back(21);t.push_back(23);t.push_back(26);t.push_back(30); matrix.push_back(t);t.clear();
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[0].size(); j++){
            cout<<s->searchMatrix(matrix,matrix[i][j])<<" ";
            //break;
		}
        //break;
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
