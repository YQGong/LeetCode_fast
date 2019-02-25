static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int len=nums.size();
        if(len==0) return 0;
        if(len==1){
            return 1;
        }
        
        int index=0;
        int position=1;
        int r=1;
        while(index+1<len){
            if(nums[index]==nums[index+1]){
                ++index;
            }else{
                nums[position]=nums[index+1];
                ++position;
                ++index;
                ++r;
            }
        }
        nums.resize(r);
        return r;
    }
};
