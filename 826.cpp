#include "debugging.h"
#include <vector>

using std::vector;

class Solution {
	public:
		int maxProfitAssignment(vector<int>& jobDifficulties, vector<int>& profit, vector<int>& workers) {
			int jobCount = jobDifficulties.size();
			int sum = 0;

			for(int& workersSkill : workers) {
				int highestPayingJob = 0;

				for(int index = 0; index < jobCount; index++) {
					if(jobDifficulties[index] <= workersSkill) {
						int paid = profit[index];
						highestPayingJob = (highestPayingJob > paid) ? highestPayingJob : paid;
					}
				}

				sum += highestPayingJob;
			}

			return sum;
		}
};

int main() {
	Solution s;
	vector<int> difficulty = { 2, 4, 6, 8, 10 };
	vector<int> profit = { 10, 20, 30, 40, 50, 60 };
	vector<int> workers = { 4, 5, 6, 7 };
	printf("got %d, expected 100\n", s.maxProfitAssignment(difficulty, profit, workers));
}
