#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeShapesToFile()
{
    ofstream file("shapes.txt");

    if (file)
    {
        if (!file.is_open())
        {
            cout << "Unable to open file!" << endl;
            return;
        }

        file << "Circle" << endl;
        file << "Radius: 5" << endl;

        file << endl;

        file << "Rectangle" << endl;
        file << "Length: 10" << endl;
        file << "Width: 20" << endl;

        file << endl;

        file << "Square" << endl;
        file << "Side: 6" << endl;

        file << endl;

        file << "Triangle" << endl;
        file << "Side1: 3" << endl;
        file << "Side2: 4" << endl;
        file << "Side3: 5" << endl;

        file.close();

        cout << "Shape information written successfully." << endl;
    }
}

class Shape
{
public:
    virtual void display() = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;

    virtual ~Shape()
    {
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    void display() override
    {
        cout << "Circle" << endl;
        cout << "Radius: " << radius << endl;
    }

    double area() override
    {
        return 3.14 * radius * radius;
    }

    double perimeter() override
    {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    void display() override
    {
        cout << "Rectangle" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    }

    double area() override
    {
        return length * width;
    }

    double perimeter() override
    {
        return 2 * (length + width);
    }
};

class Square : public Rectangle
{
private:
    double side;

public:
    Square(double s) : Rectangle(s, s)
    {
        side = s;
    }

    void display() override
    {
        cout << "Square" << endl;
        cout << "Side: " << side << endl;
    }
};

class Triangle : public Shape
{
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3)
    {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    void display() override
    {
        cout << "Triangle" << endl;
        cout << "Side1: " << side1 << endl;
        cout << "Side2: " << side2 << endl;
        cout << "Side3: " << side3 << endl;
    }

    double perimeter() override
    {
        return side1 + side2 + side3;
    }

    double area() override
    {
        double s = perimeter() / 2;

        return sqrt(s * (s - side1) *
                    (s - side2) *
                    (s - side3));
    }
};

int main(void)
{
    writeShapesToFile();
    ifstream file("shapes.txt");

    if (!file.is_open())
    {
        cout << "Unable to open file!" << endl;
        return 1;
    }
    string shape;
    string radiusLine;

    getline(file, shape);
    getline(file, radiusLine);
    double radius = stod(radiusLine.substr(8));

    Circle c(radius);

    c.display();

    cout << "Area: " << c.area() << endl;
    cout << "Perimeter: " << c.perimeter() << endl;

    file.close();

    return 0;
}