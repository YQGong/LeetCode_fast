static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
    public:
        int romanToInt(string s) {
            int dict[256],r(0);

            dict['I']=1   ;
            dict['V']=5   ;
            dict['X']=10  ;
            dict['L']=50  ;
            dict['C']=100 ;
            dict['D']=500 ;
            dict['M']=1000;

            for(int p=0;p<s.size();p++){
                if(p<s.size()-1&&dict[s[p]]<dict[s[p+1]]){
                    r-=dict[s[p]];
                } else {
                    r+=dict[s[p]];
                }
            }
            return r;
        }
};
