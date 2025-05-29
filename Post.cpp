#include "Post.h"
#include <algorithm>

Post::Post() {
    this->text = "";
    this->imageID = 0;
    this->userID = 0;
    this->date = 0;
    this->likes = 0;
    this->postID = 0;
    this->likers = {};
    this->comments = {};
}

Post::Post(string text, int imageID, int userID, int date, int likes, int postID, vector<int> likers, vector<Comment> comments) {
    this->text = std::move(text);
    this->imageID = imageID;
    this->userID = userID;
    this->date = date;
    this->likes = likes;
    this->postID = postID;
    this->likers = likers;
    this->comments = std::move(comments);
}

string &Post::getText() {
    return text;
}

void Post::setText(string &text) {
    this->text = std::move(text);
}

int &Post::getImageID() {
    return imageID;
}

void Post::setImageID(int &imageID) {
    this->imageID = imageID;
}

int &Post::getUserID() {
    return userID;
}

void Post::setUserID(int &userID) {
    this->userID = userID;
}

int &Post::getDate() {
    return date;
}

void Post::setDate(int &date) {
    this->date = date;
}

int Post::getLikes() {
    return likes;
}

void Post::setLikes(int likes) {
    this->likes = likes;
}

int& Post::getPostID() {
    return postID;
}

void Post::setPostID(int &postID) {
    this->postID = postID;
}

vector<int>& Post::getLikers() {
    return likers;
}

void Post::setLikers(vector<int> &likers) {
    this->likers = std::move(likers);
}

vector<Comment>& Post::getComments() {
    return comments;
}

void Post::setComments(vector<Comment> &comments) {
    this->comments = std::move(comments);
}

bool Post::operator==(const Post &comp) const {
    return text == comp.text && imageID == comp.imageID && userID == comp.userID && date == comp.date && likes == comp.likes;
}

void Post::printComments() {
    for (int i=0; i<comments.size(); i++) {
        std::cout << "Text: " << comments[i].getText() << std::endl;
        std::cout << "User ID: " << comments[i].getUserID() << std::endl;
        std::cout << "Date: " << comments[i].getDate() << std::endl;
        std::cout << "# of Likes: " << comments[i].getLikes() << std::endl;
        std::cout << "Comment ID: " << comments[i].getCommentID() << std::endl;
        for (int j=0; j < comments[j].getLikers().size(); j++) {
            std::cout << "Liker ID: " << comments[i].getLikers()[j] << std::endl;
        }
        std::cout << std::endl;
    }
}

