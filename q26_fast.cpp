static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
	static vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> r;
		if (words.size() == 0) return r;
		int n = words[0].size(), len = words.size()*n;
		string patt;
		int end = s.size() - len;
		unordered_map<string, int> count, type;
		for (int i = 0; i<words.size(); ++i) {
			++count[words[i]];
			type[words[i]] = i + 1;
		}
		for (int i = 0; i<n; ++i) {
			int posi = i;

			while (posi <= end) {
				unordered_map<string, int> flags;
				int drop(0), start = posi;
				int j = 0;
				while (posi <= s.size()) {
					int num = count[s.substr(posi, n)];
					if (num != 0) {
						if (flags[s.substr(posi, n)] == num) {
							while (type[s.substr(posi - j * n, n)] != type[s.substr(posi, n)]) {
								--flags[s.substr(posi - j * n, n)];
								--j;
							}
							start = posi - (j - 1) * n;
							posi += n;
							continue;
						}
						++flags[s.substr(posi, n)];
						++j;
						posi += n;
						if (j == words.size()) {
							r.push_back(start);
							start += n;
							--flags[s.substr(posi - j * n, n)];
							--j;
						}
						continue;
					}
					posi += n;
					break;
				}
			}
		}
		return r;
	}
};
