## Features

- Automatic date correction for invalid dates (like Feb 30).
- Leap year support.
- Arithmetic operations (add, subtract days from dates).
- Date comparisons (==, !=, >, <, etc.).
- Conversion to/from tm structure.
- Date formatting as strings.

## Methods

- Leap Year Check: bool leapyearcheck(int y)

- Date Formatting: Conversion of dates to string using the operator string() method.

- Day of the Week: char* dayofweek() const - Returns the day of the week for the current date.

- Date Correction: void correctdate() - Automatically corrects invalid dates (e.g., converts February 30 to March 2).

## Operators

- Date Arithmetic: Supports +, -, +=, -=, ++, -- (both prefix and postfix) operators for adding and subtracting days.

- Date Comparisons: Overloaded operators ==, !=, <, <=, >, >= for comparing dates.
  
## Set/Get Methods:

- void setdate(int y, unsigned short m, unsigned short d)
- void setyear(int y)
- void setmonth(unsigned short m)
- void setday(unsigned short d)
- int getyear() const
- unsigned short getmonth() const
- unsigned short getday() const
