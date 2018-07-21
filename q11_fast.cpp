static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,upp=height.size()-1,max=0;
        while(upp>low){
            if(height[low]<height[upp]){
                if ((upp-low)*height[low]>max) max=(upp-low)*height[low];
                ++low;
            }else {
                if ((upp-low)*height[upp]>max) max=(upp-low)*height[upp];
                --upp;
            }
        }
        return max;
    }
};
