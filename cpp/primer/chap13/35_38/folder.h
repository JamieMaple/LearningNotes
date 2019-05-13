#ifndef FOLDER_H
#define FOLDER_H

#include <set>

class Message;

class Folder {
    friend void swap(Folder&, Folder&);
    public:
        void remMsg(Message *message) { messages.erase(message); }
        void addMsg(Message *message) { messages.insert(message); }
    private:
        std::set<Message*> messages;
};

void swap(Folder& lhs, Folder& rhs);

#endif /* ifndef FOLDER_H */
