#include "std_lib_facilities.h"

template<class Iter>
void print(Iter f, Iter e, const string& s)
{
    cout << s << ": { ";
    while (f!=e) {
        cout << *f << ' ';
        ++f;
    }
    cout << "}\n";
}

//6.feladat
template<typename Iter1, typename Iter2>
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while (f1 != e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}

	return f2;
}

int main(){
	
	//1.feladat
	array<int,10> arr;
	for(int i = 0; i<10; ++i)
		arr[i] = i;
	print(arr.begin(), arr.end(), "arr\n");
	//2.feladat	
	vector<int> vect;
	for(int i = 0; i < 10; i++)
		vect.push_back(i);
	print(vect.begin(), vect.end(), "vect\n");
	//3.feladat
	list<int> lista;
	for(int i = 0; i < 10; i++)
		lista.push_back(i);
	print(lista.begin(), lista.end(), "lista\n");
	
	//4.feladat
	array<int,10> arr_copy = arr;
	print(arr_copy.begin(), arr_copy.end(),"arr_copy\n");
	vector<int> vect_copy = vect;
	print(vect_copy.begin(), vect_copy.end(),"vect_copy\n");
	list<int> lista_copy = lista;
	print(lista_copy.begin(), lista_copy.end(),"lista_copy\n");
	
	//5.feladat
	for(array<int,10>::iterator p = arr.begin(); p!=arr.end(); ++p)
		*p += 2;
	print(arr.begin(),arr.end(),"arr+=2\n");

	for(vector<int>::iterator p = vect.begin(); p!=vect.end(); ++p)
        	*p += 3;
        print(vect.begin(),vect.end(),"vect+=3\n");

	for(list<int>::iterator p = lista.begin(); p!=lista.end(); ++p)
        *p += 5;
	print(lista.begin(),lista.end(),"lista+=5\n");

	//7.feladat
	vector<int>::iterator vect_it = mycopy(arr.begin(),arr.end(),vect.begin());
	array<int,10>::iterator arr_it = mycopy(lista.begin(),lista.end(),arr.begin());

	if (vect_it!=vect.begin() && arr_it!=arr.begin()) {
        	print(arr.begin(),arr.end(),"arr copied from lista");
        	print(vect.begin(),vect.end(),"vect copied from arr");
        	print(lista.begin(),lista.end(),"lista");
	
	//8.feladat
	vect_it = find(vect.begin(),vect.end(),3);
	if (vect_it != vect.end())
        	cout << "In vect, 3 has index " << vect_it-vect.begin() << ".\n";

	list<int>::iterator lista_it = find(lista.begin(),lista.end(),27);

	if (lista_it!=lista.end()) {
		int idx = 0;
		for (list<int>::iterator iter = lista.begin(); iter!=lista_it; ++iter)
			++idx;
		cout << "In lista, 27 has index " << idx << ".\n";
	}
	else
		cout << "27 is not in lista.\n";
	}
}
