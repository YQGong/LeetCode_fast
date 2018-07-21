static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    int reverse(int x) {
        long long r;
        while(true){
            r+=x%10;
            x/=10;
            if(!x) break;
            r*=10;
        }
        if (r >= 2147483648 || r < -2147483648) return 0;
        return r;
    }
};
