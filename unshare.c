#include <Python.h>
#include <sched.h>

static PyObject *_unshare(PyObject *self, PyObject *args) {
    int clone_flags;

    if (!PyArg_ParseTuple(args, "i", &clone_flags))
        return NULL;

    if (unshare(clone_flags) == -1) {
        PyErr_SetFromErrno(PyExc_RuntimeError);
        return NULL;
    } else {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyMethodDef unshare_methods[] = {
    {"unshare", _unshare, METH_VARARGS,
    "Use as: unshare(flag)\n"
    "possible flags: CLONE_NEWNS, CLONE_NEWUTS, CLONE_NEWPID, "
    "CLONE_NEWUSER, CLONE_NEWIPC, CLONE_NEWNET, CLONE_THREAD\n"
    "See man 2 unshare.\n"
    },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef unshare_module = {
    PyModuleDef_HEAD_INIT,
    "unshare",
    "Python extension for calling C's unshare function",
    -1,
    unshare_methods
};

PyMODINIT_FUNC PyInit_unshare(void) {
    PyObject *module = PyModule_Create(&unshare_module);

    // clone constants
    PyModule_AddIntConstant(module, "CLONE_NEWNS", CLONE_NEWNS);     // mount namespace
    PyModule_AddIntConstant(module, "CLONE_NEWUTS", CLONE_NEWUTS);   // UTS (hostname) namespace
    PyModule_AddIntConstant(module, "CLONE_NEWPID", CLONE_NEWPID);   // PID namespace
    PyModule_AddIntConstant(module, "CLONE_NEWUSER", CLONE_NEWUSER); // users namespace
    PyModule_AddIntConstant(module, "CLONE_NEWIPC", CLONE_NEWIPC);   // IPC namespace
    PyModule_AddIntConstant(module, "CLONE_NEWNET", CLONE_NEWNET);   // network namespace
    PyModule_AddIntConstant(module, "CLONE_THREAD", CLONE_THREAD);

    return module;
}
