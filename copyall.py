import os
import shutil


def fetch_files_r(path: str):
    files_found = []
    for root, _, files in os.walk(path):
        for file in files:
            files_found.append(os.path.join(root, file))
    return files_found


def get_files_difference(root: str, divisor: str):
    divisor_files = fetch_files_r(divisor)
    root_files = fetch_files_r(root)

    divisor_mod_time = {file.lstrip(divisor + os.sep): os.path.getmtime(file) for file in divisor_files}

    diff_files = []
    for root_file in root_files:
        stripped_root_file = root_file.lstrip(root + os.sep)
        found_file = divisor_mod_time.get(stripped_root_file)

        if not found_file or os.path.getmtime(root_file) > found_file:
            diff_files.append(stripped_root_file)

    return diff_files


def create_file_r(from_file, to_file):
    file_directory = os.path.dirname(to_file)
    os.makedirs(file_directory, exist_ok=True)
    shutil.copyfile(from_file, to_file)


# IMPORTANT VARIABLES
#################################

dynamic_lib_source = "lib"
bin_source = "bin"

#################################

# LOGIC
#################################

files_to_cp = get_files_difference(dynamic_lib_source, bin_source)

for file in files_to_cp:
    dyn_file = os.path.join(dynamic_lib_source, file)
    bin_file = os.path.join(bin_source, file)
    create_file_r(dyn_file, bin_file)

#################################
