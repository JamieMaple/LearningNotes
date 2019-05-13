#include "message.h"

Message::Message(const Message &rhs):
    content(rhs.content), folders(rhs.folders) {
    addToFolders(rhs);
}

Message::~Message() {
    for (auto& f : folders) {
        f->remMsg(this);
    }
}

Message& Message::operator=(const Message& m) {
    removeFromFolders();
    content = m.content;
    folders = m.folders;
    addToFolders(m);

    return *this;
}

void Message::addToFolders(const Message& m) {
    for (auto& f : m.folders) {
        f->addMsg(this);
    }
}

void Message::removeFromFolders() {
    for (auto& f : folders) {
        f->remMsg(this);
    }
}

void Message::save(Folder& f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f) {
    folders.erase(&f);
    f.remMsg(this);
}

