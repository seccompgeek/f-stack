TOPDIR=..

ifeq ($(FF_PATH),)
	FF_PATH=${TOPDIR}
endif

ifeq ($(FF_DPDK),)
	FF_DPDK=${TOPDIR}/dpdk/x86_64-native-linuxapp-gcc
endif

DPDK_PC_PATH ?= $(FF_DPDK)/lib/pkgconfig
PKGCFG := PKG_CONFIG_SYSROOT_DIR=$(SYSROOT) PKG_CONFIG_LIBDIR=$(DPDK_PC_PATH) pkg-config
LIBDPDK_LIBS := $(shell $(PKGCFG) --libs --static libdpdk)
LIBS += -L${FF_DPDK}/lib -Wl,--whole-archive $(LIBDPDK_LIBS) -Wl,--no-whole-archive

LIBS+= -L${FF_PATH}/lib -Wl,--whole-archive,-lfstack,--no-whole-archive
#LIBS+= -L${FF_DPDK}/lib -Wl,--whole-archive,-ldpdk,--no-whole-archive
LIBS+= -Wl,--no-whole-archive -lrt -lm -ldl -lcrypto -pthread -lnuma

CC ?= cc

TARGET="helloworld"
all:
	${CC} -O -gdwarf-2  -I../lib -DINET6 -o ${TARGET} main.c ${LIBS}
	${CC} -O -gdwarf-2  -I../lib -o ${TARGET}_epoll main_epoll.c ${LIBS}
	${CC} -O -gdwarf-2 	-I../lib -o fstack-pfe fstack-pfe.c ${LIBS}

.PHONY: clean
clean:
	rm -f *.o ${TARGET} ${TARGET}_epoll
