#include <iostream>
#include "mint.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	mint m1("999"),m2("301"),m3("");
	m3.aff();
	m3=m1+m2;
	m3.aff();
	m1+=m2;
	std::cout<<"\n";
	m1.aff();
	m1=m1+m2;
	m1.aff();
	return 0;
}
