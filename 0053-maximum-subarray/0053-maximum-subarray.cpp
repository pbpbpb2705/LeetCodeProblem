class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> processed, processed_2;
        int tmp = nums[0], ans = 0, tmp_sum = 0, corner = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            corner = max(corner, nums[i]);
            if (nums[i] * nums[i - 1] < 0 || (nums[i - 1] == 0 && nums[i] < 0) || (nums[i] == 0 && nums[i - 1] < 0)) {
                processed.push_back(tmp);
                tmp = nums[i];
            }
            else tmp += nums[i];
        }
        processed.push_back(tmp);

        for (int i = 0; i < processed.size(); ++i) {
            if (processed[i] >= 0) tmp_sum += processed[i];
            else {
                if (i == processed.size() - 1) break;
                if (processed[i] + processed[i + 1] > 0 && processed[i] + tmp_sum > 0) tmp_sum += processed[i];
                else if (processed[i] + tmp_sum > 0) {
                    ans = max(ans, tmp_sum);
                    tmp_sum += processed[i];
                }
                else {
                    ans = max(ans, tmp_sum);
                    tmp_sum = 0;
                }
            }
            cout << processed[i] << endl;
        }
        ans = max(tmp_sum, ans);
        if (processed.size() == 1) {
            return (processed[0] >= 0) ? processed[0] : corner;
        }
        return ans;
    }
};