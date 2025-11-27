#ifndef DLIST_H
#define DLIST_H


// node api

/// @brief Opaque datatype for a doubly linked node.
typedef struct s_dnode dnode_t;

// creation

/**
 * Creates a new node.
 * @param data the data the node holds
 * @return a doubly linked node
 */
dnode_t* dnode_create(void* data);

/**
 * Deletes a node.
 * That is, after the operation the node pointer is not useable anymore.
 * Note: does not delete the data.
 */
void dnode_delete(dnode_t* node);

// access 

/**
 * Returns the successor of a node.
 * @param node the node to get the successor from
 * @return the successor node
 */
dnode_t* dnode_get_next(dnode_t* node);

/**
 * Returns the predecessor of a node.
 * @param node the node to get the predecessor from
 * @return the predecessor node
 */
dnode_t* dnode_get_prev(dnode_t* node);

/**
 * Returns the data of a node.
 * Note that the node does not own the data.
 * If one deletes the data, the node contains a dangling pointer!
 * @param node the node to get the data from
 * @return the data of the node
 */
void* dnode_get_data(dnode_t* node);


// list api

/// @brief Opaque datatype for a doubly linked list.
typedef struct s_dlist dlist_t;

// creation

/**
 * Creates a new empty list.
 * @return a doubly linked list
 */
dlist_t* dlist_create(void);

/**
 * Deletes a list. That is deleting all nodes and the list itself.
 * The list pointer should be nulled after that.
 * @param list the list to be freed
 */
void dlist_delete(dlist_t* list);

// access

/**
 * Returns the first node of the list.
 * @param list a doubly linked list
 * @return the first node, if index is valid and list has atleast one node
 */
dnode_t* dlist_get_head(dlist_t* list);

/**
 * Returns the last node of the list.
 * @param list a doubly linked list
 * @return the last node, if index is valid and list has atleast one node
 */
dnode_t* dlist_get_last(dlist_t* list);

/**
 * Returns the node at the given position.
 * @param list a doubly linked list
 * @param index position of the node
 * @return the node, if index is valid
 */
 dnode_t* dlist_get_node_at(dlist_t* list, int index);

 /**
 * Returns the data stored in the node at the given position.
 * @param list a doubly linked list
 * @param index position of the node with the data
 * @return the data in the node, if index is valid
 */
void* dlist_get_data_at(dlist_t* list, int index);

/**
 * Returns the position of a node in the list.
 * @param list the list to inspect
 * @returns the position of the node
 */
int dlist_index_of(dlist_t* list, dnode_t* node);

/**
 * Returns the number of nodes in the list.
 * @param list the list to inspect
 * @returns the number of nodes in the list
 */
int dlist_length(dlist_t* list);

// manipulation

/**
 * Adds a new node at the end of the list.
 * If the list is empty this becomes the new single node in the list.
 * @param list a doubly linked list
 * @param data the data for the new node
 */
void dlist_append(dlist_t* list, void* data);

/**
 * Adds a new node at the head of the list.
 * If the list is empty this becomes the new single node in the list.
 * @param list a doubly linked list
 * @param data the data for the new node
 */
void dlist_prepend(dlist_t* list, void* data);

/**
 * Inserts a new node holding the data into the list at the given position.
 * @param list a doubly linked list
 * @param index the position to insert the node.
 * - If index is negative, the node gets prepended.
 * - If index is larger than the number of nodes in the list,
 *   then the new node gets appended.
 * - If index is valid, the node is inserted at the position.
 *   That is, after insertion the node has the given index.
 *   Note that you must relink neighbored nodes appropiately.
 * @param data the data for the new node
 */
void dlist_insert_at(dlist_t* list, int index, void* data);

/**
 * Removes the node at the position from the list.
 * @param list a doubly linked list
 * @param index position of the node to be removed
 * - If index is negative, the head is removed.
 * - If index is too big, the last gets removed.
 * - If index is valid, the node at the position is removed.
 *   Note that you must relink neighbour nodes appropiately.
 */
void dlist_remove_at(dlist_t* list, int index);

/**
 * Removes all nodes from a linked list.
 * After this operation the list is empty.
 * @param list a doubly linked list
 */
void dlist_remove_all(dlist_t* list);

// advanced

/**
 * Copies a list.
 * The list copy looks identical to the original,
 * but has all its own nodes pointing to the same data.
 * @param list the list to be copied
 * @return a copy of the given list
 */
dlist_t* dlist_copy(dlist_t* list);

/**
 * Reverses the list.
 * A reversed list has all nodes in the opposite order.
 * @param list the list to reverse
 */
void dlist_reverse(dlist_t* list);

/**
 * Concatenates two lists.
 * The second list is appended at the end of the first list. 
 * Note that the second list must be empty after concatenation.
 * @param list1 the list getting longer
 * @param list2 the list getting appended
 */
void dlist_concat(dlist_t* list1, dlist_t* list2);


#endif