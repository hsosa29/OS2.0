#include <ISR.hpp>
#include <Screen.hpp>

const char* exception_messages[]=
{
	
};

extern "C"
void ND_ISR_Handler(struct regs *r)
{
	
}

extern "C"{
void ND_ISR_Common()
{
	asm volatile(
	"popl %ebp	   \n"	
	"pushal	   \n"
	"pushl	%ds\n"//ds
	"pushl	%es\n"//es
	"pushl	%fs\n"//fs
	"pushl	%gs\n"//gs
	"movw $0x10, %ax \n"
	"movw %ax, %ds \n"
	"movw %ax, %es \n"
	"movw %ax, %fs \n"
	"movw %ax, %gs \n"
	"pushl %esp \n"
	"movl $ND_ISR_Handler, %eax \n"
	"call *%eax \n"
	"popl %esp \n"
	"popl %gs \n"
	"popl %fs \n"
	"popl %es \n"
	"popl %ds \n"
	"popal    \n"
	"add $0x8, %esp \n"
	"sti	\n"
	"iret \n"
	);
}

void ND::ISR::ISR1()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x00\n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR2()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x01 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR3()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x02 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR4()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x03 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR5()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x04 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR6()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x05 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR7()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x06 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR8()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x07 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR9()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x08 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR10()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x09 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR11()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0A \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR12()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0B \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR13()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0C \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR14()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0D \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR15()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x0E \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR16()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x0F \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR17()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x10 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR18()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x11 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR19()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x12 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR20()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x13 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR21()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x14 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR22()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x15 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR23()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x16 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR24()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x17 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR25()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x18 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR26()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x19 \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR27()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1A \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR28()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1B \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR29()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1C \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR30()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1D \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR31()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1E \n"
	"jmp ND_ISR_Common \n"
	);
}
void ND::ISR::ISR32()
{
	asm volatile(
	"popl %ebp	   \n"	
	"cli \n"
	"pushl $0x00 \n"
	"pushl $0x1F \n"
	"jmp ND_ISR_Common \n"
	);
}
}
