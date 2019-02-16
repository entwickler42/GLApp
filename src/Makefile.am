bin_PROGRAMS = glapp
glapp_SOURCES = glapp.cpp myglgame.cpp tutorial_i.cpp tutorial.cpp tutorial_ii.cpp GLTexture.cpp glcamera.cpp

# set the include path found by configure
INCLUDES= $(all_includes)

# the library search path.
glapp_LDFLAGS = $(all_libraries) $(LIBSDL_RPATH)
glapp_CXXFLAGS = $(LIBSDL_CFLAGS)
glapp_LDADD = $(LIBSDL_LIBS)
noinst_HEADERS = myglgame.h tutorial_i.h tutorial.h tutorial_ii.h GLTexture.h glcamera.h
