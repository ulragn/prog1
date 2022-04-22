#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include<cerrno>
#include<complex>

using namespace std;
using namespace Numeric_lib;

//4.feladat
void fel4(){
	int i;
	cout << "Enter ints (char to exit): ";
	while(cin >> i){
		errno = 0;
		double d = sqrt(i);
		if (errno == EDOM)
			cout << "no square root\n";
		else
			cout << "sqrt(" << i << ") = " << d << '\n';
	}
}

//5.feladat
void fel5(){
	cin.clear();
	cin.ignore();
	cout << "Enter 10 floating point values: ";
	Matrix<double> m(10);
	double d;
	for(int i = 0; i < m.size(); i++){
		cin >> d;
		if (!cin) throw runtime_error("Problem reading from cin");
		m[i] = d;
	}
	cout << "Matrix: " << m << '\n';
}

//6.feladat
void fel6(){
	cout << "Multiplication table. Enter n: ";
	int n;
	cin >> n;
	cout << "Enter m: ";
	int m;
	cin >> m;
	Matrix<int,2> mtable(n,m);
	for (Index i = 0; i<mtable.dim1(); ++i) {
		for (Index j = 0; j<mtable.dim2(); ++j) {
			mtable(i,j) = (i + 1) * (j + 1);
			cout << setw(5) << mtable(i,j);
		}
		cout << '\n';
	}
}

//7.feladat
void fel7(){
	Matrix<complex<double>> m(10);
	cout << "\nEnter 10 complex numbers (Re,Im): ";
	complex<double> c;
	for (int i = 0; i<10; ++i) {
		cin >> c;
		if (!cin) throw runtime_error("problem reading complex number");
		m[i] = c;
	}
	complex<double> sum;
	for (Index i = 0; i<m.size(); ++i)
		sum += m[i];
	cout << "Sum: " << sum << '\n';
}

//8.feladat
void fel8(){
	Matrix<int,2> m(2,3);
	cout << "\nEnter six ints: ";
	int n;
	for (int i = 0; i<m.dim1(); ++i)
		for (int j = 0; j<m.dim2(); ++j) {
			cin >> n;
			m(i,j) = n;
		}
	cout << "Matrix:\n" << m << '\n';	
}

int main(){

	//1.feladat
	cout << "size of: \n";
	cout << "char: " << sizeof(char) << '\n';
	cout << "short: " << sizeof(short) << '\n';
	cout << "int: " << sizeof(int) << '\n';
	cout << "long: " << sizeof(long) << '\n';
	cout << "float: " << sizeof(float) << '\n';
	cout << "double: " << sizeof(double) << '\n';
	cout << "int*: " << sizeof(int*) << '\n';
	cout << "double*: " << sizeof(double*) << '\n';

	//2.feladat
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	
	//3.feladat
	cout << "Matrix sizes: \n";
	cout << "1D int, 10 elements: " << sizeof(a) << '\n';
	cout << "1D int, 100 elements: " << sizeof(b) << '\n';
	cout << "1D double, 10 elements: " << sizeof(c) << '\n';
	cout << "2D int, 10x10 elements: " << sizeof(d) << '\n';
	cout << "3D int, 10x10x10 elements: " << sizeof(e) << '\n';
	
	fel4();
	fel5();
	fel6();
	fel7();
	fel8();
	
	
	
}
