static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	static int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int r(0), target(0);
		if (A.size()<1) return r;
		if (B.size()<1) return r;
		if (C.size()<1) return r;
		if (D.size()<1) return r;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		sort(C.begin(), C.end());
		sort(D.begin(), D.end());
		int lowbound = B[0] + C[0] + D[0];
		int uppbound = B[B.size() - 1] + C[C.size() - 1] + D[D.size() - 1];
		for (int i1 = 0; i1 < A.size(); ++i1) {
			if (A[i1] + lowbound > target) break;
			if (A[i1] + uppbound < target) continue;
			int end = D.size() - 1;
			int lowbound2 = C[0] + D[0];
			int uppbound2 = C[C.size() - 1] + D[end];
			for (int i2 = 0; i2 < B.size(); ++i2) {
				if (A[i1] + B[i2] + lowbound2 > target) break;
				if (A[i1] + B[i2] + uppbound2 < target) continue;
				while (A[i1] + B[i2] + C[0] + D[end] > target) --end;
				int j = 0, k = end;
				while (j<C.size() && k >= 0) {
					int sum = A[i1] + B[i2] + C[j] + D[k];
					if (sum == target) {
						int xflag(1);
						while (k > 0 && D[k - 1] == D[k]) {
							--k;
							++xflag;

						}
						int yflag(1);
						while (j<C.size() - 1 && C[j + 1] == C[j]) {
							++j;
							++yflag;
						}
						--k;
						++j;
						r += xflag * yflag;
					}
					if (sum > target) {
						k--;
						while (k>0 && D[k + 1] == D[k]) {
							k--;
						}
					}
					if (sum < target) {
						j++;
						while ((j < D.size())&&(C[j - 1] == C[j])) {
							j++;
						}
					}
				}

			}
		}
		return r;

	}
};
