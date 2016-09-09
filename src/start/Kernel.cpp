
#include <ND_Screen.hpp>
#include <ND_Color.hpp>
#include <ND_Panic.hpp>
#include <ND_Keyboard.hpp>
#include <ND_GDT.hpp>
#include <ND_IDT.hpp>
#include <ND_IRQ.hpp>
#include <ND_Timer.hpp>
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
