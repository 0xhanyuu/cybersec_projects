# holistic-caesar-cipher

A tool for outputting all Caesar Cipher shifts of a plaintext string written in C.

## Features:

- Handles all alpha characters.

- Handles all digit characters.

- Handles all special characters.

- The default shift is set to `(shift != 48)`, therefore the program outputs all shifts up until ROT47, but can easily be changed to the other default possible 25 shifts by setting `(shift != 26)`.

## Notes:

- The C locale does not natively recognise characters `£` and `¬` as special characters / punctuation, therefore they have not been added to the 'lookup' functionality of the special characters of this program.
