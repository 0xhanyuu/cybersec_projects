# xorcrypt

A rudimentary tool for encrypting / decrypting files through a simple bitwise `xor` function written entirely in C++.

The program reads the input file character by character, producing an output file whereby each character that is read is piped into a bitwise `xor` function and written to the output file.

## Usage:

`Usage: ./xorcrypt <-e>/<-d> <file/file.xc>/<file.xc/file> <key>`

For more information, `./xorcrypt` can be ran to list details about the arguments of this program.

## Notes:

This is not a secure way to encrypt files and has been produced to demonstrate C++ fundamentals.
