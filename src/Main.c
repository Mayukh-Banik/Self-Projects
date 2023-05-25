#include "npArrayDef.h"
#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
    if (argc != 1 || argv[1] != NULL)
    {
        return -1;
    }
    
    return 0;
}

static PyObject* spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return PyLong_FromLong(sts);
}