#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;
typedef Graph_lib::Rectangle rect;

template<class T> class Vector_ref {
public:

void push_back(T&);

void push_back(T*);

T& operator[](int i);

const T& operator[](int i) const;
int size() const;
};

int main(){

	Simple_window win{Point{100, 0}, 800, 1000, "Drill_13"};
	win.wait_for_button();

	const double spaceSize = 100;
	const double gridSize = 800;
	
	Lines grid;
	for(double i; i < gridSize; i+= spaceSize){
	
		grid.add(Point {i,0}, {Point(i, gridSize)});
		grid.add(Point {0,i}, {Point(gridSize, i)});
	}
	grid.set_color(Color::black);
	win.attach(grid);

	win.wait_for_button();
	
	//3.feladat
	Graph_lib::Vector_ref<Rectangle> rectangles;

	for (int i = 0; i < 800; i += 100){
		rectangles.push_back(new Rectangle{Point{i,i}, Point{i+100, i+100}});
		rectangles[rectangles.size()-1].set_fill_color(Color::red);
		win.attach(rectangles[rectangles.size()-1]);
	}
	win.wait_for_button();

	//4.feladat
	Image kep1 {Point{0,300},"cica.jpg"};
	Image kep2 {Point{500,100},"cica.jpg"};
	Image kep3 {Point{300,600},"cica.jpg"};
	win.attach(kep1);
	win.attach(kep2);	
	win.attach(kep3);
	
	win.wait_for_button();
	
	//5.feladat
	


	for(int i = 0; i < 800; i += 100){
		for(int j = 0; j < 800; j += 100){
		//Image take_this {Point{i,j},"takethis.jpg"}; //fentrol le
		Image take_this {Point{j,i},"takethis.jpg"}; //balrol jobbra
		win.attach(take_this);
		win.wait_for_button();
		}
	}
	
	
	
}
