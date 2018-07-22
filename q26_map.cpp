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
		int end = s.size()-len;
        unordered_map<string,int> count;
        for(int i=0;i<words.size();++i) ++count[words[i]];
		for (int i = 0; i<n; ++i) {
			int posi = i;

			while (posi <= end) {
				unordered_map<string,int> flags;
				int drop(0),start=posi;
				for (int j = 0; j<words.size(); ++j) {
                    int num=count[s.substr(posi,n)];
					if (num!=0) {
						if (flags[s.substr(posi,n)] == num) {
							posi += n;
							drop = j + 1;
							break;
						}
						++flags[s.substr(posi,n)];
						posi += n;
						continue;
					}
					posi += n;
					drop = j + 1;
					break;
				}
				//posi += n;

				if (drop) {
					posi = start + n;
					continue;
				}

				r.push_back(start);

				while (true) {
					int flag(0);
					for (int t = 0; t<n; t++) {
						if (s[start+t] != s[posi + t]) {
							flag = 1;
							break;
						}
					}
					start += n;
					posi += n;
					if (flag) {
						posi = start + n;
						break;
					}
					r.push_back(start);
				}
			}
		}
		return r;
	}
};
