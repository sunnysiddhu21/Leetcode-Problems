class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastSeen;  // Stores the last index of each card
        int ans = INT_MAX;
        int n = cards.size();
        
        for (int i = 0; i < n; ++i) {
            if (lastSeen.find(cards[i]) != lastSeen.end()) {
                // If the card was seen before, calculate the window size
                ans = min(ans, i - lastSeen[cards[i]] + 1);
            }
            lastSeen[cards[i]] = i;  // Update the last occurrence of the card
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
