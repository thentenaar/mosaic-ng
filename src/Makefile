All: $(MOSAIC)

LIBHTMLW_DIR = ../libhtmlw
LIBXMX_DIR = ../libXmx
LIBXMX_INC = ../libXmx
LIBPNG_DIR = ../libpng

PROGRAM_LIBS = $(LIBWWW_DIR)/libwww.a $(LIBHTMLW_DIR)/libhtmlw.a $(LIBXMX_DIR)/libXmx.a $(LIBNUT_DIR)/libnut.a
LIBS = $(PROGRAM_LIBS) $(X_LIBS) $(PNG_LIBS) $(JPEG_LIBS) $(KRB_LIBS) $(MATH_LIB) $(SYS_LIBS)

CFILES = main.c gui.c  gui-dialogs.c gui-menubar.c gui-documents.c gui-news.c\
  newsrc.c\
  gui-extras.c mo-www.c hotlist.c history.c\
  globalhist.c img.c\
  picread.c xpmhash.c xpmread.c gifread.c pixmaps.c\
  medcut.c hotfile.c child.c mailto.c readJPEG.c readPNG.c\
  accept.c\
  kcms.c md5.c proxy-dialogs.c proxy-misc.c gui-popup.c gui-ftp.c\
  prefs.c

OBJS = main.o gui.o gui-dialogs.o gui-menubar.o gui-documents.o gui-news.o\
  newsrc.o\
  gui-extras.o mo-www.o hotlist.o history.o\
  globalhist.o img.o\
  picread.o xpmhash.o xpmread.o gifread.o pixmaps.o\
  medcut.o hotfile.o child.o mailto.o readJPEG.o readPNG.o\
  accept.o\
  kcms.o md5.o proxy-dialogs.o proxy-misc.o gui-popup.o gui-ftp.o\
  prefs.o

globalhist.o: globalhist.c ../libhtmlw/HTML.h
	$(CC) -c $(CFLAGS) globalhist.c

$(MOSAIC): $(OBJS) $(PROGRAM_LIBS)
	$(PURIFY) $(CC) $(LDFLAGS) -o $(MOSAIC) $(OBJS) $(LIBS)

#HFILES = mosaic.h prefs.h prefs_defs.h xresources.h
#$(OBJS): $(HFILES)
#hotlist.o hotfile.o: hotlist.h
#gui.o: toolbar.h xresources.h ../libhtmlw/HTML.h bitmaps/*.xbm
#img.o: ../libhtmlw/HTML.h
#gui-documents.o: toolbar.h
#comment.o: comment.h
#kcms.o: kcms.h
#gui-popup.o: gui-popup.h
#pixmaps.o: pixmaps/*.xpm
#$(PIXMAPS)
#mo-dtm.o: ../libhtmlw/HTML.h
#prefs.o: prefs.h prefs_defs.h xresources.h

#depend:
#	makedepend -m -- $(CFLAGS) -- $(CFILES)

wipe:
	-rm -f Mosaic Mosaic-p Mosaic-q $(OBJS) core
clean:
	-rm -f Mosaic Mosaic-p Mosaic-q *.o core
tags:
	etags -t *.[ch]

# DO NOT DELETE THIS LINE -- make depend depends on it.

main.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h 
main.o: main.h gui.h child.h globalhist.h port.h kcms.h

gui.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h gui.h port.h
gui.o: gui-documents.h main.h mo-www.h gui-menubar.h proxy.h pixmaps.h
gui.o: ../libwww2/HTAAUtil.h ../libhtmlw/HTML.h xresources.h
gui.o: pixmaps/*.xpm 
gui.o: bitmaps/*.xbm

gui-dialogs.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h
gui-dialogs.o: gui-dialogs.h gui-documents.h gui.h mo-www.h
gui-dialogs.o: ../libhtmlw/HTML.h ../libnut/system.h

gui-menubar.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h
gui-menubar.o: main.h ../libhtmlw/HTML.h gui.h gui-ftp.h gui-popup.h
gui-menubar.o: hotlist.h gui-dialogs.h gui-news.h port.h
gui-menubar.o: history.h mo-www.h globalhist.h proxy.h
gui-menubar.o: ../libwww2/HTAAUtil.h

gui-documents.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h 
gui-documents.o: gui.h gui-documents.h gui-extras.h mo-www.h 
gui-documents.o: history.h ../libhtmlw/HTML.h port.h 

gui-news.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h gui.h
gui-news.o: gui-news.h ../libnut/system.h ../libhtmlw/HTML.h newsrc.h
gui-news.o: ../libwww2/HTNews.h ../libwww2/HTAccess.h ../libwww2/HTUtils.h
gui-news.o: ../libwww2/HTString.h ../libwww2/HTAnchor.h ../libwww2/HTList.h
gui-news.o: ../libwww2/HTAtom.h ../libwww2/HTFormat.h ../libwww2/HTStream.h
gui-news.o: ../src/newsrc.h

newsrc.o: mosaic.h newsrc.h ../libXmx/Xmx.h toolbar.h
newsrc.o: prefs.h prefs_defs.h

gui-extras.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h gui.h
gui-extras.o: gui-extras.h mo-www.h ../libhtmlw/HTML.h ../libnut/system.h

mo-www.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h 
mo-www.o: mo-www.h ../libwww2/HTAAUtil.h ../libwww2/HTUtils.h
mo-www.o: ../libwww2/HTString.h ../libwww2/tcp.h ../libwww2/HTTCP.h
mo-www.o: ../libwww2/HTParse.h ../libwww2/HTAccess.h ../libwww2/HTAnchor.h
mo-www.o: ../libwww2/HTList.h ../libwww2/HTAtom.h ../libwww2/HTFormat.h
mo-www.o: ../libwww2/HTStream.h ../libwww2/HTML.h ../libwww2/HTMLDTD.h
mo-www.o: ../libwww2/SGML.h ../libwww2/HText.h ../libwww2/HTInit.h
mo-www.o: gui-dialogs.h gui.h

hotlist.o: mosaic.h ../libXmx/Xmx.h toolbar.h
hotlist.o: prefs.h prefs_defs.h hotlist.h hotfile.h gui.h
hotlist.o: mo-www.h bitmaps/hotlist.xbm ../libnut/system.h

history.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h 
history.o: gui.h mo-www.h gui-popup.h ../libhtmlw/HTML.h
history.o: hotlist.h ../libwww2/HTAAUtil.h

globalhist.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h
globalhist.o: mo-www.h globalhist.h ../libhtmlw/HTML.h ../libnut/system.h

img.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h gui.h img.h
img.o: mo-www.h globalhist.h picread.h ../libhtmlw/HTML.h port.h
img.o: bitmaps/gopher_image.xbm bitmaps/gopher_movie.xbm
img.o: bitmaps/gopher_menu.xbm bitmaps/gopher_text.xbm
img.o: bitmaps/gopher_sound.xbm bitmaps/gopher_index.xbm
img.o: bitmaps/gopher_telnet.xbm bitmaps/gopher_binary.xbm
img.o: bitmaps/gopher_unknown.xbm

picread.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h 
picread.o: picread.h gifread.h xpmread.h readJPEG.h readPNG.h

xpmhash.o: xpm.h

xpmread.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h xpmread.h

gifread.o: gifread.h

pixmaps.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h 
pixmaps.o: pixmaps.h xpmread.h xpm.h
pixmaps.o: pixmaps/*.xpm

hotfile.o: mosaic.h ../libXmx/Xmx.h toolbar.h
hotfile.o: prefs.h prefs_defs.h hotlist.h mo-www.h ../libhtmlw/HTML.h

child.o: child.h list.h

mailto.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h gui.h 
mailto.o: ../libnut/url-utils.h ../libnut/system.h

readJPEG.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h readJPEG.h

readPNG.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h readPNG.h

accept.o: port.h accept.h memStuffForPipSqueeks.h

kcms.o: kcms.h

md5.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h md5.h

proxy-dialogs.o: proxy.h mosaic.h ../libXmx/Xmx.h
proxy-dialogs.o: toolbar.h prefs.h prefs_defs.h

proxy-misc.o: proxy.h

gui-popup.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h
gui-popup.o: gui-ftp.h mo-www.h gui-popup.h ../libhtmlw/HTML.h hotlist.h
gui-popup.o: gui-documents.h

gui-ftp.o: mosaic.h ../libXmx/Xmx.h toolbar.h
gui-ftp.o: prefs.h prefs_defs.h gui.h gui-ftp.h gui-popup.h
gui-ftp.o: ../libhtmlw/HTML.h hotlist.h ../libnut/system.h

prefs.o: mosaic.h ../libXmx/Xmx.h toolbar.h prefs.h prefs_defs.h
