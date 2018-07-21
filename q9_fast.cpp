static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();


#define uint32_t int

class Solution {
public:
	bool isPalindrome(int x) {
		int r(0),x2;
		int64_t c = 3435973837;
		if (x<0) return false;
		if (x<10) return true;
		while (true) {
			x2 = static_cast<int32_t>((static_cast<int64_t>(x) * c) >> 35);
			r = r * 10 + (x -10* x2);
			x = x2;
			if (x<10 * (r + 1) || r == 0) break;
		}
		if (r == 0 && x != 0) return false;
		if (r == x||r==x/10) return true;
		return(false);
	}
};
