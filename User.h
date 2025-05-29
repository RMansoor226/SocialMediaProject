#ifndef PROJECTX_USER_H
#define PROJECTX_USER_H
#include "Post.h"
#include <iostream>
using namespace std;

class User {
        string name;
        int age;
        string email;
        int id;
        vector<Post> posts;
    public:
        User();
        User(string name, int age, string email, int id, vector<Post> posts);
        string& getName();
        void setName(string& name);
        int& getAge();
        void setAge(int& age);
        string& getEmail();
        void setEmail(string& email);
        int& getID();
        void setID(int& id);
        vector<Post>& getPosts();
        void setPosts(vector<Post>& posts);
        bool operator==(const User& comp) const;
        // Post CRUD Methods
        void printPosts();
        Post& createPost(string text, int imageID, int userID, int date, int likes, int postID, vector<int> likers, vector<Comment> comments);
        bool deletePost(const Post& old);
        void updatePostText(const Post& old, string text);
        void updatePostImageID(const Post& old, int imageID);
        void updatePostUserID(const Post& old, int userID);
        void updatePostDate(const Post& old, int date);
        void updatePostLikes(const Post& old, int likes);
        void updatePostLikers(const Post& old, vector<int> likers);
        void updateComments(const Post& old, vector<Comment> comments);
        // Comment CUD Methods
        Comment& createComment(Post& host, string text, int userID, int date, int likes, int commentID, vector<int> likers);
        bool deleteComment(Post& host, Comment& old);
        void updateCommentText(Post& host, Comment& old, string text);
        void updateCommentUserID(Post& host, Comment& old, int userID);
        void updateCommentDate(Post& host, Comment& old, int date);
        void updateCommentLikes(Post& host, Comment& old, int likes);
        void updateCommentID(Post& host, Comment& old, int commentID);
        void updateCommentLikers(Post& host, Comment& old, vector<int> likers);
        // Like/Unlike Methods
        void likePost(Post& host, int userID);
        void unlikePost(Post& host, int userID);
        static void likeComment(Post& host, Comment& old, int userID);
        void unlikeComment(Post& host, Comment& old, int userID);
};


#endif //PROJECTX_USER_H
