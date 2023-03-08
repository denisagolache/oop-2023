#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdarg.h>
#include <cstring>

int Math::Add(int x, int y) {
	return x + y;
}

int Math::Add(int x, int y, int z) {
	return x + y + z;
}

int Math::Add(double x, double y) {
	return (double)x + y;
}

int Math::Add(double x, double y, double z) {
	return (double)x + y + z;
}

int Math::Mul(int x, int y) {
	return x * y;
}

int Math::Mul(int x, int y, int z) {
	return x * y * z;
}

int Math::Mul(double x, double y) {
	return (int)x * y;
}

int Math::Mul(double x, double y, double z) {
	return (int)x * y * z;
}

int Math::Add(int count, ...) {
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
		sum += va_arg(args, int);
	va_end(args);
	return sum;

}

char* Math::Add(const char* s1, const char* s2) {
	if (s1 == nullptr || s2 == nullptr)
		return nullptr;
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	char* result = new char[l1 + l2 + 1];
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}