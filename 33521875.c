//-------------------------------------------------------
// Do not edit this area of the code
//-------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

struct node 
{
  struct node *leftPtr;
  int data;
  struct node *rightPtr;
};

void insert_node(struct node** treePtr, int data);
void Find_Largest_Value_in_Left_Subtree_of_Root_Node(struct node* treePtr, int* largest_value);

struct node *rootPtr = NULL;

int main() {
  int data[6];
  int largest_value = 0;

  //scan the data that should occupy the 6 nodes of the binary search tree
  scanf("%d %d %d %d %d %d", (&data[0]), (&data[1]), (&data[2]), (&data[3]), (&data[4]), (&data[5]));
  
  //Insert the 6 nodes into the binary search tree
  for (int i = 0; i < 6; i++)
  {
    insert_node(&rootPtr, data[i]);
  }

  //Find the largest value in the left subtree of the root node
  Find_Largest_Value_in_Left_Subtree_of_Root_Node(rootPtr, &largest_value);
  printf("%d", largest_value);
}

void insert_node(struct node **treePtr, int data) {
  if (*treePtr == NULL) {
    (*treePtr) = (struct node *)malloc(sizeof(struct node));
    (*treePtr)->data = data;
    (*treePtr)->leftPtr = NULL;
    (*treePtr)->rightPtr = NULL;
  } else {
    if (data < (*treePtr)->data) {
      insert_node(&((*treePtr)->leftPtr), data);
    } else {
      insert_node(&((*treePtr)->rightPtr), data);
    }
  }
}
//-------------------------------------------------------
    void Find_Largest_Value_in_Left_Subtree_of_Root_Node(struct node* treePtr, int* largest_value) 
    {
    //-------------------------------------------------------
    // Write your code here
    //-------------------------------------------------------
        static struct node* prevPtr = NULL; // Initiate a prevPtr that is one node behind treePtr
        static int count = 0; // Keep track of the count everytime the function is called
        if (count == 0 && treePtr) // During the first call of the function, the treePtr goes to the left subtree
        {
            count++; // Increment the count 
            prevPtr = treePtr; // Update the prevPtr
            Find_Largest_Value_in_Left_Subtree_of_Root_Node((treePtr->leftPtr), largest_value); // Recursively call the function while updating treePtr to the left node
        }
        else if (treePtr) // In the following recursive calls, traverse the right nodes, since right nodes are larger in value
        {
            prevPtr = treePtr; 
            Find_Largest_Value_in_Left_Subtree_of_Root_Node((treePtr->rightPtr), largest_value);
        }
        else // When the treePtr reaches NULL (end of the link), the prevPtr will contain the largest value in the left subtree
        {
            *largest_value = (prevPtr->data);
        }    
    }