#include<iostream>
#include<vector>
#include<limits.h>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

using namespace std;

/*
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 *
 * 示例:
 *
 * 输入:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *     [4,2,1]
 *     ]
 *     输出: 7
 *     解释: 因为路径 1→3→1→1→1 的总和最小。
 *
 */

class Solution {
public:
    // 找一条和最大的路径
    int core(vector< vector<int> > & grid, vector< vector<int> > & dp, int i, int j){
        // 调用core前，检查i和j的取值范围。
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        int flagi = 0;
        int flagj = 0;
        if(i+1<grid.size()){
            dp[i+1][j] = core(grid,dp,i+1,j);
            flagi = 1;
        }
        if(j+1<grid[0].size()){
            dp[i][j+1] = core(grid,dp,i,j+1);
            flagj = 1;
        }

        if(flagi==1 && flagj==1)
            dp[i][j] = min(dp[i+1][j], dp[i][j+1])+grid[i][j];

        if(flagi==1 && flagj==0)
            dp[i][j] = dp[i+1][j]+grid[i][j];

        if(flagi==0 && flagj==1)
            dp[i][j] = dp[i][j+1]+grid[i][j];

        if(flagi==0 && flagj==0)
            dp[i][j] = grid[i][j];

        //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        return dp[i][j];

    }
    int minPathSum(vector<vector<int> >& grid) {
        vector<vector<int> > dp;
        for(int i=0; i<grid.size(); i++){
            vector<int> t;
            for(int j=0; j<grid[0].size(); j++){
                t.push_back(INT_MAX);
            }
            dp.push_back(t);
        }
        core(grid,dp,0,0);
        return dp[0][0];
    }
};

int main(int argc, char *argv[]){
	Solution * s = new Solution();
	vector<vector<int> > grid;
	vector<int> t;
	t.push_back(1);t.push_back(3);t.push_back(1);grid.push_back(t);t.clear();
	t.push_back(1);t.push_back(5);t.push_back(1);grid.push_back(t);t.clear();
	t.push_back(4);t.push_back(2);t.push_back(1);grid.push_back(t);t.clear();
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            //grid[i][j] = -grid[i][j];
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
	cout<<s->minPathSum(grid)<<endl;
	
    return 0;
}
