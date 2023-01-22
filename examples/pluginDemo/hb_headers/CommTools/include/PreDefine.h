//
// Created by ice on 2019-06-29.
//

#ifndef JNI_PREDEFINE_H
#define JNI_PREDEFINE_H

#include <string>

#ifdef Platfrom_Windows
#define FILE_SEPRATOR "\\"
#else
#define FILE_SEPRATOR "/"
#endif



#ifndef UINT
typedef unsigned int UINT;
#endif

#ifndef _ULONG
typedef unsigned long long int _ULONG;
//typedef unsigned long _ULONG;
#endif

#ifndef _LONG
typedef long long int _LONG;
//typedef long _LONG;
#endif


#ifndef UCHAR
typedef unsigned char UCHAR;
#endif

#ifndef USHORT
typedef unsigned short USHORT;
#endif

struct REG_VEC_R_I16 { // 普通寄存器 整形
    USHORT part0;
    USHORT part1;
};

struct REG_VEC_D_I32 { // D寄存器 整形
    uint32_t part0;
    uint32_t part1;
};
struct REG_VEC_D_I16 { // D寄存器
    USHORT part0;
    USHORT part1;
    USHORT part2;
    USHORT part3;
};

struct REG_VEC_D_I8 { // D寄存器
    uint8_t part0;
    uint8_t part1;
    uint8_t part2;
    uint8_t part3;
    uint8_t part4;
    uint8_t part5;
    uint8_t part6;
    uint8_t part7;
};

struct REG_VEC_Q_I32 {
    REG_VEC_D_I32 lowPart;
    REG_VEC_D_I32 highPart;
};
struct REG_VEC_Q_I16 {
    REG_VEC_D_I16 lowPart;
    REG_VEC_D_I16 highPart;
};
struct REG_VEC_Q_I8 {
    REG_VEC_D_I8 lowPart;
    REG_VEC_D_I8 highPart;
};
// 代表整形  便于按位处理
struct REGINT32 {
    uint8_t part0;
    uint8_t part1;
    uint8_t part2;
    uint8_t part3;
};

struct REGINT64 {
    uint32_t lowPart;
    uint32_t highPart;
};
// 定义128位 用于处理neon寄存器
struct UINT128 {
    uint64_t lowPart;
    uint64_t highPart;
};


#ifndef Defalt_Disasm_Len
#define Defalt_Disasm_Len 24  // 默认反编译的大小  每次就反编译一行
#endif

#ifndef MAX_Cached_Disasm_Buf_Size
#define MAX_Cached_Disasm_Buf_Size  20000 * 2400  // 存储2w行 约 45M  用于xxinfo的内存申请
#endif

#ifndef Default_Cached_Disasm_LineCount
#define Default_Cached_Disasm_LineCount  50*10000  // 反汇编的行数
#endif

#ifndef VirtualProcess_CacheSize
#define VirtualProcess_CacheSize  500 *1024 *1024  // 总内存的池子的大小
#endif

#ifndef VirtualProcess_MaxPoolSize
#define VirtualProcess_MaxPoolSize  320 *1024 *1024   // 一个任务的大小
#endif

#ifndef PJ_BufferHeader_Size
#define PJ_BufferHeader_Size  200
#endif

// 每个实例默认的mutex个数
#ifndef PJ_Default_MutexCount_PerEntry
#define PJ_Default_MutexCount_PerEntry  100
#endif

// 存储 mutex的池子的大小
#ifndef IceMutex_MaxPoolSize
#define IceMutex_MaxPoolSize  5 *1024 *1024
#endif

// 反编译引擎类的大小
#ifndef DisEngine_MaxPoolSize
#define DisEngine_MaxPoolSize  5 *1024 *1024
#endif

// 存储信号的大小
#ifndef SigAction_MaxPoolSize
#define SigAction_MaxPoolSize  1 *1024 *1024
#endif

// 存储事件的大小
#ifndef Event_MaxPoolSize
#define Event_MaxPoolSize  1 *1024 *1024
#endif

//CachedDisasm IceHashMap 等的大小
#define INSTRUCTION_CACHE_SIZE 0x1000


#endif //JNI_PREDEFINE_H
