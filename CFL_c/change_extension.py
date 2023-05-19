import os
import shutil

# Set the directory path to search for files
directory_path = "./"

# Get a list of all files in the directory
files = os.listdir(directory_path)

# Loop through all files in the directory
for file_name in files:
    # Check if the file has a .cpp extension
    if file_name.endswith(".cpp"):
        # Generate the new file name by replacing .cpp with .c
        new_file_name = file_name.replace(".cpp", ".c")
        # Construct the full file paths
        old_file_path = os.path.join(directory_path, file_name)
        new_file_path = os.path.join(directory_path, new_file_name)
        # Rename the file
        shutil.move(old_file_path, new_file_path)
        # Print the old and new file names for confirmation
        print(f"Renamed file: {file_name} -> {new_file_name}")

