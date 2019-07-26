/*
 *Name: Zhilong Gan
 *Student Number: 100331942
 *Course Number: CPSC 1160
 *Date: Jul 25, 2019
 *Purpose: this is the Node class
 *Assignment 8
 */


/*
  this file contain the prototype of Node
  a Node will have an integer number as the value it contain
  the other Node will represent the next Node that it connect to
  also there are some function relate to Node
*/


#include<string>
#include<iostream>

using namespace std;

#ifndef NODE_H
#define NODE_H

struct Node
{
	int value;
	Node* next;
};


// finctions 
int car(const Node* p);		// get value
Node* cdr(const Node* p);		// get next
void setcar(const Node* p, int n);		// set value
void setcdr(Node* p, Node* q);		// set next
Node* cons(int value, Node* q);		// constructor of Node

int length(Node* p);		// get lenght 
bool searchInOrder(int x, Node* p);		// search x in an order list
bool hasDuplicates(Node* p);		// detect the same number in a list
bool search(int x, Node* p);		// search x in a list
Node* append(int x, Node* p);		// append x to the end of the list
Node* reverse(Node* p);		// reverse a list
Node* reverseHelper(Node* p);		// helper function of reverse()
bool isLonger(Node* p, Node* q);	// compare the length of 2 lists
Node* ithNode(Node* p, int i);		// find ith Node in a list
Node* deleteList(Node* p);		// delete a list
Node* mergeTwoOrderedLists(Node* p, Node* q);		// merge 2 ordered lists
Node* array2List(int arr[], int n);		// conver array to list
Node* readList();		// input a list from standard input
bool isValid(string input);		// check input is value or not
void printList(Node* p);		// print a list

#endif