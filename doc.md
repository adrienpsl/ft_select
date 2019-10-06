
1 build le parser
    * comment je mets mes structure
    * comment je parse les arguments (si pas imprimable ...)
2 comment gere les signaux > C et Z
3 print et redimensionner
4 faire les changement 
5 tester 

the process I have to protect: 
-> SIGINT > ctrl + c : please go back to the main loop
-> SIGQUIT > ctrl + \ : please quit immediately
-> SIGHUP > is send when I close the terminal window

-> SIGTSTP > ctrl + z : please suspend 
-> SIGCONT > is used when my program restart

-> SIGWINCH > is send when the window change
->  

-> the pb of my terminal :
    // reset and exit with clean data
    -> SIGABRT > when double free 
    -> SIGBUS > bus error
    -> SIGSEGV > segfault