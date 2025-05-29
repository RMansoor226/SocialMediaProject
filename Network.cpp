#include "Network.h"
#include <utility>

Network::Network() {
    users = {};
}

vector<User>& Network::getUsers() {
    return users;
}

void Network::setUsers(vector<User>& users) {
    this->users = std::move(users);
}

vector<pair<int, int>>& Network::getFriends() {
    return friends;
}

void Network::setFriends(vector<pair<int, int>>& friends) {
    this->friends = std::move(friends);
}

void Network::printUsers() {
    for (int i=0; i<users.size(); i++) {
        std::cout << "Name: " << users[i].getName() << std::endl;
        std::cout << "Age: " << users[i].getAge() << std::endl;
        std::cout << "Email: " << users[i].getEmail() << std::endl;
        std::cout << "ID: " << users[i].getID() << std::endl;
        std::cout << "Posts: " << std::endl;
        for (int j=0; j < users[i].getPosts().size(); j++) {
            users[i].printPosts();
        }
        std::cout << std::endl;
    }

}

User Network::createUser(std::string name, int age, std::string email, int id, vector<Post> posts) {
    // Input validation
    if (age <= 0) {
        std::cerr << "Age cannot be 0 or less." << std::endl;
        return User();
    }
    if (id < 0) {
        std::cerr << "ID cannot be negative." << std::endl;
        return User();
    }
    if (name.empty()) {
        std::cerr << "Name cannot be empty." << std::endl;
        return User();
    }
    if (email.empty()) {
        std::cerr << "Email cannot be empty." << std::endl;
        return User();
    }

    // Linear Search to check if the user already exists
    for (auto & user : users) {
        if (user.getName() == name) {
            std::cerr << "User with this name already exists." << std::endl;
            return User();
        }
        if (user.getEmail() == email) {
            std::cerr << "User with this email already exists." << std::endl;
            return User();
        }
        if (user.getID() == id) {
            std::cerr << "User with this ID already exists." << std::endl;
            return User();
        }
    }

    // Create a new user
    User newUser = User(std::move(name), age, std::move(email), id, std::move(posts));

    // Add the new user to the vector of Users
    users.push_back(newUser);
    return newUser;
}

bool Network::deleteUser(const User& removed) {
    auto it = std::find(users.begin(), users.end(), removed);
    if (it != users.end()) {
        users.erase(it);
        return true;
    }
    return false;
}

void Network::updateUserName(User& old, std::string name) {
    for (auto & user : users) {
        if (user.getID() == old.getID()) {
            old.setName(name);
        }   else {
            continue;
        }
        if (user.getName() == name) {
            std::cerr << "User with this name already exists." << std::endl;
            return;
        }
    }
}

void Network::updateUserAge(User& old, int age) {
    for (auto & user : users) {
        if (user.getID() == old.getID()) {
            old.setAge(age);
        }   else {
            continue;
        }
        if (user.getAge() <=0 ) {
            std::cerr << "Invalid Age." << std::endl;
            return;
        }
    }
}

void Network::updateUserEmail(User& old, std::string email) {
    for (auto & user : users) {
        if (user.getID() == old.getID()) {
            old.setEmail(email);
        }   else {
            continue;
        }
        if (user.getEmail() == email) {
            std::cerr << "User with this email already exists." << std::endl;
            return;
        }
    }
}

void Network::updateUserID(User& old, int id) {
    for (auto & user : users) {
        if (user.getID() == old.getID()) {
            old.setID(id);
        }   else {
            continue;
        }
        if (user.getID() == id) {
            std::cerr << "User with this ID already exists." << std::endl;
            return;
        }
    }
}

void Network::updateUserPosts(User& old, vector<Post> posts) {
    for (auto & user : users) {
        if (user.getID() == old.getID()) {
            old.setPosts(posts);
        }   else {
            continue;
        }
    }
}

void Network::addFriend(int userID1, int userID2) {
    // Check if the users exist
    auto it1 = std::find_if(users.begin(), users.end(), [userID1](User& u) { return u.getID() == userID1; });
    auto it2 = std::find_if(users.begin(), users.end(), [userID2](User& u) { return u.getID() == userID2; });

    if (it1 != users.end() && it2 != users.end()) {
        friends.emplace_back(userID1, userID2);
    } else {
        std::cerr << "One or both users do not exist." << std::endl;
    }
}

void Network::removeFriend(int userID1, int userID2) {
    auto it = std::find(friends.begin(), friends.end(), std::make_pair(userID1, userID2));
    if (it != friends.end()) {
        friends.erase(it);
    } else {
        std::cerr << "Friendship not found." << std::endl;
    }
}