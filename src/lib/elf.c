#include <stdio.h>
#include <string.h>

#include <michet/michet.h>
#include <michet/elf.h>

int michet_write_elf_header(michet_t *michet)
{
  Elf64_Ehdr elf64_header;

  michet->offset += sizeof(Elf64_Ehdr);
  
  memset(&elf64_header, 0, sizeof(Elf64_Ehdr));
  elf64_header.e_ident[EI_MAG0] = 0x7f;
  elf64_header.e_ident[EI_MAG1] = 'E';
  elf64_header.e_ident[EI_MAG2] = 'L';
  elf64_header.e_ident[EI_MAG3] = 'F';
  elf64_header.e_ident[EI_CLASS] = ELFCLASS64;
  elf64_header.e_ident[EI_DATA] = ELFDATA2LSB;
  elf64_header.e_ident[EI_VERSION] = EV_CURRENT;
  elf64_header.e_ident[EI_OSABI] = ELFOSABI_SYSV;
  elf64_header.e_ident[EI_ABIVERSION] = ELFOSABI_SYSV;
  elf64_header.e_type = ET_EXEC;
  elf64_header.e_machine = EM_386;
  elf64_header.e_version = EV_CURRENT;
  elf64_header.e_entry = 0;	/* virtual address of the program entry point */
  elf64_header.e_phoff = 0;	/* file offset in bytes of the program header table */
  elf64_header.e_shoff = 0;	/* file offset in bytes of the section header table */
  elf64_header.e_flags = 0;	/* CPU flags */
  elf64_header.e_ehsize = sizeof(Elf64_Ehdr);	/* size of the ELF Header */
  elf64_header.e_phentsize = 0;			/* size of the program header table */
  elf64_header.e_phnum = 0;			/* number of entries in the program header table */
  elf64_header.e_shentsize = 0;			/* size of the section header table */
  elf64_header.e_shnum = 0;			/* number of entries in the section header table */
  elf64_header.e_shstrndx = SHN_UNDEF;			/* section name string table offset */

  if ((fwrite(&elf64_header, sizeof(Elf64_Ehdr), 1, michet->fp)) != sizeof(Elf64_Ehdr)) {
    return -1;
  }
  
  return 0;
}

int michet_write_elf_program_header_table(michet_t *michet)
{

  return 0;
}

int michet_write_elf_segment(michet_t *michet)
{

  return 0;
}
