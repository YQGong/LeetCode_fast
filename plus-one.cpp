static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index=digits.size()-1;
        while(index>=0&&digits[index]==9){
            digits[index--]=0;
        }
        if(index>=0){
            digits[index]+=1;
        }else{
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
