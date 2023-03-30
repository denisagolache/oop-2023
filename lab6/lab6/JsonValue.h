#pragma once
#include <ostream>
#include <iostream>

#define MAX_STRING_SIZE 255
#define MAX_ARRAY_SIZE  16
class JsonValue {
  public:
    virtual ~JsonValue() = 0;
    virtual void print(std::ostream& out) const = 0;
};

class NullValue : public JsonValue {
  public:
    void print(std::ostream& out) const override;
};

class NumberValue : public JsonValue {
    double value;

  public:
    NumberValue(double value);
    void print(std::ostream& out) const override;
};
class BoolValue : public JsonValue {
    bool value;

  public:
    BoolValue(bool value);
    void print(std::ostream& out) const override;
};

class StringValue : public JsonValue {
    char* value;

  public:
    StringValue(const char* value);
    ~StringValue() ;
    void print(std::ostream& out) const override;
};

class ArrayValue : public JsonValue {
    int size;
    JsonValue* values[MAX_ARRAY_SIZE];
    static void print_indent(std::ostream& out, int indentationLevel);

  public:
    ArrayValue();
    ~ArrayValue();
    void add(JsonValue* value);
    void print(std::ostream& out) const override;
};

class ObjectValue : public JsonValue {
    int size;
    char names[MAX_ARRAY_SIZE][MAX_STRING_SIZE];
    std::pair<const char*, JsonValue*> values[MAX_ARRAY_SIZE];
    static void print_indent(std::ostream& out, int indentationLevel);

  public:
    ObjectValue();
    ~ObjectValue();
    void add(const char* name, JsonValue* value);
    void print(std::ostream& out) const override;
    operator unsigned() const;
};
