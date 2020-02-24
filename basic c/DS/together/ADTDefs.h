#ifndef _ADTDefs_h_
#define _ADTDefs_h_

typedef enum
{
    ERR_OK=0,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,

    ERR_STACK_BBBBB = 30,

} ADTErr;
/*
 * @enum types of different errors for returns
*/
#endif
