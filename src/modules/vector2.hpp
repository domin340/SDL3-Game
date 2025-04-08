#pragma once

struct Vector2
{
    float X, Y;

    Vector2(float x, float y) : X(x), Y(y) {}

    // COMPARISON OPERATORS
    bool operator==(const Vector2& vec) const;
    bool operator!=(const Vector2& vec) const;
    bool operator<(const Vector2& vec) const;
    bool operator<=(const Vector2& vec) const;
    bool operator>(const Vector2& vec) const;
    bool operator>=(const Vector2& vec) const;

    // MATHEMATIC OPERATORS
    Vector2 operator+(const Vector2& vec) const;
    Vector2 operator-(const Vector2& vec) const;
    Vector2 operator*(const Vector2& vec) const;
    Vector2 operator/(const Vector2& vec) const;
};
