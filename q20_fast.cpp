class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for(int i=0;i<s.size();++i){
            if(s[i]=='['||s[i]=='{'||s[i]=='(') {
                left.push(s[i]);
                continue;
            }
            if(left.empty()) return false;
            if(s[i]==']'&&left.top()=='[') {
                left.pop();
                continue;
            }
            if(s[i]==')'&&left.top()=='(') {
                left.pop();
                continue;
            }
            if(s[i]=='}'&&left.top()=='{') {
                left.pop();
                continue;
            }
            return false;
        }
        if(left.empty()) return true;
        return false;
    }
};
