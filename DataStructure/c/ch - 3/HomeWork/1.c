#include "includes/std.h"
struct node_s {
  int num;
  struct node_s * next;
};

typedef struct node_s Node, List;

List CreateList(void);

void AddNode(List, int);

void ThroughList(List, void (*p)(List));

void DisposeList(List);

int main(void) {
  

  return 0;
}