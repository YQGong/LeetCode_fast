static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();
struct patt {
	char match=0;
	int mode=-1;
	int p;

	patt() {}
	~patt() {}

	void setp(int pin) { p = pin; }

	void setpatt(char matin, char modin) {
		match = matin;
		if (modin == '*') mode = 1;
	}

	void setpatt() {
		mode = -1;
	}

	void setpatt(char matin) {
		match = matin;
		mode = 0;
	}

	int matchq() { return mode; }

	int matchq(char in) {
		if (mode == -1) return 0;//代表需要读下一个patt
		if (match == '.' || in == match) {
			if (mode == 0) {
				mode = -1;
				return 1;//表示成功匹配
			}
			if (mode == 1) {
				return 2;//代表分叉
			}
		}
		if (mode == 1 && in != match) {
			mode = -1;
			return 0;//代表需要读下一个patt
		}
		return -1;//代表不匹配
	}

	int readpatt(string& s) {
		if (p >= s.size()) return -1;
		if (p == s.size() - 1) {
			setpatt(s[p]);
			p++;
			return 0;
		}
		if (p + 1<s.size()) {
			if (s[p + 1] != '*') {
				if ((s[p]>64 && s[p]<91) || (s[p]>96 && s[p]<123) || s[p] == '.') {
					setpatt(s[p]);
					p++;
				}
				else {
					mode = -1;
					p++;
				}
			}
			else if (s[p + 1] == '*') {
				if ((s[p]>64 && s[p]<91) || (s[p]>96 && s[p]<123) || s[p] == '.') {
					setpatt(s[p], '*');
					p += 2;
				}
				else {
					mode = -1;
					p += 2;
				}
			}
			return 0;
		}
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {
		list<patt> pattlist;
		int sp(0), pp(0);

		patt initpatt;
		initpatt.setp(sp);
		pattlist.push_back(initpatt);

		while (sp < s.size()) {
			for (list<patt>::iterator it = pattlist.begin(); it != pattlist.end();) {
				while (true) {
					int index = it->matchq(s[sp]);
					if (index == -1) {
						it = pattlist.erase(it);
						if (pattlist.empty()) {
							it = pattlist.end();
						}
						break;//deleted
					}
					if (index == 0) {
						if (it->readpatt(p) == -1) {
							it = pattlist.erase(it);
							if (pattlist.empty()) {
								it = pattlist.end();
							}
							break;//deleted
						}
					}
					if (index == 1) {
						if (it != pattlist.end()) {
							++it;
						}
						break;//mode:-1
					}
					if (index == 2) {
						patt temppatt = *it;
						temppatt.setpatt();
						pattlist.push_back(temppatt);
						if (it != pattlist.end()) {
							++it;
						}
						break;//mode:1
					}
				}
			}
			sp++;
		}
		for (list<patt>::iterator it = pattlist.begin(); it != pattlist.end();) {
			if (it->p == p.size()) return true;
			while (true) {
				if (it->readpatt(p)==-1) {
					if (it->matchq() == 1) {
						return true;
					}
					else {
						if (it != pattlist.end()) {
							++it;
						}
						break;
					}

				}
				if (it->matchq() != 1) {
					if (it != pattlist.end()) {
						++it;
					}
					break;
				}
			}
		
		}
		return false;
	}
};
