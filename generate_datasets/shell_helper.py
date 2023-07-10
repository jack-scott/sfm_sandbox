import atexit
import code
import readline
import rlcompleter
import builtins

class InteractiveShellHelper:
    def __init__(self):
        self.histfile = ".python_history"
        self.setup_readline()
        # Register the cleanup function to be called when the program exits
        atexit.register(self.interact)

    def setup_readline(self):
        # Enable tab completion
        readline.parse_and_bind("tab: complete")

        # Enable history
        readline.set_history_length(1000)

        try:
            readline.read_history_file(self.histfile)
        except FileNotFoundError:
            pass

        # Save history when exiting
        # atexit.register(readline.write_history_file, self.histfile)

    def interact(self, main_locals=None):
        # Combine local and global variables
        local_vars = builtins.__dict__.copy()
        if main_locals is not None:
            local_vars.update(main_locals)

        # Open an interactive shell with combined variables
        code.interact(local=local_vars)