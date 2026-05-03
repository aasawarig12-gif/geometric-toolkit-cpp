#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
};

class Circle : public Shape//circle
{
    float radius;
public:
    Circle(float r) { radius = r; }
    void area()
    {
        cout << "\nArea of Circle = " << 3.1416 * radius * radius << endl;\
    }
    void perimeter()
    {
        cout << "Perimeter of Circle = " << 2 * 3.1416 * radius << "\n";
    } 
};

class Square : public Shape//square
{
    float side;
public:
    Square(float s) { side = s; }
    void area()
    {
        cout << "\nArea of Square = " << side * side << endl;
    }
    void perimeter()
    {
        cout << "Perimeter of Square = " << 4 * side << "\n";
    }
};

class Rectangle : public Shape//rectangle
{
    float length, breadth;
public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }
    void area()
    {
        cout << "\nArea of Rectangle = " << length * breadth << endl;
    }
    void perimeter()
    {
        cout << "Perimeter of Rectangle = " << 2 * (length + breadth) << "\n";
    } 
};

class EquilateralTriangle : public Shape//equilateraltriangle
{
    float side;
public:
    EquilateralTriangle(float s) { side = s; }
    void area()
    {
        cout << "\nArea of Equilateral Triangle = " << (sqrt(3) / 4) * side * side << endl;
    }
    void perimeter()
    {
        cout << "Perimeter of Equilateral Triangle = " << 3 * side << "\n";
    } 
};

class ScaleneTriangle : public Shape//scalenetriangle
{
    float a, b, c;
public:
    ScaleneTriangle(float s1, float s2, float s3)
    {
        a = s1;
        b = s2;
        c = s3;
    }
    void area()
    {
        float s = (a + b + c) / 2;
        cout << "\nArea of Scalene Triangle = " << sqrt(s * (s - a) * (s - b) * (s - c)) << endl;
    }
    void perimeter()
    { 
        cout << "Perimeter of Scalene Triangle = " << (a + b + c) << "\n";
    } 
};

class Kite : public Shape//kite
{
    float d1, d2, a, b;
public:
    Kite(float diag1, float diag2, float side1, float side2)
    {
        d1 = diag1;
        d2 = diag2;
        a = side1;
        b = side2;
    }
    void area()
    {
        cout << "\nArea of Kite = " << (d1 * d2) / 2 << endl;
    }
    void perimeter()
    {
        cout << "Perimeter of Kite = " << 2 * (a + b) << "\n";
    }
};

class Rhombus : public Shape//rhombus
{
    float d1, d2, side;
public:
    Rhombus(float diag1, float diag2, float s)
    {
        d1 = diag1;
        d2 = diag2;
        side = s;
    }
    void area()
    {
        cout << "\nArea of Rhombus = " << (d1 * d2) / 2 << endl;
    }
    void perimeter()
    {
        cout << "Perimeter of Rhombus = " << 4 * side<<"\n";
    } 
};

class Trapezium : public Shape//trapezium 
{
    float a, b, c, d, h;
public:
    Trapezium(float s1, float s2, float s3, float s4, float height)
    {
        a = s1;
        b = s2;
        c = s3;
        d = s4;
        h = height;
    }
    void area()
    {
        cout << "\nArea of Trapezium = " << 0.5 * (a + b) * h << endl;
    }
    void perimeter()
    {
        cout << "Perimeter of Trapezium = " << (a + b + c + d) << "\n";
}
};

int main()
{
    Shape *s;//base class pointer 
    int choice, triangleChoice;
    float r, side, l, b, s1, s2, s3, d1, d2, height, s4;
    cout << "\n========== GEOMETRIC TOOLKIT ==========\n";
    cout<<"\n";
    do
    {
        cout << "1. Circle-A circle is a round shape where every point on its edge is the same distance from the center\n";
        cout << "2. Square-A square has four equal sides and four right angles. All sides are the same length, and opposite sides are parallel.\n";
        cout << "3. Rectangle-A rectangle also has four right angles. Opposite sides are equal in length.\n";
        cout << "4. Triangle-A triangle has three sides and three angles.The sum of all angles is 180°.\n";
        cout << "5. Kite-A kite has two pairs of adjacent sides equal. One pair of opposite angles are equal.\n";
        cout << "6. Rhombus-A rhombus has four equal sides, but angles are not right angles. Opposite sides are parallel, and opposite angles are equal.\n";
        cout << "7. Trapezium-A trapezium has one pair of opposite sides parallel. The other pair is not parallel.\n";
        cout << "8. Exit\n";
        cout<<"\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter radius: ";
            cin >> r;
            s = new Circle(r);
            s->area();
            s->perimeter();
            delete s;
            break;

        case 2:
            cout << "Enter side: ";
            cin >> side;
            s = new Square(side);
            s->area();
            s->perimeter();
            delete s;
            break;

        case 3:
            cout << "Enter length and breadth: ";
            cin >> l >> b;
            s = new Rectangle(l, b);
            s->area();
            s->perimeter();
            delete s;
            break;

        case 4:
            cout << "\nChoose any one Triangle Type:\n";
            cout << "1. Equilateral Triangle\n";
            cout << "2. Scalene Triangle\n";
            cout << "Enter your choice: ";
            cin >> triangleChoice;

            if (triangleChoice == 1)
            {
                cout << "Enter side: ";
                cin >> side;
                s = new EquilateralTriangle(side);
                 s->area();
                 s->perimeter();
                 delete s;
            }
            else if (triangleChoice == 2)
            {
                cout << "Enter three sides: ";
                cin >> s1 >> s2 >> s3;
                s = new ScaleneTriangle(s1, s2, s3);
                 s->area();
                 s->perimeter();
                 delete s;
            }
            else
            {
                cout << "Invalid triangle choice!\n";
                continue;
            }
            break;

        case 5:
            cout << "Enter diagonals and two sides: ";
            cin >> d1 >> d2 >> s1 >> s2;
            s = new Kite(d1, d2, s1, s2);
            s->area();
            s->perimeter();
            delete s;
            break;

        case 6:
            cout << "Enter diagonals and one side: ";
            cin >> d1 >> d2 >> side;
            s = new Rhombus(d1, d2, side);
            s->area();
            s->perimeter();
            delete s;
            break;

        case 7:
            cout << "Enter four sides and height: ";
            cin >> s1 >> s2 >> s3 >> s4 >> height;
            s = new Trapezium(s1, s2, s3, s4, height);
            s->area();
            s->perimeter();
            delete s;
            break;

        case 8:
            cout << "\nExiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
            continue;
        }

    } while (choice!=9);

    return 0;
}
