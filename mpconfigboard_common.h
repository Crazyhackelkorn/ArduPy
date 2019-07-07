
#define MICROPY_PY_BUILTINS_HELP                    (1)
#define MICROPY_PY_BUILTINS_HELP_TEXT               grove_help_text



#define MICROPY_WARNINGS                    (1)
//will eat 4k space
#define MICROPY_FLOAT_IMPL                  (MICROPY_FLOAT_IMPL_FLOAT)
//#define MICROPY_FLOAT_IMPL                  (MICROPY_FLOAT_IMPL_NONE)
#define MICROPY_CPYTHON_COMPAT              (ARDUPY_FULL_BUILD)
#define MICROPY_STREAMS_NON_BLOCK           (1)
#define MICROPY_MODULE_WEAK_LINKS           (ARDUPY_FULL_BUILD)
#define MICROPY_ENABLE_FINALISER            (1)
#define MICROPY_STACK_CHECK                 (0)
#define MICROPY_KBD_EXCEPTION               (1)
#define MICROPY_ENABLE_COMPILER     (1)
#define MICROPY_MODULE_FROZEN_STR           (0)
#define MICROPY_QSTR_EXTRA_POOL             mp_qstr_frozen_const_pool
#define MICROPY_CAN_OVERRIDE_BUILTINS       (1)



//control over Python builtins
#define MICROPY_PY_FUNCTION_ATTRS           (1)
#define MICROPY_PY_DESCRIPTORS              (1)
#define MICROPY_PY_BUILTINS_STR_UNICODE     (1)
#define MICROPY_PY_BUILTINS_STR_CENTER      (ARDUPY_FULL_BUILD)
#define MICROPY_PY_BUILTINS_STR_PARTITION   (ARDUPY_FULL_BUILD)
#define MICROPY_PY_BUILTINS_STR_SPLITLINES  (ARDUPY_FULL_BUILD)
#define MICROPY_PY_BUILTINS_BYTEARRAY       (1)
#define MICROPY_PY_BUILTINS_MEMORYVIEW      (1)
#define MICROPY_PY_BUILTINS_SET             (1)
#define MICROPY_PY_BUILTINS_SLICE           (1)
#define MICROPY_PY_BUILTINS_SLICE_ATTRS     (1)
#define MICROPY_PY_BUILTINS_FROZENSET       (ARDUPY_FULL_BUILD)
#define MICROPY_PY_BUILTINS_PROPERTY        (1)
#define MICROPY_PY_BUILTINS_RANGE_ATTRS     (1)
#define MICROPY_PY_BUILTINS_ROUND_INT       (1)
#define MICROPY_PY_BUILTINS_TIMEOUTERROR    (1)
#define MICROPY_PY_ALL_SPECIAL_METHODS      (ARDUPY_FULL_BUILD)
#define MICROPY_PY_BUILTINS_COMPILE         (1)
#define MICROPY_PY_BUILTINS_ENUMERATE       (1)
#define MICROPY_PY_BUILTINS_FILTER          (1)
#define MICROPY_PY_BUILTINS_REVERSED        (1)
#define MICROPY_PY_BUILTINS_INPUT           (1)
#define MICROPY_PY_BUILTINS_MIN_MAX         (1)
#define MICROPY_PY_BUILTINS_HELP            (1)
#define MICROPY_PY_BUILTINS_HELP_MODULES    (1)
#define MICROPY_PY___FILE__                 (1)
#define MICROPY_PY_MICROPYTHON_MEM_INFO     (0)
#define MICROPY_PY_ARRAY                    (1)
#define MICROPY_PY_ARRAY_SLICE_ASSIGN       (1)
#define MICROPY_PY_ATTRTUPLE                (1)
#define MICROPY_PY_COLLECTIONS              (1)
#define MICROPY_PY_MATH                     (0)
#define MICROPY_PY_MATH_SPECIAL_FUNCTIONS   (0)
#define MICROPY_PY_CMATH                    (0)
#define MICROPY_PY_GC                       (1)
#define MICROPY_PY_IO_FILEIO                (1)
#define MICROPY_PY_STRUCT                   (0)
#define MICROPY_PY_SYS                      (1)
#define MICROPY_PY_SYS_MAXSIZE              (1)
#define MICROPY_PY_SYS_STDFILES             (1)
#define MICROPY_PY_UERRNO                   (ARDUPY_FULL_BUILD)
#define MICROPY_PY_UERRNO_ERRORCODE         (!ARDUPY_FULL_BUILD)
#define MICROPY_PY_USELECT                  (1)
#define MICROPY_PY_UTIME_MP_HAL             (1)
#define MICROPY_PY_THREAD                   (0)
#define MICROPY_PY_THREAD_GIL               (0)
#define MICROPY_PY_THREAD_GIL_VM_DIVISOR    (32)
#define MICROPY_PERSISTENT_CODE_LOAD        (1)

#define MICROPY_MODULE_FROZEN_MPY   (1)
#define MICROPY_QSTR_BYTES_IN_HASH  (1)
#define MICROPY_ALLOC_PATH_MAX      (256)
#define MICROPY_EMIT_X64            (0)
#define MICROPY_COMP_MODULE_CONST   (1)
#define MICROPY_COMP_CONST          (1)
#define MICROPY_COMP_DOUBLE_TUPLE_ASSIGN (1)
#define MICROPY_COMP_TRIPLE_TUPLE_ASSIGN (0)
#define MICROPY_MEM_STATS           (0)
#define MICROPY_DEBUG_PRINTERS      (0)
#define MICROPY_ENABLE_GC           (1)
#define MICROPY_HELPER_REPL         (1)
#define MICROPY_REPL_EMACS_KEYS     (1)
#define MICROPY_REPL_AUTO_INDENT    (1)
#define MICROPY_ENABLE_SOURCE_LINE  (1)
#define MICROPY_ENABLE_DOC_STRING   (0)
#define MICROPY_ERROR_REPORTING  MICROPY_ERROR_REPORTING_NORMAL
// #define MICROPY_ERROR_REPORTING     (MICROPY_ERROR_REPORTING_TERSE)
#define MICROPY_BUILTIN_METHOD_CHECK_SELF_ARG (ARDUPY_FULL_BUILD)
#define MICROPY_PY_ASYNC_AWAIT (0)
#define MICROPY_LONGINT_IMPL        (MICROPY_LONGINT_IMPL_MPZ)
#define MP_SSIZE_MAX (0x7fffffff)
#define MP_STATE_PORT MP_STATE_VM
// type definitions for the specific machine

// extended modules
#define MICROPY_PY_UCTYPES          (1)
#define MICROPY_PY_UZLIB            (1)
#define MICROPY_PY_UJSON            (1)
#define MICROPY_PY_URE              (ARDUPY_FULL_BUILD)
#define MICROPY_PY_URE_SUB          (ARDUPY_FULL_BUILD)
#define MICROPY_PY_URE_MATCH_GROUPS           (ARDUPY_FULL_BUILD)
#define MICROPY_PY_URE_MATCH_SPAN_START_END   (ARDUPY_FULL_BUILD)
#define MICROPY_PY_UHEAPQ           (1)
#define MICROPY_PY_UHASHLIB         (1)
#define MICROPY_PY_UBINASCII        (1)
#define MICROPY_PY_URANDOM          (0)
#define MICROPY_PY_URANDOM_EXTRA_FUNCS (0) 


// #define MICROPY_PY_USSL                     (1)
// #define MICROPY_SSL_MBEDTLS                 (1)
// #define MICROPY_PY_USSL_FINALISER           (1)