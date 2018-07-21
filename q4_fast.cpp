static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();
class interval {
public:
	int upp, low, len;
	vector<int>& pvect;
	interval(vector<int>& vect) :pvect(vect), upp(vect.size() - 1), len(vect.size()), low(0) {}
};
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		interval m(nums1), n(nums2);
		interval* tm = NULL, *tn = NULL, *temp = NULL;
		int mid1, mid2, id1(0), id2(0), mytry, posi, index, k(0);
		tm = (interval*)&m;
		tn = (interval*)&n;

		if (nums1.size() == 0) return (tn->pvect[tn->len >> 1] + tn->pvect[tn->len - (tn->len >> 1) - 1]) / 2.;
		if (nums2.size() == 0) return (tm->pvect[tm->len >> 1] + tm->pvect[tm->len - (tm->len >> 1) - 1]) / 2.;

		while (id1 != 1 || id2 != 1) {
			if (tm->upp < tm->low) {
				temp = tm;
				tm = tn;
				tn = temp;
				continue;
			}
			mytry = tm->pvect[tm->low + ((tm->upp - tm->low + 1) >> 1)];
			posi = myfind(mytry, tn->pvect, k);
			index = (tm->len - (tm->low + ((tm->upp - tm->low + 1) >> 1)) - 1 + (tn->len - posi - k) - ((tm->low + ((tm->upp - tm->low + 1) >> 1)) + posi));
			if (index>k) {
				tm->low = tm->low + ((tm->upp - tm->low + 1) >> 1);
				tn->low = posi;
				if (index == k+1) {
					mid1 = mytry;
					id1 = 1;
					if (id2 == 1) break;
				}
			}
			else if (index<-k) {
				tm->upp = tm->low + ((tm->upp - tm->low + 1) >> 1) - 1;
				tn->upp = posi - 1;
				if (index == -k-1) {
					mid2 = mytry;
					id2 = 1;
					if (id1 == 1) break;
				}
			}
			else {
				mid1 = mytry;
				mid2 = mytry;
				id1 = 1;
				id2 = 1;
				break;
			}
			temp = tm;
			tm = tn;
			tn = temp;
		}
		return (mid1 + mid2) / 2.;
	}
	int myfind(int mytry, vector<int>& nums1, int & k) {
		int upp = nums1.size()-1, low = 0;
		while ((nums1[upp] != mytry || nums1[low] != mytry)&&upp>low) {
			if (nums1[low +((upp - low) >> 1)] < mytry) low = low + ((upp - low) >> 1) + 1;
			else upp = low + ((upp - low) >> 1);
		}
		upp = low;
		while (nums1[upp] == mytry ) {
			++upp;
			if (upp == nums1.size()) break;
		}
		k = upp - low;
		return nums1[low]<mytry?low+1:low;
	}
};
