class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        vector<int> res;
        int maxx = INT_MIN;
        for(int i = 0; i < k; i++){
            maxx = max(nums[i], maxx);
        }
        res.push_back(maxx);
        for(int i = 1; i <= nums.size() - k; i++){
            if(nums[i + k - 1] > maxx){
                maxx = nums[i + k - 1];
                res.push_back(maxx);
                continue;
            }
            if(nums[i] == maxx){
                res.push_back(maxx);
                continue;
            }
            if(nums[i - 1] == maxx){
                maxx = INT_MIN;
                for(int j = 0; j < k; j++){
                    maxx = max(maxx, nums[i + j]);
                }
                res.push_back(maxx);
            }
            else {
                res.push_back(maxx);
            }
        }
        return res;
    }
};