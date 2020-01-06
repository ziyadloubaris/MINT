#ifndef MINT_H
#define MINT_H

class mint
{
	public:
		mint(int number);
		mint(char * number);
		mint(const mint&);
		void aff();
		friend mint operator +(mint const &m1 , mint const &m2);
		friend mint operator +(mint const &m1 , int m2);
		mint& operator +=(mint m2);
		mint& operator ++();
		mint operator ++(int);
		friend bool operator >(mint m1 , mint m2);
		friend bool operator <(mint m1 , mint m2);
		friend bool operator ==(mint m1 , mint m2);
		friend bool operator >=(mint m1 , mint m2);
		friend bool operator <=(mint m1 , mint m2);
	protected:
		char * mint_number;
};

#endif
