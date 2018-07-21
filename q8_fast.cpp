static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
	int myAtoi(string str) {
		long long r(0),sign(1),digits(0);
		int p(-1),len=str.size();
		//while (p<len&&str[++p] == '"');
		while (p<len&&str[++p] == ' ');
		if (p >= len) return 0;
		if (str[p] == '+') {
            p++;
			//while (p<len&&str[++p] == ' ');
		} else if (str[p] == '-') {
            p++;
			sign = -1;
			//while (p<len&&str[++p] == ' ');
		}
		if (p >= len) return 0;
		if (str[p] < 47 && str[p] > 58) return 0;
		while (true) {
			if (str[p] > 47 && str[p] < 58 && digits < 12) {
				r *= 10;
				r += str[p] - 48;
				if(r!=0) digits += 1;
			}
			else {
				break;
			}
			if (++p >= len) break;
		}
		if (((sign*r) < INT_MIN)||(digits>=12&&sign<0)) {
			return INT_MIN;
		}
		if (((sign*r) > INT_MAX) || (digits >= 12 && sign>0)) {
			return INT_MAX;
		}
		return sign*r;
	}
};
