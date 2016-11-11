#ifndef PORTS_HPP
#define PORTS_HPP

#include <Types.hpp>

namespace ND{
	namespace Ports{
			uint8_t InputB(uint16_t _port);
			uint16_t InputW(uint16_t port);
			void OutputB(uint16_t port, uint8_t value); 
		}
	}
#endif
