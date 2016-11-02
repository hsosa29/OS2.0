 #ifndef KEYBOARD_HPP
 #define KEYBOARD_HPP
 
 #define ND_KEYBOARD_KEY_RELEASE 0x80
 
 namespace ND{
		namespace Keyboard{
				void Setup();
				void wait();
				unsigned char GetChar();
				char* GetString();
				unsigned int GetInt();
			}
	 }
extern "C"
void ND_Keyboard_Handler(struct regs* r);
 #endif
