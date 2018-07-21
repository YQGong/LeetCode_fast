static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	string longestPalindrome(string s) {
		int size = 2 * s.size() + 2;
		int* p=new int[size]();
		int mx(0), id(0), mc(0), ml(0);

		for (int i = 0; i<size; i++) {
			p[i] = i<mx ? min(p[2 * id - i], mx - i) : 1;
			while ((((-(((i + p[i]) << 31) >> 31)) == 0) &&((i - p[i] - 2) >> 1)>-1 && s[((i + p[i] - 2) >> 1)] == s[((i - p[i] - 2) >> 1)])\
				||(((-(((i + p[i]) << 31) >> 31)) == 1) && (i - p[i])>0)) {
				p[i]++;
			}
			int temp = p[i];
			if (mx<i + p[i]) {
				mx = i + p[i];
				id = i;
			}
			if (ml<p[i]) {
				mc = i;
				ml = p[i];
			}
		}
		return s.substr((mc - ml) / 2, ml - 1);
	}
};
