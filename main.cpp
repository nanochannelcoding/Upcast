#include <iostream>
#include <cmath>
#include <memory>
// Abstract base class
class Circle {
protected:
    double m_radius;
    double m_area;

public:
    virtual ~Circle() = default;

    Circle(double radius) {
        if (radius > 0) {
            m_radius = radius;
        }
        else {
            m_radius = 1;
        }
        m_area = m_area = M_PI * pow(m_radius, 2);
    }
    virtual void calcVolume()=0;
    virtual double getVolume()=0;
};

class Cylinder: public Circle {
private:
    double m_volume;
    double m_height;
public:
    Cylinder(double radius, double height):Circle(radius) {
        if (height > 0) {
            m_height = height;
        }
        else {
            m_height = 1;
        }
        m_volume = 0;
    }
    void calcVolume() override {
        m_volume = m_area * m_height;
    }
    double getVolume() override {
        return m_volume;
    }
};

class Sphere: public Circle {
private:
    double m_volume;
public:
    Sphere(double radius):Circle(radius) {
        m_volume = 0;
    }
    void calcVolume() override {
        m_volume = (4.0/3.0) * M_PI * pow(m_radius, 3);
    }
    double getVolume() override {
        return m_volume;
    }
};

class Cone: public Circle {
private:
    double m_volume;
    double m_height;
public:
    Cone(double radius, double height):Circle(radius) {
        if (height > 0) {
            m_height = height;
        }
        else {
            m_height = 1;
        }
        m_volume = 0;
    }
    void calcVolume() override {
        m_volume = M_PI * pow(m_radius, 2) * (m_height / 3);
    }
    double getVolume() override {
        return m_volume;
    }
};

int main() {
    // sandbox for playing with objects
    int choice;
    std::unique_ptr<Circle> object;
    std::cout << "Select an object: \n1. Cylinder \n2. Cone \n3. Sphere" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        double cylRadius;
        double cylHeight;
        std::cout << "Enter the radius: ";
        std::cin >> cylRadius;
        std::cout << "Enter the height: ";
        std::cin >> cylHeight;
        object = std::make_unique<Cylinder>(cylRadius, cylHeight);
    }
    else if (choice == 2) {
        double coneRadius;
        double coneHeight;
        std::cout << "Enter cone radius";
        std::cin >> coneRadius;
        std::cout << "Enter cone height";
        std::cin >> coneHeight;
        object = std::make_unique<Cone>(coneRadius, coneHeight);
    }
    else if (choice == 3) {
        double sphRadius;
        std::cout << "Enter sphere radius: ";
        std::cin >> sphRadius;
        object = std::make_unique<Sphere>(sphRadius);
    }
    else {
        std::cout << "Wrong choice" << std::endl;
    }

    object->calcVolume();
    std::cout << object->getVolume() << std::endl;

    return 0;
}
