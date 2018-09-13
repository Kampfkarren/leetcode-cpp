#include <string>
#include <vector>
#include "debugging.h"

using std::string;

class Solution {
	public:
		string longestCommonPrefix(std::vector<string>& strings) {
			if(!strings.size())
				return "";
			string longestPrefix = strings.back(); strings.pop_back();

			for(string& text : strings) {
				int index = 1;
				string prefix = "";
				debug("%lu %lu\n", longestPrefix.size(), text.size());
				while(index <= longestPrefix.size() && index <= text.size()) {
					string current = text.substr(0, index);
					if(longestPrefix.substr(0, index) == current) {
						debug("new longest: %s\n", current.c_str());
						prefix = current;
						index++;
					} else
						break;
				}

				longestPrefix = prefix;
			}

			return longestPrefix;
		}
};

int main() {
	Solution s;
	std::vector<string> strings = { "flower", "flow", "flight" };
	debug("Answer: %s (should be fl)\n", s.longestCommonPrefix(strings).c_str());
	return 0;
}
