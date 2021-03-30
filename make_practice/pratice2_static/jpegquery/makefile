DIRS = jpegquery_info app/jpegquery_test/

all:
	for i in $(DIRS) ; do make -C $$i || exit $? ; done

clean:
	for i in $(DIRS) ; do make -C $$i clean; done

install:
	for i in $(DIRS) ; do make -C $$i install; done
