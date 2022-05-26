# cself
This little and ugly C program is the result of question/challenge between colleagues.
We asked ourselves: is it possible to write a C program that outputs its own source code?
(of course, no access to the source code, fopen, fread, fprintf, ... is allowed).
YES. It is possible. Thanks to the preprocessor.

Try to write your own... Since the program has at least to contain:

int main(int argc, char *argv[])

... you'll have to execute somewhere

printf("int main(int argc, char *argv[])\n");

but if you do so carelessly, you may need to execute somewhere further

printf("printf(\"int main(int argc, char *argv[])\n\");");

... and so one. Will you find a way to break the spiral?
