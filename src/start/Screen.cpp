#include <Types.hpp>
#include <Color.hpp>
#include <Screen.hpp>
#include <Ports.hpp>

uint16_t *vidmem= (uint16_t *)0xB8000;
ND_Color backColour = BLACK;
ND_Color foreColour = WHITE;
uint8_t cursor_x = 0;
uint8_t cursor_y = 0;

static void UpdateCursor()
{
   // The screen is 80 characters wide...
   uint16_t cursorLocation = cursor_y * 80 + cursor_x;
   ND::Ports::OutputB(0x3D4, 14);                  // Tell the VGA board we are setting the high cursor byte.
   ND::Ports::OutputB(0x3D5, cursorLocation >> 8); // Send the high cursor byte.
   ND::Ports::OutputB(0x3D4, 15);                  // Tell the VGA board we are setting the low cursor byte.
   ND::Ports::OutputB(0x3D5, cursorLocation);      // Send the low cursor byte.
}


ND_Color ND::Screen::GetColor(ND_SIDE side)
{
	if(side==ND_SIDE_BACKGROUND){
		return backColour;
	}else{
		return foreColour;
	}
}

void ND::Screen::SetColor(ND_SIDE side, ND_Color colour)
{
	if(side==ND_SIDE_BACKGROUND)
	{
		backColour=colour;
	}else{
		foreColour=colour;
	}
}

void ND::Screen::PutChar(char c)
{
	uint8_t  attributeByte = (backColour << 4) | (foreColour & 0x0F);
	uint16_t attribute = attributeByte << 8;
	uint16_t *location;
	if (c == 0x08 && cursor_x)
	{
		cursor_x--;
	}else if(c == '\r')
	{
		cursor_x=0;
	}else if(c == '\n')
	{
		cursor_x=0;
		cursor_y++;
	}
	if(c >= ' ') /* Printable character */
	{
		location = vidmem + (cursor_y*80 + cursor_x);
		*location = c | attribute;
		cursor_x++;
	}
	if(cursor_x >= 80) /* New line, please*/
	{
		cursor_x = 0;
		cursor_y++;
	}

	
	/* Scroll if needed*/
	uint8_t attributeByte2 = (0 /*black*/ << 4) | (15 /*white*/ & 0x0F);
	uint16_t blank = 0x20 /* space */ | (attributeByte2 << 8);
	if(cursor_y >= 25)
	{
       int i;
       for (i = 0*80; i < 24*80; i++)
       {
           vidmem[i] = vidmem[i+80];
       }

       // The last line should now be blank. Do this by writing
       // 80 spaces to it.
       for (i = 24*80; i < 25*80; i++)
       {
           vidmem[i] = blank;
       }
       // The cursor should now be on the last line.
       cursor_y = 24;
   }
	/* Update cursor */
	UpdateCursor();
}

void ND::Screen::PutString(const char* str)
{
	int i=0;
	while(str[i]) 
	{
		ND::Screen::PutChar(str[i++]);
	}
}

 void ND::Screen::Clear(ND_Color colour)
{
  
   uint8_t attributeByte = (colour /*background*/ << 4) | (15 /*white - foreground*/ & 0x0F);
   uint16_t blank = 0x20 /* space */ | (attributeByte << 8);

   int i;
   for (i = 0; i < 80*25; i++)
   {
       vidmem[i] = blank;
   }

  
   cursor_x = 0;
   cursor_y = 0;
   
   UpdateCursor();
}

void ND::Screen::SetCursor(uint8_t x, uint8_t y)
{
	cursor_x=x;
	cursor_y=y;
	
	UpdateCursor();
}

void ND::Screen::itoa(unsigned int i){
	unsigned int tmp;
    if(i<0){
        ND::Screen::PutChar('-');
        i *= -1;
    }
    tmp = 0;
	do{
		tmp = tmp * 10 + i % 10;
		i = i / 10;
	}while(i);
    do{ 
        ND::Screen::PutChar((char)(tmp % 10 + 48));
        tmp = tmp / 10;
    }while(tmp);

}

int ND::Screen::atoi (char* str)
	{
		int res = 0; 
			
		for (int i = 0; str[i] != '\0'; ++i)
			res = res*10 + str[i] - '0';
	
		
		res = (res + 38)/10;

		return res;
	}
