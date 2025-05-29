#ifndef PROJECTX_POST_H
#define PROJECTX_POST_H
#include "Comment.h"
#include <iostream>
#include <vector>
using namespace std;

class Post {
    string text;
    int imageID;
    int userID;
    int date;
    int likes;
    int postID;
    vector<int> likers;
    vector<Comment> comments;
public:
    Post();
    Post(string text, int imageID, int userID, int date, int likes, int postID, vector<int> likers, vector<Comment> comments);
    string& getText();
    void setText(string& text);
    int& getImageID();
    void setImageID(int& imageID);
    int& getUserID();
    void setUserID(int& userID);
    int& getDate();
    void setDate(int& date);
    int getLikes();
    void setLikes(int likes);
    int& getPostID();
    void setPostID(int& postID);
    vector<int>& getLikers();
    void setLikers(vector<int>& likers);
    vector<Comment>& getComments();
    void setComments(vector<Comment>& comments);
    bool operator==(const Post& comp) const;
    // Comment Read Method
    void printComments();
};

#endif //PROJECTX_POST_H
