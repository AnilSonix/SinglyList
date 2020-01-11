#include<iostream>
#include "List.h"

void main() {
	{
		List l;

		l.insertLast(11);
		l.insertLast(22);
		l.insertLast(33);
		l.insertLast(44);

		l.removeFrom(2);

		l.show();
	}
}
