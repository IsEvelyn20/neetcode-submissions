class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited;
    string res;

    string foreignDictionary(vector<string>& words) {
        for(auto& word : words) {
            for(char ch : word) {
                adj[ch];
            }
        }

        for(int i = 0; i < words.size() - 1; i ++) {
            string& w1 = words[i], w2 = words[i + 1];
            int len1 = w1.length(), len2 = w2.length();
            int minlen = min(len1, len2);

            if(len1 > len2 && w1.substr(0, minlen) == w2.substr(0, minlen)) {
                return "";
            }
            for(int j = 0; j < minlen; j ++) {
                if(w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        for(auto pair : adj) {
            char ch = pair.first;
            if(!dfs(ch)) {
                return "";
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(char ch) {
        if(visited.find(ch) != visited.end()) {
            return !visited[ch];
        }
        visited[ch] = true;
        for(char nei : adj[ch]) {
            if(!dfs(nei)) {
                return false;
            }
        }
        visited[ch] = false;
        res.push_back(ch);
        return true;
    }
};
