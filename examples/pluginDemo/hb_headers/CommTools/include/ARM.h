#ifndef MMTLS_ARM_H
#define MMTLS_ARM_H

#include <string>

#define ROTELEN 0x40 // 整形
//循环左移:
#define CROL(value, bits) ((value << bits) | (value >> (ROTELEN - bits)))
//循环右移:
//#define CROR(value, bits) ((value >> bits) | (value << (ROTELEN - bits)))

inline int CROR(unsigned int value, char bits) {
    return (value >> bits) | (value << (ROTELEN - bits));
};

class ARM {
public:
    static void STR(unsigned char *szDst, unsigned int iSrc);

    static void STRD(unsigned char *szDst, uint64_t lSrc);

    static void STR(unsigned int &iDst, unsigned int iSrc); // 这个是为了兼容的函数 非对标arm
    static void STRH(unsigned char *szDst, unsigned int iSrc);

    static void STRB(unsigned char *szDst, unsigned int iSrc);

    static unsigned int ORR(unsigned int iPara1, unsigned int iPara2);

    static unsigned int ORN(unsigned int iPara1, unsigned int iPara2);

    static unsigned int EOR(unsigned int iPara1, unsigned int iPara2); // 逻辑异或
    static unsigned int ROR32(unsigned int value, char bits);

    static unsigned int ROL32(unsigned int word, unsigned int shift);

    static unsigned int LSR32(unsigned int iPara1, unsigned int iPara2); // 逻辑右移  无符号
    static uint64_t LSR64(uint64_t iPara1, unsigned int iPara2); // 逻辑右移  无符号
    static int ASR32(int iPara1, int iPara2); // 算数右移 有符号
    static int64_t ASR64(int64_t lPara1, int iPara2); // 算数右移 有符号
    static unsigned int LSL32(unsigned int iPara1, unsigned int iPara2);

    static uint64_t LSL64(uint64_t iPara1, unsigned int iPara2);

    static unsigned int MLA(unsigned int iPara1, unsigned int iPara2, unsigned int iPara3);

    static unsigned int REV(unsigned int iPara);

    static unsigned int RBIT(unsigned int iPara);

    static unsigned int AND(unsigned int iPara1, unsigned int iPara2); // ands : 故Z一般看目标寄存器的值是否为0，Rd=0时Z=1，否则Z=0。

    static unsigned char *LDRW(unsigned char *szDst);

    static uint64_t LDRD(unsigned char *szDst);

    static unsigned int LDR(unsigned char *szDst);

    static unsigned int LDRB(unsigned char *szDst);

    static unsigned int LDRH(unsigned char *szDst);

    static unsigned int LDRSH(unsigned char *szDst);

    static unsigned int LDRSB(unsigned char *szDst);

    static void STRW(unsigned char *szDst, unsigned char *szAddr); // 将指针地址写入到szDst的缓冲区 szDst长度应当至少8字节

    // 位域
    static unsigned int UBFX(unsigned int iPara, int lsb, int iWidth);

    static int SBFX(int iPara, int lsb, int iWidth);

    // 半字相加扩展为全字  Sign extend Halfword with Add, to extend a 16-bit value to a 32-bit value.
    // https://developer.arm.com/docs/dui0473/latest/arm-and-thumb-instructions/sxtah
    static unsigned int SXTAH(unsigned int stPara1, unsigned int stPara2);

    static unsigned int UXTAB(unsigned int stPara1, unsigned int stPara2);

    //
    static unsigned int BFC(unsigned int iPara, int lsb, int iWidth);

    static unsigned int BIC(unsigned int iPara1, int iPara2);

    static unsigned int BICW(unsigned int iPara1, int iPara2);

    static unsigned int UXTH(unsigned int iPara1);

    static int SXTH(int iPara1);

    static int SXTB(int iPara1);

    static unsigned int UXTB(unsigned int iPara1);

    static unsigned int UXTB16(unsigned int iPara1);

    static unsigned int MOVT(unsigned int iSrc, unsigned int iValue);

    static unsigned int MOVW(unsigned int iSrc, unsigned int iValue);

    static unsigned int MLS(unsigned int lOne, unsigned int lSec, unsigned int lThird);

    static int64_t SMULL(int iOne, int iSec);

    //static int64_t UMULL(int64_t lOne, int64_t lSec, int64_t lThird);  连乘
    static int64_t UMLAL(int64_t lOne, int64_t lSec, int64_t lThird);

    static int64_t SMLAL(unsigned int iLow, unsigned int iHig, int iN, int iM);

    static unsigned int SMMUL(int lOne, int lSec);

    static bool TST(unsigned int iPara1, unsigned int iPara2);

    static unsigned int RSB(unsigned int iPara1, unsigned int iPara2);

    static int RSBMI(int iPara1, int iPara2);

    static int CLZ(int iPara1);

    static int MVN(int iPara1);

    static unsigned int MUL(unsigned int iPara1, unsigned int iPara2);

    static unsigned int RRX(unsigned int iPara1, bool bC);

    static unsigned int NEG(unsigned int iPara1);

public:
    static unsigned int SBC(unsigned int value, unsigned int value1, bool c);

    static unsigned int BFI(unsigned int dst, unsigned int src, unsigned int lsb, unsigned int width);

    static int SMMLA(int para1, int para2, int para3);

    // 浮点数转16进制
    static uint64_t Double2Hex(double fPara);

    static double Hex2Double(uint64_t lPara);

    static unsigned int Float2Hex(float fPara);

    static float Hex2Float(unsigned int iPara);
};

#endif //MMTLS_ARM_H
