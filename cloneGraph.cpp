#include <vector>


using std::vector;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* dfs(Node* c, unordered_map<Node*, Node*>& mp ) {

        vector<Node* > neighbor;
        Node* clone = new Node(c->val);
    }

    Node* cloneGraph(Node* node) {
        
    }
};