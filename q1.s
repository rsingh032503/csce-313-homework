.section .text
.globl openr
# file path will be in the %rdi register when openr is called since it is the first argument
openr:
    movq $2, %rax          # system call number for open
    movq $0, %rsi          # set the flags to O_RDONLY
    syscall                # perform the system call with the values in the %rdi and %rsi registers (file path and O_RDONLY flag)
    ret                    # return from function
    