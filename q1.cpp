class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        for(int i = 0; i < len ; i++){
            for(int j = i+1; j < len;j++){
                if(nums[i]+nums[j]==target){
                    vector<int> result(2);
                    result[0]=i;
                    result[1]=j;
                    return(result);
                }
            }
        }
    }
};
