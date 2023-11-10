class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> processed, processed_2;
        int tmp = nums[0], ans = 0, tmp_sum = 0, corner = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            corner = max(corner, nums[i]);
            if (nums[i] * nums[i - 1] < 0 || (nums[i - 1] == 0 && nums[i] < 0) || (nums[i] == 0 && nums[i - 1] < 0)) {
                //Push back the current tmp
                cout << tmp << " ";
                processed.push_back(tmp);
                if (processed.size() == 1) {
                    if (tmp > 0) tmp_sum += tmp;
                    tmp = nums[i];
                    continue;
                }

                //Perform calculate
                if (tmp > 0) {
                    tmp_sum += tmp;
                }
                else {
                    ans = max(tmp_sum, ans);
                    if (tmp_sum + tmp < 0) {
                        tmp_sum = 0;
                    }
                    else {
                        tmp_sum += tmp;
                    }
                }
                cout << tmp_sum << endl;

                //Update tmp for next
                tmp = nums[i];
            }
            else tmp += nums[i];
        }
        processed.push_back(tmp);
        if (tmp > 0) tmp_sum += tmp;
        cout << tmp << " " << tmp_sum << endl;
        ans = max(tmp_sum, ans);
        if (processed.size() == 1) {
            return (processed[0] >= 0) ? processed[0] : corner;
        }
        return ans;
    }
};