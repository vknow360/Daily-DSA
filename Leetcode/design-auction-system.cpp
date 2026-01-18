class AuctionSystem
{
public:
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_map<int, set<pair<int, int>>> mx;
    AuctionSystem()
    {
    }

    void addBid(int userId, int itemId, int bidAmount)
    {
        auto &bidM = mp[itemId];
        if (bidM.find(userId) != bidM.end())
        {
            mx[itemId].erase({bidM[userId], userId});
        }
        bidM[userId] = bidAmount;
        mx[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount)
    {
        auto &bidM = mp[itemId];
        if (bidM.find(userId) != bidM.end())
        {
            mx[itemId].erase({bidM[userId], userId});
        }
        bidM[userId] = newAmount;
        mx[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId)
    {
        auto &bidM = mp[itemId];
        mx[itemId].erase({bidM[userId], userId});
        bidM.erase(userId);
    }

    int getHighestBidder(int itemId)
    {
        if (mx.find(itemId) == mx.end() || mx[itemId].empty())
            return -1;
        return (*(mx[itemId].rbegin())).second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */