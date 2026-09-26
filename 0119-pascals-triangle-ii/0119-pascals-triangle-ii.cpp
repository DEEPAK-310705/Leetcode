class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long res = 1;
        for (int i = 0; i <= rowIndex; i++) {
            ans.push_back((int)res);
            res = res * (rowIndex - i) / (i + 1);
        }
        return ans;
    }
};