/****************************************************************************
 * NCSA Mosaic for the X Window System                                      *
 * Software Development Group                                               *
 * National Center for Supercomputing Applications                          *
 * University of Illinois at Urbana-Champaign                               *
 * 605 E. Springfield, Champaign IL 61820                                   *
 * mosaic@ncsa.uiuc.edu                                                     *
 *                                                                          *
 * Copyright (C) 1993, Board of Trustees of the University of Illinois      *
 *                                                                          *
 * NCSA Mosaic software, both binary and source (hereafter, Software) is    *
 * copyrighted by The Board of Trustees of the University of Illinois       *
 * (UI), and ownership remains with the UI.                                 *
 *                                                                          *
 * The UI grants you (hereafter, Licensee) a license to use the Software    *
 * for academic, research and internal business purposes only, without a    *
 * fee.  Licensee may distribute the binary and source code (if released)   *
 * to third parties provided that the copyright notice and this statement   *
 * appears on all copies and that no charge is associated with such         *
 * copies.                                                                  *
 *                                                                          *
 * Licensee may make derivative works.  However, if Licensee distributes    *
 * any derivative work based on or derived from the Software, then          *
 * Licensee will (1) notify NCSA regarding its distribution of the          *
 * derivative work, and (2) clearly notify users that such derivative       *
 * work is a modified version and not the original NCSA Mosaic              *
 * distributed by the UI.                                                   *
 *                                                                          *
 * Any Licensee wishing to make commercial use of the Software should       *
 * contact the UI, c/o NCSA, to negotiate an appropriate license for such   *
 * commercial use.  Commercial use includes (1) integration of all or       *
 * part of the source code into a product for sale or license by or on      *
 * behalf of Licensee to third parties, or (2) distribution of the binary   *
 * code or source code to third parties that need it to utilize a           *
 * commercial product sold or licensed by or on behalf of Licensee.         *
 *                                                                          *
 * UI MAKES NO REPRESENTATIONS ABOUT THE SUITABILITY OF THIS SOFTWARE FOR   *
 * ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED          *
 * WARRANTY.  THE UI SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY THE    *
 * USERS OF THIS SOFTWARE.                                                  *
 *                                                                          *
 * By using or copying this Software, Licensee agrees to abide by the       *
 * copyright law and all other applicable laws of the U.S. including, but   *
 * not limited to, export control laws, and the terms of this license.      *
 * UI shall have the right to terminate this license immediately by         *
 * written notice upon Licensee's breach of, or non-compliance with, any    *
 * of its terms.  Licensee may be held legally responsible for any          *
 * copyright infringement that is caused or encouraged by Licensee's        *
 * failure to abide by the terms of this license.                           *
 *                                                                          *
 * Comments and questions are welcome and can be sent to                    *
 * mosaic-x@ncsa.uiuc.edu.                                                  *
 ****************************************************************************/


/*
 * Written By:  Scott Powers
 * Date:        April 26, 1995
 * Purpose:     Creates a comment card for Mosaic. Submittal is via form
 *		  and works in conjunction with	a "C" cgi-bin program.
 */
#include "../config.h"
#include "mosaic.h"
#include "gui.h"
#include "comment.h"


#include <pwd.h>
#include <sys/utsname.h>


#ifdef DEBUG_CC
int do_comment=1;
#else
int do_comment=0;
#endif


extern mo_window *current_win;
extern char *machine;
extern struct utsname mo_uname;


void CommentCard(mo_window *win);
int DumpHtml(char *htmlname);
char *MakeFilename();
void InitCard(char *fname);
void PutCardCount(long *num, char *fname);
long GetCardCount(char *fname);

char *comment_card_html_top= \
"<title>\n" \
"	Comment Card for Mosaic 2.6\n" \
"</title>\n" \
"\n" \
"<h1 align=center>\n" \
"	Please Help Us Help You!!\n" \
"</h1>\n" \
"\n" \
"<hr>\n" \
"\n" \
"<h2>\n" \
"	Thank you for using NCSA Mosaic! We are continually striving to\n" \
"	improve Mosaic to better meet the needs of its users. We would\n" \
"	appreciate your taking the time to answer these few questions.\n" \
"</h2>\n" \
"\n" \
"<hr>\n" \
"\n" \
"<form method=\"POST\" action=\"http://sdg.ncsa.uiuc.edu/XCGI/comment26\">\n" \
"\n" \
"	<h3>\n" \
"		<ul>\n" \
"			<li>\n" \
"				If you do not like surveys or you have already\n" \
"				completed this survey, please press this\n" \
"				button,\n" \
"				<input type=\"submit\" value=\"Just Count Me\" \n" \
"				name=\"countme\">,\n" \
"				to be counted. Pushing the above button\n" \
"				will send the following information about\n" \
"				your system to be used in our statistics\n" \
"				(completely anonymous):\n" \
"				<p>\n" \
"\n";

char *comment_card_html_bot= \
"				</p>\n" \
"			</li>\n" \
"			<br>\n" \
"			<li>\n" \
"				If you do not want to fill out this card,\n" \
"				just push the \"Close Window\" button at the\n" \
"				bottom of this window.\n" \
"			</li>\n" \
"			<br>\n" \
"			<li>\n" \
"				Otherwise, please proceed!\n" \
"			</li>\n" \
"		</ul>\n" \
"	</h3>\n" \
"\n" \
"	<hr>\n" \
"\n" \
"	<p>\n" \
"		How long have you been using Mosaic?\n" \
"		<br>\n" \
"		<select name=\"usage\">\n" \
"			<option value=\"no comment\" selected>\n" \
"				No Comment\n" \
"			<option value=\"never\">\n" \
"				Never\n" \
"			<option value=\"lt 1 mon\">\n" \
"				Less Than 1 Month\n" \
"			<option value=\"1-6 mon\">\n" \
"				1 - 6 Months\n" \
"			<option value=\"6 mon-1 yr\">\n" \
"				6 Months to a Year\n" \
"			<option value=\"1-2 yrs\">\n" \
"				1 - 2 Years\n" \
"			<option value=\"gt 2 yrs\">\n" \
"				More Than 2 Years\n" \
"		</select>\n" \
"	</p>\n" \
"\n" \
"	<p>\n" \
"		How familiar are you with the World Wide Web?\n" \
"		<br>\n" \
"		<select name=\"www\">\n" \
"			<option value=\"no comment\" selected>\n" \
"				No Comment\n" \
"			<option value=\"no experience\">\n" \
"				No Experience\n" \
"			<option value=\"novice\">\n" \
"				Novice\n" \
"			<option value=\"intermediate\">\n" \
"				Intermediate\n" \
"			<option value=\"expert\">\n" \
"				Expert\n" \
"			<option value=\"master\">\n" \
"				Web Master\n" \
"		</select>\n" \
"	</p>\n" \
"\n" \
"	<p>\n" \
"		On which other platform(s) do you use Mosaic?\n" \
"		<br>\n" \
"		<select name=\"platform\">\n" \
"			<option value=\"no comment\" selected>\n" \
"				No Comment\n" \
"			<option value=\"no other\">\n" \
"				No Other\n" \
"			<option value=\"mac\">\n" \
"				Macintosh\n" \
"			<option value=\"windows\">\n" \
"				Windows\n" \
"			<option value=\"mac and windows\">\n" \
"				Macintosh and Windows\n" \
"		</select>\n" \
"	</p>\n" \
"\n" \
"	<p>\n" \
"		What type of internet connection do you have?\n" \
"		<br>\n" \
"		<select name=\"connection\">\n" \
"			<option value=\"no comment\" selected>\n" \
"				No Comment\n" \
"			<option value=\"no connection\">\n" \
"				No Connection\n" \
"			<option value=\"don't know\">\n" \
"				Don't Know\n" \
"			<option value=\"modem lt 9600\">\n" \
"				Modem Less Than 9600\n" \
"			<option value=\"modem eq 9600\">\n" \
"				Modem at 9600\n" \
"			<option value=\"modem eq 144\">\n" \
"				Modem at 14.4k\n" \
"			<option value=\"modem eq 288\">\n" \
"				Modem at 28.8k\n" \
"			<option value=\"modem gt 288\">\n" \
"				Modem Greater Than 28.8k\n" \
"			<option value=\"isdn\">\n" \
"				ISDN\n" \
"			<option value=\"direct\">\n" \
"				Direct Connection\n" \
"		</select>\n" \
"	</p>\n" \
"\n" \
"	<p>\n" \
"		Have you ever sent email to our technical support?\n" \
"		<br>\n" \
"		<select name=\"email\">\n" \
"			<option value=\"no comment\" selected>\n" \
"				No Comment\n" \
"			<option value=\"yes\">\n" \
"				Yes, I Have\n" \
"			<option value=\"no\">\n" \
"				No, I Have Not\n" \
"		</select>\n" \
"\n" \
"		<dl>\n" \
"			<dd>\n" \
"				If so, was it satisfactory?\n" \
"				<br>\n" \
"				<select name=\"satisfied\">\n" \
"					<option value=\"no comment\" selected>\n" \
"						No Comment\n" \
"					<option value=\"yes\">\n" \
"						Yes, It Was\n" \
"					<option value=\"no\">\n" \
"						No, It Was Not\n" \
"				</select>\n" \
"				<dl>\n" \
"					<dd>\n" \
"						Why or why not?\n" \
"						<textarea name=\n" \
"						\"satisfied_feedback\" \n" \
"						rows=2 cols=40>\n" \
"						</textarea>\n" \
"					</dd>\n" \
"				</dl>\n" \
"			</dd>\n" \
"		</dl>\n" \
"	</p>\n" \
"\n" \
"<!---\n" \
"NOTE:\n" \
"	The following list of browsers\n" \
"	are IN ALPHABETICAL ORDER! Please Please Please, if you add one, put\n" \
"	it in ALPHABETICAL order as well...so we are not accused of being\n" \
"	perferential\n" \
"--->\n" \
"	<p>\n" \
"		What is your <b>favorite</b> Web browser?\n" \
"		<dl>\n" \
"			<dd>\n" \
"				<select name=\"favorite\" size=5>\n" \
"					<option value=\"no comment\" selected>\n" \
"						No Comment\n" \
"					<option value=\"arena\">\n" \
"						Arena\n" \
"					<option value=\"emacs-w3\">\n" \
"						Emacs-W3\n" \
"					<option value=\"spyglass\">\n" \
"						Enhanced Mosaic (Spyglass)\n" \
"					<option value=\"hot java\">\n" \
"						Hot Java\n" \
"					<option value=\"lynx\">\n" \
"						Lynx\n" \
"					<option value=\"ncsa\">\n" \
"						N.C.S.A. Mosaic\n" \
"					<option value=\"netscape $$$\">\n" \
"						Netscape (for $$$)\n" \
"					<option value=\"netscape free\">\n" \
"						Netscape (for free)\n" \
"					<option value=\"viola\">\n" \
"						Viola\n" \
"				</select>\n" \
"			</dd>\n" \
"		</dl>\n" \
"	</p>\n" \
"\n" \
"	<p>\n" \
"		Other comments and/or suggestions are welcomed:\n" \
"		<textarea name=\"comments_feedback\" rows=5 cols=60>\n" \
"		</textarea>\n" \
"	</p>\n" \
"\n" \
"	<p>\n" \
"		When you are done, please press this button:\n" \
"		<input type=\"submit\" value=\"Submit Comment Card for X Mosaic\"\n" \
"		name=\"submitme\">\n" \
"	</p>\n" \
"\n" \
"</form>\n" \
"\n";

void CommentCard(mo_window *win) {

FILE *fp;
long num[10];
char *fname;
int n;
char *htmlname, *htmlurl;

	if (!win) {
		win=mo_next_window(NULL);
	}
	if (!win) {
		return;
	}

	for (n=0; n<10; n++) {
		num[n]=0;
	}

	if (!do_comment) {
		if (!(fname=MakeFilename())) {
			return;
		}

		num[0]=GetCardCount(fname);
		num[0]++;
	}

#ifndef PRERELEASE
	if (num[0]==COMMENT_TIME || do_comment) {
		if (!(htmlname=tmpnam(NULL))) {
			free(fname);

			return;
		}
		if (!DumpHtml(htmlname)) {
			free(fname);

			return;
		}
		htmlurl=(char *)calloc(strlen(htmlname)+strlen("file://localhost")+10,sizeof(char));
		sprintf(htmlurl,"file://localhost%s",htmlname);
		mo_open_another_window(win,htmlurl,NULL,NULL);
		free(htmlurl);
	}
#endif

	if (!do_comment) {
		PutCardCount(num,fname);
	}

	free(fname);

	return;
}


int DumpHtml(char *htmlname) {

FILE *fp;

	if (!(fp=fopen(htmlname,"w"))) {
		return(0);
	}
	fprintf(fp,"%s\n",comment_card_html_top);
	fprintf(fp,"					Mosaic Compiled OS: %s<br>\n",MO_COMMENT_OS);
	fprintf(fp,"					<input type=\"hidden\" name=\"os\" value=\"%s\">\n",MO_COMMENT_OS);
	fprintf(fp,"					Sysname: %s<br>\n",mo_uname.sysname);
	fprintf(fp,"					<input type=\"hidden\" name=\"sysname\" value=\"%s\">\n",mo_uname.sysname);
	fprintf(fp,"					Release: %s<br>\n",mo_uname.release);
	fprintf(fp,"					<input type=\"hidden\" name=\"release\" value=\"%s\">\n",mo_uname.release);
	fprintf(fp,"%s\n",comment_card_html_bot);
	fclose(fp);

	return(1);
}


char *MakeFilename() {

char *hptr, home[256], *fname;
struct passwd *pwdent;

	/*
	 * Try the HOME environment variable, then the password file, and
	 *   finally give up.
	 */
	if (!(hptr=getenv("HOME"))) {
		if (!(pwdent=getpwuid(getuid()))) {
			return(NULL);
		}
		else {
			strcpy(home,pwdent->pw_dir);
		}
	}
	else {
		strcpy(home,hptr);
	}

	fname=(char *)calloc(strlen(home)+strlen(COMMENT_CARD_FILENAME)+
			     strlen(MO_VERSION_STRING)+5,sizeof(char));
	sprintf(fname,"%s/%s%s",home,COMMENT_CARD_FILENAME,MO_VERSION_STRING);

	return(fname);
}


void InitCard(char *fname) {

FILE *fp;
long num[10];
int n;

	if (!(fp=fopen(fname,"w"))) {
		return;
	}

	num[0]=1;
	n=fwrite(num,sizeof(long),2,fp);

	fclose(fp);

	return;
}


void PutCardCount(long *num, char *fname) {

FILE *fp;
int n;

	if (!(fp=fopen(fname,"w"))) {
		return;
	}

	n=fwrite(num,sizeof(long),2,fp);

	fclose(fp);

	return;
}


long GetCardCount(char *fname) {

FILE *fp;
long num[10];
int n;

	if (!(fp=fopen(fname,"r"))) {
		InitCard(fname);
		return((long)0);
	}
	fseek(fp,0L,SEEK_SET);
	n=fread(num,sizeof(long),2,fp);

	fclose(fp);

	return(num[0]);
}
