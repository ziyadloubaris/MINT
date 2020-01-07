#include "mint.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

mint::mint(int number) // avec se constructeur je ne peut pas depasser les 4 octe permis
{
	int taille=0;
	int number_cpy=number;
	
	while(number_cpy){
		taille++;
		number_cpy = number_cpy /10;
	}
	mint_number= new char (taille);
	int cpt=0;
	int aide_int ;
	char aide_char[0];
	
	while(number){
		
		aide_int=number%10;
		number=number/10;
		itoa(aide_int , aide_char ,10);
		if(cpt==0)
		{
			strcpy(mint_number,aide_char);	
		}
		else{
			strcat(mint_number,aide_char);	
		}
		cpt++;
		
	}
	
	
	for(int i=0 ; i<cpt/2;i++){
		aide_int=mint_number[i];
		mint_number[i]=mint_number[cpt-1-i];
		mint_number[cpt-1-i]=aide_int;
		
	}

}

mint::mint(char * number) // avec se constructeur je peut depasser la taille permise tant qu'il ya de l'epace dans la RAM
{
	
	if(number!= NULL)
	{
		int i=0;
		int j=0;
		while(number[i]=='0'){ //je calcule le nombre de 0 qu'il ya au debut :)
			i++;
		}
		
		int taille = strlen(number);
		mint_number = new char(taille);
		
		while(number[i]!='\0'){
			
			mint_number[j]=number[i];
			i++;
			j++;
		}
		mint_number[j]='\0';
	
	}
	else
	{
		mint_number=new char(0);
	}
}
mint::mint(const mint& m1)//constructeur de copy
{
	mint_number=new char(strlen(m1.mint_number));
	strcpy(mint_number,m1.mint_number);
}

mint operator +(mint const &m1 , mint const &m2)
{
	char *resultat;	
	int taille_resultat;

	if(strlen(m1.mint_number) > strlen(m2.mint_number))//je determine la taille la plus grande pour pouvoire allouer le resultat
	{
		resultat=new char(strlen(m1.mint_number)+1);
		taille_resultat=strlen(m1.mint_number)+1;	
	}
	else if (strlen(m1.mint_number) < strlen(m2.mint_number))
	{
		resultat=new char(strlen(m2.mint_number)+1);
		taille_resultat=strlen(m2.mint_number)+1;
	}
	else
	{
		resultat=new char(strlen(m2.mint_number)+1);
		taille_resultat=strlen(m2.mint_number)+1;	
	}
	
	bool retenue = false;
	int i=1;
	int number_m1 , number_m2 , number_resultat;	
	char aide_char[0];
	char aide_char2[0];

	while( taille_resultat>=0)
	{
		if(strlen(m1.mint_number)-i>=0)// la transformation des chiffre from char to int 
		{
			aide_char2[0]=m1.mint_number[strlen(m1.mint_number)-i];
			number_m1=atoi(aide_char2);	
		}
		else // si nous avons parcouru toute la chaine de m1 mais que la taille est encore >= 0 on doit pouvoir faire la somme 
		{
			number_m1=0;
		}
		
		if(strlen(m2.mint_number)-i>=0)// la transformation des chiffre from char to int
		{
			aide_char2[0]=m2.mint_number[strlen(m2.mint_number)-i];
			number_m2=atoi(aide_char2);	
		}
		else
		{
			number_m2=0;
		}
		
		number_resultat=number_m1+number_m2;
	
	
		if(retenue == false)
		{
			if(number_resultat <10)
			{
				itoa(number_resultat, aide_char , 10);
				resultat[ taille_resultat] = aide_char[0];		
			}
			else
			{
				itoa((number_resultat)%10, aide_char , 10);
				resultat[ taille_resultat] = aide_char[0];
				retenue=true;
			}
		}
		else
		{
			if(number_resultat+1<10)
			{
				itoa(number_resultat+1, aide_char , 10);
				resultat[ taille_resultat] = aide_char[0];
				retenue = false;
			}
			else
			{
				itoa((number_resultat+1)%10, aide_char , 10);
				resultat[ taille_resultat] = aide_char[0];
				retenue = true;
			}
					
		}	
		
		 taille_resultat--;
		 i++;

	}

	return resultat;
}

mint& mint::operator +=(mint m2)
{
	*this = *this + m2;
	return *this;
}

void mint::aff()
{
	cout<<mint_number<<"\n";
}
//------------------------------------------------------------------
bool operator >(mint m1, mint m2)
{
	return (strcmp(m1.mint_number,m2.mint_number) >0)  ?  1 :  0 ;
}

bool operator <(mint m1, mint m2)
{
	return (strcmp(m1.mint_number,m2.mint_number) <0)  ?  1 :  0 ;
}
//------------------------------------------------------------------
bool operator ==(mint m1, mint m2)
{
	return (strcmp(m1.mint_number,m2.mint_number) ==0)  ?  1 :  0 ;
}
//-----------------------------------------------------------------
bool operator >=(mint m1, mint m2)
{
	return (strcmp(m1.mint_number,m2.mint_number) >=0)  ?  1 :  0 ;
}

bool operator <=(mint m1, mint m2)
{
	return (strcmp(m1.mint_number,m2.mint_number) <=0)  ?  1 :  0 ;
}
//------------------------------------------------------------------

mint operator +(mint const &m1 , int m2)
{
	mint m=m2 ,result=m2;	

	result.aff();
		result=m1+m;
	return result;
}

mint& mint::operator ++()
{
	*this = *this+1;
	return *this;
}
mint mint::operator ++(int)
{
	mint result = *this;
	++(*this);

	return result;
}

