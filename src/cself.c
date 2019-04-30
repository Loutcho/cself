#include <stdio.h>
#include <strings.h>

char buffer[10000];
char tmp[1000];

#define EXEC_STORE(X, Y) { X; strcat(buffer, "EXEC_STORE(\n"); strcat(buffer, Y); strcat(buffer, ",\n"); quote(Y, tmp); strcat(buffer, tmp); strcat(buffer, "\n)\n"); }
#define PRINTSTORED { printf(buffer); printf("PRINTSTORED\n"); memset(buffer, 0x0, 10000); }
#define PRINT_EXEC(X, Y) { printf("PRINT_EXEC(\n"); quote(X, tmp); printf(tmp); printf(",\n"); printf(X); printf("\n)\n"); Y; }

static void quote(char *in, char *out)
{
int i, j;
i = 0;
j = 0;
out[j ++] = '"';
while (i < strlen(in))
{
switch(in[i])
{
case '"':
case '\\':
out[j ++] = '\\';
default:
out[j ++] = in[i ++];
}
}
out[j ++] = '"';
out[j ++] = '\0';
}

void main()
{
memset(buffer, 0x0, 10000);
EXEC_STORE(
printf("#include <stdio.h>\n"),
"printf(\"#include <stdio.h>\\n\")"
)
EXEC_STORE(
printf("#include <strings.h>\n"),
"printf(\"#include <strings.h>\\n\")"
)
EXEC_STORE(
printf("\n"),
"printf(\"\\n\")"
)
EXEC_STORE(
printf("char buffer[10000];\n"),
"printf(\"char buffer[10000];\\n\")"
)
EXEC_STORE(
printf("char tmp[1000];\n"),
"printf(\"char tmp[1000];\\n\")"
)
EXEC_STORE(
printf("\n"),
"printf(\"\\n\")"
)
EXEC_STORE(
printf("#define EXEC_STORE(X, Y) { X; strcat(buffer, \"EXEC_STORE(\\n\"); strcat(buffer, Y); strcat(buffer, \",\\n\"); quote(Y, tmp); strcat(buffer, tmp); strcat(buffer, \"\\n)\\n\"); }\n"),
"printf(\"#define EXEC_STORE(X, Y) { X; strcat(buffer, \\\"EXEC_STORE(\\\\n\\\"); strcat(buffer, Y); strcat(buffer, \\\",\\\\n\\\"); quote(Y, tmp); strcat(buffer, tmp); strcat(buffer, \\\"\\\\n)\\\\n\\\"); }\\n\")"
)
EXEC_STORE(
printf("#define PRINTSTORED { printf(buffer); printf(\"PRINTSTORED\\n\"); memset(buffer, 0x0, 10000); }\n"),
"printf(\"#define PRINTSTORED { printf(buffer); printf(\\\"PRINTSTORED\\\\n\\\"); memset(buffer, 0x0, 10000); }\\n\")"
)
EXEC_STORE(
printf("#define PRINT_EXEC(X, Y) { printf(\"PRINT_EXEC(\\n\"); quote(X, tmp); printf(tmp); printf(\",\\n\"); printf(X); printf(\"\\n)\\n\"); Y; }\n"),
"printf(\"#define PRINT_EXEC(X, Y) { printf(\\\"PRINT_EXEC(\\\\n\\\"); quote(X, tmp); printf(tmp); printf(\\\",\\\\n\\\"); printf(X); printf(\\\"\\\\n)\\\\n\\\"); Y; }\\n\")"
)
EXEC_STORE(
printf("\n"),
"printf(\"\\n\")"
)
EXEC_STORE(
printf("static void quote(char *in, char *out)\n"),
"printf(\"static void quote(char *in, char *out)\\n\")"
)
EXEC_STORE(
printf("{\n"),
"printf(\"{\\n\")"
)
EXEC_STORE(
printf("int i, j;\n"),
"printf(\"int i, j;\\n\")"
)
EXEC_STORE(
printf("i = 0;\n"),
"printf(\"i = 0;\\n\")"
)
EXEC_STORE(
printf("j = 0;\n"),
"printf(\"j = 0;\\n\")"
)
EXEC_STORE(
printf("out[j ++] = '\"';\n"),
"printf(\"out[j ++] = '\\\"';\\n\")"
)
EXEC_STORE(
printf("while (i < strlen(in))\n"),
"printf(\"while (i < strlen(in))\\n\")"
)
EXEC_STORE(
printf("{\n"),
"printf(\"{\\n\")"
)
EXEC_STORE(
printf("switch(in[i])\n"),
"printf(\"switch(in[i])\\n\")"
)
EXEC_STORE(
printf("{\n"),
"printf(\"{\\n\")"
)
EXEC_STORE(
printf("case '\"':\n"),
"printf(\"case '\\\"':\\n\")"
)
EXEC_STORE(
printf("case '\\\\':\n"),
"printf(\"case '\\\\\\\\':\\n\")"
)
EXEC_STORE(
printf("out[j ++] = '\\\\';\n"),
"printf(\"out[j ++] = '\\\\\\\\';\\n\")"
)
EXEC_STORE(
printf("default:\n"),
"printf(\"default:\\n\")"
)
EXEC_STORE(
printf("out[j ++] = in[i ++];\n"),
"printf(\"out[j ++] = in[i ++];\\n\")"
)
EXEC_STORE(
printf("}\n"),
"printf(\"}\\n\")"
)
EXEC_STORE(
printf("}\n"),
"printf(\"}\\n\")"
)
EXEC_STORE(
printf("out[j ++] = '\"';\n"),
"printf(\"out[j ++] = '\\\"';\\n\")"
)
EXEC_STORE(
printf("out[j ++] = '\\0';\n"),
"printf(\"out[j ++] = '\\\\0';\\n\")"
)
EXEC_STORE(
printf("}\n"),
"printf(\"}\\n\")"
)
EXEC_STORE(
printf("\n"),
"printf(\"\\n\")"
)
EXEC_STORE(
printf("void main()\n"),
"printf(\"void main()\\n\")"
)
EXEC_STORE(
printf("{\n"),
"printf(\"{\\n\")"
)
EXEC_STORE(
printf("memset(buffer, 0x0, 10000);\n"),
"printf(\"memset(buffer, 0x0, 10000);\\n\")"
)
PRINTSTORED
PRINT_EXEC(
"printf(\"}\\n\")",
printf("}\n")
)
}
