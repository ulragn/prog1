#include "Simple_window.h"
#include "Graph.h"


int main()
try
{
	using namespace Graph_lib;
	int x_max = 1920;
	int y_max = 1080;
	int winx = 600;
	int winy = 400;
	
	//12.7.2
	Point tl {100,100};
	Simple_window win {tl,600,400,"My window"};
	win.wait_for_button();
	
	//12.7.3
	Axis x {Axis::x, Point{20,300}, 280, 10, "x axis"}; 
	win.attach(x);
	
	Axis y {Axis::y, Point{20,300}, 280, 10, "y axis"};
	y.set_color(Color::red); //eredeti: cyan
	y.label.set_color(Color::green); //eredeti: dark_red
	win.attach(y);
	win.wait_for_button();
	
	//12.7.4
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	win.attach(sine);
	win.wait_for_button();
	
	//12.7.5
	sine.set_color(Color::blue);
	
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	
	poly.set_color(Color::yellow); //eredeti: red
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.wait_for_button();
	
	//12.7.6
	Rectangle r {Point{200,200}, 100, 150};
	win.attach(r);
	
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	
	poly_rect.add(Point(50,75));
	win.wait_for_button();
	
	//12.7.7
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,2)); //eredeti: 4
	poly_rect.set_style(Line_style(Line_style::dash,4)); //eredeti: 2
	poly_rect.set_fill_color(Color::blue); //eredeti: green
	win.wait_for_button();
	
	//12.7.8
	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(18); //eredeti: 20
	win.wait_for_button();
	
	//12.7.9
	Image ii {Point(100,50),"myboi.jpg"};
	win.attach(ii);
	ii.move(100,200);
	win.wait_for_button();
	
	//12.7.10
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::red); //eredeti: dark_red
	Mark m {Point(100,200),'x'};
	ostringstream oss;
	oss << "screen size: " << x_max << "*" << y_max << "; window size: " << winx << "*" << winy;
	Text sizes {Point{100,20},oss.str()};
	
	Image cal {Point{225,225},"myboimichael.gif"};
	cal.set_mask(Point{40,40},200,150);
		
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	
	win.wait_for_button();
}
catch(exception& e) {
	// some error reporting
	return 1;
}
catch(...) {
	// some more error reporting
	return 2;
}
