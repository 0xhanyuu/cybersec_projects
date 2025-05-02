# xorcrypt

A rudimentary tool for encrypting / decrypting files through a simple bitwise `xor` function written entirely in C++.

`Usage: ./xorcrypt <-e>/<-d> <file.txt/file.xc>/<file.xc/file.txt> <key>`

The program reads the input file character by character, producing an output file whereby each character that is read is piped into a bitwise `xor` function and written to the output file.

This is not a secure way to encrypt files and has been produced to demonstrate C++ fundamentals.
