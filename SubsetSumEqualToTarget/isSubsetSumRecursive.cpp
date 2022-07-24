#include <iostream>
#include <vector>
using namespace std;

/**
 * There must be 2 base cases here as we are changing 2 entities while
 * recursing. Thus the function must have 2 different base cases 
 * to ensure recursion breaks for both the entities. 
 **/
bool isSubsetSumRecursive(vector<int> &nums, int index, int target) {
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
		return nums[0] == target;
	}
	
	bool pick = false;
	if (nums[index] <= target)
		pick = isSubsetSumRecursive(nums, index - 1, target - nums[index]);
	
	bool notPick = isSubsetSumRecursive(nums, index - 1, target);
	
	/**
	 * We made 2 choices above to include or exclude the index, now if any
	 * one of the choice returns true, we return true
	 **/
	return pick | notPick;
}

int main() {
	vector<int> nums = { 3, 34, 4, 12, 5, 2 };
	int target = 9;
	int n = nums.size();
	
	if (isSubsetSumRecursive(nums, n-1, target) == true)
		cout <<"Found a subset with given target : " << target;
	else
		cout <<"No subset found with given target: " << target;
	return 0;
}