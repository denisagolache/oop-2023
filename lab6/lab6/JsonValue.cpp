#define _CRT_SECURE_NO_WARNINGS
#include "JsonValue.h"
#include <ostream>
#include <iostream>
#include <cstring>
#include <string>
#include <memory>
void NullValue::print(std::ostream& out) const {
    out << "null";
}

NumberValue::NumberValue(double value) : value(value) {
}

void NumberValue::print(std::ostream& out) const {
    out << value;
}

BoolValue::BoolValue(bool value) : value(value) {
}

void BoolValue::print(std::ostream& out) const {
    out << (value ? "true" : "false");
}

StringValue::StringValue(const char* value) {
    this->value = new char[strlen(value) + 1];
    strcpy(this->value, value);
}

StringValue::~StringValue() {
    delete[] value;
}
void StringValue::print(std::ostream& out) const {
    out << "\"" << value << "\" ";
}
void ArrayValue::print_indent(std::ostream& out, int indentationLevel) {
    for (int i = 0; i < indentationLevel; i++) {
        out << " ";
    }
}
ArrayValue::ArrayValue() : size(0) {
}

ArrayValue::~ArrayValue() {
    for (int i = 0; i < size; i++)
        delete values[i];
}

void ArrayValue::add(JsonValue* value) {
    if (size < MAX_ARRAY_SIZE) {
        values[size++] = value;
    }
}
void ArrayValue::print(std::ostream& out) const {
    out << "[";
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            out << ", ";
        }

        values[i]->print(out);
    }
    out << "]";
}

ObjectValue::ObjectValue() : size(0) {
}
ObjectValue::~ObjectValue() {
    for (int i = 0; i < size; i++) {
        delete values[i].second;
    }
}
void ObjectValue::add(const char* name, JsonValue* value) {
    if (size >= MAX_ARRAY_SIZE) {
        return;
    }
    std::strncpy(names[size], name, MAX_STRING_SIZE);
    names[size][MAX_STRING_SIZE - 1] = '\0';
    values[size].first = names[size];
    values[size].second = value;

    size++;
}
void ObjectValue::print_indent(std::ostream& out, int indentationLevel) {
    for (int i = 0; i < indentationLevel; i++)
        out << " ";
}
void ObjectValue::print(std::ostream& out) const {
    out << "{";
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            out << ", ";
        }

        out << "\"" << values[i].first << "\": ";
        values[i].second->print(out);
    }
    out << "}";
}

ObjectValue::operator unsigned() const {
    return size;
}
JsonValue::~JsonValue() {
}