#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    unordered_map<string, vector<string>> adjList;
    unordered_map<string, int> visited;
    queue<string> q;

    dict.insert(beginWord);
    for (const string &word : dict) visited[word] = INT_MAX;

    q.push(beginWord);
    visited[beginWord] = 0;

    while (!q.empty()) {
        string word = q.front();
        q.pop();
        string temp = word;

        for (int i = 0; i < word.size(); i++) {
            char origChar = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (dict.count(word) && visited[word] >= visited[temp] + 1) {
                    visited[word] = visited[temp] + 1;
                    adjList[word].push_back(temp);
                    q.push(word);
                }
            }
            word[i] = origChar;
        }
    }

    vector<vector<string>> result;
    vector<string> path;
    function<void(string)> dfs = [&](string word) {
        path.push_back(word);
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            result.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            for (const string &prev : adjList[word]) dfs(prev);
        }
        path.pop_back();
    };

    if (visited[endWord] == INT_MAX) return {};
    dfs(endWord);
    return result;
}
