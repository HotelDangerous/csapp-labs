# Assembly Inspection: `check_sign_int()`

Built with: `gcc -Og -S ./src/mask/01_check_sign.c`. Function code was manually pulled from resulting assembly file and cleaned of compiler / linker directives.
> Compiled with `-Og` optimization to preserve readability of the generated assembly code.

---
## Function Snippet
**Assembly Code:**
```asm
check_sign_int:
    sarl $31, %edi
    leal 1(%rdi), %eax
    ret
```

**C Reference:**
```c
int check_sign_int(int x) { 
    return ~(x >> 31) & 0x01;
}
```


### Notes
**`sarl $31, %edi`: Arithmetic right-shift by 31 bits**:
The result of this operation is 4 bytes where the bits are either all 1s (`0xFFFFFFFF`) or all 0s (`0x00000000`). In other words, this operation yields the integer value `-1` or `0`.

**`leal 1(%rdi), %eax`: Clever compiler trick**:
Our C code isolates the least significant bit (LSB) by performing a bitwise and with the hexadecimal value `0x01`. The instruction `leal 1(%rdi), %eax` achieves the same result by computing (%edi + 1) where there are two cases:
- 1. `%edi` contains the value `0x00000000`: Yielding `0x00000001`;
- 2. `%edi` contains the value `0x11111111`: Yielding `0x00000000` by wraparound.
in either case the result is zero-extended to fit the 64-bit wide register `%rax`.

**ret**: The value stored in `%rax` is returned. The register `%rax` is always used to return integer numbers.

