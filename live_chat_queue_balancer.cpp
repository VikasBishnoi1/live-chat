#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "ChatQueueBalancer.h"

using namespace std;

// Helper function to get current time as string
string getCurrentTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[30];
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

int main() {
    int capacity;
    cout << "Enter maximum chat queue size: ";
    cin >> capacity;

    ChatQueueBalancer balancer(capacity);
    int choice;
    string username;

    do {
        cout << "\n=== Live Chat Queue Balancer ===\n";
        cout << "1. Add User to Queue\n";
        cout << "2. Assign User to Agent\n";
        cout << "3. Show Queue\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                balancer.addUser(username, getCurrentTime());
                break;

            case 2:
                balancer.assignUser();
                break;

            case 3:
                balancer.displayQueue();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
