#include "../../include/MyBigChars.h"
unsigned long long MyBigChars::bc_initbigchar(char value)
{
    switch (tolower(value)) {
    case '+': {
        return 105194717184;
    }
    case '-': {
        return 2113929216;
    }
    case '0':
        return 4378558560649593660;
    case '1':
        return 18446528828139322428u;
    case '2':
        return 18375534255494185983u;
    case '3':
        return 18429786241194050559u;
    case '4':
        return 13889313455544189891u;
    case '5':
        return 18428941610344711167u;
    case '6':
        return 18429789600164856831u;
    case '7':
        return 13889313184910721279u;
    case '8':
        return 18429789346707260415u;
    case '9':
        return 18428941879933649919u;
    case 'a':
        return 14106333961122988860u;
    case 'b':
        return 4594731288203871039u;
    case 'c':
        return 4378346574204617532u;
    case 'd':
        return 4608242089300587327u;
    case 'e':
        return 18375534217078703103u;
    case 'f':
        return 217020519520863231u;
    default:
        return 0;
    }
}