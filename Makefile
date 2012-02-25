##
## Toplevel Makefile for all Makefiles
##

##
## Scott Powers
##

all: dev_$(DEV_ARCH)

list: dev_
help: dev_
dev_::
	@echo "You must specify one of the following or set the environment variable"
	@echo "[DEV_ARCH] to one of the following:"
	@echo "  linux -- x86 running Linux 1.2.13 DYNAMIC"
	@echo "  linux-static -- x86 running Linux 1.2.13 ALL STATIC"
	@echo "  linux-static-motif -- x86 running Linux 1.2.13 STATIC MOTIF"
	@echo " "
	@echo "To make a Purify or Quantify version of Mosaic, put a 'p_' or"
	@echo "  'q_' in front of the platform."
	@echo "If your OS is not listed, you will need to copy one of the"
	@echo "  the Makefiles.OS in the 'makefiles' directory, edit it for"
	@echo "  your system, edit this Makefile to add your system, compile,"
	@echo "  and send in your changes to: mosaic-x@ncsa.uiuc.edu."

purifyd:
	$(MAKE) p_$(DEV_ARCH)

quantifyd:
	$(MAKE) q_$(DEV_ARCH)

rm_and_touch:
	@rm -f config.h
	@touch config.h

dev_linux: rm_and_touch linux
linux: rm_and_touch
	$(MAKE) -f makefiles/Makefile.linux DEV_ARCH=linux
p_linux: rm_and_touch
	$(MAKE) -f makefiles/Makefile.linux purifyd DEV_ARCH=linux
q_linux: rm_and_touch
	$(MAKE) -f makefiles/Makefile.linux quantifyd DEV_ARCH=linux

dev_linux_static: rm_and_touch linux_static
linux_static: rm_and_touch
	$(MAKE) -f makefiles/Makefile.linux staticd DEV_ARCH=linux
p_linux_static: rm_and_touch
	$(MAKE) -f makefiles/Makefile.linux p_staticd DEV_ARCH=linux
q_linux_static: rm_and_touch
	$(MAKE) -f makefiles/Makefile.linux q_staticd DEV_ARCH=linux

dev_linux_static_motif: rm_and_touch linux_static_motif
linux_static_motif: rm_and_touch
	$(MAKE) -f makefiles/Makefile.linux static_motifd DEV_ARCH=linux
p_linux_static_motif: rm_and_touch
	$(MAKE) -f makefiles/Makefile.linux p_static_motifd DEV_ARCH=linux
q_linux_static_motif: rm_and_touch
	$(MAKE) -f makefiles/Makefile.linux q_static_motifd DEV_ARCH=linux

clean:
	cd libXmx; $(MAKE) clean
	cd libhtmlw; $(MAKE) clean
	cd libnut; $(MAKE) clean
	cd libwww2; $(MAKE) clean
	cd src; $(MAKE) clean MOSAIC="Mosaic"
	@echo "Done cleaning..."
