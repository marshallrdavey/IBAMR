include $(top_srcdir)/config/Make-rules

EXTRA_PROGRAMS = explicit_ex0 explicit_ex1

explicit_ex0_CXXFLAGS = $(AM_CXXFLAGS) -DNDIM=2
explicit_ex0_LDADD = $(IBAMR_LDFLAGS) $(IBAMR2d_LIBS) $(IBAMR_LIBS)
explicit_ex0_SOURCES = explicit_ex0.cpp

explicit_ex1_CXXFLAGS = $(AM_CXXFLAGS) -DNDIM=2 -DSOURCE_DIR=\"$(abs_srcdir)\"
explicit_ex1_LDADD = $(IBAMR_LDFLAGS) $(IBAMR2d_LIBS) $(IBAMR_LIBS)
explicit_ex1_SOURCES = explicit_ex1.cpp

tests: $(EXTRA_PROGRAMS)
	if test "$(top_srcdir)" != "$(top_builddir)" ; then \
	  ln -f -s $(srcdir)/*input $(PWD) ; \
	  ln -f -s $(srcdir)/*output $(PWD) ; \
	fi ;
.PHONY: tests
