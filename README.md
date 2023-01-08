# Indexing using AVL tree

  Tree is defined through class Node whose definition includes data members, constructors, destructors, traversals (Recursive and Iterative), Height, Difference in height between Left and Right subtrees

  AVL Tree class definition includes a root node as data member. 
  Member functions include 4 rotations for balancing, Balance functions each for after insertion and after deletion, constructors, destructors, insert(), delete(), search(), get() and set() for the root. 
  Operators += and -+ were overloaded with Insertion and Deletion as their functions.

  Indexing is done on a structured file whose structure data member "id" is its primary ID. The index class has an AVL class object and an integer keeping note of last index used as its data members. 
  Member functions include constructor, destructor, getIndex(), reset(), setIndices() and insert.

  Stack and Queue are used for traversals (Iterative method).
