class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size()==0) return 0;
        int counter=0;
        reverse_iterator rit=s.rbegin();
        while(rit!=s.rend()&&*rit==' ') ++rit;
        while(rit!=s.rend()&&*rit!=' '){
            ++counter;
            ++rit;
        }
        return counter;
    }
};
