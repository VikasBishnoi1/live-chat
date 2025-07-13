// ChatQueueBalancer.h
#ifndef CHATQUEUEBALANCER_H
#define CHATQUEUEBALANCER_H

#include <iostream>
#include <vector>
using namespace std;

struct ChatUser {
    string username;
    string timestamp;
};

class ChatQueueBalancer {
private:
    int front, rear, size, capacity;
    vector<ChatUser> queue;

    void logToFile(const string& message);

public:
    ChatQueueBalancer(int cap);
    void addUser(const string& username, const string& time);
    void assignUser();
    void displayQueue();
    bool isFull();
    bool isEmpty();
};

#endif // CHATQUEUEBALANCER_H
