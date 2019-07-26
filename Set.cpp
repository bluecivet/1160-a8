/*
 *Name: Zhilong Gan
 *Student Number: 100331942
 *Course Number: CPSC 1160
 *Date: Jul 25, 2019
 *Purpose: this is the implementation of the Set class
 *Assignment 8
 */

#include "Set.h"
#include "Node.h"
#include<iostream>

using namespace std;

/*
	this constructor is a copy constructor 
	is create a new link in the memory instead of just copying the object
	a is the Set need to be copied
	it is O(n)
*/

Set::Set(const Set& a) : Set()
{
	if (a.list == nullptr)		// if a is null return null
	{
		this->list = nullptr;
		return;
	}

	Node* temp = a.list;		// for going to the list without moving a.list

	while (temp != nullptr)		// create list 
	{	
		this->list = cons(car(temp), this->list);
		temp = cdr(temp);
	}

	this->list = reverse(this->list);
}

//////////////////////////////////////////////////////

/*
	the function check the lengt of set
	return the size of the Set
	it is O(n)
*/
int Set::size()
{
	return length(this->list);
}

//////////////////////////////////////////////////////

/*
	the function check the set is empty or not
	return true if the list is empty
	false for not empty
	it is O(1)
*/
bool Set::isEmpty() const
{
	if (this->list == nullptr)
		return true;
	else
		return false;
}

////////////////////////////////////////////////////

/*
	the function find the if the x value exit in the set
	x is the value want to find
	return ture for x is exist in the set false for not exist
	it is O(n)
*/
bool Set::member(int x) const
{
	return searchInOrder(x, this->list);
}

///////////////////////////////////////////////////////

/*
	the functino will insert x value in the set and will be inserted in acdenting order
	x is the value want to insert
	if it just insert the begining of the list it will be O(1)
	otherwise it will be O(n)
*/

void Set::insert(int x)
{
	
	if (this->isEmpty())
		this->list = cons(x, nullptr);

	if (member(x))		// if x also exist in the set end the function 
		return;

	if (x < car(this->list))		// if x nned to be inserted in the first place 
	{
		this->list = cons(x, this->list);
		return;
	}

	Node* temp = this->list;

	while (cdr(temp) != nullptr && car(cdr(temp)) < x)	// go through the set
	{
		temp = cdr(temp);
	}
	setcdr(temp, cons(x, cdr(temp)));
}

//////////////////////////////////////////////////////////

/*
	the function remove search and remove value x in the set if found
	x is the value want to remove
	it is O(n)
*/

void Set::remove(int x)
{
	if (this->list == nullptr)
		return;

	Node* head = this->list;	// for not changing this->list
	Node* temp;		
	Node* before = nullptr;		// sort the before Node

	// check the first one
	if (car(head) == x)
	{
		this->list = cdr(head);
		delete head;
		return;
	}

	while (head != nullptr && car(head) <= x)	// go through the set
	{
		if (car(head) == x)
		{
			temp = head;
			setcdr(before, cdr(head));
			delete temp;
			return;
		}

		// if not found go to next Node
		before = head;
		head = cdr(head);
	}
}

//////////////////////////////////////////////////////////

/*
	the function output the set from stantard output
	the printList int Node.h is O(n)
	so it is O(n)
*/

void Set::print() const
{
	printList(this->list);	// use method in Node.h
}

///////////////////////////////////////////////////////////

/*
  the funtion overload assigment operation which will create a new Set instead of copying address
  the overload constructor is O(n) and there are no other loop or recursion
  so it is O(n)
*/

Set& Set::operator =(Set& a)
{
	if(!this->isEmpty())	// delete the current list  assign the new set later
		deleteList(this->list);
	Set* result = new Set(a);
	this->list = result->list;
	return *result;
}

///////////////////////////////////////////////////////////

/*
  the funtion represent union for the Set
  a and b are the sets wwant to union
  the result will create the union set in the memory
  
  since the function will go through both list at once assume the side of a is n and the side of b is n
  the function will bepend on the longer one, if m is longer than it will be O(m)
*/

const Set operator +(const Set& a, const Set& b)
{
	// check one of them is a null
	if (a.list == nullptr)
		return Set(b);
	if (b.list == nullptr)
		return Set(a);

	// create the set in memory. the Node that are not needed will be deleted
	Set* c = new Set(a);	
	Set* d = new Set(b);

	Node* p = c->list;
	Node* q = d->list;
	Node* k;	// the main way to go
	Node* head;
	Node* temp;

	// find smaller Node
	if (car(p) < car(q))
	{
		k = p;
		p = cdr(p);
	}
	else
	{
		k = q;
		q = cdr(q);
	}
	
	head = k;	// sort the first Node of set

	while (q != nullptr && p != nullptr)	// go througt both set
	{
		/*
		  because p and q are inorder, we donot need to worry the same element will behind them
		  if there are same element go to next one
		*/
		if (car(k) == car(p))		// check if there are same in p them go to next o
		{
			temp = p;
			p = cdr(p);
			delete temp;
			temp = nullptr;
			continue;
		}
		if (car(k) == car(q))		// check if there are same in q then go to next q
		{
			temp = q;
			q = cdr(q);
			delete temp;
			temp = nullptr;
			continue;
		}

		if (car(p) < car(q))	// set k to p
		{
			setcdr(k, p);
			p = cdr(p);
		}
		else		// set k to q
		{
			setcdr(k, q);
			q = cdr(q);
		}

		k = cdr(k);
	}


	// go throug the rest of p
	while (p != nullptr)
	{
		if (car(p) == car(k))
		{
			temp = p;
			p = cdr(p);
			delete temp;
			temp = nullptr;
			continue;
		}

		setcdr(k, p);
		p = cdr(p);
		k = cdr(k);
	}

	// go throug the rest of q

	while (q != nullptr)
	{
		if (car(k) == car(q))
		{
			temp = q;
			q = cdr(q);
			delete temp;
			temp = nullptr;
			continue;
		}
		setcdr(k, q);
		q = cdr(q);
		k = cdr(k);
	}

	//set c and d to NULL sothat the system will not delete them otherwise there will be a bug
	c = NULL;
	d = NULL;
	return Set(head);
}

////////////////////////////////////////////////////////////

/*
  the function represent interseptiong of two sets
  a and b are sets
  return a new set which allocated in memory

  since the function will go through both list at once assume the side of a is n and the side of b is n
  the function will depend on the shorter one, if m is shorter than it will be O(m)
*/

const Set operator *(const Set& a, const Set& b)
{
	if (a.list == nullptr || b.list == nullptr)	// if one of them are empty 
		return Set();

	Set* c = new Set(a);	// create new memory
	Set* d = new Set(b);	// create new memory later will delete the Noded that are not needed
	Node* p = c->list;		// if there are intersecpt p will not be deleted entirely
	Node* q = d->list;		// q will be deleted entirely whether there are intercept or not

	Node* temp;		// for deleting Nodes

	// the below are all for p
	Node* before = nullptr;
	Node* after = cdr(p);
	Node* head = nullptr;

	while (p != nullptr && q != nullptr)		// go through both
	{
		if (car(p) < car(q))	// if p < q then delete p until p >= q
		{
			// some many variable for p is because p is the one will return to funtion
			// and the last Node have to be nullptr. Delete will not assign nullptr
			after = cdr(p);
			if (before != nullptr)
			{
				setcdr(before, nullptr);
			}
			temp = p;
			p = after;
			delete temp;
		}
		else if (car(q) < car(p))		// if q < p then delete q until q >= q
		{
			temp = q;
			q = cdr(q);
			delete temp;
		}
		else   // p == q	(interscept)
		{
			if (head == nullptr)	// defind head 
				head = p;

			// delete q and go to next one 
			temp = q;
			q = cdr(q);
			delete temp;
			temp = nullptr;

			// delete p and go to next one but keep setting p->next to nullptr use after to sort the Node after p
			
			after = cdr(p);
			if (before != nullptr)
			{
				setcdr(before, p);
				setcdr(p, nullptr);
			}
			before = p;
			
			p = after;
		}
		
		

	} // end while loop

	// delete the rest
	if (q != nullptr)
	{
		deleteList(q);
		q = nullptr;
	}

	
	if (p != nullptr && before != nullptr)
	{
		setcdr(before, nullptr);
		deleteList(p);
	}
	
	
	// because once p or q reaches to the end 
	// that mean there will not be any more intercept

	//set c and d to NULL sothat the system will not delete them otherwise there will be a bug
	c = NULL;
	d = NULL;
	return Set(head);

} // end method


/////////////////////////////////////////////////////////////////////

/*
  the function will show the set 
  a is the set
  
  the function printList in Node.h is O(n) because it go throuh the entire array
  so it is O(n)
*/

ostream& operator <<(ostream& os, Set& a)
{
	printList(a.list);
	return os;
}

/////////////////////////////////////////////////////////////////////

/*
  the function will let user input the set
  a is the set needed to be inputed

  the depends on the user input, if the user keep input worng the function will not end 
  but otherwise since the function need to check validation, it is O(n)
*/

istream& operator >>(istream &is, Set& a)
{
	while (true)
	{
		 readList(a);

		if (hasDuplicates(a.list))
		{
			cout << "you enter a has same number in the set" << endl;
			cout << "please enter again";
			deleteList(a.list);
		}
		else
			break;
	}
	return is;
}

/////////////////////////////////////////////////////////////////////

/*
	the function read the set 
*/

void readList(Set &a)
{
	string input;	// to sort input
	int realInput;	// later conver the string
	Node* p = nullptr;

	cout << "please input integer numbers. Enter non-number to end" << endl;
	while (true)
	{
		cin >> input;

		if (!isValid(input))	// check valid input
		{
			// not valid will clear cin and tread as end of input
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			break;
		}
		else
		{
			realInput = stoi(input);
			a.insert(realInput);
		}
	} // end while

}



//////////////////////////////////////////////////////////////////////
/*
	the function check is Set a is a porper subset of Set b
	Set b should have every element that a contain
	the length of b should be longer than a
	if Set a has nothing, it still a subset of b

	pretent a has n elements and b has m elements
	to find the length of a and b it will be O(n) and O(m) so total is O(m + n)
	and there is a for loop and the for loop has a funtion "member(x)' 
	the total will be O(n * m)
*/

bool operator <(const Set& a, const Set& b)
{
	int al = length(a.list);
	int bl = length(b.list);

	if (al >= bl)
		return false;

	for (Node* p = a.list; p != nullptr; p = cdr(p))
	{
		if (!b.member(car(p)))
			return false;
	}

	return true;
}