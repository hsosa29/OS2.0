
#include <Memory.hpp>

void* ND::Memory::Set(void* buf, int c, size_t len)
{
	unsigned char* tmp=(unsigned char*)buf;
	while(len--)
	{
		*tmp++=c;
	}
	return buf;
}

void* ND::Memory::Copy(void* dest,const void* src, size_t len)
{
	const unsigned char* sp=(const unsigned char*)src;
	unsigned char* dp=(unsigned char*)dest;
	for(;len!=0;len--) *dp++=*sp++;
	return dest;
}

int ND::Memory::Compare(const void* p1, const void* p2, size_t len)
{
	const char* a=(const char*)p1;
	const char* b=(const char*)p2;
	size_t i=0;
	for(;i<len;i++)
	{
		if(a[i] < b[i])
			return -1;
		else if(a[i] > b[i])
			return 1;
	}
	return 0;
}
