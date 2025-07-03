class Solution {
public:
    char kthCharacter(int k) {
        int x =__builtin_popcount(k-1);
        return 'a' + x;
    }
};