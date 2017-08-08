
import os

Import('env_local')

release_dir = "#release"

src_fname = [
    "bitmath.c",
    "bitreader.c",
    "bitwriter.c",
    "crc.c",
    "fixed.c",
    "float.c",
    "format.c",
    "lpc.c",
    "memory.c",
    "stream_encoder.c",
    "stream_encoder_framing.c",
    "window.c",
]

sources = [os.path.join('src', x) for x in src_fname]

objs_list = [env_local.SharedObject(x) for x in sources]

lib_org = env_local.SharedLibrary("libFLAC",  objs_list)
lib_static = env_local.StaticLibrary("libFLAC",  objs_list)

# env_local.Default(lib_org)

# Stripping binary
release_lib = env_local.Command(os.path.join(release_dir, str(lib_org[0])), str(lib_org[0]), '$STRIP --strip-unneeded -o $TARGET $SOURCE')

# Copy library to destination folder
release_static_lib = env_local.Install(release_dir, [lib_static])
env_local.Depends(release_lib, [lib_org, release_static_lib])
env_local.Default(release_lib)
# env_local.Alias('install', release_lib)

# # Create latest_build link
# tgt = Entry('#latest_build').abspath
# src = Entry(release_dir).abspath
# if os.path.islink(tgt) or os.path.exists(tgt):
#     os.remove(tgt)
# try:
# 	os.symlink(src, tgt)
# except AttributeError:
#     print "SCONS WARNING -- Skipping the linking of [%s] to [%s]. This is linkely to happen if you are currently compiling on minGW."%(src,tgt)
