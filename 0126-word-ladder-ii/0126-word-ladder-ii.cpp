#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
    std::unordered_map<std::string, std::vector<std::string>> adj;
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> path;

    void dfs(std::string& word, std::string& beginWord) {
        if (word == beginWord) {
            std::vector<std::string> temp = path;
            std::reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for (std::string& p : adj[word]) {
            path.push_back(p);
            dfs(p, beginWord);
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {};

        std::unordered_set<std::string> current_layer;
        current_layer.insert(beginWord);
        bool found = false;

        while (!current_layer.empty() && !found) {
            for (const std::string& word : current_layer) dict.erase(word);
            std::unordered_set<std::string> next_layer;

            for (std::string word : current_layer) {
                std::string original = word;
                for (int i = 0; i < word.size(); i++) {
                    char c = word[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        if (dict.find(word) != dict.end()) {
                            next_layer.insert(word);
                            adj[word].push_back(original);
                            if (word == endWord) found = true;
                        }
                    }
                    word[i] = c;
                }
            }
            current_layer = next_layer;
        }

        if (found) {
            path.push_back(endWord);
            dfs(endWord, beginWord);
        }
        return ans;
    }
};