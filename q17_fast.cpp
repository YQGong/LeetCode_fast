class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const string list[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        const int count[8]={2,2,2,2,2,3,2,3}; 
        vector<string> r;
        string working="";
        int size=digits.size();
        if(size<1) return r;
        for(int i=0;i<digits.size();++i){
            if(digits[i]>57||digits[i]<50) return r;
            working+=list[digits[i]-50][0];
        }
        r.push_back(working);
        while(true){
            for(int i=size-1;i>=0;--i){
                if (!(working[i]==list[digits[i]-50][count[digits[i]-50]])){
                    ++working[i];
                    break;
                }
                if(i==0) return r;
                working[i]=list[digits[i]-50][0];
            }
            r.push_back(working);
        }
    }
};
