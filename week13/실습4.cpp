#include<iostream>
//shape class
class Shape {
public:
	//상속하는 메서드들의 다형성을 위한 virtual
	virtual void draw() = 0;
};

//shape 상속
class Rectangle : public Shape {
public:
	void draw() { std::cout << "Shape: Rectangle" << std::endl; };

};

//shape 상속
class Circle : public Shape {
public:
	void draw() { std::cout << "Shape: Circle" << std::endl; };

};

//shape 상속
class ShapeDecorator : public Shape {
protected:
	Shape* decoratedShape;
public:
	//constructor
	ShapeDecorator(Shape* decoratedShape) {
		this->decoratedShape = decoratedShape;
	}
	void draw() { decoratedShape->draw(); }

};

//ShapeDecorator 상속
class RedShapeDecorator : public ShapeDecorator {
public:
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {}
	void draw() {
		decoratedShape->draw();
		setRedBorder(decoratedShape);
	}
private:
	void setRedBorder(Shape* decoratedShape) {
		std::cout << "Border Color: Red" << std::endl;
	}
};

int main() {

	Shape* circle = new Circle();
	Shape* redCircle = new RedShapeDecorator(new Circle());
	Shape* redRectangle = new RedShapeDecorator(new Rectangle());
	std::cout << "Circle with normal border" << std::endl;
	circle->draw();

	std::cout << "\nCircle of red border" << std::endl;
	redCircle->draw();

	std::cout << "\nRectangle of red border" << std::endl;
	redRectangle->draw();

	return 0;
}