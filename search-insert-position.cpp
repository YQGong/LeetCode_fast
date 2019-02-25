static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index=0;
        while(index<nums.size()&&target>nums[index]){
            ++index;
        }
        return index;
    }
};
