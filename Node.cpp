/*
 *Name: Zhilong Gan
 *Student Number: 100331942
 *Course Number: CPSC 1160
 *Date: Jul 25, 2019
 *Purpose: this is the implementation of the Node class
 *Assignment 8
 */


/*
  the file contain the implement funtion in Node.h
*/

#include<iostream>
#include<string>
#include"Node.h"

using namespace std;

/*
  the functon will get the value for a Node
  p is the Node
*/
int car(const Node* p)
{
	if (p == nullptr)
	{
		cout << "null note in car " << endl;
		exit(1);
	}

	return p->value;
}

///////////////////////////////////////////////////

/*
  the function get the next Node for a Node
  p is the Node
*/

Node* cdr(const Node* p)
{
	if (p == nullptr)
	{
		cout << "null note in cdr " << endl;
		exit(1);
	}

	return p->next;
}


///////////////////////////////////////////////////

/*
  the function set the value for a Node
  p is the Node 
  n is the value
*/

void setcar(Node* p, int n)
{
	if (p == nullptr)
	{
		cout << "null note in setcar" << endl;
		exit(1);
	}

	p->value = n;
}

//////////////////////////////////////////////////////

/*
  the function set the next Node for a Node
  p is the Node
  q is the next Node
*/

void setcdr(Node* p, Node* q)
{
	if (p == nullptr)
	{
		cout << "null note in setcdr" << endl;
		exit(1);
	}

	p->next = q;
}

/////////////////////////////////////////////////////

/*
  the functon create a Node
  value is the value need to set
  q is the next Node 
*/

Node* cons(int value, Node* q)
{
	Node* p = new Node;
	p->value = value;
	p->next = q;

	return p;
}

//---------------------------------------------------


//----------------------------------------------------

/*
  the function return the length of a list
  p is the first Node of a list
*/

int length(Node* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + length(cdr(p));
	}
}


///////////////////////////////////////////////////////////

/*
  the function check is x exist in a list
  x is the nummber need to be search
  p is the first Node is a list
  return true for exist false for not
*/

bool searchInOrder(int x, Node* p)
{
	if (p == nullptr)
		return false;

	if (car(p) == x)
		return true;

	if (car(p) > x)		//once p value large than x the, there are no need to search rest of the list 
		return false;

	return searchInOrder(x, cdr(p));
}


/////////////////////////////////////////////////////////

/*
  the function check is there same numbers is a list
  p is the first note of lsit
  return ture for has same numbers false for not
*/

bool hasDuplicates(Node* p)
{
	if (p == nullptr)
		return false;

	if (search(car(p), cdr(p)))  // using search function 
		return true;
	else
		return hasDuplicates(cdr(p));	// search next one
}

//////////////////////////////////////////////////////////

/*
  the function search x in a list
  x is the value need to be searched
  p is the first node of the list
  reutrn true for has x false for not
*/

bool search(int x, Node* p)
{
	if (p == nullptr)    // search to the end
		return false;
	if (car(p) == x)	// if found 
		return true;

	return search(x, cdr(p));	// search next ont
}

/////////////////////////////////////////////////////////

/*
  the function append x to the end of the list 
  x is the value need to be append
  p is the first node of the list
*/

Node* append(int x, Node* p)
{
	if (p == nullptr)  // p is the end of the list
	{
		p = cons(x, nullptr);	// create x
		return p;
	}
	if (cdr(p) == nullptr)   // p is the last Node of the list
	{
		setcdr(p, cons(x, nullptr)); // create and connect
		return p;
	}

	append(x, cdr(p));		// recursion

	return p;
}

/////////////////////////////////////////////////////////////

/*
  the function reverse a list
  p is the first Node of a list
  return the new fist Ndoe of the reversed list
*/

Node* reverse(Node* p)
{
	if (p == nullptr)
		return p;

	Node* q = p;
	// find the end Node, which will become head Node after reverse 
	while (cdr(q) != nullptr)
	{
		q = cdr(q);
	}
	// q will be the end Node

	reverseHelper(p);		// reverse the lsit
	return q;
}

//////////////////////////////////////////////////

/*
  the function reverse a lsit
  p is the fist Node of the list
*/
Node* reverseHelper(Node* p)
{
	// go down to the last Node 
	if (cdr(p) == nullptr)
	{
		return p;
	}

	Node* q = reverseHelper(cdr(p));	// q will be the next node of p 

	setcdr(q, p);	// reverse the Node
	setcdr(p, nullptr);		// break the origanial connecttion 
	return p;
}

//////////////////////////////////////////////////

/*
  the function compare the length of 2 lists
  p is the first Node of the list that want to compare
  q is the fist Node of the lsit that compare to 
  reutrn ture for p is longer false for not
*/

bool isLonger(Node* p, Node* q)
{
	while (true)
	{
		// see which list go to the end first
		if (p == nullptr)
			return false;

		if (q == nullptr)
			return true;

		// go to next Node
		p = cdr(p);
		q = cdr(q);
	}
}

/////////////////////////////////////////////////////////

/*
  the functon will return the ith Node is a lsit
  p is the fist Node in a list
  i is the ith Node 
*/

Node* ithNode(Node* p, int i)
{
	if (i < 0)
	{
		cout << "ithNode is negative" << endl;
		exit(1);
	}

	int n = 0;	// count 

	while (p != nullptr)
	{
		if (n == i)
			return p;

		p = cdr(p);		// go to next Node
		n++;
	}

	return nullptr;		// if i larger than the length of list return nullptr
}

////////////////////////////////////////////////////////////

/*
  the function will delete a list
  p is the first node of a list
*/

Node* deleteList(Node* p)
{
	Node* temp;  // to sort current node

	while (p != nullptr)
	{
		temp = p;
		p = cdr(p);		// go to next node	
		delete temp;	// delete the current Node
	}

	return p;		// p should be nullptr at the end
}

//////////////////////////////////////////////////////////////

/*
  the function will merge two ordered list 
  p is the fist node of 1 list
  q is the first node of the other list
*/

Node* mergeTwoOrderedLists(Node* p, Node* q)
{
	if (p == nullptr)
		return q;
	if (q == nullptr)
		return p;

	Node* k;  // extra variable for magering can be treated as third link list 
	Node* head;		// to keep the head for third list

	// find out which list should be the first node of the third list 
	if (car(p) > car(q))
	{
		k = q;
		q = cdr(q);
	}
	else
	{
		k = p;
		p = cdr(p);
	}

	head = k;	// after know which k is first sort it first 

	// merging them 
	while (p != nullptr && q != nullptr)
	{
		if (car(p) < car(q))
		{
			setcdr(k, p);	// connect k to p
			p = cdr(p);		
			k = cdr(k);
		}
		else
		{
			setcdr(k, q);	// connect k to q
			q = cdr(q);
			k = cdr(k);
		}
	}

	// merge the rest 
	while (p != nullptr)
	{
		setcdr(k, p);
		k = cdr(k);
		p = cdr(p);
	}

	while (q != nullptr)
	{
		setcdr(k, q);
		k = cdr(k);
		q = cdr(q);
	}

	return head;
}

///////////////////////////////////////////////////////////////

/*
  the function conver an array to a list
  arr is the array
  i the number of element in arrr
*/

Node* array2List(int arr[], int n)
{
	Node* p = nullptr;

	for (int i = n - 1; i >= 0; i--)
	{
		p = cons(arr[i], p);
	}

	return p;
}

///////////////////////////////////////////////////////////////

/*
  the function read from standard input and create list from the number in the input
*/

Node* readList()
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
			p = cons(realInput, p);
		}
	} // end while

	return reverse(p);
}

////////////////////////////////////////////////////

/*
  the function will check the validation for input
  input should be an integer and accept negative
  input is the string
*/

bool isValid(string input)
{
	for (int i = 0; i < input.length(); i++)	// check each letter
	{
		if (input[i] > '9' || input[i] < '0')	
		{
			if (input[i] == '-' && i == 0)	// accept negative
				continue;
			else
				return false;
		}
	}

	return true;
}

///////////////////////////////////////////////////////

/*
  the function will print the list on standard output
  p is the first Node of the list
*/

void printList(Node* p)
{
	cout << "[ ";
	while (p != nullptr)
	{
		cout << car(p) << " ";
		p = cdr(p);
	}
	cout << "]" << endl;
}