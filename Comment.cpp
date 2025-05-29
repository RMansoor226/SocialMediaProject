//
// Created by apaxm on 5/21/2025.
//

#include "Comment.h"

Comment::Comment() {
    this->text = "";
    this->userID = 0;
    this->date = 0;
    this->likes = 0;
    this->commentID = 0;
    this->likers = {};
}

Comment::Comment(string text, int userID, int date, int likes, int commentID, vector<int> likers) {
    this->text = std::move(text);
    this->userID = userID;
    this->date = date;
    this->likes = likes;
    this->commentID = commentID;
    this->likers = std::move(likers);
}

string& Comment::getText() {
    return text;
}

void Comment::setText(string& text) {
    this->text = std::move(text);
}

int& Comment::getUserID() {
    return userID;
}

void Comment::setUserID(int& userID) {
    this->userID = userID;
}

int& Comment::getDate() {
    return date;
}

void Comment::setDate(int& date) {
    this->date = date;
}

int Comment::getLikes() {
    return likes;
}

void Comment::setLikes(int likes) {
    this->likes = likes;
}

int& Comment::getCommentID() {
    return commentID;
}

void Comment::setCommentID(int& commentID) {
    this->commentID = commentID;
}

vector<int>& Comment::getLikers() {
    return likers;
}

void Comment::setLikers(vector<int>& likers) {
    this->likers = std::move(likers);
}

bool Comment::operator==(const Comment& comp) const {
    return (this->text == comp.text && this->userID == comp.userID && this->date == comp.date && this->likes == comp.likes && this->commentID == comp.commentID && this->likers == comp.likers);
}

