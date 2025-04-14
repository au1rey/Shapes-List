/*******************
Name: Audrey Saidel
Student ID: 2589516
Email: audrey.saidel@snhu.edu
Assignment: Final Project
Title: Shapes and Inheritance
Description of File: .cpp for Shape class
******************/
#include "Shape.h"
#include <math.h>
#include <iostream>

using namespace std;

//Initialize PI
const float Shape::PI = 3.14159f;

Shape::~Shape() {
	
}

void Shape2D::ShowArea() const {
	cout << "Area: " << Area() << endl;
}

void Shape3D::ShowVolume() const {
	cout << "Volume: " << Volume() << endl;
}

//Operator Overloading
//Shape2D
bool Shape2D::operator>(const Shape2D& rhs) const  //Returns true or false to greater area
{
	return Area() > rhs.Area();
}
bool Shape2D::operator<(const Shape2D& rhs) const  //Returns true or false to lesser area
{
	return Area() < rhs.Area();
}
bool Shape2D::operator==(const Shape2D& rhs) const //Returns true or false to if areas are equal
{
	return Area() == rhs.Area();
}
//Shape3D
bool Shape3D::operator>(const Shape3D& rhs) const   //Returns true or false to greater volume
{
	return Volume() > rhs.Volume();
}
bool Shape3D::operator<(const Shape3D& rhs) const  //Returns true or false to lesser volume
{
	return Volume() < rhs.Volume();
}
bool Shape3D::operator==(const Shape3D& rhs) const //Returns true or false to if volumes are equal
{
	return Volume() == rhs.Volume();
}
/**************************************************2D SHAPES ******************************************************************/

//Functions for Square
Square::Square(float side)
{
	s = side;
}
float Square::GetSide() const
{
	return s;
}
void Square::SetSide(float side)
{
	s = side;
}
float Square::Area() const
{
	return s * s;
}
void Square::Scale(float scaleFactor)
{
	cout << "Scaling by: " << scaleFactor << endl;
	s = s * scaleFactor;
	cout << "Side is now: " << s << " units.\n";
}
void Square::Display() const
{
	cout << "Shape Type: Square\n";
	cout << "Side Length is: " << s << " units.\n";
	ShowArea();
}
void Square::ShowArea() const
{
	cout << "Area is: " << Area() << " units squared.\n";
}
string Square::GetName2D() const
{
	return "Square";
}

// Triangle Functions 

Triangle::Triangle(float base, float height) 
{
	b = base;
	h = height;
}
float Triangle::GetBase() const
{
	return b;
}
float Triangle::GetHeight() const
{
	return h;
}
void Triangle::SetBase(float base)
{
	b = base;
}
void Triangle::SetHeight(float height)
{
	h = height;
}
float Triangle::Area() const
{
	return .5 * b * h;
}
void Triangle::Scale(float scaleFactor) 
{
	cout << "Scaling by: " << scaleFactor << endl;
	b = b * scaleFactor;
	h = h * scaleFactor;
	cout << "Base is now: " << b << " units.\n";
	cout << "Height is now: " << h << " units.\n";
}
void Triangle::Display() const
{
	cout << "Shape Type: Triangle\n";
	cout << "Base is: " << b << " units.\n";
	cout << "Height is: " << h << " units.\n";
	ShowArea();
}
void Triangle::ShowArea() const
{
	cout << "Area is: " << Area() << " units squared.\n";
}
string Triangle::GetName2D() const
{
	return "Triangle";
}

// Rectangle Functions
Rectangle::Rectangle(float width, float height)
{
	w = width;
	h = height;
}
float Rectangle::GetWidth() const
{
	return w;
}
float Rectangle::GetHeight() const
{
	return h;
}
void Rectangle::SetWidth(float width)
{
	w = width;
}
void Rectangle::SetHeight(float height)
{
	h = height;
}
float Rectangle::Area() const
{
	return w * h;
}
void Rectangle::Scale(float scaleFactor)
{
	cout << "Scaling by: " << scaleFactor << endl;
	w = w * scaleFactor;
	h = h * scaleFactor;
	cout << "Width is now: " << w << " units.\n";
	cout << "Height is now: " << h << " units.\n";
}
void Rectangle::Display() const
{
	cout << "Shape Type: Rectangle\n";
	cout << "Width is: " << w << " units.\n";
	cout << "Height is: " << h << " units.\n";
	ShowArea();
}
void Rectangle::ShowArea() const
{
	cout << "Area is: " << Area() << " units squared.\n";
}
string Rectangle::GetName2D() const
{
	return "Rectangle";
}

// Circle functions

Circle::Circle(float radius)
{
	r = radius;
}
float Circle::GetRadius() const
{
	return r;
}
void Circle::SetRadius(float radius)
{
	r = radius;
}
float Circle::Area() const
{
	return PI * (r * r);
}
void Circle::Scale(float scaleFactor)
{
	cout << "Scaling by: " << scaleFactor << endl;
	r = r * scaleFactor;
	cout << "Radius is now: " << r << " units.\n";
}
void Circle::Display() const
{
	cout << "Shape Type: Circle\n";
	cout << "Radius is: " << r << " units.\n";
	ShowArea();
}
void Circle::ShowArea() const
{
	cout << "Area is: " << Area() << " units squared.\n";
}
string Circle::GetName2D() const
{
	return "Circle";
}

// Trapezoid functions
Trapezoid::Trapezoid(float side1, float side2, float height)
{
	a = side1;
	b = side2;
	h = height;
}
float Trapezoid::GetSide1() const
{
	return a;
}
float Trapezoid::GetSide2() const
{
	return b;
}
float Trapezoid::GetHeight() const
{
	return h;
}
void Trapezoid::SetSide1(float side)
{
	a = side;
}
void Trapezoid::SetSide2(float side)
{
	b = side;
}
void Trapezoid::SetHeight(float height)
{
	h = height;
}
float Trapezoid::Area() const
{
	return ((a + b) / 2) * h;
}
void Trapezoid::Scale(float scaleFactor)
{
	cout << "Scaling by: " << scaleFactor << endl;
	a = a * scaleFactor;
	b = b * scaleFactor;
	h = h * scaleFactor;
	cout << "Side 1 is now: " << a << " units.\n";
	cout << "Side 2 is now: " << b << " units.\n";
	cout << "Height is now: " << h << " units.\n";
}
void Trapezoid::Display() const
{
	cout << "Shape Type: Trapezoid\n";
	cout << "Side A is: " << a << " units.\n";
	cout << "Side B is: " << b << " units.\n";
	cout << "Height is: " << h << " units.\n";
	ShowArea();
}
void Trapezoid::ShowArea() const
{
	cout << "Area is: " << Area() << " units squared.\n";
}
string Trapezoid::GetName2D() const
{
	return "Trapezoid";
}

// Ellipse functions
Ellipse::Ellipse(float minor, float major)
{
	a = minor;
	b = major;
}
float Ellipse::GetMinor() const
{
	return a;
}
float Ellipse::GetMajor() const
{
	return b;
}
void Ellipse::SetMinor(float minor)
{
	a = minor;
}
void Ellipse::SetMajor(float major)
{
	b = major;
}

// Inherited functions
float Ellipse::Area() const
{
	return PI * a * b;
}
void Ellipse::Scale(float scaleFactor)
{
	cout << "Scaling by: " << scaleFactor << endl;
	a = a * scaleFactor;
	b = b * scaleFactor;
	cout << "Semi minor axis is now: " << a << " units.\n";
	cout << "Semi major axis is now: " << b << " units.\n";
}
void Ellipse::Display() const
{
	cout << "Shape Type: Ellipse\n";
	cout << "Semi minor axis is: " << a << " units.\n";
	cout << "Semi major axis is: " << b << " units.\n";
	ShowArea();
}
void Ellipse::ShowArea() const
{
	cout << "Area is: " << Area() << " units squared.\n";
}
string Ellipse::GetName2D() const
{
	return "Ellipse";
}

// Sector functions
Sector::Sector(float radius, float angle)
{
	r = radius;
	theta = angle * (PI/180);
}
float Sector::GetRadius() const
{
	return r;
}
float Sector::GetTheta() const
{
	return theta;
}
void Sector::SetRadius(float radius)
{
	r = radius;
}
void Sector::SetTheta(float angle)
{
	theta = angle * (PI / 180); //theta will always be entered in as an angle
}
float Sector::Area() const
{
	return .5 * (r * r) * theta;
}
void Sector::Scale(float scaleFactor) 
{
	cout << "Scaling by: " << scaleFactor << endl;
	r = r * scaleFactor;
	cout << "Radius is now: " << r << " units.\n";
}
void Sector::Display() const
{
	cout << "Shape Type: Sector\n";
	cout << "Radius is: " << r << " units.\n";
	cout << "Theta is: " << theta << " radians.\n";
	ShowArea();
}
void Sector::ShowArea() const
{
	cout << "Area is: " << Area() << " units squared.\n";
}
string Sector::GetName2D() const
{
	return "Sector";
}
/**************************************************3D SHAPES ******************************************************************/

//Triangular Pyramid

string TriangularPyramid::GetName3D() const
{
	return "Triangular Pyramid";
}
TriangularPyramid::TriangularPyramid(float base, float height, float pyHeight) //Constructor
{
	SetBase(base);
	SetHeight(height);
	pyH = pyHeight;
}
float TriangularPyramid::Volume() const
{
	float area = Triangle::Area();
	return (area * pyH) / 3;
}
void TriangularPyramid::Display() const
{
	cout << "Shape Type: Triangular Pyramid\n";
	cout << "Height: " << pyH << endl;
	cout << "Base: " << Triangle::GetBase() << endl;
	cout << "Height: " << Triangle::GetHeight() << endl;
	ShowVolume();

}
void TriangularPyramid::ShowVolume() const
{
	cout << "Volume: " << Volume() << " units cubed.\n";
}
void TriangularPyramid::Scale(float scaleFactor)
{
	Triangle::Scale(scaleFactor);
	pyH *= scaleFactor;
}

//Rectangular Pyramid

RectangularPyramid::RectangularPyramid(float length, float width, float pyHeight) //Constructor
{
	SetHeight(length);
	SetWidth(width);
	pyH = pyHeight;
}
float RectangularPyramid::Volume() const //Returns the volume of the shape
{
	float area = Rectangle::Area();
	return (area * pyH) / 3;
}
string RectangularPyramid::GetName3D() const //Returns the name of the shape
{
	return "Rectangular Pyramid";
}
void RectangularPyramid::Scale(float scaleFactor)
{
	Rectangle::Scale(scaleFactor);
	pyH *= scaleFactor;     
}
void RectangularPyramid::Display() const
{
	cout << "Shape Type: Rectangular Pyramid\n";
	cout << "Height: " << pyH << endl;
	cout << "Width: " << Rectangle::GetWidth() << endl;
	cout << "Length: " << Rectangle::GetHeight() << endl;
	ShowVolume();

}
void RectangularPyramid::ShowVolume() const
{
	cout << "The volume is " << Volume() << " units cubed.\n";
}

//Cylinder

Cylinder::Cylinder(float radius, float cyHeight)
{
	SetRadius(radius);
	cyH = cyHeight;
}
float Cylinder::Volume() const
{
	return Circle::Area() * cyH;
}
void Cylinder::Scale(float scaleFactor)
{
	Circle::Scale(scaleFactor);
	cyH *= scaleFactor;
}
void Cylinder::Display() const
{
	cout << "Shape Type: Cylinder:\n";
	cout << "Radius: " << Circle::GetRadius() << endl;
	cout << "Height: " << cyH << endl;
	ShowVolume();
}
void Cylinder::ShowVolume() const
{
	cout << "The volume is " << Volume() << " units cubed.\n";
}
string Cylinder::GetName3D() const //Returns the name of the shape
{
	return "Cylinder";
}

//Sphere

Sphere::Sphere(float radius)
{
	Circle::SetRadius(radius);
}
float Sphere::Volume() const
{
	return 4.0f/3.0f * PI * (GetRadius() * GetRadius() * GetRadius());
}
void  Sphere::Scale(float scaleFactor)
{
	Circle::Scale(scaleFactor);
}
void Sphere::Display() const
{
	cout << "Shape Type: Sphere\n";
	cout << "Radius: " << Circle::GetRadius() << "\n";
	ShowVolume();
}
void  Sphere::ShowVolume() const 
{
	cout << "The volume is: " << Volume() << " units cubed.\n";
}
string Sphere::GetName3D() const
{
	return "Sphere";
}