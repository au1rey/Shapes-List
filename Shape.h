/*******************
Name: Audrey Saidel
Student ID: 2589516
Email: audrey.saidel@snhu.edu
Assignment: Final Project
Title: Shapes and Inheritance
Description of File: Header File for shape class
******************/
#pragma once
#include <iostream>
#include <string>
using namespace std; 

class Shape
{
public:
	static const float PI;
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape() = 0;
};

class Shape2D : virtual public Shape {
public:
	virtual float Area() const = 0;
	virtual void ShowArea() const;
	virtual string GetName2D() const = 0;
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};

class Shape3D : virtual public Shape {
public:
	virtual float Volume() const = 0;
	virtual void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
};


// Shape 2D Child Classes

class Square : virtual public Shape2D {
private:
	float s; //length of side

public:
	Square(float side = 0.0f);
	float GetSide() const;
	void SetSide(float side);

	// Inherited functions
	float Area() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowArea() const override;
	string GetName2D() const override;
};

class Triangle : virtual public Shape2D {
private:
	float b; //base
	float h; //height

public:
	Triangle(float base = 0.0f, float height = 0.0f);
	float GetBase() const;
	float GetHeight() const;
	void SetBase(float base);
	void SetHeight(float height);

	// Inherited functions
	float Area() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowArea() const override;
	string GetName2D() const override;
};

class Rectangle : virtual public Shape2D{
private:
	float w; //width
	float h; //height

public:
	Rectangle(float width = 0.0f, float height = 0.0f);
	float GetWidth() const;
	float GetHeight() const;
	void SetWidth(float width);
	void SetHeight(float height);

	// Inherited functions
	float Area() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowArea() const override;
	string GetName2D() const override;
};

class Circle : virtual public Shape2D {
private:
	float r; //radius

public:
	Circle(float radius = 0.0f);
	float GetRadius() const;
	void SetRadius(float radius);

	// Inherited functions
	float Area() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowArea() const override;
	string GetName2D() const override;
};

class Trapezoid : virtual public Shape2D {
private:
	float a, b, h; //side, side, height
public:
	Trapezoid(float side1 = 0.0f, float side2 = 0.0f, float height = 0.0f);
	float GetSide1() const;
	float GetSide2() const;
	float GetHeight() const;
	void SetSide1(float side);
	void SetSide2(float side);
	void SetHeight(float height);

	// Inherited functions
	float Area() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowArea() const override;
	string GetName2D() const override;


};

class Ellipse : virtual public Shape2D {
private:
	float a; //minor axis
	float b; //major axis
public:
	Ellipse(float minor = 0.0f, float major = 0.0f);
	float GetMinor() const;
	float GetMajor() const;
	void SetMinor(float minor);
	void SetMajor(float major);

	// Inherited functions
	float Area() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowArea() const override;
	string GetName2D() const override;
};

class Sector : virtual public Shape2D {
private:
	float r; //radius
	float theta; //theta in radians
public:
	Sector(float radius = 0.0f, float angle = 0.0f);
	float GetRadius() const;
	float GetTheta() const;
	void SetRadius(float radius);
	void SetTheta(float angle);

	// Inherited functions
	float Area() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowArea() const override;
	string GetName2D() const override;
};

// Shape 3D Child Classes

class TriangularPyramid : virtual public Shape3D, private Triangle {
private:
	float pyH;
public:
	TriangularPyramid(float base, float height, float pyHeight);
	float Volume() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowVolume() const override;
	string GetName3D() const override;
};

class RectangularPyramid : virtual public Shape3D, private Rectangle {
private:
	float pyH;
public:
	RectangularPyramid(float length, float width, float pyHeight);
	float Volume() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowVolume() const override;
	string GetName3D() const override;

};

class Cylinder : virtual public Shape3D, private Circle {
private:
	float cyH;
public:
	Cylinder(float radius, float cyHeight);
	float Volume() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowVolume() const override;
	string GetName3D() const override;

};

class Sphere : virtual public Shape3D, private Circle {
public:
	Sphere(float radius);
	float Volume() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
	void ShowVolume() const override;
	string GetName3D() const override;

};