class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, step = 1;
        bool left = true;

        while (n > 1) {
            if (left || n % 2)
                head += step;
            n /= 2;
            step *= 2;
            left = !left;
        }

        return head;
    }
};