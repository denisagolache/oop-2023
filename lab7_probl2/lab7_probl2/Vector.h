#pragma once
#include <iostream>
#include <algorithm>
template <class T>
class Vector {
    T* vector = nullptr;
    int size = 0;
    int capacity = 0;

  public:
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other);
    ~Vector();
    Vector<T>& operator=(const Vector& other);
    Vector<T>& operator=(Vector&& other);
    T& operator[](int index);
    const T& operator[](int index) const;
    void insert(int index, const T& element);
    void remove(int index);
    void sort();
    void sort(int (*cmp)(const T&, const T&));
    void print() const;
};

template <class T>
inline Vector<T>::Vector() : vector(new T[100]), size(0), capacity(100) {
}

template <class T>
inline Vector<T>::Vector(const Vector& other) : vector(nullptr), size(0), capacity(0) {
    *this = other;
}

template <class T>
inline Vector<T>::Vector(Vector&& other) : vector(nullptr), size(0), capacity(0) {
    *this = static_cast<Vector<T>&&>(other);
}

template <class T>
inline Vector<T>::~Vector() {
    delete[] vector;
}

template <class T>
inline Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] vector;
        size = other.size;
        capacity = other.capacity;
        vector = new T[capacity];
        for (int i = 0; i < size; i++)
            vector[i] = other.vector[i];
    }
    return *this;
}

template <class T>
inline Vector<T>& Vector<T>::operator=(Vector&& other) {
    if (this != &other) {
        delete[] vector;
        vector = other.vector;
        size = other.size;
        capacity = other.capacity;
        other.vector = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template <class T>
inline const T& Vector<T>::operator[](int index) const {
    return vector[index];
}

template <class T>
inline T& Vector<T>::operator[](int index) {
    return vector[index];
}

template <class T>
inline void Vector<T>::insert(int index, const T& element) {
    if (size == capacity) {
        capacity *= 2;
        T* newVector = new T[capacity];
        for (int i = 0; i < index; i++)
            newVector[i] = vector[i];

        newVector[index] = element;
        for (int i = index + 1; i <= size; i++)
            newVector[i] = vector[i - 1];

        for (int i = size; i < capacity; i++)
            newVector[i] = T{};
        delete[] vector;
        vector = newVector;
    } else {
        for (int i = size; i > index; i--)
            vector[i] = vector[i - 1];
        vector[index] = element;
    }
    size++;
}

template <class T>
inline void Vector<T>::remove(int index) {
    for (int i = index; i < size - 1; i++)
        vector[i] = vector[i + 1];
    size--;
}

template <class T>
inline void Vector<T>::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++)
            if (vector[j] < vector[i]) {
                T temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
    }
}

template <class T>
inline void Vector<T>::sort(int (*cmp)(const T&, const T&)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (vector[j] < vector[i]) {
                T temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}

template <class T>
inline void Vector<T>::print() const {
    for (int i = 0; i < size; i++)
        std::cout << vector[i] << " ";
    std::cout << std::endl;
}
