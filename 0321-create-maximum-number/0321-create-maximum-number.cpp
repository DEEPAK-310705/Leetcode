class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;
        for (int num : nums) {
            while (!st.empty() &&
                   remove > 0 &&
                   st.back() < num) {
                st.pop_back();
                remove--;
            }
            st.push_back(num);
        }
        while (remove > 0) {
            st.pop_back();
            remove--;
        }
        return st;
    }
    bool greater(vector<int>& a, int i,
                 vector<int>& b, int j) {
        while (i < a.size() && j < b.size() &&
               a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == b.size())
            return true;
        if (i < a.size() && a[i] > b[j])
            return true;
        return false;
    }
    vector<int> merge(vector<int>& a,
                      vector<int>& b) {
        vector<int> result;
        int i = 0;
        int j = 0;
        while (i < a.size() || j < b.size()) {
            if (greater(a, i, b, j)) {
                result.push_back(a[i]);
                i++;
            }
            else {
                result.push_back(b[j]);
                j++;
            }
        }

        return result;
    }
    bool isGreater(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                return a[i] > b[i];
        }
        return false;
    }
    vector<int> maxNumber(vector<int>& nums1,
                          vector<int>& nums2,
                          int k) {
        vector<int> answer;

        int m = nums1.size();
        int n = nums2.size();
        int start = max(0, k - n);
        int end = min(k, m);
        for (int x = start; x <= end; x++) {
            int y = k - x;
            vector<int> a =
                maxSubsequence(nums1, x);
            vector<int> b =
                maxSubsequence(nums2, y);
            vector<int> candidate =
                merge(a, b);
            if (answer.empty() ||
                isGreater(candidate, answer)) {
                answer = candidate;
            }
        }
        return answer;
    }
};