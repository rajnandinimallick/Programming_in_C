#include <stdio.h>

int main(void)
{
    /* Floating-point constant */
    float floatingNumber = 123.456f;

    /* Invalid constants (commented out) */

    // unsigned int invalidFloatingConstant = 0X10.5;
    // Invalid: hexadecimal floating-point constant written incorrectly.

    // unsigned int invalidHexDigit = 0X0G1;
    // Invalid: 'G' is not a valid hexadecimal digit.

    /* Valid integer constants */

    unsigned int octalNumber = 0001;         // Octal value = 1
    unsigned int hexadecimalNumber = 0xFFFF; // Hexadecimal
    long int longInteger = 123L;             // Long integer

    unsigned int hexadecimalValue = 0XAB05;
    long int longZero = 0L;

    float negativeFloat = -597.25f;

    /* Scientific notation */

    double exponentNumber = 123.5e2; // 12350.0
    float smallFloat = .0001f;
    int positiveInteger = +12;

    /* Invalid constants (commented out) */

    // unsigned int invalidFloatAssignment = 98.6F;
    // Invalid type assignment: floating constant assigned to unsigned int.

    // unsigned int invalidUnsignedFloat = 98.7U;
    // Invalid: 'U' suffix cannot be used with floating-point constants.

    // int invalidSuffix = 17777s;
    // Invalid: 's' is not a valid integer suffix.

    // unsigned int invalidOctal = 0996;
    // Invalid: octal constants cannot contain 8 or 9.

    // long int invalidExponentAssignment = -12E-12;
    // Invalid type assignment: exponential notation is a floating-point constant.

    // int invalidCommaValue = 15,000;
    // Invalid: commas cannot be used inside numeric constants.

    /* More valid constants */

    long double longDoubleValue = 1.234L;

    unsigned int lowercaseUnsigned = 197u;
    unsigned int uppercaseUnsigned = 100U;

    unsigned long hexadecimalLong = 0XABCDEFL;
    unsigned int hexadecimalUnsigned = 0xABCu;

    int positiveNumber = +123;

    return 0;
}