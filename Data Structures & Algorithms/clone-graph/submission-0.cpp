/*
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        Node* ans = new Node();
        ans->val = node->val;
        queue<Node*> q;
        unordered_map<Node*,Node*> mp;
        mp[node] = ans;
        q.push(node);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();        
            for(auto & it:temp->neighbors){
                if(mp.find(it) == mp.end()){
                    Node * x = new Node(it->val);
                    mp[it] = x;
                    q.push(it);
                }
                mp[temp]->neighbors.push_back(mp[it]);
            }
        }
        return mp[node];
    }
};