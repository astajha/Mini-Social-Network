#include "SocialNetwork.h"

//=====================================================
// Constructor
//=====================================================

SocialNetwork::SocialNetwork()
{
    graph.clear();
}

//=====================================================
// Add User
//=====================================================

void SocialNetwork::addUser(string name)
{
    if(searchUser(name))
    {
        cout << "\nUser already exists.\n";
        return;
    }

    graph[name] = vector<string>();

    cout << "\nUser added successfully.\n";
}

//=====================================================
// Remove User
//=====================================================

void SocialNetwork::removeUser(string name)
{
    if(!searchUser(name))
    {
        cout << "\nUser not found.\n";
        return;
    }

    // Remove this user from every friend's list
    for(auto &user : graph)
    {
        vector<string> &friends = user.second;

        friends.erase(
            remove(friends.begin(),
                   friends.end(),
                   name),
            friends.end()
        );
    }

    // Remove the user
    graph.erase(name);

    cout << "\nUser removed successfully.\n";
}

//=====================================================
// Search User
//=====================================================

bool SocialNetwork::searchUser(string name)
{
    return graph.find(name) != graph.end();
}

//=====================================================
// Display Users
//=====================================================

void SocialNetwork::displayUsers()
{
    if(graph.empty())
    {
        cout << "\nNo users found.\n";
        return;
    }

    cout << "\n=========== USERS ===========\n";

    int count = 1;

    for(auto user : graph)
    {
        cout << count << ". "
             << user.first
             << endl;

        count++;
    }

    cout << "=============================\n";
}

//=====================================================
// Total Users
//=====================================================

int SocialNetwork::totalUsers()
{
    return graph.size();
}

//=====================================================
// Add Friend
//=====================================================

void SocialNetwork::addFriend(string user1, string user2)
{
    // Check whether both users exist
    if(!searchUser(user1) || !searchUser(user2))
    {
        cout << "\nOne or both users do not exist.\n";
        return;
    }

    // Same user cannot become friend
    if(user1 == user2)
    {
        cout << "\nA user cannot become friend with themselves.\n";
        return;
    }

    // Check if already friends
    for(string friendName : graph[user1])
    {
        if(friendName == user2)
        {
            cout << "\nUsers are already friends.\n";
            return;
        }
    }

    // Add friendship in both directions
    graph[user1].push_back(user2);
    graph[user2].push_back(user1);

    cout << "\nFriend added successfully.\n";
}

//=====================================================
// Remove Friend
//=====================================================

void SocialNetwork::removeFriend(string user1, string user2)
{
    if(!searchUser(user1) || !searchUser(user2))
    {
        cout << "\nOne or both users do not exist.\n";
        return;
    }

    graph[user1].erase(
        remove(graph[user1].begin(),
               graph[user1].end(),
               user2),
        graph[user1].end()
    );

    graph[user2].erase(
        remove(graph[user2].begin(),
               graph[user2].end(),
               user1),
        graph[user2].end()
    );

    cout << "\nFriend removed successfully.\n";
}

//=====================================================
// Display Friends
//=====================================================

void SocialNetwork::displayFriends(string user)
{
    if(!searchUser(user))
    {
        cout << "\nUser not found.\n";
        return;
    }

    cout << "\n========== Friends of " << user << " ==========\n";

    if(graph[user].empty())
    {
        cout << "No Friends Found.\n";
        return;
    }

    int count = 1;

    for(string friendName : graph[user])
    {
        cout << count << ". " << friendName << endl;
        count++;
    }

    cout << "=====================================\n";
}

//=====================================================
// Mutual Friends
//=====================================================

void SocialNetwork::mutualFriends(string user1, string user2)
{
    if(!searchUser(user1) || !searchUser(user2))
    {
        cout << "\nOne or both users do not exist.\n";
        return;
    }

    unordered_set<string> friendsSet;

    // Store all friends of user1
    for(string friendName : graph[user1])
    {
        friendsSet.insert(friendName);
    }

    cout << "\nMutual Friends of "
         << user1 << " and "
         << user2 << ":\n";

    bool found = false;

    for(string friendName : graph[user2])
    {
        if(friendsSet.find(friendName) != friendsSet.end())
        {
            cout << friendName << endl;
            found = true;
        }
    }

    if(!found)
    {
        cout << "No Mutual Friends.\n";
    }
}

//=====================================================
// Breadth First Search (BFS)
//=====================================================

void SocialNetwork::BFS(string startUser)
{
    if(!searchUser(startUser))
    {
        cout << "\nUser not found.\n";
        return;
    }

    unordered_set<string> visited;
    queue<string> q;

    visited.insert(startUser);
    q.push(startUser);

    cout << "\nBFS Traversal:\n";

    while(!q.empty())
    {
        string current = q.front();
        q.pop();

        cout << current << " ";

        for(string neighbour : graph[current])
        {
            if(visited.find(neighbour) == visited.end())
            {
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }
    }

    cout << endl;
}

//=====================================================
// DFS Helper
//=====================================================

void SocialNetwork::DFSHelper(string user,
                              unordered_set<string> &visited)
{
    visited.insert(user);

    cout << user << " ";

    for(string neighbour : graph[user])
    {
        if(visited.find(neighbour) == visited.end())
        {
            DFSHelper(neighbour, visited);
        }
    }
}

//=====================================================
// Depth First Search (DFS)
//=====================================================

void SocialNetwork::DFS(string startUser)
{
    if(!searchUser(startUser))
    {
        cout << "\nUser not found.\n";
        return;
    }

    unordered_set<string> visited;

    cout << "\nDFS Traversal:\n";

    DFSHelper(startUser, visited);

    cout << endl;
}

//=====================================================
// Friend Suggestion
//=====================================================

void SocialNetwork::friendSuggestion(string user)
{
    if(!searchUser(user))
    {
        cout << "\nUser not found.\n";
        return;
    }

    unordered_set<string> directFriends;

    // Store all direct friends
    for(string friendName : graph[user])
    {
        directFriends.insert(friendName);
    }

    unordered_set<string> suggestions;

    // Find friends of friends
    for(string friendName : graph[user])
    {
        for(string fof : graph[friendName])
        {
            if(fof != user &&
               directFriends.find(fof) == directFriends.end())
            {
                suggestions.insert(fof);
            }
        }
    }

    cout << "\n========== Friend Suggestions ==========\n";

    if(suggestions.empty())
    {
        cout << "No Friend Suggestions Available.\n";
        return;
    }

    int count = 1;

    for(string person : suggestions)
    {
        cout << count << ". " << person << endl;
        count++;
    }

    cout << "========================================\n";
}

//=====================================================
// Shortest Path using BFS
//=====================================================

void SocialNetwork::shortestPath(string source,
                                 string destination)
{
    if(!searchUser(source) || !searchUser(destination))
    {
        cout << "\nOne or both users do not exist.\n";
        return;
    }

    unordered_set<string> visited;
    unordered_map<string, string> parent;
    queue<string> q;

    visited.insert(source);
    q.push(source);

    bool found = false;

    while(!q.empty())
    {
        string current = q.front();
        q.pop();

        if(current == destination)
        {
            found = true;
            break;
        }

        for(string neighbour : graph[current])
        {
            if(visited.find(neighbour) == visited.end())
            {
                visited.insert(neighbour);
                parent[neighbour] = current;
                q.push(neighbour);
            }
        }
    }

    if(!found)
    {
        cout << "\nNo Connection Exists.\n";
        return;
    }

    vector<string> path;

    string current = destination;

    while(current != source)
    {
        path.push_back(current);
        current = parent[current];
    }

    path.push_back(source);

    reverse(path.begin(), path.end());

    cout << "\n========== Shortest Path ==========\n";

    for(size_t i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if(i != path.size() - 1)
            cout << " -> ";
    }

    cout << "\nTotal Connections : " << path.size() - 1 << endl;
    cout << "===================================\n";
}

//=====================================================
// Network Statistics
//=====================================================

void SocialNetwork::networkStatistics()
{
    if(graph.empty())
    {
        cout << "\nNo Users Found.\n";
        return;
    }

    int totalUsers = graph.size();

    int totalFriendships = 0;

    string mostPopularUser = "";

    string leastPopularUser = "";

    int maxFriends = -1;

    int minFriends = INT_MAX;

    for(auto user : graph)
    {
        int friends = user.second.size();

        totalFriendships += friends;

        if(friends > maxFriends)
        {
            maxFriends = friends;
            mostPopularUser = user.first;
        }

        if(friends < minFriends)
        {
            minFriends = friends;
            leastPopularUser = user.first;
        }
    }

    totalFriendships /= 2;

    double averageFriends =
        (double)(totalFriendships * 2) / totalUsers;

    cout << "\n========================================\n";
    cout << "         NETWORK STATISTICS\n";
    cout << "========================================\n";

    cout << "Total Users          : " << totalUsers << endl;

    cout << "Total Friendships    : "
         << totalFriendships << endl;

    cout << "Average Friends/User : "
         << averageFriends << endl;

    cout << "Most Popular User    : "
         << mostPopularUser
         << " (" << maxFriends << " Friends)" << endl;

    cout << "Least Popular User   : "
         << leastPopularUser
         << " (" << minFriends << " Friends)" << endl;

    cout << "========================================\n";
}