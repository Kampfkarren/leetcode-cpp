#include <stdexcept>
#include <vector>

using std::vector;

class Solution {
  public: 
    vector<int> twoSum(vector<int>& nums, int target) {
      for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
          if (nums[i] + nums[j] == target) {
            return { i, j };
          }
        }
      }

      throw std::runtime_error("Invalid inputs");
    }
};

int main() {
  Solution s;
  vector<int> input = { 2, 7, 11, 15 };
  vector<int> result = s.twoSum(input, 9);
  printf("%d %d\n", result[0], result[1]);
  return 0;
}
