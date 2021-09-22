#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main()
{
	int	years;
	double	principal;
	double	apr;

	cerr << "Please enter the principal: ";
	cin >> principal;

	cerr << "Please enter the APR: ";
	cin >> apr;

	cerr << "Please enter the number of years: ";
	cin >> years;

	double	R = apr / 12;	// periodic interest rate
	int	    N = years * 12;	// number of periods

	double	payment = principal * R / (1 - pow(1 + R, -N));

	cout.setf(ios::fixed);		// fixed point output
	cout.precision(2);		    // two places after the .

	cout << "My payment is: " << payment << endl;

	double	balance = principal;
	double	total_interest = 0;
	double	total_principal = 0;

	for (int i = 1; i <= N; i++)
	{
		double	to_interest = balance * R;
		double	to_principal = payment - to_interest;
		total_interest += to_interest;
		total_principal += to_principal;

		balance -= (payment - to_interest);

		cout << setw(3) << i << ": " << setw(10) << balance <<
			setw(10) << to_interest << setw(10) << to_principal <<endl;
	}

	cout << endl << setw(25) << total_interest << setw(10) <<
		total_principal << endl;

	return 0;
}