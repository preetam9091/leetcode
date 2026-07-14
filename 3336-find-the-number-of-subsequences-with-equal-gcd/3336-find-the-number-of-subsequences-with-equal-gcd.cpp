#include <vector>
#include <numeric>

class Solution {
public:
    int subsequencePairCount(std::vector<int>& items) {
        int peak = 0;
        for (int item : items) {
            if (item > peak) {
                peak = item;
            }
        }
        
        const int limit = 1000000007;
        std::vector<std::vector<int>> state(peak + 1, std::vector<int>(peak + 1, 0));
        state[0][0] = 1;
        
        for (int item : items) {
            std::vector<std::vector<int>> next_state = state;
            for (int a = 0; a <= peak; ++a) {
                for (int b = 0; b <= peak; ++b) {
                    if (!state[a][b]) continue;
                    
                    int updated_a = std::gcd(a, item);
                    next_state[updated_a][b] = (next_state[updated_a][b] + state[a][b]) % limit;
                    
                    int updated_b = std::gcd(b, item);
                    next_state[a][updated_b] = (next_state[a][updated_b] + state[a][b]) % limit;
                }
            }
            state = std::move(next_state);
        }
        
        long long matches = 0;
        for (int g = 1; g <= peak; ++g) {
            matches = (matches + state[g][g]) % limit;
        }
        
        return static_cast<int>(matches);
    }
};