
#include <iostream>
#include "SocialNetwork.h"

using namespace std;

int main()
{
    SocialNetwork sn;

    int choice;
    string user1, user2;

    do
    {
        cout << "\n=========================================\n";
        cout << "        MINI SOCIAL NETWORK\n";
        cout << "=========================================\n";
        cout << "1.  Add User\n";
        cout << "2.  Remove User\n";
        cout << "3.  Search User\n";
        cout << "4.  Add Friend\n";
        cout << "5.  Remove Friend\n";
        cout << "6.  Display All Users\n";
        cout << "7.  Display Friends\n";
        cout << "8.  Mutual Friends\n";
        cout << "9.  Friend Suggestions\n";
        cout << "10. BFS Traversal\n";
        cout << "11. DFS Traversal\n";
        cout << "12. Shortest Path\n";
        cout << "13. Network Statistics\n";
        cout << "14. Total Users\n";
        cout << "15. Exit\n";
        cout << "=========================================\n";

        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter User Name : ";
            cin >> user1;
            sn.addUser(user1);
            break;

        case 2:
            cout << "\nEnter User Name : ";
            cin >> user1;
            sn.removeUser(user1);
            break;

        case 3:
            cout << "\nEnter User Name : ";
            cin >> user1;

            if (sn.searchUser(user1))
                cout << "\nUser Found.\n";
            else
                cout << "\nUser Not Found.\n";

            break;

        case 4:
            cout << "\nEnter First User : ";
            cin >> user1;

            cout << "Enter Second User : ";
            cin >> user2;

            sn.addFriend(user1, user2);
            break;

        case 5:
            cout << "\nEnter First User : ";
            cin >> user1;

            cout << "Enter Second User : ";
            cin >> user2;

            sn.removeFriend(user1, user2);
            break;

        case 6:
            sn.displayUsers();
            break;

        case 7:
            cout << "\nEnter User Name : ";
            cin >> user1;
            sn.displayFriends(user1);
            break;

        case 8:
            cout << "\nEnter First User : ";
            cin >> user1;

            cout << "Enter Second User : ";
            cin >> user2;

            sn.mutualFriends(user1, user2);
            break;

        case 9:
            cout << "\nEnter User Name : ";
            cin >> user1;
            sn.friendSuggestion(user1);
            break;

        case 10:
            cout << "\nEnter Start User : ";
            cin >> user1;
            sn.BFS(user1);
            break;

        case 11:
            cout << "\nEnter Start User : ";
            cin >> user1;
            sn.DFS(user1);
            break;

        case 12:
            cout << "\nEnter Source User : ";
            cin >> user1;

            cout << "Enter Destination User : ";
            cin >> user2;

            sn.shortestPath(user1, user2);
            break;

        case 13:
            cout << "\nNetworkStatistics : ";
            sn.networkStatistics();
            break;


        case 14:
            cout << "\nTotal Users : " << sn.totalUsers() << endl;
            break;

        case 15:
            cout << "\nThank You for Using Mini Social Network!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

        if (choice != 15)
        {
            cout << "\n-----------------------------------------\n";
            cout << "Press Enter to Continue...";
            cin.ignore();
            cin.get();

#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
        }

    } while (choice != 15);

    return 0;
}



// #include "SocialNetwork.h"

// int main()
// {
//     SocialNetwork sn;

//     // Add Users
//     sn.addUser("Harsh");
//     sn.addUser("Rahul");
//     sn.addUser("Aman");
//     sn.addUser("Vivek");
//     sn.addUser("Rohit");
//     sn.addUser("Karan");

//     // Friendships
//     sn.addFriend("Harsh","Rahul");
//     sn.addFriend("Harsh","Aman");
//     sn.addFriend("Rahul","Vivek");
//     sn.addFriend("Rahul","Rohit");
//     sn.addFriend("Aman","Karan");

//     sn.displayUsers();

//     sn.displayFriends("Harsh");

//     sn.friendSuggestion("Harsh");

//     sn.shortestPath("Harsh","Vivek");

//     sn.BFS("Harsh");

//     sn.DFS("Harsh");

//     return 0;
// }