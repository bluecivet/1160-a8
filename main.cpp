/*
 *Name: Zhilong Gan
 *Student Number: 100331942
 *Course Number: CPSC 1160
 *Date: Jul 25, 2019
 *Purpose: this is the test function
 *Assignment 8
 */


#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	
	Set s, t; 


	s.insert(3); 
	s.insert(1);
	s.insert(9);
	s.insert(3);
	s.insert(7);
	s.insert(5);
	cout << "s = " << s << "\n";
	cout << "\texpecting: s = { 1 3 5 7 9 }\n";

	if (!s.member(2))         
		cout << "2 is not in the set s as expected\n";
	else        
		cout << "ERROR: 2 is in the set s\n";     


	if (s.member(7))        
		cout << "7 is in the set s as expected\n"; 
	else        
		cout << "ERROR: 7 is NOT in the set s\n"; 
	
	cout << "|s|=" << s.size() << "\n";
	cout << "\texpecting:|s|= 5\n";

	s.remove(7);
	s.remove(1);
	s.remove(9);
	s.remove(10); 
	cout << "\nafter the removals: s = " << s << "\n"; 
	cout << "\texpecting: s = { 3 5 }\n";  

	s.insert(1);
	s.insert(7);
	s.insert(3);  
	cout << "with insertions: s = " << s << "\n";  
	cout << "\texpecting: s = { 1 3 5 7 }\n";   

	t.insert(3);
	t.insert(5);
	t.insert(4);   
	cout << "with insertions: t = " << t << "\n";

	Set a1 = s + t;  
	cout << "s union t = " << a1 << "\n";
	s.remove(3); 
	t.remove(4); 
	cout << "remove 3: s = " << s << "\n";  
	cout << "remove 4: t = " << t << "\n";
	s.insert(3); 
	t.insert(4); 
		
	cout << "insert 3: s = " << s << "\n";   
	cout << "insert 4: t = " << t << "\n";   
	Set b1 = s * t;    
	cout << "s intersect t = " << b1 << "\n";  
	cout << "s = " << s << "\n"; 
	cout << "t = " << t << "\n"; 
	

	// my test
	Set a;
	cout << "is a empty before insert should be 1   real : " << a.isEmpty() << endl;
	cout << "find number in a before inset should be 0   real: " << a.member(5) << endl;
	cout << "remove a empty set should be nothing happend" << endl;
	a.remove(5);
	cout << "after remove " << endl;

	a.insert(5);
	cout << "is a empty after insert should be 0     real: " << a.isEmpty() << endl;
	cout << "find exist number in a after insert should be 1     real: " << a.member(5) << endl;
	cout << "find non exist number in a after insert should be 0    real: " << a.member(1) << endl;
	cout << "two print list method both should be [ 5 ]" << endl;
	a.print();
	cout << a << endl;

	// insert in reverse order and some of them will repeat
	a.insert(5);    // insert 5 again
	a.insert(4);
	a.insert(1);
	a.insert(4);    // insert 4 again
	a.insert(2); 
	a.insert(1);
	a.insert(3);
	a.insert(3);   // insert 4 again
	cout << "output should be 1 2 3 4 5 " << endl;
	cout << a << endl;

	cout << "remove non exist number should be nothing happened" << endl;
	a.remove(6);
	cout << "after remove shoud be 1 2 3 4 5   a = " << a << endl;

	cout << "remove 3  1  5" << endl;
	a.remove(3);
	a.remove(1);
	a.remove(5);
	cout << "after remove should be 2 4    a = " << a << endl;


	// create b for + and *
	Set b;
	Set c = a + b;
	Set c2 = a * b;
	Set c3 = b + a;

	Set c4 = b * a;
	cout << "before inserting b should be  2 4  , a + b = " << c << endl;
	cout << "before inserting b should be [ ]  , a * b = " << c2 << endl;
	cout << "before inserting b should be 2 4 , b + a = " << c3 << endl;
	cout << "before inserting b should be [ ] , b * a = " << c4 << endl;
	cout << "a < b should be 0    real:" << (a < b) << endl;
	cout << "b < a should be 1    real:" << (b < a) << endl;
	
	b.insert(4);
	a.remove(4);
	Set d = b + a;
	Set d2 = b * a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "after inseting b should be 2 4, b + a = " << d << endl;
	cout << "after inseting b should be [ ], b * a = " << d2 << endl;

	cout << "insert one more thing" << endl;
	b.insert(7);
	
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	Set d3 = b + a;
	cout << "after inseting b should be 2 4 7, b + a = " << d3 << endl;
	Set d4 = b * a;
	cout << "after inseting b should be [ ] , b * a = " << d4 << endl;
	Set d5 = a + b;
	cout << "after inseting b should be 2 4 7, a + b = " << d5 << endl;
	Set d6 = a * b;
	cout << "after inseting b should be [ ], a * b = " << d6 << endl;
	cout << "a < b should be 0    real:" << (a < b) << endl;
	cout << "b < a should be 0    real:" << (b < a) << endl;

	cout << "inset one more thing in b" << endl;
	b.insert(2);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	Set e = b + a;
	cout << "after inseting b should be 2 4 7 , b + a = " << e << endl;
	Set e1 = b * a;
	cout << "after inseting b should be 2, b * a = " << e1 << endl;
	Set e2 = a + b;
	cout << "after inseting b should be 2 4 7, a + b = " << e2 << endl;
	Set e3 = a * b;
	cout << "after inseting b should be 2, a * b = " << e3 << endl;
	cout << "a < b should be 1    real:" << (a < b) << endl;
	cout << "b < a should be 0    real:" << (b < a) << endl;


	cout << "insert more thing" << endl;
	a.insert(7);
	b.insert(3);
	b.insert(4);
	a.insert(1);
	a.insert(3);
	a.insert(5);
	cout << "size = " << a.size() << " a = " << a << endl;
	cout << "size = " << b.size() << " b = " << b << endl;
	Set e4 = b + a;
	cout << "after inseting b should be 1 2 3 4 5 7, b + a = " << e4 << endl;
	Set e5 = b * a;
	cout << "after inseting b should be 2 3 7 , b * a = " << e5 << endl;
	Set e6 = a + b;
	cout << "after inseting b should be 1 2 3 4 5 7, a + b = " << e6 << endl;
	Set e7 = a * b;
	cout << "after inseting b should b2 2 3 7, a * b = " << e7 << endl;
	cout << "a < b should be 0    real:" << (a < b) << endl;
	cout << "b < a should be 0    real:" << (b < a) << endl;

	Set f;
	cout << "please input a set" << endl;
	cin >> f;
	cout << f;

	Set g(f);
	cout << "before changing g and f" << endl;
	cout << "should be same as input   g = " << g;
	cout << "should be same as input   f = " << f;
	g.insert(10);
	cout << "after inserting 10 into g" << endl;
	cout << "should be input and have a 10   g = " << g;
	cout << "should be same as input  f = " << f;

	Set g1;
	g1 = f;
	cout << "before changing g1 and f" << endl;
	cout << "should be same as input    g1 = " << g1;
	cout << "should be same as input    f = " << f;
	g1.insert(20);
	cout << "after inserting 20 into g1" << endl;
	cout << "should be same as input and have a 20   g1 = " << g1;
	cout << "should be same as input   f = " << f;


	Set h;
	h.insert(1);
	h.insert(2);
	h.insert(3);
	
	Set j;
	j.insert(1);
	j.insert(2);
	j.insert(3);

	cout << "h = " << h;
	cout << "j = " << j;

	Set k = h + j;
	cout << "after inseting b should be 1 2 3 , h + j = " << k << endl;
	Set k1 = h * j;
	cout << "after inseting b should be 1 2 3 ,  h * j = " << k1 << endl;
	Set k2 = j + h;
	cout << "after inseting b should be 1 2 3 , j + h = " << k2 << endl;
	Set k3 = j * h;
	cout << "after inseting b should be 1 2 3 , j * h = " << k3 << endl;

	cout << "j < h should be 0    real: " << (j < h) << endl;
	cout << "h < j should be 0    real: " << (h < j) << endl;



	return 0;
}