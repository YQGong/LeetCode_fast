class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;++i){
            for(int j=i+1;j<nums.size();++j){
                if(nums[i]+nums[j]==target){
                    vector<int> r={i,j};
                    return r;
                }
            }
        }
        vector<int> r;
        return r;
    }
};
