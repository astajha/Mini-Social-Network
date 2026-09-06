==========================================================
              MINI SOCIAL NETWORK
==========================================================

Project Name:
-------------
Mini Social Network

Language Used:
--------------
C++

Concepts Used:
--------------
1. Graph (Adjacency List)
2. Breadth First Search (BFS)
3. Depth First Search (DFS)
4. Queue
5. Vector
6. Unordered Map
7. Unordered Set
8. Shortest Path Algorithm (BFS Based)
9. Friend Recommendation
10. Object Oriented Programming (OOP)

----------------------------------------------------------
Project Description
----------------------------------------------------------

Mini Social Network is a console-based C++ application that
simulates the basic functionalities of a social networking
platform.

The application allows users to create accounts, make friends,
display friend lists, find mutual friends, get friend
suggestions, traverse the social network using BFS and DFS,
and determine the shortest connection between two users.

The friendship network is represented using a Graph where
each user is considered as a vertex and each friendship is
considered as an edge.

----------------------------------------------------------
Project Folder Structure
----------------------------------------------------------

MiniProject/

│── main.cpp
│── SocialNetwork.h
│── SocialNetwork.cpp
│── README.txt

----------------------------------------------------------
How to Compile
----------------------------------------------------------

Open Terminal inside the project folder.

Compile the project using:

g++ main.cpp SocialNetwork.cpp -o main

----------------------------------------------------------
How to Run
----------------------------------------------------------

Windows

main.exe

OR

.\main.exe

Linux/Mac

./main

----------------------------------------------------------
Menu Options
----------------------------------------------------------

1. Add User
2. Remove User
3. Search User
4. Add Friend
5. Remove Friend
6. Display Users
7. Display Friends
8. Mutual Friends
9. Friend Suggestions
10. BFS Traversal
11. DFS Traversal
12. Shortest Path
13. Total Users
14. Exit

----------------------------------------------------------
Function Description
----------------------------------------------------------

1. Add User
-------------
Creates a new user in the social network.

2. Remove User
----------------
Deletes the selected user along with all existing friendships.

3. Search User
---------------
Searches whether a user exists or not.

4. Add Friend
---------------
Creates a friendship between two users.

5. Remove Friend
------------------
Removes friendship between two users.

6. Display Users
-----------------
Displays all registered users.

7. Display Friends
-------------------
Displays all friends of a selected user.

8. Mutual Friends
------------------
Finds common friends between two users.

9. Friend Suggestions
----------------------
Suggests new friends based on friends-of-friends concept.

10. BFS Traversal
------------------
Traverses the complete social network using Breadth First Search.

11. DFS Traversal
------------------
Traverses the complete social network using Depth First Search.

12. Shortest Path
------------------
Finds the minimum number of connections between two users.

13. Total Users
----------------
Displays the total number of registered users.

----------------------------------------------------------
Data Structure Used
----------------------------------------------------------

Graph
-----
Represents friendships.

Vector
------
Stores adjacency list.

Queue
-----
Used in BFS traversal.

Unordered Map
-------------
Stores graph representation.

Unordered Set
-------------
Keeps track of visited users.

----------------------------------------------------------
Algorithms Used
----------------------------------------------------------

1. BFS
2. DFS
3. Friend Suggestion
4. Mutual Friend Detection
5. Shortest Path using BFS

----------------------------------------------------------
Time Complexity
----------------------------------------------------------

Add User               O(1)

Remove User            O(V + E)

Search User            O(1)

Add Friend             O(F)

Remove Friend          O(F)

Display Users          O(V)

Display Friends        O(F)

Mutual Friends         O(F1 + F2)

Friend Suggestion      O(V + E)

BFS Traversal          O(V + E)

DFS Traversal          O(V + E)

Shortest Path          O(V + E)

Where:

V = Number of Users

E = Number of Friendships

F = Number of Friends

----------------------------------------------------------
Sample Execution
----------------------------------------------------------

Choice : 1

Enter User Name : Harsh

User Added Successfully.

Choice : 1

Enter User Name : Rahul

User Added Successfully.

Choice : 4

Enter First User : Harsh

Enter Second User : Rahul

Friend Added Successfully.

Choice : 7

Enter User Name : Harsh

Friends of Harsh

1. Rahul

Choice : 10

Enter Start User : Harsh

BFS Traversal

Harsh Rahul

----------------------------------------------------------
Expected Learning Outcomes
----------------------------------------------------------

• Understand Graph implementation using Adjacency List.

• Learn BFS and DFS traversal.

• Understand shortest path in an unweighted graph.

• Apply Object-Oriented Programming concepts.

• Implement real-world applications using Data Structures.

----------------------------------------------------------
Future Scope
----------------------------------------------------------

1. User Login System

2. File Handling

3. GUI Interface

4. Friend Request System

5. Chat Feature

6. Profile Management

7. Database Integration

8. Online Multi-user Support

==========================================================
                 END OF README
==========================================================# Mini-Social-Network
