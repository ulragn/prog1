#include "std_lib_facilities.h"


//1.feladat
class B1{
public:
	virtual void vf(){
		cout << "B1::vf" << '\n';
	}
	void f(){
		cout << "B1::f" << '\n';
	}
	virtual void pvf(){
		cout << "B1::pvf" << '\n';
	}
};


//2.feladat
class D1 : public B1{
public:
	void vf() override {
		cout << "D1::vf" << '\n';
	}
	//4.feladat
	void f() {
		cout << "D1::f" << '\n';
	}
	void pvf() {
		cout << "D1::pvf" << '\n';
	}
};

//6.feladat
class D2 : public D1{
public:
	void pvf() override{
		cout << "D2::pvf" << '\n';
	}
};

//7.feladat
class B2{
public:
	virtual void pvf() = 0;
};

class D21 : public B2{
public:
	void pvf() override {
		cout << s << '\n';
	}
	string s;
};

class D22 : public B2{
public:
	void pvf() override{
		cout << i << '\n';
	}
	void f(B2& b2ref){
		b2ref.pvf();
	}
	int i;
};



int main(){
	
	cout << "B1:" << '\n';
	B1 b1;
	b1.vf();
	b1.f();
	cout << '\n';
	
	cout << "D1:" << '\n';
	D1 d1;
	d1.vf();
	d1.f();
	cout << '\n';
	
	//3.feladat
	cout << "B1ref:" << '\n';
	B1& b1ref = d1;
	b1ref.vf();
	b1ref.f();
	cout << '\n';
	
	//5.feladat
	cout << "pvf:" << '\n';
	b1.pvf();
	d1.pvf();
	b1ref.pvf();
	cout << '\n';
	
	
	cout << "D2:" << '\n';
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
	cout << '\n';
	
	//7.feladat
	D21 d21;
	d21.s = "Valami szoveg";

	
	D22 d22;
	d22.i = 15;


	d22.f(d21);
	d22.f(d22);
	cout << '\n';
	
	
	keep_window_open();
	
	
	
	
	return 0;


}
