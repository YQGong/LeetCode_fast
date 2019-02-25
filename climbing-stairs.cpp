static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==0) return 1;
        long long r=1;
        long long  r0=1;
        for(long long  i=2;i<=n;++i){
            long long temp=r;
            r=r+r0;
            r0=temp;
        }
        return r;
    }
};
