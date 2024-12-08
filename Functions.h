#ifndef _FUNCTIONS_Interface_H_
#define _FUNCTIONS_Interface_H_


void reverseArr(u8 arr[], u8 size)
{
    u8 temp, i;
    for (i = 0; i < (size / 2); i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void convertNumberToString(u8 arr[], s8 num)
{
    u8 Nflag = 0;
    if (num < 0)
    {
        num = -num;
        Nflag = 1;
    }
    u8 x, i = 0;
    do
    {
        x = num % 10;
        num /= 10;
        arr[i] = x + '0';
        i++;
    } while (num != 0);
    if (Nflag)
    {
        arr[i] = '-';
        reverseArr(arr, i + 1);
        arr[i + 1] = '\0';
    }
    else
    {
        reverseArr(arr, i);
        arr[i] = '\0';
    }
}

void convert_u16_arrayToNumber(u16 arr[], s16 *value, u8 size)
{
    u8 i;
    *value = 0;
    for (i = 0; i < size; i++)
    {
        *value = (*value * 10) + (arr[i] );
    }
}

void convert_u8_arrayToNumber(u8 arr[], s16 *value, u8 size)
{
    u8 i;
    *value = 0;
    if (arr[0] == '-')
    {
        for (i = 1; i < size; i++)
        {
            *value = (*value * 10) + (arr[i] - '0');
        }
        *value = -*value;
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            *value = (*value * 10) + (arr[i] - '0');
        }
    }
}
void convertStringToNumber(u8 arr[], s16 *value)
{
    u8 i;
    *value = 0;
    if (arr[0] == '-')
    {
        for (i = 1; arr[i] != '\0'; i++)
        {
            *value = (*value * 10) + (arr[i] - '0');
        }
        *value = -*value;
    }
    else
    {
        for (i = 0; arr[i] != '\0'; i++)
        {
            *value = (*value * 10) + (arr[i] - '0');
        }
    }
}
#endif
