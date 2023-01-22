//
// Created by ice on 3/26/21.
//

#ifndef HONEYBADGER_ICEREGISTER_H
#define HONEYBADGER_ICEREGISTER_H

#include <string>
#include <unordered_map>
#include <map>
#include "PreDefine.h"
#include "ArmReg.h"

using namespace std;

union RegValue {
    uint32_t value32; // 普通寄存器
    REG_VEC_R_I16 vecRI16;

    uint64_t value64; // d0-d31
    REGINT32 simd32; // 方便simd指令按位处理的情况
    REGINT64 dRegValue; // 用来获取 s0-s31 寄存器的值
    // d寄存器部分
    REG_VEC_D_I32 vecDI32;
    REG_VEC_D_I16 vecDI16;
    REG_VEC_D_I8 vecDI8;

    // q寄存器部分
    UINT128 value128;
    REG_VEC_Q_I32 vecQI32;
    REG_VEC_Q_I16 vecQI16;
    REG_VEC_Q_I8 vecQI8;
    uint64_t vecQArrayLong[2]{0, 0};
    uint32_t vecQArrayInt[4];
    USHORT vecQArrayShort[8];
    uint8_t vecQArrayByte[16];
};//= {.vecQArrayLong[0] = 0,.vecQArrayLong[1] = 0};


#define V_RegName_Shandow_Size (ARM_REG_ENDING + 32)

// 存储寄存器的值  每个 debugger对应一个
class IceRegister {
public:
    IceRegister();

    ~IceRegister();

    // 设置值  用64位是为了支持浮点数等情况
    void SetRegValue(int iReg, RegValue &regValue);

    RegValue GetRegValue(int iReg);

    // 可视化
    void MakeReadable();

    // 导出寄存器的值到map  用于jni函数返回值等场景
    void Export2Map(map<UINT, uint64_t> *pMapOut);

    map<UINT, uint64_t> ExportResult();

private:
    // 生成寄存器映射表
    void CreateRegShandow();

private:
    uint64_t R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, LR, SP, PC;
    uint64_t D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15, D16, D17, D18, D19, D20, D21, D22, D23, D24, D25, D26, D27, D28, D29, D30, D31;

private:
    uint32_t m_arrayRegNameTable[V_RegName_Shandow_Size]; // 寄存器名称映射表
    uint32_t m_arrayRegValueTable[V_RegName_Shandow_Size]; // 寄存器值硬件表
};


#endif //HONEYBADGER_ICEREGISTER_H
