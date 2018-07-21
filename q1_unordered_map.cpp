class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> lst;
        int i=0;
        for(int num : nums){
            if(lst[target-num]>0){
                return vector<int>{lst[target-num]-1,i};
            } else {
                i++;
                lst[num]=i;
            }
        }
        return vector<int>{-1,-1};
    }
};
