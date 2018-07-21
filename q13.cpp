static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int romanToInt(string s) {
        int r(0);
        for(int p=0;p<s.size();) {
            r+=readnextdigit(s,p);
        }
        return r;
    }
    
    int readnextdigit(string& s,int& p){
        if(s[p]=='M') {
            ++p;
            return 1000;
        }
        if(s[p]=='D') {
            ++p;
            return 500;
        }
        if(s[p]=='C') {
            ++p;
            if(s[p]=='M') {
                ++p;
                return 900;
            }
            if(s[p]=='D') {
                ++p;
                return 400;
            }
            return 100;
                
        }
        if(s[p]=='L') {
            ++p;
            return 50;
        }
        if(s[p]=='X') {
            ++p;
            if(s[p]=='C') {
                ++p;
                return 90;
            }
            if(s[p]=='L') {
                ++p;
                return 40;
            }
            return 10;
                
        }
        if(s[p]=='V') {
            ++p;
            return 5;
        }
        if(s[p]=='I') {
            ++p;
            if(s[p]=='X') {
                ++p;
                return 9;
            }
            if(s[p]=='V') {
                ++p;
                return 4;
            }
            return 1;
                
        }
        return 0;
    }
    
};

