static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int end=nums.size()-1,r(INT_MAX>>2),bound=(target+abs(r))/3+1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>bound+1) break;
            if(nums[i]+nums[end-1]+nums[end]<target-abs(r)) continue;
            int j=i+1;
            while(nums[i]+nums[j]+nums[end]>target+abs(r)) --end;
            int k=end;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int dev=sum-target;
                if(abs(dev)<abs(r)){
                    r=dev;
                    bound=(target+abs(r))/3+1;
                }
                if(sum>=target+abs(r)){
                    //k指向下一个可能的数值，跳过所有相同的可能性，如果停止在j的位置说明此处的i已经扫完了。
                    k--;
                    while(nums[k+1]==nums[k]&&j<k){
                        k--;
                    }
                }
                if(sum<=target-abs(r)){
                    //j指向下一个可能的数值，跳过所有相同的可能性，如果停止在k的位置说明此处的i已经扫完了。
                    j++;
                    while(nums[j-1]==nums[j]&&j<nums.size()){
                        j++;
                    }
                }
            }
            while(nums[i+1]==nums[i]&&i<nums.size()){
                i++;
            }
        }
        return r+target;
    }
};
