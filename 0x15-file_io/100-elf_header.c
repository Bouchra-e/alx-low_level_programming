#include <stdio.h>
#include <stdlib.h>
#include "elf_header.h"
#include "error_handler.h"

Elf64_Ehdr parse_elf_header(FILE *fp)
{
  Elf64_Ehdr elf_header;

fseek(fp, 0, SEEK_SET);

fread(&elf_header, sizeof(Elf64_Ehdr), 1, fp);

 
if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
elf_header.e_ident[EI_MAG3] != ELFMAG3)
{
handle_error("Not an ELF file");
}

if (elf_header.e_ident[EI_CLASS] != ELFCLASS64)
{
handle_error("Not a 64-bit ELF file");
}

if (elf_header.e_ident[EI_DATA] != ELFDATA2LSB)
{
handle_error("Not little-endian ELF file");
}

return elf_header;
}

#include <stdio.h>
#include <stdlib.h>
#include "elf_header.h"

void print_elf_header(Elf64_Ehdr* elf_header) {

printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++) {
printf("%02x ", elf_header->e_ident[i]);
}
printf("\n");
printf("  Class:                             %u-bit\n", elf_header->e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);
printf("  Data:                              %s\n", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
printf("  Version:                           %u\n", elf_header->e_ident[EI_VERSION]);
printf("  OS/ABI:                            %u\n", elf_header->e_ident[EI_OSABI]);
printf("  ABI Version:                       %u\n", elf_header->e_ident[EI_ABIVERSION]);
printf("  Type:                              %u\n", elf_header->e_type);
printf("  Machine:                           %u\n", elf_header->e_machine);
printf("  Version:                           %u\n", elf_header->e_version);
printf("  Entry point address:               0x%llx\n", (unsigned long long) elf_header->e_entry);
printf("  Start of program headers:          %llu (bytes into file)\n", (unsigned long long) elf_header->e_phoff);
printf("  Start of section headers:          %llu (bytes into file)\n", (unsigned long long) elf_header->e_shoff);
printf("  Flags:                             0x%x\n", elf_header->e_flags);
printf("  Size of this header:               %u (bytes)\n", elf_header->e_ehsize);
printf("  Size of program headers:           %u (bytes)\n", elf_header->e_phentsize);
printf("  Number of program headers:         %u\n", elf_header->e_phnum);
printf("  Size of section headers:           %u (bytes)\n", elf_header->e_shentsize);
printf("  Number of section headers:         %u\n", elf_header->e_shnum);
printf("  Section header string table index: %u\n", elf_header->e_shstrndx);
}
