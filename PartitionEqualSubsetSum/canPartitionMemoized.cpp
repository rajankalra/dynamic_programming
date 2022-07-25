#include <iostream>
#include <vector>
using namespace std;

bool canPartitionUtil(vector<int> &nums, int target, int index, vector<vector<int> > &dp) {
  if (target == 0)
      return true;
  
  if (index == 0)
      return nums[index] == target;

  if (dp[index][target] != -1)
    return dp[index][target];

  int pick = false;
  if (nums[index] <= target)
      pick = canPartitionUtil(nums, target - nums[index], index-1, dp);
  int notPick = canPartitionUtil(nums, target, index-1, dp);
  
  return dp[index][target] = pick | notPick;
}
    
bool canPartition(vector<int>& nums) {
  int n = nums.size();
  int sum = 0;
  for (int i=0; i<n; i++) {
      sum += nums[i];
  }
  
  if (sum % 2 != 0)
      return false;
  
  vector<vector<int> > dp(n, vector<int>((sum/2)+1, -1));
  return canPartitionUtil(nums, sum/2, n-1, dp);
}

int main()
{
  vector<int> nums = { 3, 1, 5, 9, 12 };  
  if (canPartition(nums) == true)
      cout << "Can be divided into two subsets of equal sum";
  else
      cout << "Can not be divided into two subsets of equal sum";
  return 0;
}