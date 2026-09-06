#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include<climits>

using namespace std;

class SocialNetwork
{
private:
    // Graph Representation (Adjacency List)
    unordered_map<string, vector<string>> graph;

    // Helper function for DFS
    void DFSHelper(string user, unordered_set<string> &visited);

public:
    // Constructor
    SocialNetwork();

    // ===========================
    // User Management
    // ===========================
    void addUser(string name);
    void removeUser(string name);
    bool searchUser(string name);
    void networkStatistics();
    void displayUsers();
    int totalUsers();

    // ===========================
    // Friendship Management
    // ===========================
    void addFriend(string user1, string user2);
    void removeFriend(string user1, string user2);
    void displayFriends(string user);

    // ===========================
    // Graph Algorithms
    // ===========================
    void mutualFriends(string user1, string user2);
    void friendSuggestion(string user);
    void BFS(string startUser);
    void DFS(string startUser);
    void shortestPath(string source, string destination);
};

#endif