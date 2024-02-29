## Overview

This program is designed to demonstrate the extraction and formatting of virtual address components, such as segment, page, and offset, from a 31-bit address. It uses bitwise operations to isolate these components from a given virtual address and then prints them in a formatted manner.

## Features

- Extracts the segment, page, and offset from a 31-bit virtual address.
- Utilizes bitwise operations for extraction:
  - **Offset**: Extracted using a bitwise AND operation with `0x00000fff`.
  - **Page**: Extracted by first ANDing with `0x00ffffff` and then shifting the result right by 12 bits.
  - **Segment**: Extracted by shifting the address right by 24 bits.
- Displays the original address and its extracted components in a formatted output.

## Code Structure

- The program begins by defining the main function, which initializes a 31-bit address and variables for the segment, page, and offset.
- It then extracts these components using bitwise operations.
- The `printFormattedResults` function is called to print the original address and its components.
- Finally, the extracted values are reset to `0`, demonstrating the concept of variable reusability and function isolation.

## Expected Output

Upon execution, the program will print the original 31-bit address and its extracted components (segment, page, and offset) in a hexadecimal format.