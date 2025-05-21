// ####################################################################################################
// Include libraries:

#include "Stream.h"

// ####################################################################################################

std::string trimString(const std::string &str) 
{
    size_t start = str.find_first_not_of(' ');  // Find first non-space character
    size_t end = str.find_last_not_of(' ');     // Find last non-space character
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::vector<std::string> splitString(const std::string &line, char delimiter) 
{
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(line);

    // Split by the specified delimiter and trim each token before storing
    while (getline(ss, token, delimiter)) 
    {
        tokens.push_back(trimString(token));
    }

    return tokens;
}

bool isWhitespaceOnly(const std::string& line) 
{
    return all_of(line.begin(), line.end(), ::isspace);  // Check if all characters are spaces
}

bool validateRow(const std::vector<std::string> &data, size_t expectedColumnCount) 
{
    // Check if the row has the expected number of columns
    if (data.size() != expectedColumnCount) 
    {
        // Error: Incorrect number of columns. 
        return false;
    }

    // Check for empty fields in the row
    for (const auto &field : data) 
    {
        if (field.empty()) 
        {
            // Error : Empty field detected in the row.;
            return false;
        }
    }

    return true;
}

bool isUInt8(const std::string& str) {
    unsigned int value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && value <= std::numeric_limits<uint8_t>::max();
}

bool isUInt16(const std::string& str) {
    unsigned int value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && value <= std::numeric_limits<uint16_t>::max();
}

bool isUInt32(const std::string& str) {
    unsigned long value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && value <= std::numeric_limits<uint32_t>::max();
}

bool isUInt64(const std::string& str) {
    unsigned long long value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && value <= std::numeric_limits<uint64_t>::max();
}

bool isInt8(const std::string& str) {
    int value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && value >= std::numeric_limits<int8_t>::min() && value <= std::numeric_limits<int8_t>::max();
}

bool isInt16(const std::string& str) {
    int value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && value >= std::numeric_limits<int16_t>::min() && value <= std::numeric_limits<int16_t>::max();
}

bool isInt32(const std::string& str) {
    long value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && value >= std::numeric_limits<int32_t>::min() && value <= std::numeric_limits<int32_t>::max();
}

bool isInt64(const std::string& str) {
    long long value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && value >= std::numeric_limits<int64_t>::min() && value <= std::numeric_limits<int64_t>::max();
}

bool  isFloat(const std::string& str) {
    float value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && std::isfinite(value);
}

bool isDouble(const std::string& str) {
    double value;
    std::istringstream iss(str);
    iss >> value;
    return !iss.fail() && iss.eof() && std::isfinite(value);
}

bool isBoolean(const std::string& str) 
{
    std::string lowerStr = str;
    for (auto& c : lowerStr) c = std::tolower(c);
    return (lowerStr == "true" || lowerStr == "false");
}

bool checkValuetype(const std::string data, const std::string type)
{
    if(type == "uint8")
    {
        return isUInt8(data);
    }
    else if(type == "uint16")
    {
        return isUInt16(data);
    }
    else if(type == "uint32")
    {
        return isUInt32(data);
    }
        else if(type == "uint64")
    {
        return isUInt64(data);
    }
        else if(type == "int8")
    {
        return isInt8(data);
    }
        else if(type == "int16")
    {
        return isInt16(data);
    }
        else if(type == "int32")
    {
        return isInt32(data);
    }
        else if(type == "int64")
    {
        return isInt64(data);
    }
        else if(type == "float")
    {
        return isFloat(data);
    }
        else if(type == "double")
    {
        return isDouble(data);
    }
        else if(type == "string")
    {
        return true;
    }
        else if(type == "bool")
    {
        return isBoolean(data);
    }
    else
    {
        return false;
    }

    return true;
}

std::string decimalToString(double value, uint8_t precision) 
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    return oss.str();
}

std::string decimalToString(float value, uint8_t precision) 
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    return oss.str();
}

bool isNumber(const std::string &str) 
{
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

bool endsWith(const std::string& str, const std::string suffix) 
{
    if (str.size() >= suffix.size()) 
    {
        return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }
    return false;
}

// std::string getValueType(std::any &value)
// {
//     std::string valueType = "none";

//     if(value.type() == typeid(std::string))
//     {
//         valueType = "string";
//     }
//     else if(value.type() == typeid(float))
//     {
//         valueType = "float";
//     }
//     else if(value.type() == typeid(double))
//     {
//         valueType = "double";
//     }
//     else if(value.type() == typeid(uint8_t))
//     {
//         valueType = "uint8";
//     }
//     else if(value.type() == typeid(uint16_t))
//     {
//         valueType = "uint16";
//     }
//     else if(value.type() == typeid(uint32_t))
//     {
//         valueType = "uint32";
//     }
//     else if(value.type() == typeid(uint64_t))
//     {
//         valueType = "uint64";
//     }
//     else if(value.type() == typeid(int8_t))
//     {
//         valueType = "int8";
//     }
//     else if(value.type() == typeid(int16_t))
//     {
//         valueType = "int16";
//     }
//     else if(value.type() == typeid(int32_t))
//     {
//         valueType = "int32";
//     }
//     else if(value.type() == typeid(int64_t))
//     {
//         valueType = "int64";
//     }
//     else
//     {
//         valueType = "none";
//     }

//     return valueType;
// }




