#define STACK_SIZE 0x4000

.text

.global speaker_tone
speaker_tone:
	mov %cx, %ax
	mov %al, 182
	out %al, $0x43
	mov %ax, %cx
	out %al, $0x42
	mov %al, %ah
	out %al, $0x42
	in $0x61, %al
	or $0x03, %al
	out %al, $0x61
	
	ret

.global speaker_off
speaker_off:
	in $0x61, %al
	and $0xFC, %al
	out %al, $0x61
	
	ret

.global speaker_beep
speaker_beep:
	xor %eax,%eax
	mov %ax, 0x0C80
	call speaker_tone
	mov %ax, 2
	
	call speaker_off

	ret

