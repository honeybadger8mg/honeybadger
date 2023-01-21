//
// Created by ice on 2/19/19.
//

#ifndef SOURCE_CPUBLICUTIL_H
#define SOURCE_CPUBLICUTIL_H

#include <string>
#include <vector>

using namespace std;


class CPublicUtil {
public:
    static string To_UTF8(u16string &s);
    static string To_UTF8(u32string &s);
    static u16string To_UTF16(string &s);
    static u16string To_UTF16(u32string &s);
    static u32string To_UTF32(string &s);
    static u32string To_UTF32(u16string &s);

    static string str2HexStr(string strSrc);

    static string buf2HexStr(char *szIn, int iLen, bool bUpper = false);

    static string Hex2Str(string strHexStr);

    static string Int2String(unsigned int iPara);

    static string Int2HexString(unsigned int iPara);

    static string Byte2HexString(unsigned int iPara);

    static string Int2Mem(unsigned int iPara, int iMemLen = 4);

    static string Long2HexString(uint64_t lPara);

    static int String2Int(string strData);

    static int Mem2Int(string strData);

    static int Mem2Int(unsigned char *szData, bool bLittleEndian = false);

    static int ToLittleEndianInt(int iPara);

    static int ToBigEndianInt(int iPara);

    static string MD5ToString(unsigned char *lpMD5);

    static string ReadFile(string strFilePath);

    static bool WriteFile(string strFilePath, string strData);

    static void EnumCreateDirs(string strFullFilePath);

    static string MakeLower(string strPara);

    static string MakeUpper(string strPara);

    static string GetCurrentDir();

    static bool PathFileExist(string strFilePath);
    static bool IsDirectory(string strFilePath);

    static void GetAllFiles(string strDir, vector<string> &vecOut);
    static void DeleteEmptyDirs(string strDir);
    static void RemoveFile(string strFilePath);

    static int GetFileSize(string strFilePath);

    static uint64_t CurrentMillions();

    static vector<string> Split(string strSrc, string strKey);

    static void Sleep(double dSeconds);

    static string Replace(string strData, string strKey, string strValue);

    static string CreateParcelBuf(string strData);

    static void PrintCurrentMemory();
    static string LTrim(const string& str);
    static string RTrim(const string& str);
    static string Trim(const string& str);

public:
    static string StrFmt(char *szFmt, ...);

public:
    static int NextPrime (int N); // 获取大于参数的素数
    static string IntIP2Str(uint32_t iIp); // ip 转为字符串
};


#endif //SOURCE_CPUBLICUTIL_H
