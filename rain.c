#inclu "shell.h"
/**
 * interactive - ghadi terja3 b  1 ila kan shell is interactive mode
 * 1 will returned ila kan intractive mode and 0 will be returned ila kan otherwise mn hadok li endna 
 */
int intractive(info_t *jh)
{
	if (isatty(STDIN_FILENO)&& jh->readfd >= 0 && jh->readfd<=2){
		return 1;
	}else{
		return 0;
	}
}

/**
 * is_delim katchof  wach  character rah  delimeter
 * @c l7aref li ghadi nchofoh
 * @delim: hiya delim parameter li ghadi nkhadmo bih 
 * Return: 1 ila kant s7i7a , 0 ila kant ghalta 
 */
int is_delim(char c, char *ce)
{
	while (*ce)
		if (*ce++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha katchof lina wach dak l7aref wach char
 * @lettero: howa l input deyal l7aref 
 * ghadi terja3 lina b 1 ila kan ah we b 0 ila kan lae 
 */

int _isalpha(int lettero)
{
	if((lettero>='a'&& lettero<='z')|| (lettero 'A' && lettero 'Z')){
		return (1);
	}else{
		return (0);
	}
}



/**_atoi katred lina string l int
 * @new_string_from_int hiya bach ghadi nkhadmo 
 * ila reja3 lina 1 rah se7i7 ila reja3 lina 0 rah ghalet 
 */

int _atoi(char *new_string_from_int)
{
	int ichara=1;
	unsigned int kharij=0;
	while (*new_string_from_int != '\0'){
		if(*new_string_from_int == '-'){
			ichara = -1;
			new_string_from_int ++;
			continue;
		}else if (*new_string_from_int < '0' || *new_string_from_int > '9') {
			new_string_from_int++;
			continue;
		}
		kharij =(kharij * 10)+(*new_string_from_int -'0');
		new_string_from_int++;
	}
	return (ichara * kharij);
}
