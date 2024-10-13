//
// Created by Chandler Desforges on 10/7/24.
//

#ifndef VECTOR_3D_VECTOR3D_H
#define VECTOR_3D_VECTOR3D_H

#include <iostream>
#include <stdexcept>

enum Coordinate {x, y, z};

class Vector3D
{
private:
    double m_x, m_y, m_z;

public:
    Vector3D();
    Vector3D(double x, double y, double z);

    // fns
    [[nodiscard]] Vector3D crossProduct(const Vector3D& rhs) const;
    [[nodiscard]] double magnitude() const;
    void normalize();

    // operators
    Vector3D& operator=(const Vector3D& rhs);
    double operator[](Coordinate coord);
    void operator++();
    void operator--();
    void operator++(int);
    void operator--(int);
    void operator/=(double rhs);


    // friends
    friend Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs);
    friend Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs);
    friend double operator*(const Vector3D& lhs, const Vector3D& rhs);
    friend Vector3D operator/(const Vector3D& lhs, const double rhs);
    friend std::ostream& operator<<(std::ostream& cout, const Vector3D& rhs);
    friend std::istream& operator>>(std::istream& cin, Vector3D& rhs);
    friend bool operator==(const Vector3D& lhs, const Vector3D& rhs);
    friend bool operator!=(const Vector3D& lhs, const Vector3D& rhs);
    friend Vector3D operator-(const Vector3D& rhs);
};


#endif //VECTOR_3D_VECTOR3D_H
