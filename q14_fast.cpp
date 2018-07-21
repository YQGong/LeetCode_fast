static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int r(0);
        if(strs.size()==0) return "";
        while(true){
            if(!(r<strs[0].size())) return strs[0].substr(0,r);
            for(int i=0;i<strs.size()-1;++i){
                if(!(r<strs[i+1].size()&&strs[i][r]==strs[i+1][r])){
                    return strs[1].substr(0,r);
                }
            }
            ++r;
        }
    }
};
