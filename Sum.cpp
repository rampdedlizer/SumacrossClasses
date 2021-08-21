#include <iostream>
class DM;

class DB
{
	float m, c;
public:
	void getdata()
	{
		std::cout << " Enter the metre and centimeter respectively : ";
		std::cin >> m >> c;
	}

	void display()
	{
		std::cout << m << " metres " << c << " centimeters" << std::endl;
	}

	friend void sum(DB, DM);
};

class DM
{
	float f, i;
public:
	void getdata()
	{
		std::cout << " Enter the feets and inches respectively : ";
		std::cin >> f >> i;
	}

	void display()
	{
		std::cout << f << " feets " << i << " inches " << std::endl;
	}

	friend void sum(DB, DM);
};

void sum(DB b1, DM b2)
{
	std::cout << " Enter whether you want sum to be printed in feets/inches or metres/centimeters" << std::endl;

	std::cout << " Press 1 for metres and centimeters " << std::endl;

	std::cout << " Press 2 for feets and inches " << std::endl;

	int x;

	std::cin >> x;

	if (x == 1)
	{
		// Taking into centimeters(ignoring some decimals)

		b1.m = b1.m * 100;
		b2.f = b2.f *31.25;
		b2.i = b2.i * 2.54;

		int z = b1.m + b2.f + b1.c + b2.i;


		b1.m = z / 100;
		b1.c = z % 100;
		
		
		std::cout << " Your preferred sum is " << std::endl;
		b1.display();
	}
	else
	{
		b2.f = b2.f + b1.m;
		b2.i = b2.i + b1.c;
		// Taking into inches(ignoring some decimals)

		b2.f = b2.f*12;
		b1.m = b1.m*39.37;
		b1.c = b1.c*0.39;

		int a = b2.f+b1.m+b1.c;

		b2.f = a / 12;
		b2.f = a % 12;

		std::cout << " Your preferred sum is " << std::endl;
		b2.display();
	}
}

int main()
{
	DB o1;
	DM o2;
	 
	o1.getdata();
	o2.getdata();


	sum(o1, o2);
}
