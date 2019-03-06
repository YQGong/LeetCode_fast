static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
    string addBinary(string a, string b) {
        string r,add;
        if(a.size()>=b.size()){
            r=a;
            add=b;
        }else{
            r=b;
            add=a;
        }
        int carry=0;
        for(int i=r.size()-1;i>=0;--i){
            int total=(r[i]-48)+carry;
            if(i>=(int)(r.size()-add.size())){
                total+=(add[i-(r.size()-add.size())]-48);
            }
            r[i]=(total%2)+48;
            carry=total/2;
        }
        if(carry==1){
            r.insert(0,1,'1');
        }
        return r;
    }
};
