#pragma once

// ####################################################################################################
// Include libraries:

#include <iostream>                 // Input and output stream library
#include <string>                   // String class and related functions
#include <vector>                   // Dynamic array container
#include <sstream>                  // String stream for input/output operations on strings
#include <cctype>                   // Character classification and conversion functions
#include <limits>                   // Numeric limits for data types
#include <cmath>                    // Mathematical functions
#include <iomanip>                  // Manipulators for formatted I/O, like std::setprecision
#include <algorithm>

// ####################################################################################################

/**
 * @ingroup public_general_functions
 * @brief Function to trim leading and trailing spaces from a string.
 * @return Trimed string.
 *  */ 
std::string trimString(const std::string &str);

/**
 * @ingroup public_general_functions
 * @brief Function to split a string by a delimiter and return a vector of trimmed strings.
 * @return Splited vector string.
 *  */ 
std::vector<std::string> splitString(const std::string &line, char delimiter);

/**
 * @ingroup public_general_functions
 * @brief Function to check if a string is empty or contains only spaces
 * @return true if succeeded.
 *  */ 
bool isWhitespaceOnly(const std::string& line);

/**
 * @ingroup public_general_functions
 * @brief Function to validate a vector string has the expected number of elements. 
 * @return true if data size is expectedColumnCount and there is no empty data.
 *  */ 
bool validateRow(const std::vector<std::string> &data, size_t expectedColumnCount);

/**
 * @ingroup public_general_functions
 * @brief Check data string for certain type.
 * @param type can be: {uint8, uint16, uint32, uint64, int8, int16, int32, int64, float, double, string, bool}
 * @return true if succeeded.
 *  */ 
bool checkValuetype(const std::string data, const std::string type);

/**
 * @ingroup public_general_functions
 * @brief Check string format for bool.
 * @param str can be: {true, false, TRUE, FALSE}
 * @return true if succeeded. 
 *  */ 
bool isBoolean(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for double.
 * @return true if succeeded. 
 *  */ 
bool isDouble(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for float.
 * @return true if succeeded. 
 *  */ 
bool isFloat(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for int64.
 * @return true if succeeded. 
 *  */ 
bool isInt64(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for int32.
 * @return true if succeeded. 
 *  */ 
bool isInt32(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for int16.
 * @return true if succeeded. 
 *  */ 
bool isInt16(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for int8.
 * @return true if succeeded. 
 *  */ 
bool isInt8(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for uint64.
 * @return true if succeeded. 
 *  */ 
bool isUInt64(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for uint32.
 * @return true if succeeded. 
 *  */ 
bool isUInt32(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for uint16.
 * @return true if succeeded. 
 *  */ 
bool isUInt16(const std::string& str);

/**
 * @ingroup public_general_functions
 * @brief Check string format for uint8.
 * @return true if succeeded. 
 *  */
bool isUInt8(const std::string& str);

/** 
 * @ingroup public_general_functions
 * @brief Convert double value to string with certain precision.
 * @param value: double value.
 * @param precision: number of character after dot character. 
 * @return string of double value.
*/
std::string decimalToString(double value, uint8_t precision);

/**
 * @ingroup public_general_functions
 * @brief Convert float value to string with certain precision.
 * @param value: float value.
 * @param precision: number of character after dot character. 
 * @return string of float value.
 */ 
std::string decimalToString(float value, uint8_t precision);

/**
 * @ingroup public_general_functions
 * @brief Function to check if all cherecters on a string is a valid number. 
 * @note For decimal numbers with "." character returned false.
 * @return true if succeeded.
 *  */ 
bool isNumber(const std::string &str);

/**
 * @ingroup public_general_functions
 * @brief Function to check if a string ends with a given suffix
 * @return true if succeeded.
 *  */ 
bool endsWith(const std::string& str, const std::string suffix);

/**
 * @ingroup public_general_functions
 * @brief Get the value type in string.
 * @return One of these values: uint8, uint16, uint32, uint64, int8, int16, int32, int64, float, double, string, none.
 * @note If the value type can not detected, return "none" value.
 */
// std::string getValueType(std::any &value);
