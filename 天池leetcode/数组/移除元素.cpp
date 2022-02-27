class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size() - 1;
        for (int i = 0; i <= j; i++) {
            if (nums[i] == val) {
                swap(nums[i--], nums[j--]);
            }
        }
        return j + 1;
    }
};

// 输入：nums = [3,2,2,3], val = 3
// 输出：2, nums = [2,2]