/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <queue>
#include <vector>

class Solution {
	public:
		std::vector<std::vector<int>> levelOrder(Node* root) {
			std::vector<std::vector<int>> result;
			if(NULL == root) // why is this a leetcode input?
				return result;
			std::queue<Node*> nextLevel;
			nextLevel.push(root);
			int length = 0;
			while((length = nextLevel.size())) {
				std::vector<int> thisLevel;
				for(int i = 0; i < length; i++) {
					Node* node = nextLevel.front();
					for(Node*& child : node->children) {
						nextLevel.push(child);
					}
					thisLevel.push_back(node->val);
					nextLevel.pop();
				}
				result.push_back(thisLevel);
			}
			return result;
		}
};
