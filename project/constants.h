#ifndef INCLUDED_CONSTANTS_H
#define INCLUDED_CONSTANTS_H

enum DataTypes {INT, BOOL, STRING, CHAR, FLOAT, UINT};

typedef struct Symbol
{
    std::string identifier;
    int Type, scope, size1, size2;
} Symbol;

#endif
