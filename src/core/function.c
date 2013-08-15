#include <ljit/function.h>

ljit_function *ljit_new_function(ljit_instance *instance)
{
    ljit_function *new_function = NULL;

    if ((new_function = malloc(sizeof(ljit_function))) == NULL)
        return NULL;

    new_function->signature = NULL;
    new_function->instance = instance;
    new_function->tmp_table_size = 8;

    if ((new_function->temporary_table = malloc(8 * sizeof(ljit_value))) == NULL)
    {
        free(new_function);
        return NULL;
    }

    memset(new_function->temporary_table, 0, 8 * sizeof(ljit_value));
    new_function->bytecode = ljit_new_bytecode_list();
    new_function->uniq_index = 0;

    if (!new_function->bytecode)
    {
        free(new_function->temporary_table);
        free(new_function);
        return NULL;
    }

    return new_function;
}

static void ljit_free_signature(ljit_signature *sig)
{
    if (!sig)
        return;

    free(sig->params_type);
    free(sig);
}

void ljit_free_function(ljit_function *fun)
{
    if (!fun)
        return;

    for (unsigned short i = 0; i < fun->tmp_table_size; ++i)
    {
        if (fun->temporary_table[i])
        {
            free(fun->temporary_table[i]->data);
            free(fun->temporary_table[i]);
        }
    }

    free(fun->temporary_table);
    ljit_free_bytecode_list(fun->bytecode);
    ljit_free_signature(fun->signature);
    free(fun);
}

/** TODO : Check if one of the parameter as type VOID **/
int ljit_new_signature(ljit_function *fun,
                       ljit_types ret_type,
                       int param_number,
                       ljit_types *param_types)
{
    ljit_signature *sig = NULL;

    if (!fun)
        return -2;

    if ((sig = malloc(sizeof(ljit_signature))) == NULL)
        return -1;

    if (param_number)
    {
        if ((sig->params_type = malloc(sizeof(ljit_types) * param_number)) == NULL)
        {
            free(sig);
            return -1;
        }

        memcpy(sig->params_type, param_types,
               sizeof(ljit_types) * param_number);
    }
    else
        sig->params_type = NULL;

    sig->ret_type = ret_type;

    fun->signature = sig;

    return 0;
}
