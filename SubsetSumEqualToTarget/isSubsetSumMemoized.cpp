#include <iostream>
#include <vector>
using namespace std;

/**
 * There must be 2 base cases here as we are changing 2 entities while
 * recursing. Thus the function must have 2 different base cases 
 * to ensure recursion breaks for both the entities. 
 **/
bool isSubsetSumMemoized(vector<int> &nums, int index, int target, vector<vector<int> > &dp) {
	/**
	 * BASE CASE 1: Break recursion if at any point target becomes 0.
	 * Return true from this recursive call as we must not recurse further.
	 **/
	if (target == 0) {
		return true;
	}
	
	/**
	 * BASE CASE 2: Break recursion if we are at the other end of the array.
	 * In such a case, last element must be equal to the target to return true.
	 **/
	if (index == 0) {
		return (nums[0] == target);
	}
	
	if (dp[index][target] != -1) {
		return dp[index][target];
  }
	
	bool notPick = isSubsetSumMemoized(nums, index - 1, target, dp);
	bool pick = 0;
	if (nums[index] <= target)
		pick = isSubsetSumMemoized(nums, index - 1, target - nums[index], dp);

  /**
	 * We made 2 choices above to include or exclude the index, now if any
	 * one of the choice returns true, we return true
	 **/
	return dp[index][target] = pick | notPick;
}


int main() {
	vector<int> nums = { 3, 34, 4, 12, 5, 2 };
	int target = 9;
	int n = nums.size();
	
  vector<vector<int> > dp(n, vector<int>(target+1, -1));
	if (isSubsetSumMemoized(nums, n-1, target, dp) == true)
		cout <<"Found a subset with given target : " << target;
	else
		cout <<"No subset found with given target: " << target;
	return 0;
}