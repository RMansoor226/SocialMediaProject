#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "Network.h"
#include <sstream>
#include <iostream>

TEST_CASE("Constructors") {
    User nobody;
    Post empty;
    Post post1("Yes, we can!", 1, 1000, 20231001, 1, 2000, {1001}, {});
    User somebody("Bob Bildech", 23, "bobthebuilder@gmail.com", 1000, {post1});

    SECTION("Default User") {
        REQUIRE(nobody.getName().empty());
        REQUIRE(nobody.getAge() == 0);
        REQUIRE(nobody.getEmail().empty());
        REQUIRE(nobody.getID() == 0);
        REQUIRE(nobody.getPosts().empty());
    }

    SECTION("Default Post") {
        REQUIRE(empty.getText().empty());
        REQUIRE(empty.getImageID() == 0);
        REQUIRE(empty.getUserID() == 0);
        REQUIRE(empty.getDate() == 0);
        REQUIRE(empty.getLikes() == 0);
        REQUIRE(empty.getPostID() == 0);
        REQUIRE(empty.getLikers().empty());
        REQUIRE(empty.getComments().empty());
    }

    SECTION("Parameterized User") {
        REQUIRE(somebody.getName() == "Bob Bildech");
        REQUIRE(somebody.getAge() == 23);
        REQUIRE(somebody.getEmail() == "bobthebuilder@gmail.com");
        REQUIRE(somebody.getID() == 1000);
        REQUIRE((somebody.getPosts()[0].getText()) == "Yes, we can!");
    }

    SECTION("Parameterized Post") {
        REQUIRE(post1.getText() == "Yes, we can!");
        REQUIRE(post1.getImageID() == 1);
        REQUIRE(post1.getUserID() == 1000);
        REQUIRE(post1.getDate() == 20231001);
        REQUIRE(post1.getLikes() == 1);
        REQUIRE(post1.getPostID() == 2000);
        REQUIRE((post1.getLikers())[0] == 1001);
        REQUIRE(post1.getComments().empty());
    }
}

TEST_CASE("createUser method") {
    SECTION("createUser emptyPosts emptyComments") {
        Network facebook;
        facebook.createUser("Bob Bildech", 23, "bobthebuilder@gmail.com", 1000, {});
        REQUIRE(facebook.getUsers().size() == 1);
        REQUIRE(facebook.getUsers()[0].getName() == "Bob Bildech");
        REQUIRE(facebook.getUsers()[0].getAge() == 23);
        REQUIRE(facebook.getUsers()[0].getEmail() == "bobthebuilder@gmail.com");
        REQUIRE(facebook.getUsers()[0].getID() == 1000);
        REQUIRE(facebook.getUsers()[0].getPosts().empty());
    }

    SECTION("createUser withPosts emptyComments") {
        Network instagram;
        Post post1("Yes, we can!", 1, 1000, 20231001, 1, 2000, {1001}, {});
        instagram.createUser("Bob Bildech", 23, "bobthebuilder@gmail.com", 1000, {post1});
        REQUIRE(instagram.getUsers().size() == 1);
        REQUIRE(instagram.getUsers()[0].getName() == "Bob Bildech");
        REQUIRE(instagram.getUsers()[0].getAge() == 23);
        REQUIRE(instagram.getUsers()[0].getEmail() == "bobthebuilder@gmail.com");
        REQUIRE(instagram.getUsers()[0].getID() == 1000);
        REQUIRE(instagram.getUsers()[0].getPosts().size() == 1);
        REQUIRE(instagram.getUsers()[0].getPosts()[0].getText() == "Yes, we can!");
        REQUIRE(instagram.getUsers()[0].getPosts()[0].getImageID() == 1);
        REQUIRE(instagram.getUsers()[0].getPosts()[0].getUserID() == 1000);
        REQUIRE(instagram.getUsers()[0].getPosts()[0].getDate() == 20231001);
        REQUIRE(instagram.getUsers()[0].getPosts()[0].getLikes() == 1);
        REQUIRE(instagram.getUsers()[0].getPosts()[0].getPostID() == 2000);
        REQUIRE((instagram.getUsers()[0].getPosts()[0].getLikers())[0] == 1001);
        REQUIRE(instagram.getUsers()[0].getPosts()[0].getComments().empty());
    }

    SECTION("createUser withPosts withComments") {
        Network twitter;
        Post post1("He didn't kill himself", 1, 1000, 20231001, 1, 2000, {1001}, {});
        Comment comment1("Little Saint James", 1001, 20231001, 0, 3000, {});
        post1.getComments().push_back(comment1);
        twitter.createUser("Jefferson Eppenstein", 69, "thepredator@gmail.com", 1001, {post1});
        REQUIRE(twitter.getUsers().size() == 1);
        REQUIRE(twitter.getUsers()[0].getName() == "Jefferson Eppenstein");
        REQUIRE(twitter.getUsers()[0].getAge() == 69);
        REQUIRE(twitter.getUsers()[0].getEmail() == "thepredator@gmail.com");
        REQUIRE(twitter.getUsers()[0].getID() == 1001);
        REQUIRE(twitter.getUsers()[0].getPosts().size() == 1);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getText() == "He didn't kill himself");
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getImageID() == 1);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getUserID() == 1000);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getDate() == 20231001);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getLikes() == 1);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getPostID() == 2000);
        REQUIRE((twitter.getUsers()[0].getPosts()[0].getLikers())[0] == 1001);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getComments().size() == 1);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getComments()[0].getText() == "Little Saint James");
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getComments()[0].getUserID() == 1001);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getComments()[0].getDate() == 20231001);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getComments()[0].getLikes() == 0);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getComments()[0].getCommentID() == 3000);
        REQUIRE(twitter.getUsers()[0].getPosts()[0].getComments()[0].getLikers().empty());
    }
}

TEST_CASE("createPosts & createComments Method") {
    Network facebook;
    User bigBob = facebook.createUser("Billy Bob", 34, "bigwilly@gmail.com", 2001, {});
    Post one = bigBob.createPost("Hello World!", 1, 2001, 20231001, 0, 3001, {}, {});
    User fig = facebook.createUser("Nig Figs", 25, "chemistryconcept@gmail.com", 2002, {});

    SECTION("createPost with empty comments") {
        REQUIRE(facebook.getUsers().size() == 2);
        REQUIRE(one.getText() == "Hello World!");
        REQUIRE(one.getImageID() == 1);
        REQUIRE(one.getUserID() == 2001);
        REQUIRE(one.getDate() == 20231001);
        REQUIRE(one.getLikes() == 0);
        REQUIRE(one.getPostID() == 3001);
        REQUIRE(one.getLikers().empty());
        REQUIRE(one.getComments().empty());
    }

    SECTION("createComment") {
        Comment uno = fig.createComment(one, "This is a comment", 2002, 20231001, 0, 4001, {});
        REQUIRE(uno.getText() == "This is a comment");
        REQUIRE(uno.getUserID() == 2002);
        REQUIRE(uno.getDate() == 20231001);
        REQUIRE(uno.getLikes() == 0);
        REQUIRE(uno.getCommentID() == 4001);
        REQUIRE(uno.getLikers().empty());
    }
}

TEST_CASE("deleteUser & deletePost & deleteComment Methods") {
    Network x;
    User g = x.createUser("Gordon Ramses", 42, "hellskitchen@gmail.com", 1001, {});
    Post p = g.createPost("I love cooking!", 1, 1001, 20231001, 0, 2001, {}, {});
    User h = x.createUser("Hillary Clinton", 75, "crookedemails@gmail.com", 1002, {});
    Comment c = h.createComment(p, "I love cooking too!", 1002, 20231001, 0, 3001, {});
    SECTION("deleteComment") {
        REQUIRE(p.getComments().size() == 1);
        REQUIRE(h.deleteComment(p, c));
        REQUIRE(p.getComments().empty());
        REQUIRE_FALSE(h.deleteComment(p, c)); // Should return false since comment is already deleted
    }
    SECTION("deletePost") {
        REQUIRE(x.getUsers().size() == 2);
        REQUIRE(g.getPosts().size() == 1);
        REQUIRE(g.deletePost(p));
        REQUIRE(g.getPosts().empty());
        REQUIRE_FALSE(g.deletePost(p)); // Should return false since post is already deleted
    }
    SECTION("deleteUser") {
        REQUIRE(x.getUsers().size() == 2);
        REQUIRE(x.deleteUser(h));
        REQUIRE(x.getUsers().size() == 1);
        REQUIRE_FALSE(x.deleteUser(h)); // Should return false since user is already deleted
    }
}

TEST_CASE("Update User Methods") {
    Network y;
    User a = y.createUser("Anakin Skywalker", 23, "chosenone@gmail.com", 1066, {});
    SECTION("Update User Name") {
        REQUIRE(a.getName() == "Anakin Skywalker");
        y.updateUserName(a, "Darth Vader");
        REQUIRE(a.getName() == "Darth Vader");
    }
    SECTION("Update User Age") {
        REQUIRE(a.getAge() == 23);
        y.updateUserAge(a, 45);
        REQUIRE(a.getAge() == 45);
    }
    SECTION("Update User Email") {
        REQUIRE(a.getEmail() == "chosenone@gmail.com");
        y.updateUserEmail(a, "lordvader@gmail.com");
        REQUIRE(a.getEmail() == "lordvader@gmail.com");
    }
    SECTION("Update User ID") {
        REQUIRE(a.getID() == 1066);
        y.updateUserID(a, 6666);
        REQUIRE(a.getID() == 6666);
    }
    SECTION("Update User Posts") {
        REQUIRE(a.getPosts().empty());
        y.updateUserPosts(a, {Post("I am your father", 1, 1066, 20231001, 0, 2001, {}, {})});
        REQUIRE(a.getPosts().size() == 1);
        REQUIRE(a.getPosts()[0].getText() == "I am your father");
        REQUIRE(a.getPosts()[0].getImageID() == 1);
        REQUIRE(a.getPosts()[0].getUserID() == 1066);
        REQUIRE(a.getPosts()[0].getDate() == 20231001);
        REQUIRE(a.getPosts()[0].getLikes() == 0);
        REQUIRE(a.getPosts()[0].getPostID() == 2001);
        REQUIRE(a.getPosts()[0].getLikers().empty());
        REQUIRE(a.getPosts()[0].getComments().empty());
    }

}

TEST_CASE("Update Post Methods") {
    Network z;
    User a = z.createUser("Big Yoda", 900, "masteryoda@gmail.com", 1980, {});
    Post p = a.createPost("A Jedi craves not these things", 1, 1980, 20231001, 0, 3001, {}, {});
    SECTION("Update Post Text") {
        REQUIRE(p.getText() == "A Jedi craves not these things");
        a.updatePostText(p, "Anger leads to hate. Hate leads to suffering.");
        REQUIRE(a.getPosts()[0].getText() == "Anger leads to hate. Hate leads to suffering.");
    }
    SECTION("Update Post Image ID") {
        REQUIRE(p.getImageID() == 1);
        a.updatePostImageID(p, 1000);
        REQUIRE(a.getPosts()[0].getImageID() == 1000);
    }
    SECTION("Update Post User ID") {
        REQUIRE(p.getUserID() == 1980);
        a.updatePostUserID(p, 1983);
        REQUIRE(a.getPosts()[0].getUserID() == 1983);
    }
    SECTION("Update Post Date") {
        REQUIRE(p.getDate() == 20231001);
        a.updatePostDate(p, 20250527);
        REQUIRE(a.getPosts()[0].getDate() == 20250527);
    }
    SECTION("Update Post Likes") {
        REQUIRE(p.getLikes() == 0);
        a.updatePostLikes(p, 1);
        REQUIRE(a.getPosts()[0].getLikes() == 1);
    }
    SECTION("Update Post Likers") {
        REQUIRE(p.getLikers().empty());
        a.updatePostLikers(p, {2017});
        REQUIRE(a.getPosts()[0].getLikers().size() == 1);
        REQUIRE(a.getPosts()[0].getLikers()[0] == 2017);
    }
    SECTION("Update Post Comments") {
        REQUIRE(p.getComments().empty());
        a.updateComments(p, {Comment("Master Yoda, you can't die.", 2017, 20171215, 0, 1983, {})});
        REQUIRE(a.getPosts()[0].getComments().size() == 1);
        REQUIRE(a.getPosts()[0].getComments()[0].getText() == "Master Yoda, you can't die.");
        REQUIRE(a.getPosts()[0].getComments()[0].getUserID() == 2017);
        REQUIRE(a.getPosts()[0].getComments()[0].getDate() == 20171215);
        REQUIRE(a.getPosts()[0].getComments()[0].getLikes() == 0);
        REQUIRE(a.getPosts()[0].getComments()[0].getCommentID() == 1983);
        REQUIRE(a.getPosts()[0].getComments()[0].getLikers().empty());
    }
}

TEST_CASE("Update Comment Methods") {
    Network w;
    User b = w.createUser("Bruce Wayne", 35, "capecrusader@gmail.com", 1939, {});
    Post p = b.createPost("I am vengeance.", 2, 1939, 20230110, 0, 2001, {}, {});
    Comment c = b.createComment(p, "I am the night.", 1939, 20230110, 0, 3001, {});
    SECTION("Update Comment Text") {
        REQUIRE(c.getText() == "I am the night.");
        b.updateCommentText(p, c, "I am Batman.");
        REQUIRE(p.getComments()[0].getText() == "I am Batman.");
    }
    SECTION("Update Comment User ID") {
        REQUIRE(c.getUserID() == 1939);
        b.updateCommentUserID(p, c, 2000);
        REQUIRE(p.getComments()[0].getUserID() == 2000);
    }
    SECTION("Update Comment Date") {
        REQUIRE(c.getDate() == 20230110);
        b.updateCommentDate(p, c,20220304);
        REQUIRE(p.getComments()[0].getDate() == 20220304);
    }
    SECTION("Update Comment Likes") {
        REQUIRE(c.getLikes() == 0);
        b.updateCommentLikes(p, c, 1);
        REQUIRE(p.getComments()[0].getLikes() == 1);
    }
    SECTION("Update Comment ID") {
        REQUIRE(c.getCommentID() == 3001);
        b.updateCommentID(p, c,3003);
        REQUIRE(p.getComments()[0].getCommentID() == 3003);
    }
    SECTION("Update Comment Likers") {
        REQUIRE(c.getLikers().empty());
        b.updateCommentLikers(p, c, {2012});
        REQUIRE(p.getComments()[0].getLikers().size() == 1);
        REQUIRE(p.getComments()[0].getLikers()[0] == 2012);
    }
}

TEST_CASE("Print Methods") {
    Network net;
    net.createUser("Alice", 30, "alice@example.com", 1, {});

    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    net.printUsers();

    // Restore std::cout
    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    REQUIRE(output.find("Name: Alice") != std::string::npos);
    REQUIRE(output.find("Age: 30") != std::string::npos);
    REQUIRE(output.find("Email: alice@example.com") != std::string::npos);
    REQUIRE(output.find("ID: 1") != std::string::npos);
}

TEST_CASE("Like/Unlike Methods") {
    Network central;
    User k = central.createUser("Keegan-Michael Key", 54, "funnykey@gmail.com", 1001, {});
    Post p = k.createPost("I love comedy!", 1, 1001, 20231001, 0, 2001, {}, {});
    User j = central.createUser("Jordan Peele", 46, "funnypeele@gmail.com", 1002, {});
    SECTION("Like Post") {
        REQUIRE(p.getLikes() == 0);
        j.likePost(p, j.getID());
        REQUIRE(p.getLikes() == 1);
        REQUIRE((p.getLikers())[0] == j.getID());
    }
    SECTION("Unlike Post") {
        j.likePost(p, j.getID());
        REQUIRE(p.getLikes() == 1);
        REQUIRE((p.getLikers())[0] == j.getID());
        j.unlikePost(p, j.getID());
        REQUIRE(p.getLikes() == 0);
        REQUIRE(p.getLikers().empty());
    }
    Comment c = j.createComment(p, "I love comedy too!", 1002, 20231001, 0, 3001, {});
    SECTION("Like Comment") {
        REQUIRE(p.getComments()[0].getLikes() == 0);
        k.likeComment(p, p.getComments()[0], k.getID());
        REQUIRE(p.getComments()[0].getLikes() == 1);
        REQUIRE((p.getComments()[0].getLikers())[0] == k.getID());
    }
    SECTION("Unlike Comment") {
        k.likeComment(p, p.getComments()[0], k.getID());
        REQUIRE(p.getComments()[0].getLikes() == 1);
        REQUIRE((p.getComments()[0].getLikers())[0] == k.getID());
        k.unlikeComment(p, p.getComments()[0], k.getID());
        REQUIRE(p.getComments()[0].getLikes() == 0);
        REQUIRE(p.getComments()[0].getLikers().empty());
    }
}

TEST_CASE("Add/Remove Friend Method") {
    Network socialNetwork;
    User reptile = socialNetwork.createUser("Mark Zuckerberg", 39, "DataThief@gmail.com", 1007, {});
    User psycho = socialNetwork.createUser("Kanye West", 45, "AntisemiticGangster@gmail.com", 1008, {});
    SECTION("Add Friend") {
        REQUIRE(socialNetwork.getFriends().empty());
        socialNetwork.addFriend(reptile.getID(), psycho.getID());
        REQUIRE(socialNetwork.getFriends().size() == 1);
        REQUIRE(socialNetwork.getFriends()[0] == pair(reptile.getID(), psycho.getID()));
    }
    SECTION("Remove Friend") {
        socialNetwork.addFriend(reptile.getID(), psycho.getID());
        REQUIRE(socialNetwork.getFriends().size() == 1);
        socialNetwork.removeFriend(reptile.getID(), psycho.getID());
        REQUIRE(socialNetwork.getFriends().empty());
    }
}