static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    string intToRoman(int num) {
        string r="";
        while(num){
            num-=nextdigit(num,r);
        }
        return r;
    }
    
    int nextdigit(int num,string& s){
        if(num>=1000) {
            s+="M";
            return 1000;
        }
        if(num>=900) {
            s+="CM";
            return 900;
        }
        if(num>=500) {
            s+="D";
            return 500;
        }
        if(num>=400) {
            s+="CD";
            return 400;
        }
        if(num>=100) {
            s+="C";
            return 100;
        }
        if(num>=90) {
            s+="XC";
            return 90;
        }
        if(num>=50) {
            s+="L";
            return 50;
        }
        if(num>=40) {
            s+="XL";
            return 40;
        }
        if(num>=10) {
            s+="X";
            return 10;
        }
        if(num>=9) {
            s+="IX";
            return 9;
        }
        if(num>=5) {
            s+="V";
            return 5;
        }
        if(num>=4) {
            s+="IV";
            return 4;
        }
        if(num>=1) {
            s+="I";
            return 1;
        }
        return 0;
    }
    
};
