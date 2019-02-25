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
        for(int i=r.size()-1;i>=(int)((r.size()-add.size()));--i){
            if(add[i-(r.size()-add.size())]=='1'){
                plusOne(r,i);
            }
        }
        return r;
    }
    
    void plusOne(string & base,int& position){
        int index=position;
        while(index>=0&&base[index]=='1') base[index--]='0';
        if(index>=0){
            base[index]='1';
        }else{
            base.insert(0,1,'1');
            ++position;
        }
    }
};
