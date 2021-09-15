#pragma once
#include "raylib.h"
#include "raymath.h"
#include <iostream>

inline Vector2 operator+(const Vector2& left_vector, const Vector2& right_vector) {
	return Vector2Add(left_vector, right_vector);
}

inline Vector2 operator-(const Vector2& left_vector, const Vector2& right_vector) {
	return Vector2Subtract(left_vector, right_vector);
}
inline Vector2 operator*(const Vector2& left_vector, const Vector2& right_vector) {
	return Vector2Multiply(left_vector, right_vector);
}
inline Vector2 operator/(const Vector2& left_vector, const Vector2& right_vector) {
	return Vector2Divide(left_vector, right_vector);
}

inline Vector2 operator+(const Vector2& left_vector, const int& right_int) {
	return Vector2AddValue(left_vector, (float)right_int);
}

inline Vector2 operator-(const Vector2& left_vector, const int& right_int) {
	return Vector2SubtractValue(left_vector, (float)right_int);
}
inline Vector2 operator*(const Vector2& left_vector, const int& right_int) {
	return Vector2{ left_vector.x * right_int,left_vector.y * right_int };
}
inline Vector2 operator/(const Vector2& left_vector, const int& right_int) {
	return Vector2{ left_vector.x / right_int,left_vector.y / right_int };
}

inline Vector2 operator+(const Vector2& left_vector, const float& right_float) {
	return Vector2AddValue(left_vector, right_float);
}

inline Vector2 operator-(const Vector2& left_vector, const float& right_float) {
	return Vector2SubtractValue(left_vector, right_float);
}
inline Vector2 operator*(const Vector2& left_vector, const float& right_float) {
	return Vector2{ left_vector.x * right_float,left_vector.y * right_float };
}
inline Vector2 operator/(const Vector2& left_vector, const float& right_float) {
	return Vector2{ left_vector.x / right_float,left_vector.y / right_float };
}

inline Vector2 operator+(const Vector2& left_vector, const double& right_float) {
	return Vector2AddValue(left_vector, (float)right_float);
}

inline Vector2 operator-(const Vector2& left_vector, const double& right_float) {
	return Vector2SubtractValue(left_vector, (float)right_float);
}
inline Vector2 operator*(const Vector2& left_vector, const double& right_float) {
	return Vector2{ left_vector.x * (float)right_float,left_vector.y * (float)right_float };
}
inline Vector2 operator/(const Vector2& left_vector, const double& right_float) {
	return Vector2{ left_vector.x / (float)right_float,left_vector.y / (float)right_float };
}

inline bool operator==(const Vector2& left_vector, const Vector2& right_vector) {
	return left_vector.x == right_vector.x && left_vector.y == right_vector.y;
}

inline bool operator!=(const Vector2& left_vector, const Vector2& right_vector) {
	return !(left_vector.x == right_vector.x && left_vector.y == right_vector.y);
}

inline std::ostream& operator<<(std::ostream& os, const Vector2& vector)
{
	os << "( " << vector.x << ", " << vector.y << " )";
	return os;
}

