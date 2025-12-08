#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Kyles C Compiler
// GNU Linux and Windows Compatible C Compiler

// Main Header
include "kycc.h"

// Compiler file resolutions
static char* input_file;
static char* output_file;
static char* asm_dr_file;

// Dump / Linker Settings/
static bool dump_ast_tree;
static bool cpp_only;
static bool dump_asm;
static bool dont_linkf;

// Native Definitions for cpp ext
static Buffer* cpp_definitions;
static Vector* tmp_files = &EMPTY_VECTOR;

// KYCC Has direct ASM and CPP compatibility and draws from
// GNU examples like GCC and the B Language compiler

static void cmd_usage_opts(int exit_code) {
	 fprintf(exit_code ? stderr : stdout,
		"Usage: Kyle's C Compiler [ -e ] [ -a ] [ -h ] <file>\n\n"
		"\n"
		"  1: -i <path>		add include file path\n"
		"  2: -e 		print source code (pre)\n"
		"  3: -d <name>		define name as macro before compilation\n"
		"  4: -s		Stop before assembly (default)\n"
		"  5: -c		Omit Linker (default)\n"
		"  6: -u <name>		undefine name as macro\n"
		"  7: -kdumper-tree	prints the AST\n"
		"  8: -kdumper-stack	prints the stacktrace\n"
		"  9: -o <filename>	output to specified filename\n"
		"  10: -m32, -m64	outputs 32bit or 64bit(default) code\n"
		"  11: -dw		disables all warnings\n"
		"  12: -h		prints this help screen\n"
		"\n"
		" [-e], [-a], [-c] or [-s] must be specified.\n\n");	
	exit(exit_code);
}

static void delete_tmp_files();
static char* base(char *path);
static char* replace_suffix(char* file_name, char suffix);


int main(int argc, char* argv[]) {

}

