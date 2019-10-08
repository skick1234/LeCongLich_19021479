#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int PTb2(float a, float b, float c, float &x1, float &x2) {
	float delta = pow(b, 2) - 4*a*c;
	if (delta < 0) {
		x1 = x2 = 0;
		return 0;
	}
	else if (delta == 0) {
		x1 = x2 = -b/(2*a);
		return 1;
	}
	else {
		delta = sqrt(delta);
		x1 = (-b+delta)/(2*a);
		x2 = (-b-delta)/(2*a);
		return 2;
	}
}

int main() {
	float X1, X2, a, b, c;
	cin >> a >> b >> c;
	cout << setprecision(5) << fixed;
	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				cout << "phuong trinh co vo so nghiem";
			else
				cout << "phuong trinh vo nghiem";
		} else {
			if (-c/b > 0)
				cout << "phuong trinh co 2 nghiem\n"
					<< -sqrt(-c/b) << " " << sqrt(-c/b);
			else if (c == 0)
				cout << "phuong trinh co 1 nghiem\n" << (float) 0;
			else
				cout << "phuong trinh vo nghiem";
		}
	} else {
		if (PTb2(a, b, c, X1, X2) == 0)
			cout << "phuong trinh vo nghiem";
		else if(PTb2(a, b, c, X1, X2) == 1 )	{
			if (X1 < 0)
				cout << "phuong trinh vo nghiem";
			else if (X1 == 0)
				cout << "phuong trinh co 1 nghiem\n" << (float) 0;
			else {
				cout << "phuong trinh co 2 nghiem\n";
				cout << -sqrt(X1) << " " << sqrt(X1);
			}
		} else {
			if (X1 < 0) {
				if(X2 < 0)
					cout<< "phuong trinh vo nghiem";
				else if(X2 == 0)
					cout << "phuong trinh co 1 nghiem\n" << (float) 0;
				else {
					cout << "phuong trinh co 2 nghiem\n"
						<< -sqrt(X2) << " " << sqrt(X2);
				}
	 
			}
			else if (X1 == 0) {
				if(X2 < 0)
					cout << "phuong trinh co 1 nghiem\n" << (float) 0;
				else {
					cout << "phuong trinh co 3 nghiem\n"
						<< -sqrt(X2) << " " << (float) 0 << " " << sqrt(X2);
				}
			}
			else {
				if (X2 < 0) {
					cout << "phuong trinh co 2 nghiem\n"
						<< -sqrt(X1) << " " << +sqrt(X1);
				}
				else if (X2 == 0) {
					cout << "phuong trinh co 3 nghiem\n"
						<< -sqrt(X1) << " " << (float) 0 << " " << sqrt(X1);
				}
				else {
					if (X1 > X2)
						cout << "phuong trinh co 4 nghiem\n"
							<< -sqrt(X1) << " " << -sqrt(X2) << " "
							<< sqrt(X2) << " " << sqrt(X1);
					else
						cout << "phuong trinh co 4 nghiem\n"
							<< -sqrt(X2) << " " << -sqrt(X1) << " "
							<< sqrt(X1) << " " << sqrt(X2);
				}
			}
		}
	}
	return 0;
}
 