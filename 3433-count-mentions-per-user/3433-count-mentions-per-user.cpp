class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        unordered_map<int, int> offlineMap;
        unordered_set<int> onlineUsers;
        for (int i = 0; i < numberOfUsers; i++) {
            onlineUsers.insert(i);
        }

        sort(events.begin(), events.end(), [](vector<string>& a, vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA != timeB) return timeA < timeB;
            return a[0] == "OFFLINE" ? true : false;
        });

        int currTime = 0;

        for (auto& event : events) {
            string eventType = event[0];
            int timestamp = stoi(event[1]);
            string data = event[2];

            if (timestamp > currTime) {
                currTime = timestamp;

                vector<int> toRemove;
                for (auto& entry : offlineMap) {
                    int userId = entry.first;
                    int offlineTime = entry.second;

                    if (currTime - offlineTime >= 60) {
                        toRemove.push_back(userId);
                        onlineUsers.insert(userId);
                    }
                }

                for (int userId : toRemove) {
                    offlineMap.erase(userId);
                }
            }

            if (eventType == "OFFLINE") {
                int userId = stoi(data);
                onlineUsers.erase(userId);
                offlineMap[userId] = currTime;
            } else if (eventType == "MESSAGE") {
                if (data == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentions[i]++;
                    }
                } else if (data == "HERE") {
                    vector<int> toRemove;
                    for (auto& entry : offlineMap) {
                        int userId = entry.first;
                        int offlineTime = entry.second;

                        if (currTime - offlineTime >= 60) {
                            toRemove.push_back(userId);
                            onlineUsers.insert(userId);
                        }
                    }

                    for (int userId : toRemove) {
                        offlineMap.erase(userId);
                    }

                    for (int userId : onlineUsers) {
                        mentions[userId]++;
                    }
                } else {
                    stringstream ss(data);
                    string token;
                    while (ss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userId = stoi(token.substr(2));
                            mentions[userId]++;
                        }
                    }
                }
            }
        }

        return mentions;
    }
};