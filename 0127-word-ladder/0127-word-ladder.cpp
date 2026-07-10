#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        
        std::queue<std::string> q;
        q.push(beginWord);
        int steps = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                std::string word = q.front();
                q.pop();
                
                if (word == endWord) return steps;
                
                for (int j = 0; j < word.size(); ++j) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = original;
                }
            }
            steps++;
        }
        return 0;
    }
};