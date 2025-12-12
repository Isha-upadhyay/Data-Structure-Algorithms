class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);       // mention count
        vector<int> online(numberOfUsers, 1);         // 1 = online, 0 = offline
        vector<int> offlineUntil(numberOfUsers, 0);   // time when user comes back online

        // Correct sorting: sort by timestamp, and at the same timestamp:
        // OFFLINE must come BEFORE MESSAGE
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);

            if (timeA != timeB) return timeA < timeB;

            // Same timestamp:
            if (a[0] == b[0]) return false;  // stable: keep original order

            // OFFLINE < MESSAGE
            if (a[0] == "OFFLINE") return true;
            return false;
        });

        for (auto& event : events) {
            string type = event[0];
            int timestamp = stoi(event[1]);

            // Step 1: Before processing event, auto-online update
            for (int i = 0; i < numberOfUsers; i++) {
                if (online[i] == 0 && offlineUntil[i] <= timestamp) {
                    online[i] = 1;  // bring user back online
                }
            }

            // Step 2: Process event
            if (type == "OFFLINE") {
                int user = stoi(event[2]);
                online[user] = 0;
                offlineUntil[user] = timestamp + 60;
            }
            else { // MESSAGE event
                string msg = event[2];

                if (msg == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++)
                        mentions[i]++;
                }
                else if (msg == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++)
                        if (online[i] == 1)
                            mentions[i]++;
                }
                else {
                    // Parse idX tokens
                    stringstream ss(msg);
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
