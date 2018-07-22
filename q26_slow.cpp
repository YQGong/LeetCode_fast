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
		vector<int> count;
		int end = s.size();
		for (int i = 0; i<words.size(); ++i) {
			int found = patt.find(words[i]);
			end -= words[i].size();
			while (found%n != 0 && found != string::npos) {
				found = patt.find(words[i],found+1);
			}
			if (string::npos != found) {
				++count[found / n];
				continue;
			}
			patt += words[i];
			count.push_back(1);
		}
		for (int i = 0; i<n; ++i) {
			int posi = i;

			while (posi <= end) {
				int* flags = new int[patt.size() / n]();
				int drop(0),start=posi;
				int found;
				for (int j = 0; j<words.size(); ++j) {
					found = patt.find(s.substr(posi, n));
					while (found%n != 0&& found != string::npos) {
						found = patt.find(s.substr(posi, n),found+1);
					}
					if (found != string::npos) {
						if (flags[found / n] == count[found / n]) {
							posi += n;
							drop = j + 1;
							break;
						}
						++flags[found / n];
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
				delete(flags);
			}
		}
		return r;
	}
};
