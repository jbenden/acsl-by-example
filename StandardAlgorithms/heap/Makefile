

# add special targets to enable testing with pop_heap

clean:: FORCE
	(cd pop_heap; $(MAKE) clean)
	$(RM) libheap.a


test::
	(cd pop_heap; $(MAKE) obj)
	(cd pop_heap; $(MAKE) test)

include ../Makefile.call

OBJ :=  push_heap/push_heap.o\
 	make_heap/make_heap.o\
	sort_heap/sort_heap.o\
	is_heap/is_heap.o

lib: libheap.a

libheap.a: obj FORCE
	@ar cr  $@ $(OBJ)
	@ranlib  $@

