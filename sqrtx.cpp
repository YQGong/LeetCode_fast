static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int mySqrt(int x) {
        long long test=1;
        while(test*test<x){
            test*=2;
        }
        if(test*test==x) return test;
        long long low=test/2;
        long long high=test;
        while(oneStep(low,high,x)) {
            continue;
        }
        return low;
    }
    
    long long oneStep(long long& low,long long& high,long long sqr){
        if (high-low<=1) return 0;
        long long test=(high+low)/2;
        if(test*test>sqr){
            high=test;
        }else if(test*test==sqr){
            low=test;
            return 0;
        }else{
            low=test;
        }
        return 1;
    }
};
