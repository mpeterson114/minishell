# Minishell 🐚
## Summary
A Bash-inspired shell programmed in C. Capable of command parsing and execution, environmental variable expansion and some builtin functions, along with other shell functionalities such as redirection, pipes and signal handling. 
> This was a two-person project completed with **ilonazh** 

## ⚙️ Usage
Clone the repository:
```
git clone git@github.com:mpeterson114/minishell.git
```
Compile:
```
cd minishell && make
```
And run the executable:
```
./minishell
```
A prompt will appear. You can then enter your shell commands to be executed.

To exit the Minishell, enter the ```ctrl-d```command.

## 📌 Supported Features
* Prompt display
* Command history (up and down arrows)
* System executables available from the environment (```ls```, ```cat```, ```grep```, etc.)
* Local executables (```./minishell```)
* Builtin commands :
  * ```echo``` (with/without option ```-n```)
  * ```cd``` (with only a relative or absolute path)
  * ```pwd``` (no options)
  * ```export``` (no options)
  * ```unset``` (no options)
  * ```env``` (no options or arguments)
  * ```exit``` (with exit number but no other options)
* Pipes ```|``` 
* Redirections:
  * ```>``` redirects output
  * ```>>``` redirects output in append mode
  * ```<``` redirects input
  * ```<< DELIMITER``` displays a new prompt, reads user input until reaching the specified ```DELIMITER```, redirects user input to command input (does not update history)
* Environment variables (i.e. ```$USER``` or ```$VAR```) that expand to their values.
* ```$?``` expands to the exit status of the most recently executed foreground pipeline.
* User keyboard signals:
  * ```ctrl-c``` displays a new prompt line.
  * ```ctrl-d``` exits minishell
  * ```ctrl-\``` does nothing

Minishell does _not_ support ```\```, ```;```, ```&&```, ```||```, or wildcards.

