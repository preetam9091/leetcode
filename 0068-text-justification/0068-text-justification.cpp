#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> res;
        for (int i = 0, j; i < words.size(); i = j) {
            int width = 0;
            for (j = i; j < words.size() && width + words[j].size() + (j - i) <= maxWidth; ++j) {
                width += words[j].size();
            }
            int spaces = 1, extra = 0;
            if (j - i != 1 && j != words.size()) {
                spaces = (maxWidth - width) / (j - i - 1);
                extra = (maxWidth - width) % (j - i - 1);
            }
            std::string line = words[i];
            for (int k = i + 1; k < j; ++k) {
                line += std::string(spaces, ' ');
                if (extra-- > 0) line += " ";
                line += words[k];
            }
            line += std::string(maxWidth - line.size(), ' ');
            res.push_back(line);
        }
        return res;
    }
};