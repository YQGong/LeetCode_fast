static const auto speedup = []() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    return 0;
}();

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(next(nums,0)==1) reverse(nums.begin(),nums.end());
    }
    
    int next(vector<int>& nums,int position){
        if(position==nums.size()-1) return 1;
        if(next(nums,position+1)==0) return 0;
        if(nums[position]>=nums[position+1]) return 1;
        int scan=position+2;
        while(scan<nums.size()&&nums[position]<nums[scan]){
            ++scan;
        }
        commute(nums[position],nums[scan-1]);
        reverse(nums.begin()+position+1,nums.end());
        return 0;
    }
    
    void commute(int & a,int & b){
        int temp=a;
        a=b;
        b=temp;
    }
};
