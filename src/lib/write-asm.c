#include <stdio.h>
#include <stdint.h>

#include <michet/michet.h>

#include <michet/asm-x86.h>
#include <michet/write-asm.h>

int pos = 0;

void write_padding(FILE *fd)
{
  uint8_t padding = 0;

  fwrite(&padding, 1, 1, fd);
  fwrite(&padding, 1, 1, fd);
  fwrite(&padding, 1, 1, fd);

  pos += 3;
}

void write_32(FILE *fd, uint32_t instructions)
{
  fwrite(&instructions, sizeof(uint32_t), 1, fd);
}

void write_instruction(FILE *fd, uint8_t instruction)
{
  fwrite(&instruction, sizeof(uint8_t), 1, fd);
  pos += 1;
}

int get_addr_from_pos(int pos)
{
  int address = pos / 16;
  return address;
}


void write_print(michet_t *michet, char *text_to_print, size_t len)
{
  FILE *fd;
  uint8_t instruction;

  // ELF Magic
  write_32(michet->fp, 0x464c457f);
  write_32(michet->fp, 0x00010101);
  write_32(michet->fp, 0x00000000);
  write_32(michet->fp, 0x00000000);

  write_32(michet->fp, 0x00030002);
  write_32(michet->fp, 0x00000001);

  // Offset of our _start
  write_32(michet->fp, 0x08048080);

  // phdr offset
  write_32(michet->fp, 0x00000034);

  write_32(michet->fp, 0x00000000);
  write_32(michet->fp, 0x00000000);
  write_32(michet->fp, 0x00200034);
  write_32(michet->fp, 0x00280002);

  write_32(michet->fp, 0x00030004);
  write_32(michet->fp, 0x00000001);
  write_32(michet->fp, 0x00000000);
  write_32(michet->fp, 0x08048000);

  write_32(michet->fp, 0x08048000);
  write_32(michet->fp, 0x0000009d);
  write_32(michet->fp, 0x0000009d);
  write_32(michet->fp, 0x00000005);

  write_32(michet->fp, 0x00001000);
  write_32(michet->fp, 0x00000001);
  write_32(michet->fp, 0x000000a0);
  write_32(michet->fp, 0x080490a0);

  write_32(michet->fp, 0x080490a0);
  write_32(michet->fp, 0x0000000d);
  write_32(michet->fp, 0x0000000d);
  write_32(michet->fp, 0x00000006);

  write_32(michet->fp, 0x00001000);
  write_32(michet->fp, 0x00000000);
  write_32(michet->fp, 0x00000000);
  write_32(michet->fp, 0x00000000);

  // mov edx, len
  write_instruction(michet->fp, MOV+EDX);
  write_instruction(michet->fp, len);
  write_padding(michet->fp);

  // mov ecx, 0xA0
  write_instruction(michet->fp, MOV+ECX);
  write_instruction(michet->fp, 0xA0); // 0xA0 is the address where the string starts

  // Unknown bits
  write_instruction(michet->fp, 0x90);
  write_instruction(michet->fp, 0x04);
  write_instruction(michet->fp, 0x08);

  // mov ebx, 1
  write_instruction(michet->fp, MOV+EBX);
  write_instruction(michet->fp, 0x01);
  write_padding(michet->fp);

  // mov eax, 4
  write_instruction(michet->fp, MOV+EAX);
  write_instruction(michet->fp, 0x04);
  write_padding(michet->fp);

  // int 0x80
  write_instruction(michet->fp, INT);
  write_instruction(michet->fp, 0x80);

  // mov eax, 1
  write_instruction(michet->fp, MOV+EAX);
  write_instruction(michet->fp, 0x01);
  write_padding(michet->fp);

  // int 0x80
  write_instruction(michet->fp, INT);
  write_instruction(michet->fp, 0x80);
  write_padding(michet->fp);

  fwrite(text_to_print, len, 1, michet->fp);

  fflush(michet->fp);

}
