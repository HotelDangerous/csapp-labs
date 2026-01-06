# Assembly Inspection: `is_even()`

Built with: `gcc -Og -S 02_is_even.c`. Function code was manually pulled from resulting assembly file and cleaned of compiler / linker directives.
> Compiled with `-Og` optimization to preserve readability of the generated assembly code.

---
## Function Snippet
**Assembly Code:**
```asm
is_even:
	movl	%edi, %eax
	notl	%eax
	andl	$1, %eax
	ret
```

**C Reference:**
```c
char is_even(int x) { return (char)(~x & 0x01); }
```

---
### Notes
**`movl %edi, %eax` Move 32-bit argument:**

This operation moves the 32-bit `int` argument into the lower 32-bits of register `%rax` labeled `eax` for Intel's x86-64 CPU's.

**`notl %eax` Complement:**
Computes the bitwise complement of the value stored in register `%eax`. Each one in the bit string is converted to a zero and vice-of-versa.

**`andl $1, %eax` Logical AND:**
Computes the bitwise logical *AND* between the value stored in register `%eax` and the immediate value `1`. The immediate (*constant*) `1` is encoded as a bit string having least significant bit (LSB) equal to one and all other bits set to zero. In the case of an integer, this is `0x00000001`. The result is either `0x00000000` when the LSB of the argument is 0, or `0x00000001` when the LSB of the argument is 1.

**`ret` Return**
The assembly operates on 32-bit registers; the C cast to `char` affects interpretation, not the bit pattern of the returned value. Information, such as data type, requires two things: bits and context. When we perform a cast in our C code, we change the context, not the bit information. The change in context is what makes the returned value a `char`.

### Reasoning

Parity is determined by the least significant bit:
- If `x` is even, then `x & 1 = 0` → `~x` has LSB = 1 → `(~x) & 1 = 1`
- If `x` is odd,  then `x & 1 = 1` → `~x` has LSB = 0 → `(~x) & 1 = 0`

