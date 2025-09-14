class Solution
{
public:
    bool isNStraightHand(std::vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        
        map<int, int> cardCount;
        for (int card : hand)
            cardCount[card]++;

        while (!cardCount.empty())
        {
            int startCard = cardCount.begin()->first;
            // Remove cards from the map to form a valid group
            for (int i = 0; i < groupSize; i++)
            {
                int currentCard = startCard + i;
                if (cardCount.find(currentCard) == cardCount.end())
                    return false;
                // Decrease the frequency of the current card
                cardCount[currentCard]--;
                if (cardCount[currentCard] == 0)
                    cardCount.erase(currentCard);
            }
        }
        
        return true;
    }
};