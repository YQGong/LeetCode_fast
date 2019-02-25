class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        int position=0;
        int r=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==val){
                continue;
            }else{
                nums[position++]=nums[i];
                r++;
            }
        }
        return r;
    }
};
