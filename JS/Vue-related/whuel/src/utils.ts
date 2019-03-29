function isObject(o: any) {
  return o != null && typeof o === 'object';
}

function isElementNode(node: Node) {
  return node.nodeType === 1;
}

function isTextNode(node: Node) {
  return node.nodeType === 3;
}
