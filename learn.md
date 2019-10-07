# les signaux 
- ce sont des int que recois le processus de lui meme ou du noyaux,
il donne des ordres ou previennet de demande.
    * avec fg, il previenne le processus qu'une demande de background est en cours
      et que le process, ici doit quitter. ca permet a mon programme de communiquer avec 
      le system et de savoir ce qu'il se passe ! 
    * I need to learn what tty is ? 
    
# int tgetnum(char *id)
-> me permet de get les line et les colomns de mon terminal 
int column_count = tgetnum("co");
int line_count = tgetnum("li");

# int tgetflag(char *id)
regarde si je peux faire les choses que je veux faire (return bool)

#char tgetstr(char *name, NULL);
char *cl_cap = tgetstr("cl", NULL); // return mon le termcaps a utiliser

# int tputs(const char *str, int affcnt, int (*putc)(int));
va faire le termcaps, 2eme est le nombre de line affecter, la fonction set un putchar

