/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
   bool checkBSTandData(Node* root, int *left_max, int* right_min) {
       int temp;
       if (root == NULL) {
           return true;
       }
       
       if (checkBSTandData(root->left, left_max, &temp) == false) {
           return false;
       }
       if (root->left == NULL) {
           *left_max = root->data;
       } else if (root->data <= MAX(*left_max, temp)) {
           return false;
       }
       
       if (checkBSTandData(root->right, &temp, right_min) == false) {
           return false;
       }
       
       if (root->right == NULL) {
           *right_min = root->data;
       } else if (root->data >= MIN(*right_min, temp)) {
           return false;
       }
       
       return true;
   }
   bool checkBST(Node* root) {
       int left_max, right_min;
       return checkBSTandData(root, &left_max, &right_min);
   }
