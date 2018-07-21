static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
	static vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> r;
		if (nums.size()<4) return r;
		sort(nums.begin(), nums.end());
		int end = nums.size() - 1;
		int i1 = 0, i2 = end;
		for (; i1 < nums.size() - 3; ++i1) {
			if (nums[i1]+nums[i1+1]+nums[i1+2]+nums[i1+3] > target) break;
			end = nums.size() - 1;
			if (nums[i1] + nums[end - 2] + nums[end - 1] + nums[end] < target) continue;
			for (i2 = i1 + 1; i2 < nums.size() - 2; ++i2) {
				if (nums[i1] + nums[i2] +nums[i2+1] +nums[i2+2] > target) break;
				if (nums[i1] + nums[i2] + nums[i2 + 1] + nums[end] > target) --end;
				int j = i2 + 1;
				int k = end;
				while (j < k) {
					int sum = nums[i1] + nums[i2] + nums[j] + nums[k];
					if (sum == target) {
						r.push_back({ nums[i1],nums[i2], nums[j], nums[k] });
					}
					if (sum > target) {
						//k指向下一个可能的数值，跳过所有相同的可能性，如果停止在j的位置说明此处的i已经扫完了。
						k--;
						while (nums[k + 1] == nums[k] && j < k) {
							k--;
						}
					}
					if (sum <= target) {
						//j指向下一个可能的数值，跳过所有相同的可能性，如果停止在k的位置说明此处的i已经扫完了。
						j++;
						while (nums[j - 1] == nums[j] && j < nums.size()) {
							j++;
						}
					}
				}
				while (nums[i2 + 1] == nums[i2] && i2<nums.size()) {
					i2++;
				}

			}
			while (nums[i1 + 1] == nums[i1] && i1<nums.size()) {
				i1++;
			}
		}
		return r;
	}
};
