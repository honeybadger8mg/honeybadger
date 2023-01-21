//
// Created by ice on 2022/1/1.
//

#ifndef HONEYBADGER_ICERANDOM_H
#define HONEYBADGER_ICERANDOM_H

#include <string>

using namespace std;

class IceRandom {
public:
    //
    static uint32_t NextInt(uint32_t iMin, uint32_t iMax);
    static uint8_t NextByte();
    static string NextBuffer(int iLen);
    static string NextString62(int iLen); // 完整字母表 包含大小写
    static string NextString16(int iLen); // 0-9a-f 只有小写


    static string CreateUUID();
};


#endif //HONEYBADGER_ICERANDOM_H
