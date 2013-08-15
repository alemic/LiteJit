#include "internal.h"

static int _ljit_resize_tmp_table(ljit_function *fun)
{
    return 0;
}

ljit_value _ljit_new_temporary(ljit_function *fun, ljit_types type)
{
    ljit_value val = NULL;

    if ((val = ljit_new_value(type)) == NULL)
        return NULL;

    if (fun->uniq_index == fun->tmp_table_size)
    {
        if (_ljit_resize_tmp_table(fun))
        {
            free(val);
            return NULL;
        }
    }

    val->is_tmp = 1;
    val->index = fun->uniq_index++;
    fun->temporary_table[val->index] = val;

    return val;
}

void _ljit_free_temporary(ljit_function *fun, ljit_value tmp)
{
    if (!tmp && tmp->index >= fun->tmp_table_size
        && fun->temporary_table[tmp->index] != tmp)
        return;

    fun->temporary_table[tmp->index] = NULL;

    free(tmp->data);
    free(tmp);
}

void _ljit_free_bytecode(ljit_function *fun, ljit_bytecode *instr)
{
    if (!instr)
        return;

    ljit_free_value(fun, instr->op1);
    ljit_free_value(fun, instr->op2);
    ljit_free_value(fun, instr->ret_val);

    free(instr);
}
