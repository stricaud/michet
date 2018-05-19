#ifndef _MICHET_ELF_H_
#define _MICHET_ELF_H_

#include <inttypes.h>

#include <michet/michet.h>

typedef uint64_t Elf64_Addr;
typedef uint16_t Elf64_Half;
typedef uint64_t Elf64_Off;
typedef int32_t  Elf64_Sword;
typedef uint32_t Elf64_Word;

#define EI_MAG0 0
#define EI_MAG1 1
#define EI_MAG2 2
#define EI_MAG3 3
#define EI_CLASS 4
#define EI_DATA 5
#define EI_VERSION 6
#define EI_OSABI 7
#define EI_ABIVERSION 8
#define EI_PAD 9
#define EI_NIDENT 16

#define ELFCLASS32 1
#define ELFCLASS64 2

#define ELFDATA2LSB 1		/* Little Endian */
#define ELFDATA2MSB 2

#define EV_NONE    0 // Invalid version
#define EV_CURRENT 1 // Current version

#define ELFOSABI_SYSV 0
#define ELFOSABI_HPUX 1
#define ELFOSABI_STANDALONE 255

#define ET_NONE   0 // No file type
#define ET_REL    1 // Relocatable file
#define ET_EXEC   2 // Executable file
#define ET_DYN    3 // Shared object file
#define ET_CORE   4 // Core file
#define ET_LOPROC 0xff00 // Processor specific
#define ET_HIPROC 0xffff // Processor specific

#define EM_NONE  0 // No machine
#define EM_M32   1 // AT&T WE 32100
#define EM_SPARC 2 // SPARC
#define EM_386   3 // Intel 80386
#define EM_68K   4 // Motorola 68000
#define EM_88K   5 // Motorola 88000
#define EM_860   6 // Intel 80860
#define EM_MIPS  8 // MIPS RS3000
#define EM_AMD64 62

/* special section indices */
#define SHN_UNDEF 0
#define SHN_LOPROC 0xFF00 // Processor-specific use
#define SHN_HIPROC 0xFF1F
#define SHN_LOOS 0xFF20 // Environment-specific use
#define SHN_HIOS 0xFF3F
#define SHN_ABS 0xFFF1 // Indicates that the corresponding reference is an absolute value
#define SHN_COMMON 0xFFF2 // Indicates a symbol that has been declared as a common block (Fortran COMMON or C tentative declaration)

#define SHT_NULL 0 // Marks an unused section header
#define SHT_PROGBITS 1 // Contains information defined by the program
#define SHT_SYMTAB 2 // Contains a linker symbol table
#define SHT_STRTAB 3 // Contains a string table
#define SHT_RELA 4 // Contains “Rela” type relocation entries
#define SHT_HASH 5 // Contains a symbol hash table
#define SHT_DYNAMIC 6 // Contains dynamic linking tables
#define SHT_NOTE 7 // Contains note information
#define SHT_NOBITS 8 // Contains uninitialized space; does not occupy any space in the file
#define SHT_REL 9 // Contains “Rel” type relocation entries
#define SHT_SHLIB 10 // Reserved
#define SHT_DYNSYM 11 // Contains a dynamic loader symbol table
#define SHT_LOOS 0x60000000 // Environment-specific use
#define SHT_HIOS 0x6FFFFFFF
#define SHT_LOPROC 0x70000000 // Processor-specific use
#define SHT_HIPROC 0x7FFFFFFF


#define SHF_WRITE 0x1 // Section contains writable data
#define SHF_ALLOC 0x2 // Section is allocated in memory image of program
#define SHF_EXECINSTR 0x4 // Section contains executable instructions
#define SHF_MASKOS 0x0F000000 // Environment-specific use
#define SHF_MASKPROC 0xF0000000 // Processor-specific use


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

int michet_write_elf_header(michet_t *michet);

#endif	/* _MICHET_ELF_H_ */
