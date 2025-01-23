#include <bits/stdc++.h>
using namespace std;

    void help(vector<int>& nums,vector<vector<int>>& ans,int st){
        if(st==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=st;i<nums.size();i++){
            swap(nums[i],nums[st]);
            help(nums,ans,st+1);
            swap(nums[i],nums[st]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        help(nums,ans,0);
        return ans;
    }

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);

    // Print the result
    cout << "Permutations of [1, 2, 3] are:\n";
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}