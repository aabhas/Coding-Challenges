//     root ->  5
//           /     \
//         1         11
//                 /    \
//               9        13
//             /   \     /  \
//            6    10  12    15
//
// get_lca(root, 6, 10) == 9
// get_lca(root, 9, 13) == 11
// get_lca(root, 1, 11) == 5

typedef struct _node {
  int value;
  struct _node* _left;
  struct _node* _right;
  struct _node* _parent;
} node;

node* make_node(int value, node* left, node* right) {
  node *n = (node*) malloc(sizeof(node));
  n->value = value;
  n->_left = left;
  n->_right = right;
  return n;
}

node* get_left_node(node* root) {
  // TODO
  return root->_left;
}

node* get_right_node(node* root) {
  // TODO
  return root->_right;
}

int get_lca(node* root, int value1, int value2) {
  // value1 < value2
  // value1 and value2 are both present

  // TODO
  if(root == NULL) return NULL;
  
  if((root->value) > value2)
      return get_lca(get_left_node(root), value1, value2);
      
  if((root->value) < value1)
      return get_lca(get_right_node(root), value1, value2);
  
  //edge cases
  if((root->value) == value1 || (root->value) == value2)
  {    
      if(root->parent != NULL)
          return root->parent->value;
      else return NULL;
  }
  
     return root->value;
    
   //return NULL;
}
