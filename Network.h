#ifndef PROJECTX_NETWORK_H
#define PROJECTX_NETWORK_H

#include "User.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Network {
        vector<User> users;
        vector<pair<int, int>> friends;
    public:
        Network();
        vector<User>& getUsers();
        void setUsers(vector<User>& users);
        vector<pair<int, int>>& getFriends();
        void setFriends(vector<pair<int, int>>& friends);
        // User CRUD Methods
        void printUsers();
        User createUser(std::string name, int age, std::string email, int id, vector<Post> posts);
        bool deleteUser(const User& removed);
        void updateUserName(User& old, std::string name);
        void updateUserAge(User& old, int age);
        void updateUserEmail(User& old, std::string email);
        void updateUserID(User& old, int id);
        void updateUserPosts(User& old, vector<Post> posts);
        // Friend Methods
        void addFriend(int userID1, int userID2);
        void removeFriend(int userID1, int userID2);
};

#endif //PROJECTX_NETWORK_H
