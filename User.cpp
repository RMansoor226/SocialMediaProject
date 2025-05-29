#include "User.h"
#include <algorithm>

User::User() {
    this->name = "";
    this->age = 0;
    this->email = "";
    this->id = 0;
    this->posts = {};
}

User::User(string name, int age, string email, int id, vector<Post> posts) {
    this->name = std::move(name);
    this->age = age;
    this->email = std::move(email);
    this->id = id;
    this->posts = std::move(posts);
}

string& User::getName() {
    return name;
}

void User::setName(string& name) {
    this->name = std::move(name);
}

int& User::getAge() {
    return age;
}

void User::setAge(int& age) {
    this->age = age;
}

string& User::getEmail() {
    return email;
}

void User::setEmail(string& email) {
    this->email = std::move(email);
}

int& User::getID() {
    return id;
}

void User::setID(int& id) {
    this->id = id;
}

vector<Post>& User::getPosts() {
    return posts;
}

void User::setPosts(vector<Post>& posts) {
    this->posts = std::move(posts);
}

bool User::operator==(const User& comp) const {
    return name == comp.name && age == comp.age && email == comp.email && id == comp.id;
}

void User::printPosts() {
    for (int i=0; i<posts.size(); i++) {
        std::cout << "Text: " << posts[i].getText() << std::endl;
        std::cout << "Image ID: " << posts[i].getImageID() << std::endl;
        std::cout << "User ID: " << posts[i].getUserID() << std::endl;
        std::cout << "Date: " << posts[i].getDate() << std::endl;
        std::cout << "# of Likes: " << posts[i].getLikes() << std::endl;
        std::cout << "Post ID: " << posts[i].getPostID() << std::endl;
        for (int j=0; j < posts[i].getLikers().size(); j++) {
            std::cout << "Likers: " << posts[i].getLikers()[j] << std::endl;
        }
        for (int k=0; k < posts[i].getComments().size(); k++) {
            posts[i].printComments();
        }
        std::cout << std::endl;
    }
}

Post& User::createPost(string text, int imageID, int userID, int date, int likes, int postID, vector<int> likers, vector<Comment> comments) {
    posts.emplace_back(std::move(text), imageID, userID, date, likes, postID, likers, std::move(comments));
    return posts.back();
}

bool User::deletePost(const Post& old) {
    auto it = std::find(posts.begin(), posts.end(), old);
    if (it != posts.end()) {
        posts.erase(it);
        return true;
    }
    else {
        std::cerr << "Post not found." << std::endl;
        return false;
    }
}

void User::updatePostText(const Post& old, string Text) {
    for (auto & post : posts) {
        if (post == old) {
            post.setText(Text);
            return;
            }
    }
    std::cerr << "Post not found." << std::endl;
}

void User::updatePostImageID(const Post& old, int ImageID) {
    for (auto & post : posts) {
        if (post == old) {
            post.setImageID(ImageID);
            return;
        }
    }
    std::cerr << "Post not found." << std::endl;
}

void User::updatePostUserID(const Post& old, int UserID) {
    for (auto & post : posts) {
        if (post == old) {
            post.setUserID(UserID);
            return;
        }
    }
    std::cerr << "Post not found." << std::endl;
}

void User::updatePostDate(const Post& old, int Date) {
    for (auto & post : posts) {
        if (post == old) {
            post.setDate(Date);
            return;
        }
    }
    std::cerr << "Post not found." << std::endl;
}

void User::updatePostLikes(const Post& old, int Likes) {
    for (auto & post : posts) {
        if (post == old) {
            post.setLikes(Likes);
            return;
        }
    }
    std::cerr << "Post not found." << std::endl;
}

void User::updatePostLikers(const Post& old, vector<int> Likers) {
    for (auto & post : posts) {
        if (post == old) {
            post.setLikers(Likers);
            return;
        }
    }
    std::cerr << "Post not found." << std::endl;
}

void User::updateComments(const Post& old, vector<Comment> Comments) {
    for (auto & post : posts) {
        if (post == old) {
            post.setComments(Comments);
            return;
        }
    }
    std::cerr << "Post not found." << std::endl;
}

Comment& User::createComment(Post& host, string text, int userID, int date, int likes, int commentID, vector<int> likers) {
    host.getComments().emplace_back(std::move(text), userID, date, likes, commentID, std::move(likers));
    return host.getComments().back();
}

bool User::deleteComment(Post& host, Comment &old) {
    auto it = std::find(host.getComments().begin(), host.getComments().end(), old);
    if (it != host.getComments().end()) {
        host.getComments().erase(it);
        return true;
    }
    else {
        std::cerr << "Comment not found." << std::endl;
        return false;
    }
}

void User::updateCommentText(Post& host, Comment &old, string Text) {
    for (auto & i : host.getComments()) {
        if (i == old) {
            i.setText(Text);
            return;
        }
    }
    std::cerr << "Comment not found." << std::endl;
}

void User::updateCommentUserID(Post& host, Comment &old, int UserID) {
    for (auto & i : host.getComments()) {
        if (i == old) {
            i.setUserID(UserID);
            return;
        }
    }
    std::cerr << "Comment not found." << std::endl;
}

void User::updateCommentDate(Post& host, Comment &old, int Date) {
    for (auto & i : host.getComments()) {
        if (i == old) {
            i.setDate(Date);
            return;
        }
    }
    std::cerr << "Comment not found." << std::endl;
}

void User::updateCommentLikes(Post& host, Comment &old, int Likes) {
    for (auto & i : host.getComments()) {
        if (i == old) {
            i.setLikes(Likes);
            return;
        }
    }
    std::cerr << "Comment not found." << std::endl;
}

void User::updateCommentID(Post& host, Comment &old, int CommentID) {
    for (auto & i : host.getComments()) {
        if (i == old) {
            i.setCommentID(CommentID);
            return;
        }
    }
    std::cerr << "Comment not found." << std::endl;
}

void User::updateCommentLikers(Post& host, Comment &old, vector<int> Likers) {
    for (auto & i : host.getComments()) {
        if (i == old) {
            i.setLikers(Likers);
            return;
        }
    }
    std::cerr << "Comment not found." << std::endl;
}

void User::likePost(Post& host, int userID) {
    auto it = std::find(host.getLikers().begin(), host.getLikers().end(), userID);
    if (it == host.getLikers().end()) {
        host.getLikers().push_back(userID);
        host.setLikes(host.getLikes()+1);
    } else {
        std::cerr << "User already liked this post." << std::endl;
    }
}

void User::unlikePost(Post& host, int userID) {
    auto it = std::find(host.getLikers().begin(), host.getLikers().end(), userID);
    if (it != host.getLikers().end()) {
        host.getLikers().erase(it);
        host.setLikes(host.getLikes()-1);
    } else {
        std::cerr << "User has not liked this post." << std::endl;
    }
}

void User::likeComment(Post& host, Comment& old, int userID) {
    for (auto & i : host.getComments()) {
        if (i == old) {
            auto it = std::find(i.getLikers().begin(), i.getLikers().end(), userID);
            if (it == i.getLikers().end()) {
                i.getLikers().push_back(userID);
                i.setLikes(i.getLikes()+1);
            } else {
                std::cerr << "User already liked this comment." << std::endl;
            }
            return;
        }
    }
    std::cerr << "Comment not found." << std::endl;
}

void User::unlikeComment(Post& host, Comment& old, int userID) {
    for (auto & i : host.getComments()) {
        if (i == old) {
            auto it = std::find(i.getLikers().begin(), i.getLikers().end(), userID);
            if (it != i.getLikers().end()) {
                i.getLikers().erase(it);
                i.setLikes(i.getLikes()-1);
            } else {
                std::cerr << "User has not liked this comment." << std::endl;
            }
            return;
        }
    }
    std::cerr << "Comment not found." << std::endl;
}