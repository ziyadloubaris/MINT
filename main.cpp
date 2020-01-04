#include <iostream>
#include "mint.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	//std::cout<<"hello";
	mint m1("300"), m2("301"),m3("");
	m1.aff();
	m2.aff();
//	m3.aff();
	m3=m1+m2;
	m2=m1;
	if(m1==m2)
	{
		m1.aff();
	}
	else if (m1<m2)
	{
		m2.aff();
	}
/*	m3.aff();
	m1+=m2;
	std::cout<<"\n";
	m1.aff();
	m1=m1+m2;
	m1.aff();
*/
	return 0;
}
