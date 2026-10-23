# Binary Search Tree Visualizer (C++)
This is a C++ project that implements a Binary Search Tree (BST) with a menu-based interface. You can insert, delete and search for values, view the tree, and perform different traversals. The tree is displayed using ASCII characters after every insertion or deletion, so it's easier to see how it changes.

## Files
- `bst.h` – Contains the Node structure and BST class declaration.
- `task4.cpp` – Contains the functions for inserting, deleting, searching and displaying the tree and  the main function and menu.

## How to Compile and Run
Compile the program using:

```bash
g++ -std=c++11 -Wall main.cpp bst.cpp -o bst
```

Run it using:

```bash
./bst
```

On Windows, run `bst.exe` instead.

### Checking for Memory Errors
You can also compile the program with AddressSanitizer to check for memory errors:

```bash
g++ -std=c++11 -Wall -fsanitize=address -g main.cpp bst.cpp -o bst
./bst
```

Alternatively, you can use Valgrind on Linux:

```bash
g++ -g main.cpp bst.cpp -o bst
valgrind --leak-check=full ./bst
```

## Menu Options
1. Insert a value
2. Delete a value
3. Search for a value and display the search path
4. Inorder traversal
5. Preorder traversal
6. Postorder traversal
7. Display the tree
8. Exit

## Tree Display
The tree is printed sideways using ASCII characters. The root appears on the left, right children appear above their parent, and left children appear below it. Each level is indented by six spaces.

This makes it easier to understand the structure of the tree after inserting or deleting values.

## Memory Management
Each node is created using `new Node` and stores its value along with pointers to its left and right children.

When a node is deleted from the tree, its memory is released using `delete`. The destructor also calls `clear()`, which deletes all remaining nodes from the children up to the root.

## How Insertion and Deletion Work
Insertion and deletion use recursion. Each function returns the root of the updated subtree, and the parent node updates its left or right pointer accordingly.

When deleting a node, the program handles three cases:

- **No children:** Delete the node and return `NULL`.
- **One child:** Delete the node and connect its parent to the remaining child.
- **Two children:** Replace the node's value with the smallest value in its right subtree, then delete that original node.

## Edge Cases
The program also handles a few special situations:

- Deleting from an empty tree reports that the value was not found.
- Traversals and tree display show an appropriate message when the tree is empty.
- Inserting a duplicate value is not allowed.
- Inserting or deleting the root works correctly, including when the tree becomes empty.
- Invalid menu input is rejected, and the menu is displayed again.

## Time and Space Complexity
Here, `n` is the number of nodes and `h` is the height of the tree.

| Operation | Average case | Worst case |
|---|---|---|
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Search | O(log n) | O(n) |
| Traversals | O(n) | O(n) |
| Display | O(n) | O(n) |

The tree uses O(n) space to store its nodes, and recursive operations use O(h) additional stack space.

Since this is a regular BST and not a self-balancing tree, its performance depends on how values are inserted. If values are inserted in sorted order, the tree can become skewed, making operations slower.

## Author
Vanshika Chauhan
