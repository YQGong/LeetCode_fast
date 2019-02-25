//曾出现的错误：
//1.把大于号和小于号写反了，导致输出的结果不对
//

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> r;
        int index1=0;
        int index2=0;
        while(index1<m&&index2<n){
            if(nums1[index1]<=nums2[index2]){
                r.push_back(nums1[index1++]);
            }else{
                r.push_back(nums2[index2++]);
            }
        }
        if(index1==m){
            while(index2<n) {
                r.push_back(nums2[index2]);
                ++index2;
            }
        }else{
            while(index1<m) {
                r.push_back(nums1[index1]);
                ++index1;
            }
        }
        nums1=r;
    }
};
