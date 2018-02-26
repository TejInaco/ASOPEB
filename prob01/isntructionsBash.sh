	Syntax highlighting in vim
 	
In order to activate syntax highlighting in vim, use the command

:syntax enable

or

:sy enable

or

:syn enable

You can add this setting to your .vimrc file to make it permanent.

##################################################################

Give your script a sensible name that gives a hint about what the script does. Make sure that your script name does not conflict with existing commands. In order to ensure that no confusion can rise, script names often end in .sh; even so, there might be other scripts on your system with the same name as the one you chose. Check using which, whereis and other commands for finding information about programs and files:

which -a script_name

whereis script_name

locate script_name

##################################################################

