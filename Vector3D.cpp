//
// Created by Chandler Desforges on 10/7/24.
//

#include <cmath>
#include <cassert>
#include "Vector3D.h"

Vector3D::Vector3D()
: m_x(0), m_y(0), m_z(0)
{}

Vector3D::Vector3D(double x, double y, double z)
: m_x(x), m_y(y), m_z(z)
{}

Vector3D Vector3D::crossProduct(const Vector3D &rhs) const
{
    return {m_y*rhs.m_z - rhs.m_y*m_z, rhs.m_x*m_z - m_x*rhs.m_z, m_x*rhs.m_y - rhs.m_x*m_y};
}

double Vector3D::magnitude() const
{
    return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
}

void Vector3D::normalize()
{
    double mag = magnitude();

    m_x /= mag;
    m_y /= mag;
    m_z /= mag;
}

Vector3D& Vector3D::operator=(const Vector3D &rhs)
{
    m_x = rhs.m_x;
    m_y = rhs.m_y;
    m_z = rhs.m_z;

    return *this;
}

double Vector3D::operator[](Coordinate coord)
{
    if(coord == x)
        return m_x;
    else if(coord == y)
        return m_y;
    else if(coord == z)
        return m_z;
    else
        assert("Invalid coordinate enum value!");

    return 0;
}

void Vector3D::operator++()
{
    m_x++;
    m_y++;
    m_z++;
}

void Vector3D::operator--()
{
    m_x--;
    m_y--;
    m_z--;
}

void Vector3D::operator++(int)
{
    m_x++;
    m_y++;
    m_z++;
}

void Vector3D::operator--(int)
{
    m_x--;
    m_y--;
    m_z--;
}

void Vector3D::operator/=(double rhs)
{
    m_x /= rhs;
    m_y /= rhs;
    m_z /= rhs;
}

Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
{
    return {lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y, lhs.m_z + rhs.m_z};
}

Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
{
    return {lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y, lhs.m_z - rhs.m_z};
}

double operator*(const Vector3D& lhs, const Vector3D& rhs)
{
    return (lhs.m_x * rhs.m_x) + (lhs.m_y * rhs.m_y) + (lhs.m_z * rhs.m_z);
}

Vector3D operator/(const Vector3D& lhs, const double rhs)
{
    return {lhs.m_x / rhs, lhs.m_y / rhs, lhs.m_z / rhs};
}

std::ostream& operator<<(std::ostream& cout, const Vector3D& rhs)
{
    cout << "<" << rhs.m_x << ", " << rhs.m_y << ", " << rhs.m_z << ">";

    return cout;
}

std::istream& operator>>(std::istream& cin, Vector3D& rhs)
{
    // I'm proud of this one! The iostream documentation leaves something to be desired...
    double* coords[3] = {&rhs.m_x, &rhs.m_y, &rhs.m_z};
    int i = 0;

    // look for 3 numbers in the stream
    while(i < 3)
    {
        // Skip any non-number characters
        while(cin && !std::isdigit(cin.peek()) && cin.peek() != '.' && cin.peek() != '-' && cin.peek() != '+')
        {
            char next = cin.get();

            if(next == '\n' || next == EOF)
                throw std::runtime_error("Invalid input: could not find 3 values in istream");
        }

        // extract the next number character, then iterate the pointer vector
        if(!(cin >> *coords[i++]))
            throw std::runtime_error("Invalid input: could not extract value from istream");
    }

    // clear out the rest of the non-digit characters if there are any
    while(cin && !std::isdigit(cin.peek()) && cin.peek() != '\n' && cin.peek() != EOF)
        cin.get();

    // if there's still something in the stream, check if it's a number
    if(isdigit(cin.peek()))
        throw std::runtime_error("Invalid input: more than three values detected in istream");

    // Clear anything left in the buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return cin;
}

bool operator==(const Vector3D& lhs, const Vector3D& rhs)
{
    return lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y && lhs.m_z == rhs.m_z;
}

bool operator!=(const Vector3D& lhs, const Vector3D& rhs)
{
    return lhs.m_x != rhs.m_x && lhs.m_y != rhs.m_y && lhs.m_z != rhs.m_z;}

Vector3D operator-(const Vector3D& rhs)
{
    return {-rhs.m_x, -rhs.m_y, -rhs.m_z};
}
