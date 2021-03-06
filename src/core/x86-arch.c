#include <ljit/ljit.h>
#include "internal.h"

void ljit_setup_platform(ljit_instance *instance)
{
    if (instance)
    {
        instance->target_arch = LJIT_ARCH_X86;
        instance->usable_regs = LJIT_USABLE_REGS;
    }
}

int ljit_compile_instr(ljit_codegen *cg, ljit_bytecode *instr)
{
    unsigned char *code = cg->current;

    switch (instr->type)
    {
        #include "x86-code.inc"
    }

    cg->current = code;

    return 0;
}

void ljit_gen_prolog(ljit_codegen *cg)
{
    unsigned char *code = cg->current;

    // push %ebp
    ljit_x86_push_reg(code, X86_EBP);

    // mov %esp, %ebp
    ljit_x86_mov_reg_reg(code, X86_EBP, X86_ESP);

    cg->current = code;
}
