static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	bool isPalindrome(int x) {
		int r(0);
		if (x<0) return false;
		if (x<10) return true;
		while (true) {
			r = r * 10 + (x % 10);
			x /= 10;
			if (x<10 * (r + 1) || r == 0) break;
		}
		if (r == 0 && x != 0) return false;
		if (r == x||r==x/10) return true;
		return(false);
	}
};
