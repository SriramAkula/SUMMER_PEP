#include <bits/stdc++.h>
using namespace std;

void help(vector<vector<int>>& ans,int st,vector<int> nums){
    if(st==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=st;i<nums.size();i++){
        swap(nums[i],nums[st]);
        help(ans,st+1,nums);
    }

}

vector<vector<int>> getPermutations(vector<int> nums){
    vector<vector<int>> ans;
    help(ans,0,nums);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = getPermutations(nums);

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