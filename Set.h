/*
 *Name: Zhilong Gan
 *Student Number: 100331942
 *Course Number: CPSC 1160
 *Date: Jul 25, 2019
 *Purpose: this a Set class
 *Assignment 8
 */


/*
	the file is the hfile for set 
	a set contain a link list 
	and the set will not have same element 
	the element in set are in acdeneding order
*/

#include"Node.h"

#ifndef SET_H
#define SET_H


class Set
{
private:
	Node* list;		// the first Node of link list
	friend void readList(Set& a);
public:
	
	// constructor
	Set()
	{
		list = nullptr;
	}

	Set(Node* p)
	{	
		list = p;
	}

	Set(const Set& a);	// copy constructor

	~Set()	// deconstrucote
	{
		if (this == NULL)
			return;
		deleteList(list);
	}

	Set& operator =(Set& a);		// deep copy

	bool isEmpty() const;	// check list is empty
	bool member(int x) const;	// check if x is a member
	
	void insert(int x);		// insert in acedcing
	void remove(int x);		// remove a node
	void print() const;		// print Set
		
	int size();		 // get the size of Set

	// union of a and b
	friend const Set operator +(const Set& a, const Set& b);
	// intersecption of a and b
	friend const Set operator *(const Set& a, const Set& b);
	// proper set
	friend bool operator <(const Set& a, const Set& b);
	// overload <<
	friend std::ostream& operator <<(std::ostream& os, Set& a);
	// overload >>
	friend std::istream& operator >>(std::istream& is, Set& a);

};


#endif