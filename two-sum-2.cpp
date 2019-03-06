static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int i=0;
        for(;i<nums.size();++i){
            if(map[target-nums[i]]!=0){
                //found!
                vector<int> r={map[target-nums[i]]-1,i};
                return r;
            }else{
                map[nums[i]]=i+1;
            }
        }
        vector<int> r;
        return r;
    }
};
