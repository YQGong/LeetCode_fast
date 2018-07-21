static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        unordered_map<int,vector<vector<int>>> mymap;
        
        vector<vector<int>> r;
        
        if (nums.size()<3) return r;
        {
            vector<int> tempv;
            tempv.push_back(nums[0]);
            tempv.push_back(nums[1]);
            mymap[-nums[0]-nums[1]].push_back(tempv);
        }
        for(int i=2;i<nums.size();++i){
            //1.遍历从第三个开始的所有元素,并判断是第几次重复
            int flag(0);
            for(int j=i-1;j>=0;--j){
                if(nums[j]==nums[i]) {
                    flag++;
                } else {
                    break;
                }
            }
            //2.列表里找
            unordered_map<int,int> exlst;
            if(mymap[nums[i]].size()>0&&flag<3){
                vector<vector<int>> tempr=mymap[nums[i]];
                mymap[nums[i]].clear();
                for(int j=0;j<tempr.size();++j){
                    tempr[j].push_back(nums[i]);
                    exlst[tempr[j][0]]=1;
                    exlst[tempr[j][1]]=1;
                }
                r.insert(r.end(),tempr.begin(),tempr.end());
            }
            //3.把所有的新的可能的数对加入列表
            if(flag==1){
                vector<int> tempv;
                tempv.push_back(nums[i]);
                tempv.push_back(nums[i]);
                mymap[-2*nums[i]].push_back(tempv);
            }
            if(flag==0){
                for(int j=0;j<i;++j){
                    if(exlst[nums[j]]==0){
                        vector<int> tempv;
                        tempv.push_back(nums[i]);
                        tempv.push_back(nums[j]);
                        mymap[-nums[i]-nums[j]].push_back(tempv);
                        exlst[nums[j]]=1;
                    }
                }
            }
        }
        return r;
    }
};
