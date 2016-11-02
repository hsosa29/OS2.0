#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <Types.hpp>

namespace ND{
		namespace Memory{
				void* Set(void* buf, int c, size_t len);
				void* Copy(void* dest,const void* src, size_t len);
				int Compare(const void* p1, const void* p2, size_t len);
			}
	}


#endif
