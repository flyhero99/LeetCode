class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int a[1000];
        deque<int> temp;
        for(int i = 0; i < deck.size(); i++) temp.push_back(i);
        for(int i = 0; i < deck.size(); i++) {
            a[temp.front()] = deck[i];
            temp.pop_front();
            if(!temp.empty()) {
                temp.push_back(temp.front());
                temp.pop_front();
            }
        }
        vector<int> ans;
        for(int i = 0; i < deck.size(); i++) ans.push_back(a[i]);
        return ans;
    }
};