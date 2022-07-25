#include <iostream>
#include <vector>
using namespace std;

/**
 * 1. There must be 2 base cases here as we are changing 2 entities while
 * recursing. Thus the function must have 2 different base cases 
 * to ensure recursion breaks for both the entities. 
 * 2. This implementation doesn't account for the case when set has 0s.
 **/
int countSubsetsWithSumKMemoized(vector<int> &nums, int target, int index, vector<vector<int> > &dp) {
  /**
	 * BASE CASE 1: Break recursion if at any point target becomes 0.
	 * Return 1 from this recursive call as we must not recurse further.
	 **/
	if (target == 0) {
		return 1;
	}
 
  /**
   * BASE CASE 2: Break recursion if we are at the other end of the array.
   * In such a case, last element must be equal to the target to return 1.
   **/
	if (index == 0) {
		return nums[0] == target ? 1 : 0;
	}

  if (dp[index][target] != -1) {
		return dp[index][target];
	}
 
	int exclude = countSubsetsWithSumKMemoized(nums, target, index-1, dp);
	int include = 0;
	if (nums[index] <= target) {
		include = countSubsetsWithSumKMemoized(nums, target - nums[index], index-1, dp);
  }

	return dp[index][target] = include + exclude;
}
 
int main() {
	vector<int> nums = { 1, 2, 3, 4, 5 };
	int n = nums.size();
	int target = 9;

  vector<vector<int> > dp(n, vector<int>(target+1, -1));
  cout << "Num of subsets with sum as " << target << ": " << countSubsetsWithSumKMemoized(nums, target, n - 1, dp);
	return 0;
}
