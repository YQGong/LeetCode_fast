static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();
struct unit {
	int start, len;
};
class Solution {
public:
	string longestPalindrome(string s) {
		int rstart(0), max(1);
		list<unit> alive;

		if (s.size() < 2) return s;

		//first two char;
		if (s[1] == s[0]) {
			unit temp;
			temp.start = 0;
			temp.len = 2;
			//append to alive;
			alive.push_back(temp);
		}


		for (int i = 2; i<s.size(); ++i) {
			//find in alive;
			for (list<unit>::iterator it = alive.begin(); it != alive.end();) {
				if (it->start - 1>-1&& s[i] == s[it->start - 1]) {
					it->start -= 1;
					it->len += 2;
					++it;
				}
				else {
					if (it->len>max) {
						rstart = it->start;
						max = it->len;
					}
					it=alive.erase(it);
					if (alive.empty()) {
						it = alive.end();
					}
				}
			}

			if (s[i] == s[i - 2]) {
				unit temp;
				temp.start = i - 2;
				temp.len = 3;
				//append to alive;
				alive.push_back(temp);
			}
			if (s[i] == s[i - 1]) {
				unit temp;
				temp.start = i - 1;
				temp.len = 2;
				//append to alive;
				alive.push_back(temp);
			}
		}
		if ((!alive.empty())&&alive.begin()->len > max) {
			rstart = alive.begin()->start;
			max = alive.begin()->len;
		}


		return s.substr(rstart, max);
	}
};
