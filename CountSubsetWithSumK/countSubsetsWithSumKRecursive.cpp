#include <iostream>
#include <vector>
using namespace std;

/**
 * 1. There must be 2 base cases here as we are changing 2 entities while
 * recursing. Thus the function must have 2 different base cases 
 * to ensure recursion breaks for both the entities. 
 * 2. This implementation doesn't account for the case when set has 0s.
 **/
int countSubsetsWithSumKRecursive(vector<int> &nums, int target, int index) {
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
 
	int exclude = countSubsetsWithSumKRecursive(nums, target, index-1);
	int include = 0;
	if (nums[index] <= target) {
		include = countSubsetsWithSumKRecursive(nums, target - nums[index], index-1);
  }

	return include + exclude;
}
 
int main() {
	vector<int> nums = { 1, 2, 3, 4, 5 };
	int n = nums.size();
	int target = 9;
  cout << "Num of subsets with sum as " << target << ": " << countSubsetsWithSumKRecursive(nums, target, n - 1);
	return 0;
}
