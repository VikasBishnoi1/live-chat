#include "ChatQueueBalancer.h"
#include <fstream>

ChatQueueBalancer::ChatQueueBalancer(int cap) {
    capacity = cap;
    queue.resize(capacity);
    front = -1;
    rear = -1;
    size = 0;
}

bool ChatQueueBalancer::isFull() {
    return size == capacity;
}

bool ChatQueueBalancer::isEmpty() {
    return size == 0;
}

void ChatQueueBalancer::logToFile(const string& message) {
    ofstream logfile("chat_log.txt", ios::app);
    if (logfile.is_open()) {
        logfile << message << endl;
        logfile.close();
    }
}

void ChatQueueBalancer::addUser(const string& username, const string& time) {
    if (isFull()) {
        cout << "⚠️ Queue is full! Cannot add user: " << username << endl;
        logToFile("[FULL] Failed to add: " + username + " at " + time);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }

    queue[rear] = { username, time };
    size++;

    cout << "✅ User '" << username << "' added to the queue at " << time << endl;
    logToFile("[ADD] User: " + username + " at " + time);
}

void ChatQueueBalancer::assignUser() {
    if (isEmpty()) {
        cout << "⚠️ Queue is empty. No user to assign." << endl;
        logToFile("[EMPTY] Attempted assignment.");
        return;
    }

    ChatUser assigned = queue[front];
    cout << "👨‍💻 User '" << assigned.username << "' assigned to an agent. Joined at: " << assigned.timestamp << endl;
    logToFile("[ASSIGNED] User: " + assigned.username + " (Joined at: " + assigned.timestamp + ")");

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    size--;
}

void ChatQueueBalancer::displayQueue() {
    if (isEmpty()) {
        cout << "📭 Queue is empty." << endl;
        return;
    }

    cout << "📃 Current Queue:\n";
    int i = front;
    int count = 0;
    while (count < size) {
        cout << " - " << queue[i].username << " (Joined at: " << queue[i].timestamp << ")" << endl;
        i = (i + 1) % capacity;
        count++;
    }
}
