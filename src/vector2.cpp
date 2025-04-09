#include <Engine/vector2.hpp>

// COMPARISON OPERATORS
// ------------------------------------------------------------

bool Vector2::operator==(const Vector2 &vec) const
{
    return X == vec.X && Y == vec.Y;
}

bool Vector2::operator!=(const Vector2 &vec) const
{
    return !(*this == vec);
}

bool Vector2::operator<(const Vector2 &vec) const
{
    return X < vec.X && Y < vec.Y;
}

bool Vector2::operator<=(const Vector2 &vec) const
{
    return (*this < vec) || (*this == vec);
}

bool Vector2::operator>(const Vector2 &vec) const
{
    return X > vec.X && Y > vec.Y;
}

bool Vector2::operator>=(const Vector2 &vec) const
{
    return (*this > vec) || (*this == vec);
}

// ------------------------------------------------------------

// MATHEMATICAL OPERATORS
// ------------------------------------------------------------

Vector2 Vector2::operator+(const Vector2 &vec) const
{
    return Vector2(X + vec.X, Y + vec.Y);
}

Vector2 Vector2::operator-(const Vector2 &vec) const
{
    return Vector2(X - vec.X, Y - vec.Y);
}

Vector2 Vector2::operator*(const Vector2 &vec) const
{
    return Vector2(X * vec.X, Y * vec.Y);
}

Vector2 Vector2::operator/(const Vector2 &vec) const
{
    return Vector2(X / vec.X, Y / vec.Y);
}

// ------------------------------------------------------------
