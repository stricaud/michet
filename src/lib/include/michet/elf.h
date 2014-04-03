#ifndef _MICHET_ELF_H_
#define _MICHET_ELF_H_

#include <inttypes.h>

typedef uint64_t Elf64_Addr;
typedef uint16_t Elf64_Half;
typedef uint64_t Elf64_Off;
typedef int32_t  Elf64_Sword;
typedef uint32_t Elf64_Word;

#define EI_NIDENT 16

typedef struct {
  unsigned char e_ident[EI_NIDENT];
  Elf64_Half    e_type;
  Elf64_Half    e_machine;
  Elf64_Word    e_version;
  Elf64_Addr    e_entry;
  Elf64_Off     e_phoff;
  Elf64_Off     e_shoff;
  Elf64_Word    e_flags;
  Elf64_Half    e_ehsize;
  Elf64_Half    e_phentsize;
  Elf64_Half    e_phnum;
  Elf64_Half    e_shentsize;
  Elf64_Half    e_shnum;
  Elf64_Half    e_shstrndx;
} Elf64_Ehdr;

typedef enum {
  ET_NONE   = 0, // No file type
  ET_REL    = 1, // Relocatable file
  ET_EXEC   = 2, // Executable file
  ET_DYN    = 3, // Shared object file
  ET_CORE   = 4, // Core file
  ET_LOPROC = 0xff00, // Processor specific
  ET_HIPROC = 0xffff, // Processor specific
} Elf_Type;

typedef enum {
  EM_NONE  = 0, // No machine
  EM_M32   = 1, // AT&T WE 32100
  EM_SPARC = 2, // SPARC
  EM_386   = 3, // Intel 80386
  EM_68K   = 4, // Motorola 68000
  EM_88K   = 5, // Motorola 88000
  EM_860   = 6, // Intel 80860
  EM_MIPS  = 8, // MIPS RS3000
} Elf_Machine;

typedef enum {
  EV_NONE    = 0, // Invalid version
  EV_CURRENT = 1, // Current version
} Elf_Version;

const char Elf_Magic[4] = { 0x7f, 'E', 'L', 'F' };

#endif	/* _MICHET_ELF_H_ */
