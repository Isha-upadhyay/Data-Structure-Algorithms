//-----method-1-----

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        

        if (hand.size() % groupSize != 0) return false;

        map<int, int> count;
        for (int card : hand) count[card]++;

        for (auto [card, freq] : count) {
            if (freq > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (count[card + i] < freq) return false;
                    count[card + i] -= freq;
                }
            }
        }
        return true;
    }
};



//------method-2----




class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Map to store the count of each card value
        map<int, int> cardCount;

        for (int card : hand) {
            cardCount[card]++;
        }

        // Queue to keep track of new groups starting at each card value
        queue<int> groupStartQueue;
        int lastCard = -1, currentOpenGroups = 0;

        for (auto& entry : cardCount) {
            int currentCard = entry.first;
            int count = entry.second;

            // If there are open groups and we skipped some numbers
            // OR we don't have enough cards to continue open groups
            if ((currentOpenGroups > 0 && currentCard > lastCard + 1) ||
                currentOpenGroups > count) {
                return false;
            }

            // Calculate how many new groups start from this card
            int newGroups = count - currentOpenGroups;
            groupStartQueue.push(newGroups);

            // Update tracking variables
            lastCard = currentCard;
            currentOpenGroups = count;

            // If queue size == groupSize, that means the oldest groups
            // (which started groupSize cards ago) are now complete
            if (groupStartQueue.size() == groupSize) {
                currentOpenGroups -= groupStartQueue.front();
                groupStartQueue.pop();
            }
        }

        // If all groups are complete
        return currentOpenGroups == 0;
    }
};
