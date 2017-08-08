import os

# Local x86_64 build environment
gcc_path = ''
pre_fix = ''
env_options_local = {
    "CC"    : gcc_path + pre_fix + "gcc",
    "CXX"   : gcc_path + pre_fix + "g++",
    "LD"    : gcc_path + pre_fix + "g++",
    "AR"    : gcc_path + pre_fix + "ar",
    "STRIP" : gcc_path + pre_fix + "strip",
}

env_local = Environment(**env_options_local)

env_local.Append(CPPDEFINES = {"PACKAGE_VERSION":'\\"1.3.2\\"',
                               "VERSION":'\\"1.3.2\\"',
                               "_FILE_OFFSET_BITS": 64,
                               "DWORDS_BIGENDIAN": 0,
                               "DCPU_IS_LITTLE_ENDIAN": 1,
                               "FLAC__HAS_OGG": 0,
                               "FLaC__INLINE": "__inline__",
                               "FLAC__INTEGER_ONLY_LIBRARY": 1,
                              })

env_local.Append(CPPDEFINES = ["HAVE_STDINT_H",
                               "HAVE_INTTYPES_H",
                            #    "HAVE_CXX_VARARRAYS",
                               "_LARGEFILE_SOURCE",
                               "HAVE_SOCKLEN_T",
                               "NDEBUG",
                            #    "HAVE_LROUND",
                            #    "HAVE_FSEEKO",
                            #    "HAVE_LANGINFO_CODESET",
                               "FLAC__ALIGN_MALLOC_DATA",
                              ],
                CCFLAGS=["-O3",
                         "-fPIC",
                         "-fomit-frame-pointer",
                         "-funroll-loops",
                         "-finline-functions",
                         "-Wall",
                         "-Wextra",
                         "-Wmissing-prototypes",
                         "-Wstrict-prototypes",
                        ])

path = os.environ['PATH']
env_local.Append( CPPPATH=['/usr/include/', str(os.path.join(os.getcwd(), 'include'))],
                  ENV = {'PATH' : path},
                #   LIBS=['m'],
                  LIBPATH=['/usr/lib/x86_64-linux-gnu/'] )


Export(['env_local'])
env_local.SConscript("SConscript", variant_dir='build/objs', duplicate=0)
