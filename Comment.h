#ifndef PROJECTX_COMMENT_H
#define PROJECTX_COMMENT_H
#include <iostream>
#include <vector>
using namespace std;

class Comment {
    string text;
    int userID;
    int date;
    int likes;
    int commentID;
    vector<int> likers;
public:
    Comment();
    Comment(string text, int userID, int date, int likes, int commentID, vector<int> likers);
    string& getText();
    void setText(string& text);
    int& getUserID();
    void setUserID(int& userID);
    int& getDate();
    void setDate(int& date);
    int getLikes();
    void setLikes(int likes);
    int& getCommentID();
    void setCommentID(int& commentID);
    vector<int>& getLikers();
    void setLikers(vector<int>& likers);
    bool operator==(const Comment& comp) const;
};


#endif //PROJECTX_COMMENT_H
