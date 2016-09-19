// Shortest Word Distance
// hash table

#include <algorthim>
#include <limits>
#include <unordered_map>
#include <string>
#include <cmath>

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int minimum = numeric_limits<int>::max();
        unordered_map<string, int> map;
        for(int i = 0; i < words.size(); ++i) {
            string curWords = words[i];
            map[curWords] = i;
            if (curWords == word1 && map.count(word2)) {
                minimum = std::min(minimum, i - map[word2]);
            } else if (curWords == word2 && map.count(word1)) {
                minimum = std::min(minimum, i - map[word1]);
            }
        }
        return minimum;
    }
};

// Shortest Word Distance II
// repeated multiple time, how to optimize it
// remember getting the minimum, only use first phase of merge list

#include <unordered_map>
#include <algorithm>
#include <string>
#include <limits>
#include <cmath>

class WordDistance {
private:
    unordered_map<string, vector<int>> lst;
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i) {
            string word = words[i];
            lst[word].push_back(i);
        }    
    }

    int shortest(string word1, string word2) {
        vector<int> top = lst[word1];
        vector<int> bot = lst[word2];
        int i = 0, j = 0;
        int n = top.size(), m = bot.size();
        int best = numeric_limits<int>::max();
        int a, b;
        while(i < n && j < m) {
            if (top[i] < bot[j]) {
                a = top[i]; ++i;
                b = bot[j];
            } else {
                a = bot[j]; ++j;
                b = top[i];
            }
            best = min(best, abs(a - b));
        }
        
        return best;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

// Shortest Word Distance III
// overried result later

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int minimum = numeric_limits<int>::max();
        unordered_map<string, int> map;
        for(int i = 0; i < words.size(); ++i) {
            string curWords = words[i];
            if (curWords == word1 && map.count(word2)) {
                minimum = std::min(minimum, i - map[word2]);
            } else if (curWords == word2 && map.count(word1)) {
                minimum = std::min(minimum, i - map[word1]);
            }
            map[curWords] = i;
        }
        return minimum;
    }
};