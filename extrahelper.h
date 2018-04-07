#pragma once

namespace bigboi
{
	extern int indicator;
}





/*
#define isinrange(x,a,b)  (x >= a && x <= b)
#define bits( x )    (isinrange((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (isinrange(x,'0','9') ? x - '0' : 0))
#define byte( x )    (bits(x[0]) << 4 | bits(x[1]))
#define GetModInformation        K32GetModuleInformation



class CGameSearch
{
public:
DWORD signature(const char* szModule, const char* szSignature)
{
MODULEINFO modInfo;
GetModInformation(GetCurrentProcess(), GetModuleHandleA(szModule), &modInfo, sizeof(MODULEINFO));
DWORD startAddress = (DWORD)modInfo.lpBaseOfDll;
DWORD endAddress = startAddress + modInfo.SizeOfImage;
const char* pat = szSignature;
DWORD firstMatch = 0;
for (DWORD pCur = startAddress; pCur < endAddress; pCur++) {
if (!*pat) return firstMatch;
if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == byte(pat)) {
if (!firstMatch) firstMatch = pCur;
if (!pat[2]) return firstMatch;
if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?') pat += 3;
else pat += 2;
}
else {
pat = szSignature;
firstMatch = 0;
}
}
return NULL;
}
};
extern CGameSearch search;

*/