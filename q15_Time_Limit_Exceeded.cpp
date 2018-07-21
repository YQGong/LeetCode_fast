class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> r;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                int partsum=nums[i]+nums[j];
                for(int k=j+1;k<nums.size();++k){
                    if(partsum+nums[k]==0){
                        vector<int> tempr;
                        //排序
                        tempr.push_back(nums[i]);
                        tempr.push_back(nums[j]);
                        tempr.push_back(nums[k]);
                        sort(tempr.begin(),tempr.end());
                        //查重
                        int flag(0);
                        for(int p=0;p<r.size();++p){
                            if((tempr[0]==r[p][0]&&tempr[1]==r[p][1]&&tempr[2]==r[p][2])) {
                                flag=1;
                                break;
                            }
                        }
                        //插入结果数组
                        if(flag==0){
                            r.push_back(tempr);
                        }
                    }
                }
            }
        }
        return r;
    }
};
