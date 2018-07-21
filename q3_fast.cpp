static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i(0),j,lenmax(0);
        for(j=0;j<s.size();++j){
            for(int k=i;k<j;++k){
                if(s[k]==s[j]){
                    i=k+1;
                    break;
                }
            }
            lenmax=lenmax>j-i+1?lenmax:j-i+1;
        }
        return lenmax;
    }
};
