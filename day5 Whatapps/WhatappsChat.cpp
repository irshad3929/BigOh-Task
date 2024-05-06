#include <bits/stdc++.h>

using namespace std;

/*
  DESC:- Here a MessageContent class that hold a pure virtual function that provide
         interface for diffrent types of message content
*/
class Status;
class MessageContent
{
    string type;

public:
    virtual string getContent() const = 0; // provide an interface for different types of message content.
    string getType() const
    {
        return type;
    }
};

// class for audio content
class Audio : public MessageContent
{
    string audioContent;

public:
    Audio(string content) : audioContent(content) {}
    string getContent() const override
    {
        return audioContent;
    }
};

// class for Video content
class Video : public MessageContent
{
    string videoContent;

public:
    Video(string content) : videoContent(content) {}
    string getContent() const override
    {
        return videoContent;
    }
};

// class for Text content
class Text : public MessageContent
{
    string textContent;

public:
    Text(string content) : textContent(content) {}
    string getContent() const override
    {
        return textContent;
    }
};

// Factory class to create MessageContent objects

class MessageContentFactory
{
public:
    // Method to create MessageContent objects based on type and content
    MessageContent *createContent(string type, string content)
    {
        // checking the type
        if (type == "Audio")
        {
            return new Audio(content); // return new Audio object based on content
        }
        else if (type == "Video")
        {
            return new Video(content);
        }
        else if (type == "Text")
        {
            return new Text(content);
        }
        else
        {
            cout << "Invalid message content type.";
        }
    }
};

/*
  DESC:- Message class that relate MessageContent class has-a relationship to getContent
*/

class Message
{
    int senderId;
    int receiverId;
    MessageContent *content;

public:
    Message(MessageContent *content, int receiverId, int senderId) : content(content), receiverId(receiverId), senderId(senderId) {}

    int getReceiverId() const
    {
        return receiverId;
    }
    int getSenderId() const
    {
        return senderId;
    }

    string getContent() const
    {
        return content->getContent();
    }
};

/*
  DESC:- Here User Class that relate to Message class and set status
  Relation:- Has-A relation with Message class
  Method:- sendMessage(), addStatus() in User class User add status and send message
*/

class User
{
    int id;
    string name;
    int mobileNumber;
    string email;
    vector<Message *> messages;
    vector<Status *> statuses;

public:
    User(int id, string name, int mobileNumber, string email) : id(id), name(name), mobileNumber(mobileNumber), email(email) {}

    // getter
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    int getMobileNumber()
    {
        return mobileNumber;
    }
    string getEmail()
    {
        return email;
    }
    vector<Message *> getMessages() const
    {
        return messages;
    }

    vector<Status *> getStatuses() const
    {
        return statuses;
    }

    // setter function

    void setName(string name)
    {
        this->name = name;
    }
    void setMobileNumber(int mobileNumber)
    {
        this->mobileNumber = mobileNumber;
    }
    void setEmail(string email)
    {
        this->email = email;
    }

    void sendMessage(Message *message)
    {
        messages.push_back(message);
    }
    void addStatus(Status *status)
    {
        statuses.push_back(status);
    }
};

/*
 DESC:- Here Status class define
*/

class Status
{
    string statusText;
    vector<User *> users;

public:
    Status(string text) : statusText(text) {}

    string getStatus()
    {
        return statusText;
    }
};

/*
 DESC:- Here UserManagement class define that relate to a User class
 relation:- Has-A
 Method:- addUser(),deleteUser(),showAllUser()
*/

class UserManagement
{

    vector<User *> users;

public:
    void addUser(User *user)
    {
        users.push_back(user);
    }

    void deleteUser(User *user)
    {
        auto it = find(users.begin(), users.end(), user);
        if (it != users.end())
        {
            users.erase(it);
            delete user; // free memory
        }
    }

    void showAllUser()
    {
        for (auto user : users)
        {
            cout << "Name- " << user->getName() << ", Email " << user->getEmail() << ", MobileNumber- " << user->getMobileNumber() << endl;
        }
    }
};

/*
 DESC:- Here MessageManagement class define that relate to a User class
 relation:- Has-A
 Method:- sendUser(),deleteMessage()
*/

class MessageManagement
{
    vector<Message *> messages;

public:
    void sendMessage(Message *message)
    {
        messages.push_back(message);
    }

    void deleteMessage(Message *message)
    {
        auto it = find(messages.begin(), messages.end(), message);
        if (it != messages.end())
        {
            messages.erase(it);
            delete message;
        }
    }
};

/*
 DESC:- Here StatusManagement class define that relate to a User class
 relation:- Has-A
 Method:- addStatus(),deleteStatus(),showStatues()
*/

class StatusManagement
{
    vector<Status *> statuses;

public:
    void addStatus(Status *status)
    {
        statuses.push_back(status);
    }

    void deleteStatus(Status *status)
    {
        auto it = find(statuses.begin(), statuses.end(), status);
        if (it != statuses.end())
        {
            statuses.erase(it);
        }
    }

    void showStatuses()
    {
        for (auto status : statuses)
        {
            cout << "Status: " << status->getStatus() << endl;
        }
    }
};

int main()
{
    UserManagement usermanagement;
    MessageManagement messagemanagement;
    StatusManagement statusmanagement;

    // add user
    User *user1 = new User(1, "irshad", 7052943, "irshad@example.com");
    User *user2 = new User(1, "sahil", 705298, "sahil@example.com");

    usermanagement.addUser(user1);
    usermanagement.addUser(user2);

    // show all user
    usermanagement.showAllUser();

    // Deleting user
    usermanagement.deleteUser(user1);
    cout << "\nAfter Deleting User 1:" << endl;
    usermanagement.showAllUser();

    // add status
    //  statusmanagement.addStatus("Hello there feels good");
    //  statusmanagement.addStatus("busy in work");

    MessageContent *content = new Audio("Audio file");
    cout << content->getContent() << endl; // Output: "Audio file"

    MessageContent *content1 = new Video("Video file");
    cout << content1->getContent() << endl; // Output: "Audio file"

    return 0;
}