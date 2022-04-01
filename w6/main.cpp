#include "std_lib_facilities.h"


template<class T> struct S {
    S() : val(T()) { }
    S(T d) : val(d) { }     
    T& operator=(const T&); 
    T& get();               
    const T& get() const;   
    void set(const T& d);   
private:
    T val;
};

template<class T> T& S<T>::operator=(const T& d)
{
    val = d;
    return val;
}


template<class T> T& S<T>::get() { return val; }

template<class T> const T& S<T>::get() const { return val; }

template<class T> void S<T>::set(const T& d) { val = d; }


template<class T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}

template<class T> void read_val(T& v)
{
    cin >> v;
}


template<class T> ostream& operator<<(ostream& os, const vector<T>& d)
{
    os << "{ ";
    for (int i = 0; i<d.size(); ++i) {
        os << d[i];
        if (i<d.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<class T> istream& operator>>(istream& is, vector<T>& d)
{
    char ch1;
    char ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if (!is) return is;
    if (ch1!='{') {
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin>>temp>>ch2 && ch2==',') {
        v_temp.push_back(temp);
    }
    if (ch2!='}') {
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp); // ch2=='}', read last value

    
    d = v_temp;
}
int main(){
	
	S<int> s_int(29);
	S<char> s_char('h');
	S<double> s_double(2.5);
	S<string> s_string("haliho");
	vector<int> vint;
	vint.push_back(2);
	vint.push_back(4);
	vint.push_back(6);
	S< vector<int>> s_vecti(vint);
	
	//4.feladat
	
	/*cout << "s_int: " << s_int.val << '\n';
	cout << "s_char: " << s_char.val << '\n';
	cout << "s_double: " << s_double.val << '\n';
	cout << "s_string: " << s_string.val << '\n';
	for (int i = 0; i <s_vecti.val.size(); ++i)
		cout << "s_vecti: " << s_vecti.val[i] << '\n';*/
	
	//8.feladat
	cout << "s_int: " << s_int.get() << '\n';
	cout << "s_char: " << s_char.get() << '\n';
	cout << "s_double: " << s_double.get() << '\n';
	cout << "s_string: " << s_string.get() << '\n';
	for (int i = 0; i <s_vecti.get().size(); ++i)
		cout << "s_vecti: " << s_vecti.get()[i] << '\n';
	cout << s_vecti.get() << "\n";
	
	
	//9.feladat
	s_int.set(30);
	s_char.set('k');
	s_double.set(5.2);
	s_string.set("haho");
	vint[1] = 1;
	s_vecti.set(vint);
	cout << "s_int: " << s_int.get() << '\n';
	cout << "s_char: " << s_char.get() << '\n';
	cout << "s_double: " << s_double.get() << '\n';
	cout << "s_string: " << s_string.get() << '\n';
	for (int i = 0; i <s_vecti.get().size(); ++i)
		cout << "s_vecti: " << s_vecti.get()[i] << '\n';
	cout << s_vecti.get() << "\n";
	
	
	//10.feladat
	s_int = 31;
	s_char = 'j';
	s_double = 22.5;
	s_string = "halihohaho";
	vint[1] = 3;
	s_vecti = vint;
	cout << "s_int: " << s_int.get() << '\n';
	cout << "s_char: " << s_char.get() << '\n';
	cout << "s_double: " << s_double.get() << '\n';
	cout << "s_string: " << s_string.get() << '\n';
	for (int i = 0; i <s_vecti.get().size(); ++i)
		cout << "s_vecti: " << s_vecti.get()[i] << '\n';
	cout << s_vecti.get() << "\n";
	
	//11.feladat
	const S<int> c_s_int(5);
	cout << "\nc_s_int: " << c_s_int.get() << "\n";
	
	//13.feladat
	cout << "\ns_int: ";
	read_val(s_int);
	cout << "s_char: ";
	read_val(s_char);
	cout << "s_double: ";
	read_val(s_double);
	cout << "s_string: ";
	read_val(s_string);
	cout << "\ns_int: " << s_int.get() << "\n";
	cout << "s_char: " << s_char.get() << "\n";
	cout << "s_double: " << s_double.get() << "\n";
	cout << "s_string: " << s_string.get() << "\n\n";
	
	//14.feladat
	cout << "\ns_vecti: ";
	read_val(s_vecti);
	cout << "\ns_vecti: " << s_vecti.get() << "\n";
	
	
}
