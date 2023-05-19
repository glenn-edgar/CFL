import os
import argparse

# Define the directory to search for .cpp and .h files
directory = "./"

# Define command line arguments
parser = argparse.ArgumentParser()
parser.add_argument("old_name", help="the old name to replace")
parser.add_argument("new_name", help="the new name to use")
args = parser.parse_args()

# Loop through all .cpp and .h files in the directory
for filename in os.listdir(directory):
    if filename.endswith(".cpp") or filename.endswith(".h") or filename.endswith(".c"):
        # Read the contents of the file
        with open(os.path.join(directory, filename), "r") as file:
            contents = file.read()
        # Replace all occurrences of the old name with the new name
        modified_contents = contents.replace(args.old_name, args.new_name)
        # Write the modified contents back to the file
        with open(os.path.join(directory, filename), "w") as file:
            file.write(modified_contents)

