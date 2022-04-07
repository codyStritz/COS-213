#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

// Class template of Array
template<class T>
class Array {
  // output
  friend std::ostream& operator<<(std::ostream& o, const Array<T>& a) {
    for (int i = 0; i < a.getSize(); i++) {
      o << a.ptr[i] << " ";
    }
    return o;
  }
  // input
  friend std::istream& operator>>(std::istream& input, Array<T>& a) {
    for (int i = 0; i < a.getSize(); i++) {
      input >> a.ptr[i];
    }
    return input;
  }
  
  public:
    explicit Array(int = 10); // defualt constructor
    Array(const Array<T>&);  // copy constructor
    ~Array(); // destructor
    size_t getSize() const; // return size

    const Array<T>& operator=(const Array<T>&); // assignment operator
    bool operator==(const Array<T>&) const;  // equality operator

    // inequality operator; returns opposite of == operator
    bool operator!=(const Array<T>& right) const {
      return ! (*this == right);
    }

    // subscript operator for non-const objects returns modifiable lvalue
    T& operator[](int);

    // subscript operator for const objects returns rvalue
    T operator[](int) const;

    

  private:
    size_t size;  // pointer-based array size
    T* ptr; // pointer to first element of pointer-based array
};

#endif


// Implementation of class template 

#include <iomanip>
#include <stdexcept>
using namespace std;

// default constructor
template<class T>
Array<T>::Array(int arraySize) {
  if (arraySize <= 0) {
    throw invalid_argument{"Array size must be greater than 0"};
  }
  size = static_cast<size_t>(arraySize);
  ptr = new T[size];
}

// copy constructor
template<class T>
Array<T>::Array(const Array<T>& arrayToCopy) {
  size = arrayToCopy.size;
  ptr = new T[size];
  for (int i = 0; i < size; i++) {
    ptr[i] = arrayToCopy.ptr[i];
  }
}

// destructor
template<class T>
Array<T>::~Array() {
  delete[] ptr;
}

// return number of elements of Array
template<class T>
size_t Array<T>::getSize() const {
  return size;
}

// assignment operator
template<class T>
const Array<T>& Array<T>::operator=(const Array<T>& right) {
  if (&right != this) {
    if (size != right.size) {
      delete[] ptr;
      size = right.size;
      ptr = new T[size];
    }

    for (size_t i = 0; i < size; i++) {
      ptr[i] = right.ptr[i];
    }
  }

  return *this;
}

// determine if two Arrays are equal 
template<class T>
bool Array<T>::operator==(const Array<T>& right) const {
  if (size != right.size) {
    return false;
  }

  for (size_t i = 0; i < size; i++) {
    if (ptr[i] != right.ptr[i]) {
      return false;
    }
  }

  return true;
}

// overloaded subscript operator for non-const Arrays
// reference return creates a modifiable lvalue
template<class T>
T& Array<T>::operator[](int subscript) {
  if (subscript < 0 || subscript >= size) {
    throw out_of_range{"Subscript out of range"};
  }
  return ptr[subscript];
}

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template<class T>
T Array<T>::operator[](int subscript) const {
  if (subscript < 0 || subscript >= size) {
    throw out_of_range{"Subscript out of range"};
  }

  return ptr[subscript];
}