# TimeSpan Class in C++

This project implements a `TimeSpan` class in C++ that represents a duration of time in hours, minutes, and seconds. The class supports normalization, arithmetic operations, comparisons, and stream input/output using operator overloading.

## Features

- Stores time as hours, minutes, and seconds
- Automatically normalizes values into canonical form
  - e.g., 90 seconds → 1 minute 30 seconds
- Supports arithmetic operations:
  - Addition (`+`, `+=`)
  - Subtraction (`-`, `-=`)
  - Unary negation (`-`)
- Supports comparison operators:
  - `==`, `!=`, `<`, `<=`, `>`, `>=`
- Stream operators:
  - Input (`>>`)
  - Output (`<<`)

## Key Functionality

### Normalization
The `normalize()` function ensures all TimeSpan objects are stored in a consistent format by carrying overflow between seconds, minutes, and hours.

### Operator Overloading
This project demonstrates full C++ operator overloading to allow natural arithmetic and comparison between TimeSpan objects.


## Concepts Demonstrated

- Object-oriented programming (OOP)
- Operator overloading in C++
- Data normalization logic
- Stream input/output
- Class design and encapsulation
- Edge case handling in arithmetic operations

## Purpose

This project was built to strengthen the understanding of C++ class design and operator overloading while implementing a real-world time-manipulation system.
