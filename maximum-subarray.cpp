static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int rightPartialMax=nums[0];
        int max=nums[0];
        for(int i=1;i<nums.size();++i){
            rightPartialMax=rightPartialMax>0?rightPartialMax+nums[i]:nums[i];
            max=rightPartialMax>max?rightPartialMax:max;
        }
        return max;
    }
};
