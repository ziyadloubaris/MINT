#include <iostream>
#include "mint.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	mint m1(1), m2("999889"),m3("") ,m4(0);
	m3=m1+m2;
	++m3;
	m3.aff();
	if(m3 >= 10 )
	{
	//	m3.aff();
		std::cout<< m1<<" + "<<m2<<" = "<<m3<<"\n";
	}
	m4=++m3;
	m4.aff();
	m4++;
	m4.aff();
	return 0;
}
