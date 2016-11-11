#include <Ports.hpp>
#include <Types.hpp>

uint8_t ND::Ports::InputB(uint16_t _port)
{
	unsigned char rv;
	asm volatile("inb %1, %0" : "=a"(rv) : "dN"(_port));
	return rv;
}
uint16_t ND::Ports::InputW(uint16_t port)
{
	uint16_t rv;
	asm volatile("inw %1, %0" : "=a"(rv) : "dN"(port));
}

void ND::Ports::OutputB(uint16_t port, uint8_t value)
{
	asm volatile("outb %1, %0" : : "dN"(port), "a"(value));
}
