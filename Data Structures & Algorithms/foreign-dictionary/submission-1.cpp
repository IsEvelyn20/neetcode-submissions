class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for(string& word : words) {
            for(char ch : word) {
                adj[ch] = unordered_set<char>();
                indegree[ch] = 0;
            }
        }

        for(int i = 0; i < words.size() - 1; i ++) {
            string w1 = words[i], w2 = words[i + 1];
            int len1 = w1.length(), len2 = w2.length();
            int minlen = min(len1, len2);

            if(len1 > len2 && w1.substr(0, minlen) == w2.substr(0, minlen)) {
                return "";
            }

            for(int j = 0; j < minlen; j ++) {
                if(w1[j] != w2[j]) {
                    if(!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]] ++;
                    }
                    break;
                }
            }
        }

        string res;
        queue<char> q;
        for(auto& [ch, deg] : indegree) {
            if(deg == 0) {
                q.push(ch);
            }
        }

        while(!q.empty()) {
            char ch = q.front(); q.pop();
            res += ch;
            for(auto& nei : adj[ch]){
                indegree[nei] --;
                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        return res.size() == indegree.size() ? res : "";
        
    }
};
