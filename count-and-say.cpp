static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    string countAndSay(int n) {
        string in="1";
        for(int i=0;i<n-1;++i){
            in=spell(in);
        }
        return in;
    }
    
    string spell(string in){
        int index=1;
        string out="";
        while(index-1<in.size()){
            char current=in[index-1];
            int counter=1;
            while(index<in.size()&&current==in[index]) {
                ++index;
                ++counter;
            }
            out+=to_string(counter)+current;
            ++index;
        }
        return out;
    }
};
