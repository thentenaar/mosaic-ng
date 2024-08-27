
#ifndef _KCMS_H_
#define _KCMS_H_

extern int KCMS_Enabled;
extern int KCMS_Return_Format;

#define JPEG 0
#define JYCC 1
#define GIF 2

void CheckKCMS(void);
#endif /* _KCMS_H_ */
