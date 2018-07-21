static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	string convert(string s, int numRows) {
        if (numRows == 1) {
			return s;
		}
		string r = "";
		for (int i = 1; i <= numRows; i++) {
			int posi = i - 1;
			while (posi<s.size()) {
				if (i == 1 || i == numRows) {
					r += s[posi];
					posi += 2 * (numRows - 1);
				}
				else {
					r += s[posi];
					posi += 2 * (numRows - i);
					if (posi < s.size()) {
						r += s[posi];
						posi += 2 * (i - 1);
					}
				}
			}
		}
		return r;
	}
};
