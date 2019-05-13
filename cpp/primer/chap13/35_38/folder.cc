#include "folder.h"

using std::swap;

void swap(Folder& lhs, Folder& rhs) {
    swap(lhs.messages, rhs.messages);
}

