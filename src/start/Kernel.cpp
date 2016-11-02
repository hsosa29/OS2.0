
#include <Screen.hpp>
#include <Color.hpp>

#include <Keyboard.hpp>
#include <GDT.hpp>
#include <IDT.hpp>
#include <IRQ.hpp>
#include "Terminal.hpp"

#if defined(__cplusplus)
extern "C" 
#endif
int Kernel()
{
	asm volatile("cli");
	
	ND::GDT::Install();
	ND::IDT::Install();
	ND::IRQ::Install();

	ND::Keyboard::Setup();
	
	asm volatile("sti");
	ND::Keyboard::wait();


	Terminal::main();

	return 0;
}
