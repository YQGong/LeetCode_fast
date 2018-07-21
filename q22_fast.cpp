class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<int> leftcount;
        vector<string> r;
        if(n==0) return r;
        r.push_back("(");
        leftcount.push_back(1);
        for(int i=1;i<2*n;++i){
            int sizer=r.size();
            for(int j=0;j<sizer;++j){
                if(leftcount[j]>0&&0<2*n-i-leftcount[j]){
                    r.push_back(r[j]+')');
                    leftcount.push_back(leftcount[j]-1);
                    r[j]+='(';
                    ++leftcount[j];
                    continue;
                }
                if(leftcount[j]==0){
                    r[j]+='(';
                    ++leftcount[j];
                    continue;
                }
                if(0==2*n-i-leftcount[j]){
                    r[j]+=')';
                    --leftcount[j];
                }
            }
        }
        return r;
    }
};
