#include <vector>
#include <gtest/gtest.h>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int goal = nums.size() - 1;

        for (int i = goal - 1; i >= 0; --i)
        {
            const int max_jump = nums[i];

            if (i + max_jump >= goal)
            {
                goal = i;
            }
        }

        return goal == 0;
    }
};

TEST(JumpGame, Default)
{
    Solution s;
    std::vector<int> nums = {3, 0, 8, 2, 0, 0, 1};
    EXPECT_EQ(s.canJump(nums), true);
}
