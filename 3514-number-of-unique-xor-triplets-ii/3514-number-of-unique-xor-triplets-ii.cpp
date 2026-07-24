class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        int limit = 1;
        while (limit <= max_val) {
            limit <<= 1;
        }
        
        vector<uint8_t> has_num(limit, 0);
        vector<int> unique_nums;
        for (int x : nums) {
            if (!has_num[x]) {
                has_num[x] = 1;
                unique_nums.push_back(x);
            }
        }
        
        vector<uint8_t> has_pair(limit, 0);
        vector<int> unique_pairs;
        
        int n = unique_nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int pair_xor = unique_nums[i] ^ unique_nums[j];
                if (!has_pair[pair_xor]) {
                    has_pair[pair_xor] = 1;
                    unique_pairs.push_back(pair_xor);
                }
            }
        }
        
        vector<uint8_t> has_triplet(limit, 0);
        int unique_triplets_count = 0;
        
        for (int p_xor : unique_pairs) {
            for (int x : unique_nums) {
                int triplet_xor = p_xor ^ x;
                if (!has_triplet[triplet_xor]) {
                    has_triplet[triplet_xor] = 1;
                    unique_triplets_count++;
                }
            }
        }
        
        return unique_triplets_count;
    }
};