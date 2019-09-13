#include <iostream>
#include <fstream>

// using namespace std;
using namespace std;

class complex
{
private:
	double real, imag;
public:
	complex() : real {0}, imag {0} {}
	complex(double r, double i) : real {r}, imag {i} {}
	
	friend ostream & operator<<(ostream &, const complex &);
	friend istream & operator>>(istream &, complex &);
	friend complex & operator+=(complex &, const complex &);
	friend complex & operator+(const complex &, const complex &);
};


ostream & operator<<(ostream & os, const complex & c)
{
	os << "{r:" << c.real << "i:" << c.imag<<"}";
	
	return os;
}

istream & operator >> (istream & is, complex & c)
{
	string s1, s2, s3;
	is >> s1 >> c.real >> s2 >> c.imag >>s3;
	
	if (s1 != "{r:" || s2 != "i:" || s3 != "}") 
		is.setstate(ios_base::failbit);
	return is;
}

complex & operator += (complex & c1, const complex & c2)
{
	c1.real = c1.real + c2.real;
	c1.imag = c1.imag + c2.imag;
	return c1;
}
	
complex & operator + (const complex & c1, const complex & c2)
{
	complex & c3;
	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;
	return c3;
}

int main()
{
	cout << "Enter 0 to read from stdin or 1 to read from 1 file"<<endl;
	int i;
	while (cin >> i) {
		if (i == 0 || i==1)
			break;
	}
	if (i == 0) 
		while ( complex c; cin >> c) 
			complex y {1.00,1.00};	
			cout << c + y << endl;
	else 
		string filename;
	        cin >> filename;
		ifsteam ifs {filename};
		
		if (!ifs)
			return 0;
		else  
			while ( complex c; ifs >> c)
				complex y {1.00,1.00};
				cout << c + y << endl;
	
	return 0;	
}
