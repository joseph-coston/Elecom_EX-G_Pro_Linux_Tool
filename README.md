# Elecom_EX-G_Pro_Linux_Tool
A simple configuable program for getting the extra function buttons of the
Elecom EX-G Pro trackball mouse (M-XPT1MR) to work in Linux.

I tried to design this tool to be as simple and easy to get going as possible, 
but there are a couple of things you will need to do to get it set up.

First, you will need to install the YAML C library and the xdotool:
  sudo apt install libyaml-dev xdotool
Next, navigate into the Debug directory in terminal and execute:
  make all
Finally, move back up to the root directory of the project and execute:
  ./Debug/Mouse_Mod
  
This should successfully start the program in your terminal so that you will
see keypress events printed to the terminal when they are detected.

You can edit the keybinds by changing the contents of the YAML config files.
They are pretty self-explanatory, but you can basically put any terminal command
in the quotes next to the mouse event of your choice and it will be executed
whenever that event is detected. I like using the xdotool to bind the mouse 
buttons to keyboard macros or combinations. Changes to the config files are 
reflected in the program immediately after saving them; no program restart or
recompile necessary. Only the 'config.yaml' file will be read for keybinds,
but I included as an example a way to make the program swap between multiple 
profiles using a keybind to a bash file renaming opreation and a second config
file 'config.0.yaml' that gets swapped with 'config.yaml' when you press the button
beneath the scroll wheel.

Once you have the program compiled and working, you can move the compiled executable,
along with any config files you make to the directory of your choice and add the program
to the list of startup services so that it starts in the background when you log in.

ENJOY!

~Joseph Coston
  
