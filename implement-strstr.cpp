static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int index=0;
        while(haystack.size()>=needle.size()+index){
            int p=0;
            while(haystack[index+p]==needle[p]&&p<needle.size()) p++;
            if (p==needle.size()) return index;
            ++index;
        }
        return -1;
    }
};
