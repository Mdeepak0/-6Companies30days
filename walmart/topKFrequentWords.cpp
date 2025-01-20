class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Step 1: Count the frequency of each word
        unordered_map<string, int> wordCount;
    for (const string& word : words) {
        wordCount[word]++;
    }

    // Step 2: Use a priority queue to sort the words by frequency and lexicographical order
    auto compare = [](pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first; // If frequencies are equal, sort lexicographically
        }
        return a.second < b.second; // Sort by frequency
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> maxHeap(compare);

    // Step 3: Add all words with their frequencies to the priority queue
    for (const auto& entry : wordCount) {
        maxHeap.push(entry);
    }

    // Step 4: Extract the top k elements from the heap
    vector<string> result;
    while (k-- > 0 && !maxHeap.empty()) {
        result.push_back(maxHeap.top().first);
        maxHeap.pop();
    }

    return result;

    }
};
