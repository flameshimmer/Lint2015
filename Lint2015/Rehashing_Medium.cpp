#include "stdafx.h"

//The size of the hash table is not determinate at the very beginning. If the total size of keys is too large 
//(e.g. size >= capacity / 10), we should double the size of the hash table and rehash every keys. 
//Say you have a hash table looks like below:
//
//size=3, capacity=4
//
//[null, 21, 14, null]
//       ↓    ↓
//       9   null
//       ↓
//      null
//The hash function is:
//
//int hashcode(int key, int capacity) {
//    return key % capacity;
//}
//here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same 
//hashcode 1 (21 % 4 = 9 % 4 = 1). We store them in the hash table by linked list.
//
//rehashing this hash table, double the capacity, you will get:
//
//size=3, capacity=8
//
//index:   0    1    2    3     4    5    6   7
//hash : [null, 9, null, null, null, 21, 14, null]
//Given the original hash table, return the new hash table after rehashing .
//
//
//Example
//Given [null, 21->9->null, 14->null, null],
//
//return [null, 9->null, null, null, null, 21->null, 14->null, null]
//
//Note
//For negative integer in hash table, the position can be calculated as follow:
//
//C++/Java: if you directly calculate -4 % 3 you will get -1. You can use function: a % b = (a % b + b) % b to make it is a non negative integer.
//Python: you can directly use -1 % 3, you will get 2 automatically.
//
namespace LintSolution1
{
    namespace Rehashing_Medium
    {     
		/**
		* @param hashTable: A list of The first node of linked list
		* @return: A list of The first node of linked list which have twice size
		*/
		vector<ListNode*> rehashing(vector<ListNode*> hashTable) {			
			int len = hashTable.size();
			int newCap = 2 * len;
			vector<ListNode*> result(newCap, NULL);
			if (len == 0) { return result; }

			for (ListNode* node : hashTable)
			{
				while (node)
				{
					ListNode* newNode = new ListNode(node->val); // duping the node, don't use the old one
					int newIndex = (node->val % newCap + newCap) % newCap;
					if (!result[newIndex]) { result[newIndex] = newNode; }
					else
					{
						ListNode* cur = result[newIndex];
						while (cur->next) 
						{ 
							cur = cur->next; 
						}
						cur->next = newNode;
					}
					node = node->next;
				}
			}
			return result;
		}
     
        void Main()
        {
			vector<ListNode*> input = { NULL, createList({ 91, 71 }), createList({ 2 }), NULL, createList({ 34 }), createList({ 45 }), createList({ 96 }), createList({ 27, 37 }), NULL, createList({ 19 })};
			rehashing(input);
        }
    }
}
   
    