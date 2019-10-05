# isatty :  
int isatty(int fd)
determine if the file descriptor refer to a valid terminal type device
OK => 1 // KO => 0.

# ttyname :
char *ttyname(int fd)
gets the relatived device name of the fd, for which isatty is true.

# ttyslot
I have no fucking idea, it return the slot of the current user, but what ??

# ioctl -- control device -- <sys/ioctl.h> (Input Output ConTroL)
int ioctl(int fildes, unsigned long request, ...)
permet de communiquer avec un fd, dans les deux sens,
par exemple, si je veux envoyer des donnes avec un modem,
je vais ouvrir le modem et ecrire dedans comme si c'etait un file,
mais, si je veux par exemple, lui set une vitesse de transfert ? 

la reponse d'unix a ce probleme, est d'ouvrir une function ioctl.
tout les devices on leurs propre ioctl function, et peuvent
read    : envoyer des information au kernel
write   : retrouner des informations au process
        : les deux, ou aucune.

the ioctl number encode:  
- the major device number
- the type of the ioctl
- the command
- the type of parameter

the ioctl number are include in a .h that the kernel and the device must have

# getenv
char *
getenv(const char *name);
retun the value in env of the name, null if no found, 


# termcaps functions :

termcap a besoin d'etre initialiser, et pour ce faire, 
il a besoin d'utiliser la fonction suivante pour initialiser la lib,

## getenv
int tgetent(char *bp, const char *name);
le premier est un buffer ou stocker les data,
le deuxieme est le nom de mon terminal, que je vais
surement get avec les options precedentes ! 
je dois donner a termcaps le nom de mon terminal
pour qu'il s'aligne avec lui.















