# s21_string+

Implementation of the string.h library with additions.

The russian version of the task can be found in the repository.


## Contents
0. [Preamble](#preamble)
1. [Chapter I](#chapter-i) \
    1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
    2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
    3.1. [Part 1](#part-1-implementation-of-the-stringh-library-functions)  
    3.2. [Part 2](#part-2-implementation-of-the-sprintf-and-sscanf-functions)  
    3.3. [Part 3](#part-3-bonus-implementation-of-special-string-processing-functions)  


## Preamble

![s21_string+](misc/eng/images/s21_stringplus.png)

1942, late evening, Bletchley Park, Alan Turing's desk. For almost a year, a group of smartest mathematicians, linguists, and crossword puzzle enthusiasts has been trying to solve the most difficult problem of deciphering the German Enigma encryption machine, the codes for which change every day, and the number of possible combinations is about two to the power of 64. The group often had to come up with different algorithms, and they even developed a special set of keywords and their syntax for the convenience of communication and logging and it’s exactly like the well-known C language in our universe. What a remarkable coincidence! But there was one difficulty – the Bletchley Park workers had to keep the entire sequence of actions described in this language in their heads. 

As you walk past Turing's desk, you notice a sheet that says "For letters, punctuation marks, words, and sentences processing".

*- "What is this, Alan?"* you said to the thoughtful young man standing at the window.

*-- "These are the functions that will make our lives easier! You know, deciphering Enigma by brute force…I'd rather marry Joan than we do that. Therefore, it seems that we need to keep analysing texts, looking for patterns and coincidences. And so, we’ll have to come up with various algorithms related to the processing of that very text and describe them. That is why we need a number of functions to help us with that. I'm working on them now."*

*- "And you do that using our new unified algorithms representing tool?"*

*-- "Yes, this is exactly how I do it. Where else could we use these functions?"* having said that, Turing looked at you as if you were a narrow minded person. You realised it and decided to show off your knowledge of the question:

*- "You know I think we really need this. I just recently learned this "specific language of algorithms transmission"."*

*-- "Seriously?"* Alan asked with some interest.

*- "Well, yes."*

After a few seconds, Turing came to a logical conclusion to entrust the job to you:

*-- "Listen, do you want to do it yourself? Get some not-so-busy 
people and go ahead. And I'll keep working on my mechanical code-breaking machine."*

After thinking about it for a few seconds, you decide it's a great idea:

*- "Yes, we’ll do everything in a best possible way!"*


## Chapter I

## Introduction

In this project you will develop your own implementation of the string.h library in C programming language with some additions (with your own implementation of sprintf and sscanf functions). The string.h library is the main C library for string processing. As part of the project you’ll work on tasks with string data and consolidate the structured approach.


## Chapter II

## Information

The C programming language has a set of functions implementing operations on strings (character strings and byte strings) in its standard library. Various operations, such as copying, concatenation, tokenization and searching are supported. For character strings, the standard library uses the convention that strings are null-terminated: a string of n characters is represented as an array of n + 1 elements, the last of which is a "NULL" character. \
The only support for strings in the programming language proper is that the compiler translates quoted string constants into null-terminated strings.

### string.h Types

| No. | Variable | Description |
| ------ | ------ | ------ |
| 1 | size_t | This is the unsigned integral type and is the result of the sizeof keyword. |
	
### string.h Macro

| No. | Macro | Description |
| ------ | ------ | ------ |
| 1 | NULL | This macro is the value of a null pointer constant. |

### string.h Functions

| No. | Function | Description |
| ------ | ------ | ------ |
| 1 | void *memchr(const void *str, int c, size_t n) | Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str. |
| 2 | int memcmp(const void *str1, const void *str2, size_t n) | Compares the first n bytes of str1 and str2. |
| 3 | void *memcpy(void *dest, const void *src, size_t n) | Copies n characters from src to dest. |
| 4 | void *memmove(void *dest, const void *src, size_t n) | Another function to copy n characters from str2 to str1. |
| 5 | void *memset(void *str, int c, size_t n) | Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. |
| 6 | char *strcat(char *dest, const char *src) | Appends the string pointed to, by src to the end of the string pointed to by dest. |
| 7 | char *strncat(char *dest, const char *src, size_t n) | Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. |
| 8	| char *strchr(const char *str, int c) | Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. |
| 9 | int strcmp(const char *str1, const char *str2) | Compares the string pointed to, by str1 to the string pointed to by str2. |
| 10 | int strncmp(const char *str1, const char *str2, size_t n) | Compares at most the first n bytes of str1 and str2. |
| 11 | char *strcpy(char *dest, const char *src) | Copies the string pointed to, by src to dest. |
| 12 | char *strncpy(char *dest, const char *src, size_t n) | Copies up to n characters from the string pointed to, by src to dest. |
| 13 | size_t strcspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters not in str2. |
| 14 | char *strerror(int errnum) | Searches an internal array for the error number errnum and returns a pointer to an error message string. |
| 15 | size_t strlen(const char *str) | Computes the length of the string str up to but not including the terminating null character. |
| 16 | char *strpbrk(const char *str1, const char *str2) | Finds the first character in the string str1 that matches any character specified in str2. |
| 17 | char *strrchr(const char *str, int c) | Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. |
| 18 | size_t strspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters in str2. |
| 19 | char *strstr(const char *haystack, const char *needle) | Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack. |
| 20 | char *strtok(char *str, const char *delim) | Breaks string str into a series of tokens separated by delim. |

### sprintf and sscanf

- int sscanf(const char *str, const char *format, ...) - reads formatted input from a string.
- int sprintf(char *str, const char *format, ...) - sends formatted output to a string pointed to, by str.

where:
- str − This is the C string that the function processes as its source to retrieve the data;
- format − This is the C string that contains one or more of the following items: Whitespace character, Non-whitespace character and Format specifiers. A format specifier follows this prototype: %[flags][width][.precision][length]specifier.

### sprintf And sscanf Specifiers

| No. | Specifier | Output |
| - | - | - |
| 1 | c | Character |
| 2 | d or i | Signed decimal integer |
| 3 | e | Scientific notation (mantissa/exponent) using e character |
| 4 | E | Scientific notation (mantissa/exponent) using E character |
| 5 | f | Decimal floating point |
| 6 | g | Uses the shorter of %e or %f |
| 7 | G | Uses the shorter of %E or %f |
| 8 | o | Signed octal |
| 9 | s | String of characters |
| 10 | u | Unsigned decimal integer |
| 11 | x | Unsigned hexadecimal integer |
| 12 | X | Unsigned hexadecimal integer (capital letters) |
| 13 | p | Pointer address |
| 14 | n | Nothing printed |
| 15 | % | Character |

### sprintf And sscanf Flags

| No. | Flags | Description |
| - | - | - |
| 1 | - | Left-justify within the given field width; Right justification is the default (see width sub-specifier). |
| 2 | + | Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign. |
| 3 | (space) | If no sign is going to be written, a blank space is inserted before the value. |
| 4 | # | Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero. Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow. By default, if no digits follow, no decimal point is written. Used with g or G the result is the same as with e or E but trailing zeros are not removed. |
| 5 | 0 | Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier). |

### sprintf And sscanf Width Description

| No. |	Width | Description |
| - | - | - |
| 1	| (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| 2 | * | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

### sprintf And sscanf Precision Description

| No. |	.precision | Description |
| - | - | - |
| 1	| .number | For integer specifiers (d, i, o, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For e, E and f specifiers − this is the number of digits to be printed after the decimal point. For g and G specifiers − This is the maximum number of significant digits to be printed. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed. |
| 2	| .* | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

### sprintf And sscanf Length Description

| No. |	Length | Description |
| - | - | - |
| 1 | h | The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x and X). |
| 2 | l | The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X), and as a wide character or wide character string for specifiers c and s. |
| 3 | L | The argument is interpreted as a long double (only applies to floating point specifiers − e, E, f, g and G). |

### Special string processing functions (from the String class in C#)

| No. | Function | Description |
| ------ | ------ | ------ |
| 1 | void *to_upper(const char *str) | Returns a copy of string (str) converted to uppercase. In case of any error, return NULL |
| 2 | void *to_lower(const char *str) | Returns a copy of string (str) converted to lowercase. In case of any error, return NULL |
| 3 | void *insert(const char *src, const char *str, size_t start_index) | Returns a new string in which a specified string (str) is inserted at a specified index position (start_index) in the given string (src). In case of any error, return NULL |
| 4 | void *trim(const char *src, const char *trim_chars) | Returns a new string in which all leading and trailing occurrences of a set of specified characters (trim_chars) from the given string (src) are removed. In case of any error, return NULL |


## Chapter III

## Part 1. Implementation of the string.h library functions

It is necessary to implement the described [above](#stringh-functions) functions of the string.h library: 
 - The library must be developed in C language of C11 standard using gcc compiler
 - The library's code must be located in the src folder 
 - Make it as a static library (with the header file s21_string.h)
 - The library must be developed in accordance with the principles of structured programming, duplication in the code must be avoided
 - Prepare a full coverage of the library's functions by unit-tests using the Check library
 - Provide a Makefile for building the library and tests (with the targets all, clean, test, s21_string.a)
 - Use prefix s21_ before each function
 - It is forbidden to copy the implementation of the standard string.h library and other string processing libraries and to use them
 - You must follow the logic of the standard string.h library (in terms of checks, working with memory and behavior in emergency situations - tests will help you with that)
 - Functions must work with z-string made of single-byte characters in ASCII encoding.

## Part 2. Implementation of the sprintf and sscanf functions

It is necessary to implement the sprintf and sscanf functions from the stdio.h library:
 - The functions must be placed in the s21_string.h library
 - All of the requirements outlined in [the first part](#part-1-implementation-of-the-stringh-library-functions) are applied to functions implementation
 - Full formatting (including flags, widths, precision, modifiers and conversion types) must be supported.

## Part 3. Bonus. Implementation of special string processing functions

Bonus assignment for extra points. You must implement some string processing functions from the String class (described [here](#special-string-processing-functions-from-the-string-class-in-c)):
 - The functions must be placed in the s21_string.h library
 - All of the requirements outlined in [the first part](#part-1-implementation-of-the-stringh-library-functions) are applied to functions implementation, including s21_ before the name.

