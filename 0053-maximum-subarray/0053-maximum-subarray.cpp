class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp = nums[0], ans = 0, tmp_sum = 0, corner = nums[0];
        bool isCorner = true;
        for (int i = 1; i < nums.size(); ++i) {
            corner = max(corner, nums[i]);
            if (nums[i] * nums[i - 1] < 0 || (nums[i - 1] == 0 && nums[i] < 0) || (nums[i] == 0 && nums[i - 1] < 0)) {
                if (isCorner) isCorner = false;
                //Perform calculation
                if (tmp > 0) {
                    tmp_sum += tmp;
                }
                else {
                    ans = max(tmp_sum, ans);
                    tmp_sum = (tmp_sum + tmp > 0) ? tmp_sum + tmp : 0;
                }
                //Update tmp for next
                tmp = nums[i];
            }
            else tmp += nums[i];
        }
        if (tmp > 0) tmp_sum += tmp;
        ans = max(tmp_sum, ans);
        if (isCorner) {
            return (nums[0] >= 0) ? ans : corner;
        }
        return ans;
    }
};