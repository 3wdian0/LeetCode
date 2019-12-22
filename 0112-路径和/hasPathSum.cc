#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    bool hasPathSumCore(TreeNode* root, int sum, int pre_sum){
        // 保证，进入hasPathSumCore的root都不为空
        bool result = false;
        if(root->left==NULL && root->right==NULL){
            // 叶子节点
            if(sum==(pre_sum+root->val))
                result = true;
        }
        if(root->left!=NULL){
            if(hasPathSumCore(root->left, sum, pre_sum+root->val)==true)
                result = true;
        }
        if(root->right!=NULL){
            if(hasPathSumCore(root->right,sum,  pre_sum+root->val)==true)
                result = true;
        }
        return result;
    }
    
    bool hasPathSum(TreeNode* root, int sum){
        if(root!=NULL){
            return hasPathSumCore(root, sum, 0);
        }
        return false;
    }
};
int main(int argc, char*argv[]){
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(5);

    root->left     = new TreeNode(4);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);

    root->right    = new TreeNode(8);
    root->right->left= new TreeNode(13);
    root->right->right= new TreeNode(4);
    root->right->right->right= new TreeNode(1);
    cout<<s->hasPathSum(root,22)<<endl;
    cout<<s->hasPathSum(root,27)<<endl;
    cout<<s->hasPathSum(root,26)<<endl;
    cout<<s->hasPathSum(root,18)<<endl;

    cout<<s->hasPathSum(root,19)<<endl;
    cout<<s->hasPathSum(root,400)<<endl;
    return 0;
}
