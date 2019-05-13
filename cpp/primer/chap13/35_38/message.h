#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>
#include "folder.h"

class Message {
    public:
        explicit Message(const std::string& s = std::string()): content(s) {  }
        Message(const Message&);
        Message& operator=(const Message&);
        ~Message();
        void save(Folder&);
        void remove(Folder&);
    private:
        std::string content;
        std::set<Folder*> folders;
        void addToFolders(const Message&);
        void removeFromFolders();
};

#endif /* ifndef MESSAG */
