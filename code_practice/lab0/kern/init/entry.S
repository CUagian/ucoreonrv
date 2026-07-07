#include <mmu.h>
#include <memlayout.h>

    .section .text.kern_entry,"ax",%progbits
    .globl kern_entry
kern_entry:
    br      $gp, 1f
1:  ldgp    $gp, 0($gp)
    br      $1, 2f
    .quad   bootstacktop

2:  ldl     $sp, 0($1)
    br      kern_init

.section .data
    .align PGSHIFT
    .global bootstack
bootstack:
    .space KSTACKSIZE
    .global bootstacktop
bootstacktop:
